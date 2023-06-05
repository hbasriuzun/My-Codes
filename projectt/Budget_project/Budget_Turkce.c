// Budged.c Kodunun Türkçe Çevirisi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define film_sayisi 3499
typedef struct Bütçe
{
      int butce;
      int yıl;
      char *başlık;
      char *başlık_türü;
      char *top250;
}Bütçe;

typedef struct İsim
{
    char **tür;
    char *başlık;
    char **yönetmenler;
    char *görülmeli;
    double puan;
    double skor;
    double çalışma_süresi;
    double oylar;
    char *url;
}İsim;

typedef struct turler
{
    char *tür;
    int sayı;
}turler;

void save(Budget *budget, Name *name, FILE *fp);
void open_memory(Budget *budget, Name *name, FILE *fp);
void print_budget(Budget *budget);
void print_name(Name *name);
void sort_year(Budget *budget, Name *name);
void sort_rating(Budget *budget,Name *name);
void All_information_single_movie(Budget *budget, Name *name);
void Frequecy_of_the_Genres(Name *name);
void List_of_genres(Name *name);
void Swap_Budged(Budget *budget1, Budget *budget2);
void Swap_Name(Name *name1, Name *name2);
void Print_title_and_year(Budget *budget, Name *name);
void Print_title_and_rating(Budget *budget, Name *name);

int main(){

}