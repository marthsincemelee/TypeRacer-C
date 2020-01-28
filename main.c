#include <stdio.h>
#include <stdlib.h>
#define CLEAR printf("\033[2J")

int showMenue();
void checkInput(int input);

int main() {
    showMenue();



CLEAR;
    return 0;
}



int showMenue() {

    int input;
    printf("WELCOME TO TYPERACER-C! \n"
           "What do you want to do? \n"
           "1. Start new Game \n"
           "2.Show highscores \n"
           "3. Quit game \n \n");


    scanf("%d" ,&input);
    checkInput(input);
}



void checkInput(int input){
    if(input == 1) {
    } else if (input == 2){

    } else if (input == 3){

        //do something
    }else {
        system("clear");
        printf("Your input was incorrect. Please enter a valid number! \n");
        system("clear");
        int newInput;
        scanf("%d", &newInput);
        checkInput(newInput);
    };
}


