#include <bits/stdc++.h>
using namespace std;
#pragma pack(1)
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef int LONG;
typedef struct _BMPFH
{
    BYTE bftype1;
    BYTE bftype2;
    DWORD bfsize;
    WORD bfreserved1;
    WORD bfreserved2;
    DWORD bfOffbits;
}BMPFH;
typedef struct _BMPIH
{
    DWORD bisize;
    LONG biw;
    LONG bih;
    WORD biplane;
    WORD bibitcount;
    DWORD biComp;
    DWORD bisizeimage;
    LONG bix;
    LONG biy;
    DWORD biclused;
    DWORD biclimp;
}BMPIH;
typedef struct _PALET
{
    BYTE rgbblue;
    BYTE rgbgreen;
    BYTE rgbred;
    BYTE rgbreserved;
}PALET;
typedef struct _IMAGE
{
	BMPFH   bmpfh;
	BMPIH   bmpih;
	PALET   *palet;
	BYTE    *data;
}  IMAGE;

IMAGE   *ImageRead(IMAGE *image,char *filename);
void ImageWrite(IMAGE *image, char *filename);
void writeInfo(IMAGE *image,char *fname);
void setZero(IMAGE*image);
void histogram(IMAGE* image);
void histogram(IMAGE* image, double hist[]);
void histogramEqulization(IMAGE *image);
void negativeImage(IMAGE *image);
long findSize(IMAGE*image);
void changeColorPalette(IMAGE *image);
BYTE meanofmaxmin(BYTE *data,int h,int rowsize);



int main(){
    
    IMAGE *image=(IMAGE*)malloc(sizeof(IMAGE));
	image=ImageRead(image,"biber.bmp");
	//writeInfo(image,"biber.bmp");
	//setZero(image);
	//histogram(image);
    //histogramEqulization(image);
    //negativeImage(image);
	changeColorPalette(image);
    ImageWrite(image,"test.bmp");
	free(image);
    return 0;
}

long findSize(IMAGE*image){
    int rowsize,h,w;
    h = image->bmpih.bih;
    w = image->bmpih.biw;
    rowsize = (image->bmpih.bibitcount*w+31)/32*4;
    return rowsize*h;
}

IMAGE *ImageRead(IMAGE *image,char *filename){
    BMPFH bmpfh;
    BMPIH bmpih;
    FILE *fp;
    DWORD r,rowsize,size;

    fp = fopen(filename, "rb");
    if(fp == NULL){
        printf("File not found\n");
        exit(1);
    }

    fread(&bmpfh, sizeof(BMPFH), 1, fp);
    if(bmpfh.bftype1 != 'B' || bmpfh.bftype2 != 'M'){
        printf("This is not a bitmap file\n");
        exit(1);
    }

    fread(&bmpih, sizeof(BMPIH), 1, fp);

    image = (IMAGE *) malloc(bmpfh.bfsize);
    if(image == NULL){
        printf("There is no enough memory for this operation\n");
        exit(1);
    }

    image->bmpfh = bmpfh;
    image->bmpih = bmpih;

    r = 0;
    if(bmpih.bibitcount == 1) r = 2;
    else if(bmpih.bibitcount == 4) r = 16;
    else if(bmpih.bibitcount == 8) r = 256;
    if(r!=0){
        image->palet = (PALET*) malloc(4*r);
        fread(image->palet,sizeof(BYTE),4*r,fp);
    }

    rowsize = (image->bmpih.biw * image->bmpih.bibitcount+31)/32*4;
    size = rowsize * image->bmpih.bih;
    image->data = (BYTE*) malloc(size);
    fread(image->data,size,1,fp);
    fclose(fp);
    return image;
}
void ImageWrite(IMAGE *image, char *filename)
{
    FILE *fp;
    int r=0,row,size;

    fp = fopen(filename,"wb");
    if(fp == NULL){
        printf("File openning error");
        exit(1);
    }

    fwrite(&image->bmpfh,sizeof(BMPFH),1,fp);
    fwrite(&image->bmpih,sizeof(BMPIH),1,fp);

    if(image->bmpih.bibitcount==1) r=2;
    else if(image->bmpih.bibitcount==4) r=16;
    else if(image->bmpih.bibitcount==8) r=256;

    if(r!=0) fwrite(image->palet,4*r,1,fp);

    fwrite(image->data,image->bmpih.bisizeimage,1,fp);
    fclose(fp);
}
void writeInfo(IMAGE *image,char *fname)
{
	printf("--------Info about %s  image file\n",fname);
	printf("bfType value		:%c%c\n",image->bmpfh.bftype1,image->bmpfh.bftype2);
	printf("bfsize			:%d\n",image->bmpfh.bfsize);
	printf("bfreserved1		:%d\n",image->bmpfh.bfreserved1);
	printf("bfreserved2		:%d\n",image->bmpfh.bfreserved2);
	printf("bfOffbits		:%d\n",image->bmpfh.bfOffbits);
	printf("bisize			:%d\n",image->bmpih.bisize);
	printf("Width			:%d\n",image->bmpih.biw);
	printf("Height			:%d\n",image->bmpih.bih);
	printf("biplane			:%d\n",image->bmpih.biplane);
	printf("bibitcount		:%d\n",image->bmpih.bibitcount);
	printf("Compression		:%d\n",image->bmpih.biComp);
	printf("bisizeimage		:%d\n",image->bmpih.bisizeimage);
	printf("bix			:%d\n",image->bmpih.bix);
	printf("biy			:%d\n",image->bmpih.biy);
	printf("bi color used		:%d\n",image->bmpih.biclused);
	printf("bi color imp.		:%d\n",image->bmpih.biclimp);
}
void setZero(IMAGE*image){
    int size = image->bmpih.bisizeimage;
    for(int i = 0; i < size; i++) image->data[i] = (image->data[i]*30+40)%255;

}
void histogram(IMAGE* image){
    int rowsize,h,w,i;
    int hist[256] = {0};
    h = image->bmpih.bih;
    w = image->bmpih.biw;

    rowsize = (image->bmpih.bibitcount * w + 31)/32*4;

    for ( i = 0; i < rowsize*h; i++)
        hist[image->data[i]]++;
    
    FILE *fp;
    fp = fopen("hist.txt","w");

    for(i=0;i < 256;i++)
        fprintf(fp,"%d\t%d\n",i,hist[i]);

    fclose(fp);
    
}
void histogram(IMAGE* image, double hist[]){
    int row,i,h,w;
    h = image->bmpih.bih;
    row = (image->bmpih.biw*image->bmpih.bibitcount+31)/32*4;
    for(i = 0; i <  h*row; i++){
        hist[image->data[i]]++;
    }

}
void histogramEqulization(IMAGE *image){
    double hist[256] = {0},t;
    int row,h,w,i;

    h = image->bmpih.bih;
    w = image->bmpih.biw;
    row = (w*image->bmpih.bibitcount + 31)/32 *4;

    histogram(image,hist);

    for(i=0;i< 256;i++) hist[i] /= (h*row);
    
    for(i=0;i<256;i++){
        t+=hist[i];
        hist[i] = (int)(t*255);
    }

    for(i=0;i<row*h;i++){
        image->data[i] = (BYTE)hist[image->data[i]];
    }
}
void negativeImage(IMAGE *image){
    long allsize=findSize(image);
    int i;
    for(i = 0; i<allsize; i++)
        image->data[i] = pow(2,image->bmpih.bibitcount) - 1 -image->data[i];
}
void changeColorPalette(IMAGE *image){
    int r,i;
    r = pow(2,image->bmpih.bibitcount);

    for(i=0;i<r;i++){
        image->palet[i].rgbblue = 254;//r-1-image->palet->rgbblue;
       // image->palet[i].rgbred = r-1-image->palet->rgbred;
        image->palet[i].rgbgreen = r-1-image->palet->rgbgreen;
    }
}
BYTE meanofmaxmin(BYTE *data,int h,int rowsize){
    
}


