/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP 15>
 * All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "questions.h"

// holds all catagories
char categories[NUM_CATEGORIES][MAX_LEN] = {
    "General", 
    "Tv", 
    "Nature"
};

// struct for questions
question questions[NUM_QUESTIONS];

// initialization of questions
void initialize_game(void) {
    // General category
    strcpy(questions[0].category, categories[0]);
    strcpy(questions[0].question, "What animal can be seen on the Porsche logo?");
    strcpy(questions[0].answer, "Horse");
    questions[0].value = 100;
    questions[0].answered = false;

    strcpy(questions[1].category, categories[0]);
    strcpy(questions[1].question, "Peter Parker is the superhero of which movie?");
    strcpy(questions[1].answer, "Spiderman");
    questions[1].value = 200;
    questions[1].answered = false;

    strcpy(questions[2].category, categories[0]);
    strcpy(questions[2].question, "What is Thor the God of?");
    strcpy(questions[2].answer, "Thunder");
    questions[2].value = 300;
    questions[2].answered = false;

    // TV Shows category
    strcpy(questions[3].category, categories[1]);
    strcpy(questions[3].question, "Which TV show follows the lives of Rachel, Monica, Phoebe, Ross, Chandler, and Joey?");
    strcpy(questions[3].answer, "Friends");
    questions[3].value = 100;
    questions[3].answered = false;

    strcpy(questions[4].category, categories[1]);
    strcpy(questions[4].question, "What city does Spongebob Squarepants live in?");
    strcpy(questions[4].answer, "Bikini Bottom");
    questions[4].value = 200;
    questions[4].answered = false;

    strcpy(questions[5].category, categories[1]);
    strcpy(questions[5].question, "What is Phineas and Ferb’s pet platypus named?");
    strcpy(questions[5].answer, "Perry");
    questions[5].value = 300;
    questions[5].answered = false;

    // Nature category
    strcpy(questions[6].category, categories[2]);
    strcpy(questions[6].question, "What is the process of converting sunlight into energy called in plants?");
    strcpy(questions[6].answer, "Photosynthesis");
    questions[6].value = 100;
    questions[6].answered = false;

    strcpy(questions[7].category, categories[2]);
    strcpy(questions[7].question, "What is the fastest running bird on land?");
    strcpy(questions[7].answer, "Ostrich");
    questions[7].value = 200;
    questions[7].answered = false;

    strcpy(questions[8].category, categories[2]);
    strcpy(questions[8].question, "What animal is known as the ‘King of the Jungle’?");
    strcpy(questions[8].answer, "Lion");
    questions[8].value = 300;
    questions[8].answered = false;
}

// function to display catagories that hasn't been answered yet
void display_categories(void) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (questions[i].answered == false) {
            if(strcmp(questions[i].category, "Tv")){
            	printf("%s - $%d\n", questions[i].category, questions[i].value);
            } else {
            printf("%s      - $%d\n", questions[i].category, questions[i].value);
            }
        }
    }
}

// function to displays the question selected
void display_question(char *category, int value) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value && !questions[i].answered) {
            printf("\nThe Question: %s\n", questions[i].question);
            return;
        }
    }
    printf("The question has already been answered or is invalid!\n");
}

//function to remove white spaces 
void remove_space(char *str) { 
    //removes whitespaces in the front
    while (*str && isspace(*str)) {
        ++str;
    }
    
    // Remove whitespace at the end
    char *end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) {
        *end-- = '\0';
    }
}

// function to check if answer is right
bool valid_answer(char *category, int value, char *answer) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        // finds the matching question
        if (strcmp(questions[i].category,category)==0 && questions[i].value==value) {
            // if it matches return true, otherwise false
             remove_space(questions[i].answer);
             remove_space(answer);
            if (strcmp(questions[i].answer,answer) == 0){
            	questions[i].answered = true;
            	return true;
            } 
        }
    }
    return false;
}

// function to check if teh question is already answered
bool already_answered(char *category, int value) {
    // finds the mathcing question and checks if its answer field is true
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value && questions[i].answered) {
            return true;
        }
    }
    return false;
}
