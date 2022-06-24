#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* value;
    bool is_vertical;
    bool unused;
    int size;
} word;
/*

| | |x| |
| | | | |
| | | | |

*/
bool fits_int_table(char** table, int table_size, word* curr_word) {
    int i, j;
    i = j = 1;
    int word_size = curr_word->size;
    for (int i = 0; i < word_size; i++) {
        for (int j = 0; j < word_size; j++) {
            int k = 0;
            int temp_i, temp_j;

            temp_i = i;
            temp_j = j;

            for (; k < word_size; k++) {
                printf("i=%d j=%d t=%c\n",temp_i,temp_j,table[temp_i][temp_j]);
                if(table[temp_i][temp_j] == '#') printf("%c\n",curr_word->value[k]);
                if (table[temp_i][temp_j] == '#' || table[temp_i][temp_j] == curr_word->value[k]) {
                    printf("yeah\n");
                    if (curr_word->is_vertical) {
                        temp_i += 1;
                        printf("yeah2\n");
                        if (temp_i >= word_size) break;
                    } else {
                        temp_j += 1;
                        if (temp_j >= word_size) break;
                    }
                } else {
                    break;
                }
            }
            printf("%d %d",k,word_size);
            if (k == word_size-1) {
                curr_word->unused = false;
                printf("foi\n");
                for (int w = 0; w < word_size; w++) {
                    if (curr_word->is_vertical) {
                        table[i][j] = curr_word->value[w];
                        i++;
                    } else {
                        table[i][j] = curr_word->value[w];
                        j++;
                    }
                }

                return true;
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
int build_table(char** table, int table_size, word word_list[], int curr_word_number, int number_of_words) {
    if(curr_word_number == number_of_words) {
        return 1;
    }
    fits_int_table(table, table_size, &word_list[curr_word_number]);
    return build_table(table, table_size, word_list, curr_word_number + 1, number_of_words);
}

int main() {
    int tam = 3;
    word word_list[] = {
        {"teste", false, true},
        {"linux", true, true},
        {"editor",  false, true}/*,
        {"brasil", true, true},
        {"testando", true, true},
        {"hoje", true, true},
        {"vomito", false, true},
        {"lixo", false, true}*/
        };

    int sum = 0;
    for (int i = 0; i < tam; i++){
        word_list[i].size = strlen(word_list[i].value);
        sum += word_list[i].size;
    }

    char** table = malloc(sizeof(char*) * sum);
    for (int i = 0; i < sum; i++)
        table[i] = (void *) calloc(sizeof(char), sum);

    for (int i = 0; i < sum; i++) {
        for (int j = 0; j < sum; j++) {
            table[i][j]='#';
        }
    }
    build_table(table, sum, word_list,0,tam);
    //fits_int_table(table, sum, &word_list[0]);
    printf("\n");
    for (int i = 0; i < sum; i++) {
        for (int j = 0; j < sum; j++) {
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }

    return 0;
}
