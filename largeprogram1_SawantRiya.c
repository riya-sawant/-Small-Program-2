//Riya Sawant
//Dr. Steinberg
//COP 3223 Section 
//Large Program 1

#define ROUNDS 5
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void Greeting(); //display welcome message to user
void SetSeed(int seed); //set the seed of pseudo random generator
int PlayRound(char answer, int round); //play one round
char GetGuess(); //retrieve the user's guess
int CompareLetters(char guess, char answer); //compare the user's guess with the answer
void RoundResult(int result, char answer); //determine if the user won or loss the round

char answer;

#define MAXGUESSES 5

int main()
{
    int game=0;

    char guess;
    Greeting();
    SetSeed(3);
    
	for (int game = 1; game <= ROUNDS; game++)
	{
		//this loop will allow the user play 5 rounds. You have to fill in the missing code that simulates the round and result. You will also need to determine random letter answer the program will store
		//DO NOT REMOVE OR CHANGE THE LOOP!!!
		
        int a=rand() % 26;
        char answer1= (char)(a +65);
        //printf("%c\n", answer1);
      
		PlayRound(answer1, game);
        
	}
	printf("Thank you for playing!\n");
    
	return 0;
}


int PlayRound(char answer, int round)
{
    	int result;
	printf("Round %d\n", round);

	for (int chance = 1; chance <= 5; chance++)
	{		
		printf("Guess #%d\n", chance);
		
		//this loop will allow the user to guess until they are out of chances, you have fill in the missing code that checks to see if user guessed correctly
		//DO NOT REMOVE OR CHANGE THE LOOP!!!
		

		char guesschar;
		guesschar=GetGuess(); 
		result=CompareLetters(guesschar, answer);
		
		if (result==1)
		{
		    RoundResult(result, answer);
		    return 0;
		}
	
	}
	RoundResult(result, answer);
	
	return 0;
}

char GetGuess()
{
    char guess='0';
    
   
    printf("Enter your guess: ");
    scanf(" %c",&guess);
    guess=toupper(guess);
    
    //	CompareLetters(guess,answer);
    return guess;
}


int CompareLetters(char guess, char answer)
{
    
    if (guess==answer) //if answer is right
    {
        //printf("Congratulations! You won the round!\n\n");
        return 1;
    }
    else if (guess < answer)
    {
        printf("\nThe letter you picked comes before the one I am thinking of. \n\n");
        //GetGuess();
        return 0;
    }
    else if (guess > answer)
    {
        printf("\nThe letter you picked comes after the one I am thinking of. \n\n");
        //GetGuess();
        return 0;
    }
}

void RoundResult(int result, char answer)
{
    if (result==1)
    {
        printf("\nCongratulations! You won the round!\n");
        printf("********************************************************\n");
    }
    else
    {
        printf("Sorry! You didn't win the round!\n");
        printf("The letter I was thinking of was %c.\n", answer);
        printf("********************************************************\n");
        
    }
    
}
void Greeting()
{
	printf("********************************************************\n");
	printf("Welcome to the Letter Guessing Game!\n");
	printf("Here are the rules.\n");
	printf("I will think of a letter in the English Alphabet and you will have to guess it!\n");
	printf("I will provide you a limit of 5 chances to guess the correct the letter.\n");
	printf("Are you ready to play 5 rounds? Here we go!\n");
	printf("********************************************************\n");
	printf("********************************************************\n");
}
void SetSeed(int seed)
{
    srand(seed);   
}

