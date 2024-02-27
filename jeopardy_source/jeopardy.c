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
#include "questions.h"
#include "players.h"

#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Global variables
player players[NUM_PLAYERS];

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);

int main(int argc, char *argv[]) {
    char buffer[BUFFER_LEN] = {0};
    char *tokens[10] = {NULL}; // Assuming no more than 10 tokens for a command

    // Display the game introduction and initialize the questions
    initialize_game();
    printf("Welcome to Jeopardy!\n");

    // Prompt for players names and initialize each of the players in the array
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter name for player %d: ", i + 1);
        fgets(buffer, BUFFER_LEN, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
        strcpy(players[i].name, buffer);
        players[i].score = 0; // Initialize score
    }

    // Main game loop
    while (true) {
        
        // starts with displaying all availible catagories
        display_categories();
	
	// Takes the user input, if the user types quit, the game will end
        printf("\nEnter a category and value (or 'quit' to finish): ");
        if (fgets(buffer, BUFFER_LEN, stdin) == NULL || strncmp(buffer, "quit", 4) == 0) {
            break;
        }
	
	// tokenizes the user's input
        tokenize(buffer, tokens);

	// if a catagory and value is selected, take it in
        if (tokens[0] && tokens[1]) {
            char *category = tokens[0];
            int value = atoi(tokens[1]);
	    
	    // if the question isn't answered, proceed with the question
            if (already_answered(category, value) == false) {
                display_question(category, value);
                printf("Your answer: ");
                // takes user's answer input
                fgets(buffer, BUFFER_LEN, stdin);
		// checks if the answer is correct or wrong
                if (valid_answer(category, value, buffer)) {
                    printf("Correct!\n");
                } else {
                    printf("Wrong answer.\n");
                }
            } else {
                printf("This question has already been answered.\n");
            }
        } else {
            printf("Invalid input! Please try again.\n");
        }
    }
    // Display the final results and exit
    show_results(players, NUM_PLAYERS);
    return EXIT_SUCCESS;
}

// function to tokenize the user's input
void tokenize(char *input, char **tokens) {
	
	// splits the input into tokens
	const char *delim = " "; 
	char *token = strtok(input, delim);
	
	// keeps retrieving tokens until no more tokens found
	while(token != NULL) {
		*tokens++ = token;
		token = strtok(NULL, delim);
	}
	*tokens = NULL;
}

// function to show the end result scores
void show_results(player *players, int num_players) {
	printf("Total Players: %d \n", num_players);
	printf("Results: \n");
	// Goes through each player, printing out their name and current points
	for(int i = 0; i < NUM_PLAYERS; i++) {
		printf("%s: %d \n", players[i].name, players[i].score);
	}
}

