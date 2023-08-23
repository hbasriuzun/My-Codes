#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
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
typedef struct _IMAGE
{
	BMPFH   bmpfh;
	BMPIH   bmpih;
	PALET   *palet;
	BYTE    *data;
}  IMAGE;
IMAGE *ImageRead(IMAGE *image,char *filename)
{
	BMPFH bmpfh;
	BMPIH bmpih;
	FILE *fp;
	DWORD r,rowsize,size;
	fp=fopen(filename,"rb");//tries to open the filename
	if(fp==NULL) {printf("File is not found..");exit(1);}
	fread(&bmpfh,sizeof(BMPFH),1,fp);//reads bitmap file header from the file and set to bmph
	if(bmpfh.bftype1!='B' || bmpfh.bftype2!='M')
	{
		printf("This is not a bitmap file.");
		exit(1);
	}
    fread(&bmpih,sizeof(BMPIH),1,fp);//reads bitmap info header from the file and set to bmpih
	image=(IMAGE *) malloc(bmpfh.bfsize);//allocates memory for image
	if(image==NULL) {printf("There is no enough memory for this operation");exit(1);}
	image->bmpfh=bmpfh;//sets bmpfh to image 
	image->bmpih=bmpih;//sets bmpih to image
	
	r=0;//r is set to 0 in case 24 bits per pixel or more (this kind of images does not have color palette)
    if(bmpih.bibitcount==1) r=2;//if the image 1 bit per pixel (the number of clor is 2)
	if(bmpih.bibitcount==4) r=16;//if the image 4 bits per pixel (the number of clor is 16)
	if(bmpih.bibitcount==8) r=256;////if the image 8 bits per pixel (the number of clor is 256)
	if(r!=0)
	{
		image->palet=(PALET *) malloc(4*r);//allocate memory for color palette
		fread(image->palet,sizeof(BYTE),4*r,fp);//read color palette from image to the memory
	}
	rowsize=(image->bmpih.biw*image->bmpih.bibitcount+31)/32*4;//calculates 1 row of image size 
	size=rowsize*image->bmpih.bih;//all size of image is calculated and set to size 
	image->data=(BYTE *)malloc(size);//allocates enough memory for iamage data
	fread(image->data,size,1,fp);//reads image data from file and sets to image->data
	fclose(fp); //closes the file
	return image;//returns the adress of image on the memory
}       
void ImageWrite(IMAGE *image,char *filename)
{
	FILE *fp;
	int r,rowsize,size;
	
	fp=fopen(filename,"wb");//opens the file );exit(1);}
	if(fp==NULL) {printf("Fie opening error!");exit(1);}
	fwrite(&image->bmpfh,sizeof(BMPFH),1,fp);//writes the bitmap file header to the file
	fwrite(&image->bmpih,sizeof(BMPIH),1,fp);//writes he bitmep info header to the file		
	r=0;
    if(image->bmpih.bibitcount==1) r=2;//if the image has 2 colors
	if(image->bmpih.bibitcount==4) r=16;//if the image has 16 colors
	if(image->bmpih.bibitcount==8) r=256;//if the image has 256 colors
	if(r!=0) fwrite(image->palet,4*r,1,fp);//if the image has color palette the palette is written to the file
	rowsize=(image->bmpih.biw*image->bmpih.bibitcount+31)/32*4;//a row size of image is calculated 
	size=rowsize*image->bmpih.bih;//all size of image is calculated
	fwrite(image->data,size,1,fp);//write image data to the file
	fclose(fp);//closes the file 
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
	printf("data: %d\n",*(image->data + 7));
}
void setZero(IMAGE *image)
{
	int i,rowsize;
	rowsize=(image->bmpih.biw*image->bmpih.bibitcount+31)/32*4;
	for(i=0;i<image->bmpih.bih*rowsize;i++) image->data[i]=0;
}
void histogram(IMAGE* image,double hist[]){
	int i,rowsize,size;
	rowsize = (image->bmpih.bibitcount * image->bmpih.biw + 31)/32*4;
	size = rowsize*image->bmpih.bih;
	for ( i = 0; i < size ;i++)
		hist[image->data[i]]++;	
}
void histogram(IMAGE* image){
	int hist[256]={0};
	int i,rowsize,size;
	rowsize = (image->bmpih.bibitcount * image->bmpih.biw + 31)/32*4;
	size = rowsize*image->bmpih.bih;
	for ( i = 0; i < size; i++)
		hist[image->data[i]]++;	
	FILE* fp;
	fp = fopen("hist.txt","wr");
	for(i=0; i<256; i++)
		fprintf(fp,"%d\t%d",i,hist[i]);
	fclose(fp);
}
void histogramEqualization(IMAGE*image){
	double hist[256]={0},t=0;
	IMAGE* copy_image = image;
	int i,rowsize,size,h,w;
	w = image->bmpih.biw;
	h = image->bmpih.bih;
	rowsize = (image->bmpih.bibitcount*w+31)/32*4;
	size = rowsize*h;
	histogram(image,hist);
	for ( i = 0; i < 256; i++)
	{
		t+=hist[i]/size;
		hist[i] = (BYTE)(t * 255);
	}
	for(i=0;i<size;i++){
		image->data[i] = hist[image->data[i]];
	}

}
void negativeImage(IMAGE*image){
	int i,rowsize,size,h,w;
	w = image->bmpih.biw;
	h = image->bmpih.bih;
	rowsize = (image->bmpih.bibitcount*w+31)/32*4;
	size = rowsize*h;
	for(i=0;i<size;i++){
		image->data[i] = pow(2,image->bmpih.bibitcount)-1-image->data[i];
	}
}
void changeColorPalette(IMAGE *image)
{
	int r,i;
	r=pow(2,image->bmpih.bibitcount);
	for(i=0;i<r;i++)
	{
		image->palet[i].rgbblue=pow(2,image->bmpih.bibitcount)-1-image->palet[i].rgbblue;
		image->palet[i].rgbred=pow(2,image->bmpih.bibitcount)-1-image->palet[i].rgbred;
		image->palet[i].rgbgreen=pow(2,image->bmpih.bibitcount)-1-image->palet[i].rgbgreen;
	}
}
BYTE meanofmaxmin(BYTE* data,int h, int rowsize){
	int i;
	BYTE max,min;
	for ( i = 0; i < rowsize*h; i++)
	{
		if (max<data[i]) max=data[i];
		if (min>data[i]) min=data[i];
	}
	double t = (max+min)/2.;
	return (BYTE)t;	
}
BYTE mean(BYTE *data,int h, int rowsize){
	double sum;
	int i;
	for ( i = 0; i < h*rowsize; i++)
	{
		sum+=data[i];
	}
	sum/=(rowsize*h);
	return (BYTE) sum;
}
void thresholdImage(IMAGE *image,BYTE t){
	int h,w,rowsize,i;
	h=image->bmpih.bih;
	w=image->bmpih.biw;
	rowsize=(image->bmpih.bibitcount*w+31)/32*4;

	for (i = 0; i < rowsize*h; i++)
	{
		if(image->data[i]>t) image->data[i] = 255;
		else image->data[i] = 0;
	}
}
void swap(BYTE *a, BYTE*b){
	BYTE *t;
	t = a;
	a = b;
	b = t;
}
BYTE median2(BYTE *data,int h,int rowsize){
	auto swap = [](array<int,2> a,array<int,2> b){
		return a[1] > b[1];
	};
	int i,j,index,size = rowsize * h,sum;
	int size2 = size/2;
	array<array<int,2>,255> hist;
	for ( i = 0; i < size; i++){
		hist[data[i]][1]++;	
	}
	for(i=0;i<255;i++)
		hist[i][0] = i;
	sort(hist.begin(),hist.end(),swap);

	for ( i = 0; i < size; i++)
	{
		size2-=hist[i][1];
		if(size2<0)
			return hist[i][1];
	}
	
}
BYTE median1(BYTE *data,int h,int rowsize)
{
	int j,i,index;
	for(i=0;i<h*rowsize;i++)
	{
		index=i;
		for(j=i+1;j<h*rowsize;j++)
		     if(data[j]<data[index]) index=j;
				if(i!=index) swap(&data[i],&data[index]);
					if(i%10000==0) printf("i:%d\n",i);
	}
	
	return data[h*rowsize/2];
}
void thresholdImage(IMAGE *image)
{
	int h,w,rowsize,i;
	BYTE t;
	h=image->bmpih.bih;
	w=image->bmpih.biw;
	rowsize=(image->bmpih.bibitcount*w+31)/32*4;
	//t=mean(image->data,h,rowsize);
	//t=meanofmaxmin(image->data,h,rowsize);
	t=(BYTE)median2(image->data,h,rowsize);
	printf("Threshold value:%d\n",t);
	thresholdImage(image,t);
}
void lowpassfilter(IMAGE *image, double filter[3][3]){
	int size,i,j,k,l,rowsize,h,w,sum;
	BYTE mask[3][3];
	h = image->bmpih.bih;
	w = image->bmpih.biw;
	rowsize = (image->bmpih.bibitcount*w+31)/32*4;
	size = rowsize*h;
	BYTE *data;
	data = (BYTE*)calloc(size,sizeof(BYTE));
	memcpy(data,image->data,size);
	if(data==NULL){printf("Memory problem"); exit(1);}
	for(i=1;i<h-1;i++){
		for(j=1;j<rowsize-1;j++){
			for(k=-1;k<2;k++)
				for(l=-1;l<2;l++)
					mask[k+1][l+1] = data[(i+k)*rowsize+j+l];
			sum=0;
			for(k=0;k<3;k++)
				for(l=0;l<3;l++)
					sum += mask[k][l] * filter[k][l];
			if(sum>255) sum = 255;
			else if(sum<0) sum = 0;
			image->data[i*rowsize+j]=(BYTE) sum;
		}
	}

	free(data);
}

int main()
{
	auto start = std::chrono::high_resolution_clock::now(); // Başlangıç zamanı
	IMAGE *image=(IMAGE*)malloc(sizeof(IMAGE));
	double filter[3][3]={0,-1,0,-1,5,-1,0,-1,0};//sharpened
	image=ImageRead(image,"biber.bmp");
	writeInfo(image,"biber.bmp");
	//thresholdImage(image);
	lowpassfilter(image,filter);
	ImageWrite(image,"test.bmp");
	
	free(image);

	auto end = std::chrono::high_resolution_clock::now(); // Bitiş zamanı
    std::chrono::duration<double> elapsed = end - start; // Geçen süreyi hesapla
	cout << "Gecen sure: " << elapsed.count() << endl;
	return 0;
}
