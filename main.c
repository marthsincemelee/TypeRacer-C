#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ANZAHLWOERTER 5

int showMenue();
void wordImport();


struct highscore
{
    int timesNeeded;
    char userName[10];

};
struct highscore highscores[11];
void showHighscores();
void bubblesort(struct highscore *array, int length);
void createNewHighscore(int time){
    struct highscore newHS;
    newHS.timesNeeded = time;
    printf("You needed %d seconds. \n "
           "Please type your username:", time);
    scanf("%s", &newHS.userName);
    highscores[10] = newHS;
    bubblesort(highscores, 11);

};
void initHighscores();

void checkInput(int input);

int main() {
    initHighscores();
    createNewHighscore(45);
    wordImport();
    showMenue();






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
void initHighscores(){
    for(int j = 0; j < 11; j++){
        highscores[j].timesNeeded = 9999;
    }
}

void showHighscores(){
    printf("Current Highscores: \n");
    for(int i =0; i < 10; i++){
        if(highscores[i].timesNeeded != 9999)
        printf("%d. %s: %d Sekunden. \n", i+1, highscores[i].userName, highscores[i].timesNeeded);
    }
}

void checkInput(int input){
    if(input == 1) {
    } else if (input == 2){
        system("clear");
    showHighscores();

    printf("Press 1 to go back: \n");
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

int compareHighscore(struct highscore h1, struct highscore h2) {

    if(h1.timesNeeded == 0 && h2.timesNeeded >0){
        return 1;
    }else if(h1.timesNeeded > h2.timesNeeded){
        return 1;
    }

}

void bubblesort(struct highscore *array, int length) {


    int i, j;
    struct highscore tmp;

    for (i = 1; i < length ; i++)
    {
        for (j = 0; j < length - i ; j++)
        {

            // h1 < h2
            if (compareHighscore(array[j], array[j + 1]) == 1) {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

void wordImport()
{
    FILE *datei;
    char wort[11];
    time_t t;
    int zahl;

    srand((unsigned) time(&t));
    zahl = (rand() % ANZAHLWOERTER) + 1;

    datei = fopen("TypeRacer.txt","r");

    for (int i=0; i<zahl; i++) {
        fgets(wort, 10, datei);
        //printf("Testausgabe: %s", wort);
    }

    printf("%s", wort);

    fclose(datei);

}


