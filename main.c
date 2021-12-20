#include <stdio.h>

#define TXT 1024
#define WORD 30
#define ABC  ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 
              's', 't', 'u', 'v', 'w', 'x', 'y', 'z']


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


void printText(char text[TXT]){
    int count = 0;
    while(text[count] != '\0'){
        printf("%c ", text[count]);
        count++;
    }
}
/*
int gematria(char c){
    int ans = 0;
    if()
    return ans;
}
*/
int main(){
    char word[WORD];
    char text[TXT];
    insertWord(word);
    insertText(text);
    printText(text);
    return 0;
}