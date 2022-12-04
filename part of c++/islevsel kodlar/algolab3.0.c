#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct an{
	
	char *name;
	
};

typedef struct inf{
	
	char *num;

	char *nut;
	
	char *ar;
	
	char *com;
	
	struct an det;
	

}inf;

struct inf *a(struct inf *b,int *d,int *v){

if(d[*v]==1){
	strcpy(b->det.name,"Lion");
	strcpy(b->ar,"South Africa Region");
	strcpy(b->com,"Gregariousness");
//	strcpy(b->num,"20.000,39.000");
	strcpy(b->nut,"Meat");
	return b;

}
else if(d[*v]==2){
	
	strcpy(b->det.name,"Elephant");
//	strcpy(b->num,"About 400.000");
	strcpy(b->nut,"wide variety of plants-savannah grasses ");
	strcpy(b->ar,"South and Southeast Asia");
	strcpy(b->com,"Gregariousness");
	return b;
}
else if(d[*v]==3){
	
	strcpy(b->det.name,"Rhino");
	strcpy(b->ar,"Africa-Asia");
	strcpy(b->com,"Gregariousness");
//	strcpy(b->num,"About 2000");
	strcpy(b->nut,"Grass-Shrubs-Trees-Bark");
	return b;
}
else if(d[*v]==4){
	
	strcpy(b->det.name,"Tiger");
	strcpy(b->ar,"North Siberia");
	strcpy(b->com,"Mostly Not Gregariousnessly ");
//    strcpy(b->num,"3.900");
	strcpy(b->nut,"Meat");
	return b;
}	
	
	
	return 0;
}

void goster(struct inf *p){
	
	printf(p->det.name);
	printf(p->ar);
	printf(p->com);
//	printf(p->num);
	printf(p->nut);
	
}	
	
int main() {
inf *c;
c = (inf*)calloc(100,sizeof(inf));
c->ar = (char*)calloc(100,sizeof(char));
c->com = (char*)calloc(100,sizeof(char));
c->nut = (char*)calloc(100,sizeof(char));
c->num = (char*)calloc(100,sizeof(char));
c->det.name = (char*)calloc(100,sizeof(char));

int i;
int h=4;
int arr[4]={1,2,3,4};	
int n;

printf("0=Lion,1=Elephant,2=Rhino,3=Tiger\n");
printf("Pick integer animal to get an information about that animal: ");
scanf("%d",&n);
a(c,arr,&n);
printf("a");
/*
switch (arr[n]){
	
	case '1':
		
    goster(&c);
		
		
		
		
		
	case '2':
     
     goster(&c);
	
	
	
	
	
	
	
    case '3':
	
	goster(&c);
	
	
	
	
	
	
	
	case '4':	
	goster(&c);
	
	
	
	
	
	default:
		
	printf("Not Including");
	
	
}
*/
	return 1;
}
