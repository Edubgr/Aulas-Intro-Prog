// Atividade 2
// Aluno: Eduardo Barros Guimar�es N�USP: 13679040

#include<stdio.h>

int main(int argc, char* argv[]){
    // Declarar vari�veis
    int a,b,c,n1,n2;
    // Ler o n�mero
    printf("Digite o numero: ");
    scanf("%d",&n1);
    // Definir A B e C
    a=n1/100;
    b=(n1%100)/10;
    c=n1%10;
    // Somar os algarismos
    n2=c*100+b*10+a;
    // Imprimir o valor ao contr�rio
    printf("%d ao contrario eh: %d\n",n1,n2);
    return 0;
}
