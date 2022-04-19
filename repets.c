// Atividade 3
// Eduardo Barros Guimarães
// Nº USP 13679040

#include<stdio.h>
int main(int argc, char* argv[]){
    char ch;
    do {
        // Ler caractere digitado
        printf("Digite um caracter (digite s para sair): ");
        ch=getchar();
        // Ler o enter mas não declarar em nenhuma varíavel para esvaziar o buffer
        getchar();
        // Imprimir o caractere digitado
        printf("O caracter digitado eh \"%c\".\n", ch);
        // Se o caractere for diferente de s, repita o processo
    } while (ch!='s');
    // Imprima que o programa saiu do loop
    printf("Saindo do loop\n");
    return 0;
}


