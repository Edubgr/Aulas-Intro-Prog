// Projeto 1
// Eduardo Barros Guimarães
// Nº USP 13679040

#include<stdio.h>
#include<stdbool.h>

void imprimir(int M[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%c ",M[i][j]);
        }
        printf("\n");
    }
}
bool conferir(int M[][3]){
    int t;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(j==0)t=M[i][j];
            if(M[i][j]!=t || M[i][j]=='.') break;
            if(j==2)return true;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(j==0)t=M[j][i];
            if(M[j][i]!=t || M[j][i]=='.') break;
            if(j==2)return true;
        }
    }
    if(M[0][0]==M[1][1] && M[0][0]==M[2][2] && M[0][0]!='.') return true;
    if(M[0][2]==M[1][1] && M[0][2]==M[2][0] && M[0][2]!='.') return true;

    return false;
}
int main(int argc, char* argv[]){
    int M[3][3],inicio;
    bool winner=false;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            M[i][j]='.';
        }
    }
    printf("Quem comecara, X ou O? ");
    scanf("%c",&inicio);
    if(inicio=='X') inicio=0;
    else if(inicio=='O') inicio=1;
    else {
        printf("Nao ah esse jogador, comece novamente.\n");
        return 0;
    }
    printf("O jogo comecou!\n");
    imprimir(M);
    while(winner==false){
        int i,j;
        if(inicio==0){
            printf("Jogador X: Qual as coordenadas? ");
            scanf("%d %d",&i,&j);
            if(M[i-1][j-1]!='.'){
                printf("Posicao ja escolhida, escolha outra.\n");
                continue;
            }
            M[i-1][j-1]='X';
            imprimir(M);
            winner=conferir(M);
            if(winner) printf("Jogador X venceu! Parabens!");
            inicio=1;
        } else{
            printf("Jogador O: Qual as coordenadas? ");
            scanf("%d %d",&i,&j);
            if(M[i-1][j-1]!='.'){
                printf("Posicao ja escolhida, escolha outra.\n");
                continue;
            }
            M[i-1][j-1]='O';
            imprimir(M);
            winner=conferir(M);
            if(winner) printf("Jogador O venceu! Parabens!");
            inicio=0;
        }

    }



    return 0;
}

