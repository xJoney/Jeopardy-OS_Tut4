/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();
    
    printf("Welcome to Jeopardy! \n");

    // Prompt for players names
    printf("Please Enter the 4 player names: \n");
    
    // initialize each of the players in the array
    for(int i = 0; i < NUM_PLAYERS; i++) {
    	fgets(buffer,BUFFER_LEN, stdin);
    	buffer[strcspn(buffer, "\n")] = 0;
    	strncpy(players[i].name, buffer, BUFFER_LEN);
    	
    	//starts each player off with the score 0
    	players[i].score = 0;
    }
    

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Call functions from the questions and players source files
	
	display_cartegories();
	
        // Execute the game until all questions are answered
	
        // Display the final results and exit
        
    }
    return EXIT_SUCCESS;
}
void tokenize(char *input, char **token) {
	
	// splits the input into tokens
	const char *delim = ""; 
	char *token = strtok(input, delim);
	
	// keeps retrieving tokens until no more tokens found
	while(token != NULL) {
		*tokens++ = token;
		token = strtok(NULL, delim);
	}
	*tokens = NULL;
}
void show_results(player *players, int num_players) {
	
	printf("Current results: \n");
	// Goes through each player, printing out their name and current points
	for(int i = 0; i < NUM_PLAYERS; i++) {
		printf("%s: %d \n", players[i].name, players[i].score);
	}
}

