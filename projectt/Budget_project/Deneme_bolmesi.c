#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Bu, strtok fonksiyonunun kullanimini gosteren bir ornektir.";
    char* token = strtok(str, " ");

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    return 0;
}