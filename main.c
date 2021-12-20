#include <stdio.h>

#define TXT 1024
#define WORD 30
#define TRUE 1
#define FALSE 0

const int abc[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 
                     's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

void insertWord(char word[WORD]){
    int count = 0;
    char input;
    scanf("%c", &input);
    while(input != ' ' && input != '\n' && input != '\t'){
        word[count] = input;
        count++;
        scanf("%c", &input);
    }
    word[count] = '\0';
}

void insertText(char text[TXT]){
    int count = 0;
    char input;
    scanf("%c", &input);
    while(count < TXT && input != '~'){
        text[count] = input;
        count++;
        scanf("%c", &input);
    }
    text[count] = '\0';
}

int gematria(char c){
    for(int i = 0 ; i < 26; i++){
        if(c == abc[i] || c == abc[i] - 32){ // For example: a = 97 - 32 -> A = 65 
            return i + 1;
        }
    }
    return 0;
}

int gematriaOfWord(char word[WORD]){
    int sum = 0;
    int i = 0;
    while(word[i] != '\0'){
        sum += gematria(word[i]);
        i++;
    }
    return sum;
}

void gematriaSequences(char word[WORD], char text[TXT]){
    printf("Gematria Sequences: ");
    int need = gematriaOfWord(word);
    int firstPrint = TRUE;
    for(int i = 0; text[i] != '\0'; i++){
        if(gematria(text[i]) > 0){
            int sum = 0;
            int keep = TRUE;
            for(int j = i; keep; j++){
                sum += gematria(text[j]);
                if(sum == need){
                    if(!firstPrint){
                        printf("~");
                    }
                    else{
                        firstPrint = FALSE;
                    }
                    for(int g = i; g <= j; g++){
                        printf("%c", text[g]);
                    }
                }
                if(sum >= need || text[j + 1] == '\0'){
                    keep = FALSE;
                }
            }
        }
    }
    printf("\n");
}

void reverse(char from[WORD], char to[WORD]){
    int count = 0;
    for(int i = 0; from[i] != '\0'; i++){
        count++;
    }
    for(int j = 0; j < count; j++){
        to[j] = from[count - j - 1];
    }
    to[count] = '\0';
}

void atbash(char from[WORD], char to[WORD]){
    int i = 0;
    for(int j = 0; from[j] != '\0'; j++){
        int place = gematria(from[j]) - 1;
        if(abc[place] != from[j]){
            to[j] = abc[26 - 1 - place] - 32;
        }else{
            to[j] = abc[26 - 1 - place];
        }
        i++;
    }
    to[i] = '\0';
}

void AtbashSequences(char word[WORD], char text[TXT]){
    printf("Atbash Sequences: ");
    char atbashWord[WORD];
    atbash(word, atbashWord);
    char reversedAtbash[WORD];
    reverse(atbashWord, reversedAtbash);
    int firstPrint = TRUE;
    for(int i = 0; text[i] != '\0'; i++){
        if(text[i] != ' '){
            int keep1 = TRUE;
            int keep2 = TRUE;
            int skip = 0;
            for(int j = 0; keep1 || keep2; j++){
                if(text[i + j] != ' '){
                    if(keep1){
                        if(atbashWord[j - skip] == '\0'){
                            if(!firstPrint){
                                printf("~");
                            }
                            else{
                                firstPrint = FALSE;
                            }
                            for(int g = i; g <= i + j - 1; g++){
                                printf("%c", text[g]);
                            }
                            keep1 = FALSE;
                        }
                        else if(text[i + j] != atbashWord[j - skip]){
                            keep1 = FALSE;
                        }
                    }
                    if(keep2){
                        if(reversedAtbash[j - skip] == '\0'){
                            if(!firstPrint){
                                printf("~");
                            }
                            else{
                                firstPrint = FALSE;
                            }
                            for(int g = i; g <= i + j - 1; g++){
                                printf("%c", text[g]);
                            }
                            keep2 = FALSE;
                        }
                        else if(text[i + j] != reversedAtbash[j - skip]){
                            keep2 = FALSE;
                        }
                    }
                }
                else{
                    skip++;
                }
            }
        }
    }
    printf("\n");

}

void copyWord(char from[WORD], char to[WORD]){
    int j = 0;
    for(int i = 0; from[i] != '\0'; i++){
        to[i] = from[i];
        j++;
    }
    to[j] = '\0';
}

int isContains(char arr[WORD], char c){
    for(int i = 0; arr[i] != '\0'; i++){
        if(arr[i] == c)return i;
    }
    return -1;
}

int isEmpty(char arr[WORD]){
    for(int i = 0; arr[i] != '\0'; i++){
        if(arr[i] != -1)return FALSE;
    }
    return TRUE;
}

void AnagramSequences(char word[WORD], char text[TXT]){
    printf("Anagram Sequences: ");
    char copy[WORD];
    int firstPrint = TRUE;
    for(int i = 0; text[i] != '\0'; i++){
        if(text[i] != ' '){
            int keep = TRUE;
            copyWord(word, copy);
            for(int j = i; keep && text[j] != '\0' ; j++){
                if(text[j] != ' '){
                    int k = isContains(copy, text[j]);
                    if(k != -1){
                        copy[k] = -1;
                    }
                    else{
                        keep = FALSE;
                    }
                }
                if(isEmpty(copy)){
                    if(!firstPrint){
                        printf("~");
                    }
                    else{
                        firstPrint = FALSE;
                    }
                    for(int g = i; g <= j; g++){
                        printf("%c", text[g]);
                    }
                    keep = FALSE;
                }
            }
        }
    }
}

int main(){
    char word[WORD];
    char text[TXT];
    insertWord(word);
    insertText(text);
    gematriaSequences(word, text);
    AtbashSequences(word, text);
    AnagramSequences(word, text);
    return 0;
}