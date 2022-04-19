// Atividade 2
// Eduardo Barros Guimarães
// Nº USP 13679040

#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[]){
    int a,b,c;
    // Ler lados do triângulo
    printf("Lado A: ");
    scanf("%i",&a);
    printf("Lado B: ");
    scanf("%i",&b);
    printf("Lado C: ");
    scanf("%i",&c);
    // Imprimir os lados do triângulo
    printf("O triangulo tem lado %i, %i e %i.\n",a,b,c);
    // Se a soma dos dois lados opostos forem menores que o lado, será um triângulo
    if (a+b>c && a+c>b && b+c>a){
        printf("Eh um triangulo.\n");
    }else{ // Se não, não será um triângulo e se encerra o programa
        printf("Nao eh um triangulo.\n",a,b);
        return 0;
    }
    // Se os lados forem iguais, imprime equilatero
    if (a==b && b==c)
        printf("Eh equilatero.\n");
    else {
        // Se não, se for 2 lados iguais e um diferente, imprima isoceles
        if (a==b && b==c && a==c)
            printf("Eh isoceles.\n");
        else
            // Se não, todos lados serão diferentes, então imprima escaleno
            printf("Eh escaleno.\n");
    }
    //double p=(a+b+c)/2;
    //double area=sqrt(p*(p-a)*(p-b)*(p-c));
    //printf("A area eh: %.2f.",area);
    return 0;
}

