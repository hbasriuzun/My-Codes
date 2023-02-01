#include <stdio.h>
#include <iostream>
#include <stdlib.h>

int computerturn(int *b,int *computerpoint){
    int temp = 0;
    while(1){
    int point = rand() % 5 + 1;
    if(point == 1){
        *b = 0;
        break;
    }
    else{
        temp = temp + point;
        if(temp >= 20){
            *b = 0;
            *computerpoint = *computerpoint + temp;
            break;
                }
        else{
            continue;
        }
    }
}
    return 0;
}

int playerturn(int *b,int *playerpoint){
    char c;
    int temp = 0;
    while(1){
    int point = rand() % 5 + 1;
    printf("Cikan sayi: %d \n",point);
    if(point == 1){
        *b = 1;
        return 0;
    }
    else{
        temp = temp + point;
        printf("Kalmak istiyorsaniz h tekrardan atmak istiyorsaniz r'ye basiniz: ");
        scanf(" %c",&c);
        if(c == 'h'){
            *b = 1;
            *playerpoint = *playerpoint + temp;
            return 0;
        }
        else if(c == 'r'){
            *b = 0;
            continue;
        }
        else{
            printf("Yanlis bastiniz.\n");
          //  std::cout << "Yanlis bastiniz.\n";
        }
        }
    }
}

int main()
{
    int playerpoint = 0,computerpoint = 0;
    int b = 0;
    while(1){
        if(playerpoint >= 100)
        {
            printf("Oyuncu kazandiii!!");
            break;
        }
        else if(computerpoint >= 100)
        {
            printf("Bilgisayar kazandii!!");
            break;
        }
        if(b == 0){
            printf("Oyuncunun puani: %d\n",playerpoint);
            std::cout << "Oyuncunun puani: " << playerpoint << std::endl;
            printf("Bilgisayarin puani: %d\n",computerpoint);
            playerturn(&b,&playerpoint);
        }
        else{
            printf("Sira bilgisayara gecti.\n");
            computerturn(&b,&computerpoint);
        }
    }
    return 0;
}
