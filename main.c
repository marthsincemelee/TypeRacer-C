#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define WORDCOUNT 155

char *wordsToWrite[WORDCOUNT]={"Time","Date","Today","Yesterday","Tomorrow","motivation","commitment","television",
                         "assumption","relinquish","accountant","difference","memorandum","proportion","prevalence",
                         "democratic","vegetation","investment","simplicity","folk music","transition","obligation",
                         "mainstream","possession","convulsion","multimedia","accessible","resolution","girlfriend",
                         "profession","relaxation","repetition","withdrawal","presidency","earthquake","acceptable",
                         "excavation","overcharge","homosexual","distortion","basketball","population","foundation",
                         "stereotype","depression","allocation","conviction","disappoint","reflection","conception",
                         "particular","systematic","inhabitant","right wing","illustrate","proportion","opposition",
                         "confession","resolution","constraint","chimpanzee","appreciate","accessible","photograph",
                         "vegetarian","straighten","leadership","production","commitment","homosexual","indication",
                         "reputation","protection","conscience","hypnothize","folk music","philosophy","fastidious",
                         "enthusiasm","redundancy","correction","accountant","conference","collection","mechanical",
                         "productive","conviction","government","incredible","unpleasant","distribute","negligence",
                         "relaxation","exhibition","dependence","plagiarize","gregarious","separation","exaggerate",
                         "allocation","litigation","attachment","motivation","definition","temptation","negligence",
                         "television","productive","mainstream","litigation","instrument","attachment","attractive",
                         "settlement","excavation","innovation","appearance","hemisphere","initiative","appreciate",
                         "convulsion","illustrate","plagiarize","conference","chauvinist","motivation","leadership",
                         "understand","perception","expression","projection","confidence","straighten","substitute",
                         "democratic","curriculum","assumption","conscience","foundation","collection","revolution",
                         "renumerate","nomination","brilliance","government","folk music","reputation","federation",
                         "psychology","distortion","redundancy","disability","possession","researcher","compliance"};

int showMenue();
void wordImport();
void backToMenue();
char* getRandomWord();

struct highscore
{
    double timesNeeded;
    char userName[11];
};

struct highscore highscores[11];
void showHighscores();
void bubblesort(struct highscore *array, int length);

/**
 * Creates a new highscore, method is called when a game is finished. Will ask for a user name to save the highscore. 
 * 
 * @par double time is given to the method by the programm
 */
void createNewHighscore(char username[10] ,double time)
{
    struct highscore newHS;
    newHS.timesNeeded = time;
    strcpy(newHS.userName, username);
    highscores[10] = newHS;
    bubblesort(highscores, 11);
};

void initHighscores();

void exportHighscore();

void importHighscore();


void checkInput(int input);

void startGame();


int main()
{
    int i;
    srand(time(0));
    
    //wordImport();
    importHighscore();
    showMenue();
    exportHighscore();

    return 0;
}

/**
 * Will show the menue in the console and wait for the user to make his decision.
 * 
 */
int showMenue()
{
    system("clear");
    int input;
    printf("WELCOME TO TYPERACER-C! \n"
           "What do you want to do? \n"
           "1. Start new Game \n"
           "2. Show highscores \n"
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
     startGame();   
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
        //printf("Your input was incorrect. Please enter a valid number! \n");
        showMenue();
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


    if(file_ptr != NULL){
        for (int i = 0; i < WORDCOUNT; i++)
            {
        fgets(wordsToWrite[i], 10, file_ptr);
            }
    }else
    {

    }
    


   fclose(file_ptr);
}

/**
 * Starts up a new game in standart gamemode
 * 
 * @return Returns the time needed by the user to complete the game.
 */
void startGame()
{

    int i;
    char username[10], word[11], temp[11];
    double score;
    time_t begin, end;

    printf("Please enter your username (Max 10 Characters!!!)...");
    scanf("%s", username);
    printf("Hi %s\n\n", username);
    printf("Now you'll be presented with 5 words. Please type them as fast as possible\n");
    printf("Type 'start' to start the game, type 'end' to quit\n");
    scanf("%s", temp);
    while(strcmp(temp, "start")!=0 && strcmp(temp, "end")!=0)
    {
        printf("Type 'start' to start the game, type 'end' to quit\n");
        scanf("%s", temp);
    }
    if(strcmp(temp, "end")==0)
    {
        showMenue();
    }
    else
    {
        begin = time(NULL);
        int strcmpInt = 1;
        for(i=0; i<5; i++)
        {


            strcpy(word, getRandomWord());

            printf("Word No %d: %s\n", i+1, word);
            scanf("%s", temp);
            system("clear");
            
            while(strcmp(temp,word) != 0)
            {
                //while ((getchar())!= '\n');
                
                printf("Word No %d: %s\n", i+1, word);
                scanf("%s", temp);
                printf("value: %d\n", strcmp(temp,word));
                system("clear");

            }
        }
        end = time(NULL);
        score=difftime(end, begin);
        printf("\nDone, thank you!!! Your time is: %f\n", score);

        createNewHighscore(username, score);
        showMenue();
    }
}


/**
 * User to export the current highscore array into a txt file.
 */ 
void exportHighscore(){
    FILE *f = fopen("highscores.txt", "w");
    fwrite(highscores, sizeof(char), sizeof(highscores), f);
    fclose(f);
}


/**
 * Checks if a highscores.txt file exists, then create a new one or imports the data into the game.
 */ 
void importHighscore(){

    //Check if the file alreay exists
    if(access("highscores.txt", F_OK) != -1){
        ///file exists
        FILE *ifp = fopen("highscores.txt", "r"); 
        fread(highscores, sizeof(char), sizeof(highscores), ifp);
        fclose(ifp);


    }else
    {
        // file does not exist
        initHighscores();
        exportHighscore();        
    }

    
    

}

char* getRandomWord(){
    int i = rand() % WORDCOUNT;

    return wordsToWrite[i];
}


