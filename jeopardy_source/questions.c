#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

#define MAX_CATEGORIES 3
#define MAX_QUESTIONS 3
#define MAX_CATEGORIES_LENGTH 100
#define MAX_QUESTIONS_LENGTH 100
#define MAX_ANSWERS_LENGTH 100

struct QUESTION{
    char category [MAX_CATEGORIES_LENGTH];
    char question [MAX_ANSWERS_LENGTH];
    char answer [MAX_ANSWERS_LENGTH];
    int value;
    bool answered; 
};
struct Question questions[MAX_CATEGORIES][MAX_CATEGORIES];
// initializes the array of questions for the game
void initialize_game(void) {
    // General category 
    //c0q1
    strcpy(question[1].category, "General");
    strcpy(question[1].question, "What animal can be seen on the Porsche logo?");
    strcpy(question[1].answer, "Horse");
    question[1].value = 100;
    question[1].answered = false;
    //c1q2
    strcpy(question[2].category, "General");
    strcpy(question[2].question, "Peter Parker is the superhero of which movie?");
    strcpy(question[2].answer, "Spiderman");
    question[2].value = 300;
    question[2].answered = false;
    //c1q3
    strcpy(question[3].category, "General");
    strcpy(question[3].question, "What is Thor the God of?");
    strcpy(question[3].answer, "Thunder");
    question[3].value = 500;
    question[3].answered = false;

    //Tv shows category 
    //c1q1
    strcpy(question[4].category, "TV Shows");
    strcpy(question[4].question, "Which TV show follows the lives of Rachel, Moinca, Phoebe, Ross, Chandler, and Joey?");
    strcpy(question[4].answer, "Friends");
    question[4].value = 100;
    question[4].answered = false;

    //c1q2
    strcpy(question[5].category, "TV Shows");
    strcpy(question[5].question, "What city does Spongebob live in?");
    strcpy(question[5].answer, "Bikini Bottom");
    question[5].value = 300;
    question[5].answered = false;

    //c1q3
    strcpy(question[6].category, "TV Shows");
    strcpy(question[6].question, "What is Phineas and Ferb’s pet platypus named?");
    strcpy(question[6].answer, "Perry");
    question[6].value = 500;
    question[6].answered = false;


    //nature category
    //c2q1
    strcpy(question[7].category, "TV Shows");
    strcpy(question[7].question, "What is the process of converting sunlight into energy for plants?");
    strcpy(question[7].answer, "Photosynthesis");
    question[7].value = 100;
    question[7].answered = false;
    //c2q2
    strcpy(question[8].category, "TV Shows");
    strcpy(question[8].question, "What is the fastest running bird currently alive?");
    strcpy(question[8].answer, "Ostrich");
    question[8].value = 300;
    question[8].answered = false;
    //c2q3
    strcpy(question[9].category, "TV Shows");
    strcpy(question[9].question, "What animal is known as ‘King of the Jungle’?");
    strcpy(question[9].answer, "Lion");
    question[9].value = 500;
    question[9].answered = false;
}


// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
        for (int i =0; i < MAX_CATEGORIES; i++){
            for (int j =0; j < MAX_QUESTIONS; j++){
                //questions that haven't been answered
                if (question[i][j].answer){
                    printf("%s: $%d\n", question[i][j].category, question[i][j].value);
                   
                }

            }
        }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
//loops category 
     for (int i= 0; i < MAX_CATEGORIES; i++) {
        //loops question
        for (int j = 0; j< MAX_QUESTIONS; j++) {
            //question is checked with cateogry 
            if (strcmp(question[i][j].category, category) == 0 && question[i][j].value == value && question[i][j].answer) {

                printf("Question: %s\n", question[i][j].question);
                return;
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        for (int j = 0; j < MAX_QUESTIONS; j++) {

            //checks if the the question in the category matches the string input 
            if (strcmp(question[i][j].category, category) == 0 && question[i][j].value == value && question[i][j].answer) {

                    //if it matches 
                if (strcmp(question[i][j].answer, answer) == 0) {
                    question[i][j].answered = true;
                    printf("Correct!\n");
                    return true;

                } else {
                    //if it doesn't 
                    printf("Incorrect.\n");
                    return false;
                }
            }
        }
    }    
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        for (int j = 0; j < MAX_QUESTIONS; j++) {
            if (strcmp(question[i][j].category, category) == 0 && question[i][j].value == value && question[i][j].answer) {
                return true;
}
