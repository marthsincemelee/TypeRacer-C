#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ANZAHLWOERTER 100

char wordsToWrite[ANZAHLWOERTER][11];

int showMenue();
void wordImport();
void backToMenue();

struct highscore
{
    double timesNeeded;
    char userName[10];
};

struct highscore highscores[11];
void showHighscores();
void bubblesort(struct highscore *array, int length);

/**
 * Creates a new highscore, method is called when a game is finished. Will ask for a user name to save the highscore. 
 * 
 * @par double time is given to the method by the programm
 */
void createNewHighscore(double time)
{
    struct highscore newHS;
    newHS.timesNeeded = time;
    printf("You needed %f seconds. \n "
           "Please type your username:",
           time);
    scanf("%s", &newHS.userName);
    highscores[10] = newHS;
    bubblesort(highscores, 11);
};

void initHighscores();

void exportHighscore();

void importHighscore();


void checkInput(int input);

double startGame();


int main()
{

    
    wordImport();
    //importHighscore();

    initHighscores();
    showMenue();
    //exportHighscore();

    return 0;
}

/**
 * Will show the menue in the console and wait for the user to make his decision.
 * 
 */
int showMenue()
{

    int input;
    printf("WELCOME TO TYPERACER-C! \n"
           "What do you want to do? \n"
           "1. Start new Game \n"
           "2.Show highscores \n"
           "3. Quit game \n \n");

    scanf("%d", &input);
    checkInput(input);
}

/**
 * Initiates the Highscore list will read the highscores from the file and set all highscores to a specific value which wont be used (9999)
 * 
 */
void initHighscores()
{
    for (int j = 0; j < 11; j++)
    {
        highscores[j].timesNeeded = 9999;
    }
}


/**
 * Called when the programm wants to give the option to go back to the main menue
 */
void backToMenue()
{

    int input = 0;
    printf("Press 1 to go back to the menue...\n ");
    scanf("%d", &input);

    if (input == 1)
    {
        system("clear");
        showMenue();
    }else
    {
        printf("Wrong input...try again.");
        backToMenue();
    }
    
}

/**
 * Will be called to evaluate and show the highscore list
 */
void showHighscores()
{
    printf("Current Highscores: \n\n");
    for (int i = 0; i < 10; i++)
    {
        if (highscores[i].timesNeeded != 9999)
            printf("\t %d. %s: %.2f Sekunden. \n", i + 1, highscores[i].userName, highscores[i].timesNeeded);
    }
    printf("\n");
    backToMenue();

}

/**
 * Checks the users input into the console, and redirectes to the choosen funtionallity of the programm
 */
void checkInput(int input)
{
    double time;
    if (input == 1)
    {
        time = startGame();
        createNewHighscore(time);
    }
    else if (input == 2)
    {
        system("clear");
        showHighscores();

        printf("Press 1 to go back: ");
    }
    else if (input == 3)
    {

        printf("Thanks for playing the C-Version of Typeracer\n");
        system("exit");
    }
    else
    {
        system("clear");
        printf("Your input was incorrect. Please enter a valid number! \n");
        int newInput;
        scanf("%d", &newInput);
        checkInput(newInput);
    };
}
/**
 * Compares two highscores
 * 
 * @return returns 1 if the highscore needs to be moved up on the list
 */
int compareHighscore(struct highscore h1, struct highscore h2)
{

    if (h1.timesNeeded == 0 && h2.timesNeeded > 0)
    {
        return 1;
    }
    else if (h1.timesNeeded > h2.timesNeeded)
    {
        return 1;
    }
}

/**
 * Uses bubblesort in combination with the compareHighscore method to sort the list of highscores  
 * 
 * @par the highscore array the needs to be sorted depending on the gametype
 * @par the length of the array 
 */
void bubblesort(struct highscore *array, int length)
{

    int i, j;
    struct highscore tmp;

    for (i = 1; i < length; i++)
    {
        for (j = 0; j < length - i; j++)
        {

            // h1 < h2
            if (compareHighscore(array[j], array[j + 1]) == 1)
            {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

/**
 * imports the words for the game to be shown in the casual gamemode 
 */
void wordImport()
{
    FILE *file_ptr = NULL;
    file_ptr = fopen("TypeRacer.txt", "r");

    for (int i = 0; i < ANZAHLWOERTER; i++)
    {
        fgets(wordsToWrite[i], 10, file_ptr);
    }

   fclose(file_ptr);
}

/**
 * Starts up a new game in standart gamemode
 * 
 * @return Returns the time needed by the user to complete the game.
 */
double startGame()
{

    int i;
    double diff_t;
    char userinput[20], choose;
    time_t begin, end;

    time_t t;

    srand((unsigned)time(&t));

  /*  printf("To start the game press space: \n");

    do
    {
        scanf("%c", &choose);
    } while (choose != 10);

    system("clear");*/

    begin = time(NULL);

    for (i = 1; i < 6; i++)
    {
      //  system("clear");
        wordImport();
        printf("%s\n", wordsToWrite);
        do
        {
            printf("type:\n");
            scanf("%s", &userinput);
        } while (strcmp(userinput, wordsToWrite) != 0);
    }
    end = time(NULL);

    printf("You needed %.2f seconds to complete the test!", difftime(end, begin));

    diff_t = difftime(end, begin);

    return diff_t;
}

void exportHighscore(){
    FILE *f = fopen("highscores.data", "wb");
    fwrite(highscores, sizeof(char), sizeof(highscores), f);
    fclose(f);
}


void importHighscore(){
    FILE *ifp = fopen("highscores.data", "rb"); 
    fread(highscores, sizeof(char), sizeof(highscores), ifp);
    fclose(ifp);
}