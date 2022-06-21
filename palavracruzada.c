// Projeto 2
// Eduardo Barros Guimarães
// Nº USP 13679040

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAM 10

typedef struct{
    char question[300];
    char word[100];
    int size;
    bool stat;
    int i,j;
    bool orientation;
    // 0 para horizontal e 1 para vertical
}Word;

int main(int argc, char* argv[]){
    int n=3;
    Word words[n];
    char input[100];
    int cont=0;
    while(true){
        printf("Digite a pergunta %d: ",cont+1);
        gets(input);
        if(!strcmp(input,"fim"))break;
        words[cont].stat=true;
        //words[cont].i=0;
        //words[cont].j=0;
        strcpy(words[cont].question, input);
        printf("Digite a palavra %d: ",cont+1);
        gets(input);
        strcpy(words[cont].word, input);
        words[cont].size=strlen(input);
        printf("Digite a orientacao da palavra %d: ",cont+1);
        bool pos;
        while(true){
            gets(input);
            if(!strcmp(input,"horizontal")){
            pos=false;
            break;
            }
            else if(!strcmp(input,"vertical")){
                pos=true;
                break;
            }
            else printf("Orientacao errada, digite novamente: ");
        }

        words[cont].orientation=pos;
        printf("Digite a posicao da palavra %d: ",cont+1);
        scanf("%d %d",&words[cont].i,&words[cont].j);
        static char temp[256];
        fgets(temp, sizeof(temp), stdin);
        cont++;
    }
    for(int i=0;i<1;i++){
        printf("A pergunta eh: %s\nA resposta eh: %s\nO tamanho eh: %d\nA orientacao eh: %d\n",words[i].question,words[i].word,words[i].size,words[i].orientation);
    }
/*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j!=i && words[j].stat){
                for(int k=0;k<words[i].size;k++){
                    for(int l=0;l<words[j].size;l++){
                        if(words[i].word[k]==words[j].word[l]){
                            if(!words[i].orientation){
                              words[i].i+=l;
                              words[j].i+=l;
                              words[j].j+=k;
                              words[j].stat=false;
                              printf("pos 1 x %d y %d. pos 2 x %d y %d\n",words[i].i,words[i].j,words[j].i,words[j].j);
                              break;
                            }
                        }
                    }
                    if(!words[j].stat)break;
                }
            }
        }
    }*/
    int COL=INT_MIN,LIN=INT_MIN;
    for(int i=0;i<n;i++){
        if(words[i].orientation){
            int a=words[i].size+words[i].i;
            if(a>LIN)LIN=a;
        } else {
            int a=words[i].size+words[i].j;
            if(a>COL)COL=a;
        }
    }
    char m[LIN][COL];
    for(int i=0;i<LIN;i++){
        for(int j=0;j<COL;j++){
            m[i][j]='.';
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<words[i].size;j++){
            if(words[i].orientation)
                m[j+words[i].i][words[i].j]=words[i].word[j];
            else m[words[i].i][j+words[i].j]=words[i].word[j];
        }
    }
    for(int i=0;i<LIN;i++){
        for(int j=0;j<COL;j++){
            printf("%c ",m[i][j]);
        }
        printf("\n");
    }

    return 0;
}
/*
Voce senta
cadeira
horizontal
2 0
Quando chora
lagrima
vertical
1 1
Onde cai
chao
vertical
0 6
fim

*/
