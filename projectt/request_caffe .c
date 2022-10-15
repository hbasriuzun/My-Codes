#include <stdio.h>

void icerikler(int* icerik);
void oner(int* icerik);

int main(int argc, char const *argv[])
{
    int icerik[6];
    icerikler(icerik);
    oner(icerik);
    printf("Bitti");
    return 0;
}

void icerikler(int* icerik){
    int onay,i=0;
    printf("Icerikleri Giriniz evet ise 1 hayir ise 0 yazin\n"); // icerik[0] = su  icerik[1] = sut   icerik[2] = sut kopugu icerik[3] = karamel 
    printf("Su olsun mu?\n");  scanf("%d",&onay);   icerik[i] = onay;  i++; // icerik[4] = cikolata icerik[5] = beyaz cikolata  icerik[6] = krema 
    printf("sut olsun mu?\n");  scanf("%d",&onay);   icerik[i] = onay;  i++;
    printf("Sut kopugu olsun mu?\n");  scanf("%d",&onay);   icerik[i] = onay;  i++;
    printf("karamel olsun mu?\n");  scanf("%d",&onay);   icerik[i] = onay;  i++;
    printf("Cikolata olsun mu?\n");  scanf("%d",&onay);   icerik[i] = onay;  i++;
    printf("Beyaz cikolata olsun mu?\n");  scanf("%d",&onay);   icerik[i] = onay;  i++;
    printf("Krema olsun mu?\n");  scanf("%d",&onay);   icerik[i] = onay;  i++;
}

void oner(int*icerik){
    if(icerik[0] == 1){
        printf("Americano\n"); return;}
    if(icerik[4] == 1){
        printf("Mocha\n"); return;}
    if(icerik[5] == 1){
        printf("white Mocha\n"); return;}
    if(icerik[6] == 1){
        printf("Con panna \n"); return;}
    if(icerik[3] == 1){
        printf("Caramel Macchiato \n"); return;}
    if(icerik[1] == 1){
        if (icerik[2] == 1){
            printf("Latte\n");
            printf("Cappuccino\n");
        }else
            printf("Flat White");
        return;
    }if (icerik[2] == 1){
            printf("Frappe");
            printf("Macchiato");
        
    }else
        printf("Expresso");
    
    
    

}