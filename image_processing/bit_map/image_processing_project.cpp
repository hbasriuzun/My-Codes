    #include <bits/stdc++.h>
    #include <fstream>
    #include <iostream>

    #pragma pack(1)

    typedef unsigned char BYTE;//1 bytes of memory
    typedef unsigned short WORD;//2 bytes of memory
    typedef unsigned int DWORD;//4 bytes of memory
    typedef int LONG;//4 bytes of memory
    typedef struct _BMPFH//takes 14 bytes of memory
    {
        BYTE bftype1;//1 byte and must be 'B'
        BYTE bftype2;//1 byte and must be 'M'
        DWORD bfsize;//4 bytes gives us the all size of bmp file (including headers,palette (if it has) data)
        WORD bfreserved1;// 2 btyes of memory could be set as 0
        WORD bfreserved2;// 2 btyes of memory could be set as 0
        DWORD bfOffbits;//4 bytes of memeory gives the position of data starts in the bmp file
    } BMPFH;
    typedef struct _BMPIH//40 bytes for windows bitmap file
    {
        DWORD bisize;//4 bytes and it gives the size of info header
        LONG  biw;//4 bytes and it is the width of image
        LONG bih;//4 bytes and it is the height of iimage
        WORD biplane;//2 bytes which is not important for us
        WORD bibitcount;//2 bytes it is about the type of bitmap file if it is 1 2 color, 4 (16 colors) ..
        DWORD biComp;//4 bytes not important
        DWORD bisizeimage;//4 bytes and it gives the size of data in the image 
        LONG bix;//4 bytes not importatnt
        LONG biy;//4 bytes not important
        DWORD biclused;//4 bytes not important
        DWORD biclimp;//4 byets not importatnt for us
    }  BMPIH;
    typedef struct _PALET//in palette it describes colors (what is the color number)
    {
        BYTE rgbblue;//blue commponent
        BYTE rgbgreen;//green component
        BYTE rgbred;//red component
        BYTE rgbreserved;//reserved byte the user can use this for therir aims
    } PALET;


    class IMAGE
    {
    private:
        BMPFH   bmpfh;
        BMPIH   bmpih;
        std::unique_ptr<PALET[]> palet;
        std::unique_ptr<BYTE[]> data;
        DWORD rowsize,size,palettesize;
    public:


        void ImageRead(std::string filename);
        void ImageWrite(std::string filename);
        void writeInfo(std::string fname);
        void setZero();
        void histogram(std::vector<int> &hist);
        void histogram();
        void histogram(std::vector<double> &hist){
        void histogramEqualization();



        IMAGE(/* args */);
        ~IMAGE();
    };

    IMAGE::IMAGE(/* args */)
    {
            data = nullptr; 
            palet = nullptr;  
            palettesize = 0;  // Initialize data and plaet to nullptr initially
    }

    IMAGE::~IMAGE()
    {
    }

    int main(){
        std::unique_ptr<IMAGE> resim = std::make_unique<IMAGE>();
        resim->ImageRead("biber.bmp");
        //resim->writeInfo("biber.bmp");
        //resim->setZero();
        //resim->ImageWrite("test.bmp");
        resim->histogram();
        resim->~IMAGE();
    }

    void IMAGE::ImageRead(std::string filename){
        BMPFH _bmpfh;
        BMPIH _bmpih;
        std::ifstream inputFile(filename,std::ios::binary);

        if(!inputFile) {printf("File is not found..");exit(1);}
        inputFile.read(reinterpret_cast<char*>(&_bmpfh), sizeof(BMPFH));
        if(_bmpfh.bftype1 != 'B' || _bmpfh.bftype2 != 'M'){
            printf("This is not a bitmap file.");
            exit(1);
        }
        inputFile.read(reinterpret_cast<char*>(&_bmpih), sizeof(BMPIH));

        this->bmpfh = _bmpfh;
        this->bmpih = _bmpih;

        this->palettesize = 1 << bmpih.bibitcount;
        
        if(this->palettesize!=0){
            palet = std::make_unique<PALET[]>(palettesize);
            inputFile.read(reinterpret_cast<char*>(palet.get()), this->palettesize * sizeof(PALET));
        }

        this->rowsize = (this->bmpih.biw * this->bmpih.bibitcount + 31)/32*4;
        this->size = this->rowsize * this->bmpih.bih;

        this->data = std::make_unique<BYTE[]>(this->size);
        if(this->data == nullptr) {printf("There is no enough memory for this operation");exit(1);}
        inputFile.read(reinterpret_cast<char*>(this->data.get()), size);
        inputFile.close();

    }
    void IMAGE::ImageWrite(std::string filename){
        std::ofstream outputFile(filename,std::ios::binary);
        if(!outputFile) {printf("File is not found..");exit(1);}
        outputFile.write(reinterpret_cast<char*>(&bmpfh), sizeof(BMPFH));
        outputFile.write(reinterpret_cast<char*>(&bmpih), sizeof(BMPIH));
        outputFile.write(reinterpret_cast<char*>(palet.get()), 4 * this->palettesize);
        outputFile.write(reinterpret_cast<char*>(data.get()),size );
    
        outputFile.close();
    }
    void IMAGE::writeInfo(std::string fname){
    std::cout << "--------Info about " << fname << " image file\n";
	printf("bfType value		:%c%c\n",this->bmpfh.bftype1,this->bmpfh.bftype2);
	printf("bfsize			:%d\n",this->bmpfh.bfsize);
	printf("bfreserved1		:%d\n",this->bmpfh.bfreserved1);
	printf("bfreserved2		:%d\n",this->bmpfh.bfreserved2);
	printf("bfOffbits		:%d\n",this->bmpfh.bfOffbits);
	printf("bisize			:%d\n",this->bmpih.bisize);
	printf("Width			:%d\n",this->bmpih.biw);
	printf("Height			:%d\n",this->bmpih.bih);
	printf("biplane			:%d\n",this->bmpih.biplane);
	printf("bibitcount		:%d\n",this->bmpih.bibitcount);
	printf("Compression		:%d\n",this->bmpih.biComp);
	printf("bisizeimage		:%d\n",this->bmpih.bisizeimage);
	printf("bix			:%d\n",this->bmpih.bix);
	printf("biy			:%d\n",this->bmpih.biy);
	printf("bi color used		:%d\n",this->bmpih.biclused);
	printf("bi color imp.		:%d\n",this->bmpih.biclimp);
    }
    void IMAGE::setZero(){
        int h = this->bmpih.bih;
        for(int i=0; i<h; i++)
            for(DWORD j=0; j<rowsize; j++) this->data[i*rowsize+j]=0;
    }
    void IMAGE::histogram(std::vector<double> &hist){
        for(int i = 0; i < this->size ;i++)
            hist[this->data[i]]++;
    }
    void IMAGE::histogram(){
        std::vector hist(this->palettesize);
        for (size_t i = 0; i < this->palettesize; i++)
            hist[this->data[i]]++;
        std::ofstream outputxt("hist.txt");
        if (!inputFile) {std::cerr << "Dosya açılamadı." << std::endl;return 1;}
        for (size_t i = 0; i < this->palettesize; i++)
            outputxt << i << "\t" << hist[i] << "\n";
        outputxt.close();
        
    }
    void IMAGE::histogramEqualization(){
        std::vector<double> hist(this->palettesize);
        int t;

        this->histogram(hist);
        for (size_t i = 0; i < this->palettesize; i++)
            hist[i] /= this->size;
        for (size_t i = 0; i < this->palettesize; i++)
        {
            t+=hist[i];
            hist[i] = (int)(t*this->palettesize);
        }
        for (size_t i = 0; i < this->palettesize; i++)
            this->data[i] = (BYTE)hist[this->data[i]];
    }

