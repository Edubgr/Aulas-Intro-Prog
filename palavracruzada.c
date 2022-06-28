#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* value;
    bool is_vertical;
    bool unused,exist;
    int size;
    int i,j,turn,id;
} word;

int compare (const void * a, const void * b)
{
  word *id = (word *)a;
  word *id2 = (word *)b;
  return ( id->id - id2->id );
}

bool fits_int_table(char** table, int LIN, int COL, word* curr_word, word word_list[], int curr_word_number) {
    //printf("%s %d %d %d\n", curr_word->value, curr_word->size, curr_word_number, curr_word->turn);
    int word_size = curr_word->size;

    if (!curr_word->unused){
        //printf("flag\n");
        for (int i = 0; i < word_size; i++) {
            if (curr_word->is_vertical) {
                table[curr_word->i+i][curr_word->j] = '#';
            } else {
                table[curr_word->i][curr_word->j+i] = '#';
            } 
        }/*
        for (int i = 0; i < LIN; i++) {
            for (int j = 0; j < COL; j++) {
                printf("%c ", table[i][j]);
            }
            printf("\n");
        }*/
    }
    if (curr_word_number != 0 && !curr_word->unused){
        curr_word->unused = true;
        for (int j = 0; j < curr_word_number; j++){
            //printf("aaaaaaaaaaaaa %s \n",word_list[j].value);
            for (int i = 0; i < word_list[j].size; i++) {
                if (word_list[j].is_vertical) {
                    table[word_list[j].i+i][word_list[j].j] = word_list[j].value[i];
                } else {
                    table[word_list[j].i][word_list[j].j+i] = word_list[j].value[i];
                }
            }/*
            for (int i = 0; i < LIN; i++) {
                for (int j = 0; j < COL; j++) {
                    printf("%c ", table[i][j]);
                }
                printf("\n");
            }*/
        }
        
    }
    
    int i, j, turn2,tam_i,tam_j;
    turn2=0;
    i = j = 1;
    if (curr_word->is_vertical) {
        tam_i=LIN-curr_word->size;
        tam_j=COL-1;
    } else {
        tam_i=LIN-1;
        tam_j=COL-curr_word->size;
    }
    //printf("tam_i=%d tam_j=%d \n",tam_i,tam_j);
    for (int i = 0; i <= tam_i; i++) {
        for (int j = 0; j <= tam_j; j++) {
            //printf("i=%d j=%d \n",i,j);
            int k = 0;
            int temp_i, temp_j;
            bool crossing = false;
            temp_i = i;
            temp_j = j;
            for (; k < word_size; k++) {
                //printf("letter = %c i = %d j = %d t = %c\n",curr_word->value[k],temp_i,temp_j,table[temp_i][temp_j]);
                if (table[temp_i][temp_j] == curr_word->value[k]) {
                    crossing = true;
                }
                if (table[temp_i][temp_j] == '#' || table[temp_i][temp_j] == curr_word->value[k]) {
                    //printf("%c %c",table[temp_i][temp_j], curr_word->value[k]);
                    if (curr_word->is_vertical) {
                        temp_i += 1;
                        if (temp_i-i >= word_size) {
                            break;
                        }
                    } else {
                        temp_j += 1;
                        if (temp_j-j >= word_size){
                            break;
                        }
                    }
                } else {
                    k--;
                    break;    
                }
            }
            if (k == word_size-1 && (curr_word_number == 0 || crossing)) {
                //printf("tur2 = %d turn = %d\n",turn2,curr_word->turn);
                if (turn2 >= curr_word->turn) {
                    curr_word->unused = false;
                    curr_word->i=i;
                    curr_word->j=j;
                    for (int w = 0; w < word_size; w++) {
                        if (curr_word->is_vertical) {
                            table[i][j] = curr_word->value[w];
                            i++;
                        } else {
                            table[i][j] = curr_word->value[w];
                            j++;
                        }
                    }
                    //printf("%d %d %d %d YES\n",curr_word_number,crossing,word_size-1,k);
                    for (int i = 0; i < LIN; i++) {
                        for (int j = 0; j < COL; j++) {
                            printf("%c ", table[i][j]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                    curr_word->exist = true;
                    return true;
                }else {
                    turn2++;
                }
            }
        }
    }
    return false;
}

/*int build_table(char** table, int table_size, word word_list[]) {
    for (int i = 0; i < 8; i++) {
        if (word_list[i].unused) {
            fits_int_table(table, table_size, &word_list[i]);
        }
    }
}*/
int build_table(char** table, int LIN, int COL, word word_list[], int curr_word_number, int number_of_words) {

    if(curr_word_number == number_of_words) {
        return 1;
    }

    if (!fits_int_table(table, LIN, COL, &word_list[curr_word_number], word_list, curr_word_number)){
        word_list[curr_word_number-1].turn+=1;
        int tam_i,tam_j;
        if (word_list[curr_word_number-1].is_vertical) {
            tam_i=LIN-word_list[curr_word_number-1].size+1;
            tam_j=COL; 
        } else {
            tam_i=LIN;
            tam_j=COL-word_list[curr_word_number-1].size+1;
        }
        for (int i = 0; i < number_of_words; i++){
            printf("a1 %d %s %d %d\n", word_list[i].id, word_list[i].value, word_list[i].exist, word_list[i].turn);
        }
        //printf ("asdsd %d fim %d\n",word_list[curr_word_number].turn,tam_i*tam_j);
        if(word_list[curr_word_number-1].turn >= tam_i*tam_j) {
            //return 0;
        if (curr_word_number==number_of_words-1) number_of_words=curr_word_number;
            for (int i = curr_word_number + 1; i < number_of_words; i++){
                printf("aasdasd %d %s %d %d\n", word_list[i].id, word_list[i].value, word_list[i].exist, word_list[i].turn);
                if (word_list[i].exist) break;
                else if (i == number_of_words-1){
                    number_of_words=curr_word_number+1;
                    //return 1;
                    //word_list[curr_word_number-1].turn=0;
                    //return build_table(table, LIN, COL, word_list, 0, number_of_words);
                }
            }
            
            for (int i = 0; i < number_of_words; i++){
                printf("a2 %d %s %d\n", word_list[i].id, word_list[i].value, word_list[i].exist);
            }
            printf("a4 %d %s\n", word_list[curr_word_number].id, word_list[curr_word_number].value);
            
            if (curr_word_number == number_of_words) return 1;
            word_list[curr_word_number].id=number_of_words;
            for (int i = curr_word_number; i < number_of_words; i++){
                word_list[i].id--;
            }
            for (int i = 0; i < number_of_words; i++){
                printf("a2 %d %s %d\n", word_list[i].id, word_list[i].value, word_list[i].exist);
            }

            qsort (word_list, number_of_words, sizeof(word), compare);

            for (int i = 0; i < number_of_words; i++){
                printf("a3 %d %s %d\n", word_list[i].id, word_list[i].value, word_list[i].exist);
            }
            

            qsort (word_list, number_of_words, sizeof(word), compare);

            //word_list[curr_word_number+1].exist=false;
            
            for (int i = 0; i < number_of_words; i++){
                printf("asda id %d   v%s\n", word_list[i].id, word_list[i].value);
            }
            for (int i = 0; i < number_of_words; i++){
                printf("a3 %d %d\n", word_list[i].id, word_list[i].exist);
            }
            
            //printf("%s  %s %d\n", word_list[curr_word_number].value,word_list[curr_word_number-1].value,word_list[curr_word_number-1].turn);
            //word_list[curr_word_number-1].turn=0;
            //printf("%s  %s %d\n", word_list[curr_word_number].value,word_list[curr_word_number-1].value,word_list[curr_word_number-1].turn);
            for (int i = 0; i < number_of_words; i++){
                word_list[i].i = -1;
                word_list[i].j = -1;
                word_list[i].turn = 0;
                word_list[i].unused = true;
            }
            for (int i = 0; i < LIN; i++) {
                for (int j = 0; j < COL; j++) {
                    table[i][j]='#';
                }
            }
            for (int i = 0; i < number_of_words; i++){
                printf("asd %s %d %d",word_list[i].value,word_list[i].id,word_list[i].exist);
            }
            return build_table(table, LIN, COL, word_list, 0, number_of_words);
        }
        //printf("turn %d \n", word_list[curr_word_number-1].turn);
        return build_table(table, LIN, COL, word_list, curr_word_number - 1, number_of_words);
    }
    word_list[curr_word_number+1].turn=0;
    return build_table(table, LIN, COL, word_list, curr_word_number + 1, number_of_words);
}

int main() {
    int tam = 15;
    word word_list[] = {
        {"eight", true, true},
        {"trip", false, true},
        {"four", true, true},
        {"blue", false, true},
        {"fresh", false, true},
        {"ruler", true, true},
        {"uncle", false, true},
        {"press", true, true},
        {"reach", false, true},
        {"wheel", true, true},
        {"sweep", false, true},
        {"edge", false, true},
        {"page", true, true},
        {"late", false, true},
        {"ship", true, true}//,
        //{"roar", false, true}
        };
    word word_list2[tam];
    for (int i = 0; i < tam; i++) {
        word_list2[i]=word_list[i];
    }
        /*
{"1trip", false, true},
{"2blue", false, true},
{"3fresh", false, true},
{"4uncle", false, true},
{"5reach", false, true},
{"6sweep", false, true},
{"7edge", false, true},
{"8late", false, true},
{"9four", true, true},
{"10ruler", true, true},
{"11each", true, true},
{"12press", true, true},
{"13wheel", true, true},
{"14page", true, true},
{"15eight", true, true},
{"16ship", true, true}*/
    int sum = 0;
    int COL = 0;
    int LIN = 0;

    for (int i = 0; i < tam; i++){
        word_list[i].size = strlen(word_list[i].value);
        if (word_list[i].is_vertical){
            LIN += word_list[i].size;
        } else {
            COL += word_list[i].size;
        }
        sum += word_list[i].size;
        word_list[i].exist=true;
        printf("%d\n", sum);
        word_list[i].i = -1;
        word_list[i].j = -1;
        word_list[i].turn = 0;
        word_list[i].id = i;

    }/*
    for (int i = 0; i < tam; i++){
        printf("%d\n", word_list[i].size);
    }

    qsort (word_list, tam, sizeof(word), compare);

    for (int i = 0; i < tam; i++){
        printf("%d\n", word_list[i].size);
    }*/
    LIN=8;
    COL=8;

    char** table = malloc(sizeof(char*) * LIN);
    for (int i = 0; i < LIN; i++)
        table[i] = (void *) calloc(sizeof(char), COL);

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            table[i][j]='#';
        }
    }
    printf("%d %d",LIN, COL);
    //return 0;
    build_table(table, LIN, COL, word_list, 0, tam);
    //fits_int_table(table, sum, &word_list[0]);
    printf("\n");
    COL = -1;
    LIN = -1;printf("\n");
    for (int i = 0; i < tam; i++){
        if (word_list[i].is_vertical){
            int a=word_list[i].size + word_list[i].i;
            if(a > LIN) LIN = a;
        } else {
            int a = word_list[i].size + word_list[i].j;
            if(a > COL) COL = a;
        }
    }

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            if(table[i][j] != '#') printf("%c ", table[i][j]);
            else printf("  ");
        }
        printf("\n");
    }

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            table[i][j] = '#';
        }
    }

    for (int i = 0; i < tam; i++) {
        printf("Local = %c Palavra = ", word_list2[i].value[0]);
        for (int j = 1; j < strlen(word_list2[i].value)-1; j++) {
            printf("%c",word_list2[i].value[j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < tam; i++) {
        table[word_list[i].i][word_list[i].j]=word_list[i].value[0];
        for (int j = 1; j < word_list[i].size-1; j++) {
            if(word_list[i].is_vertical) {
                if (table[word_list[i].i + j][word_list[i].j] == '#')
                    table[word_list[i].i + j][word_list[i].j] = 'x';//i + '0';
                //else table[word_list[i].i + j][word_list[i].j] = 'y';
            } else {
                if (table[word_list[i].i][word_list[i].j + j] == '#')
                    table[word_list[i].i][word_list[i].j + j] = 'x';//i + '0';
                //else table[word_list[i].i][word_list[i].j + j] = 'y';
            }
            
        }
    }
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            if(table[i][j] != '#') printf("%c ", table[i][j]);
            else printf("  ");
        }
        printf("\n");
    }

    return 0;
}