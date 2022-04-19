// Atividade 3
// Eduardo Barros Guimarães
// Nº USP 13679040

#include<stdio.h>

int main(int argc, char* argv[]){
    float n,maior,menor;
    maior=0;
    menor=11;
    do {
        printf("Digite a nota: ");
        scanf("%f",&n);
        if(n>maior)maior=n;
        if(n<menor && n>0)menor=n;
    } while (n>0);
    printf("A nota maior eh %.2f.\n", maior);
    printf("A nota menor eh %.2f.\n", menor);

    return 0;
}


