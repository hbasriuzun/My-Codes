#include <stdio.h>

void F(FILE *fpin, FILE *fpout){
    char str[128];
    if(feof(fpin)){
        return;
    }
    fscanf(fpin, "%s", str);
    if(*str>='a' && *str<='z'){
        *str = *str - 32;
    }
    fprintf(fpout, "%s\n", str);
    F(fpin, fpout);
}

int main(){
    char slm[] = {1,2,3};
    char* slm2 = slm;

    printf("%d", sizeof(slm));
    printf("%d", sizeof(slm2));
    return 0;
}