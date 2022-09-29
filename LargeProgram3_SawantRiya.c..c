//Riya Sawant
//Dr. Steinberg
//COP 3223C Section ??
//Large Program 3


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAXSTRIKES 6
#define MAXWORDS 20
#define ROUNDS 5



void rules(void); //display rules of the game

void maskWord (char starword[], int size); //mask the word with stars to display to user in game

int playRound(char starword[], char answer[]); //function that plays a round of hangman. returns 1 if user won

int occurancesInWord(char userguess, char answer[]); //number of times letter occurs in word. Greater than 0 means letter exist

void updateStarWord(char starword[], char answer[], char userguess); 
//update starword. replace respective * character with respective letter

void playAgain(int *play); //ask user if to play again. 1 is yes 2 is n



int main()
{
	int size, game=0;
	
  	char starword[MAXWORDS];
  	char answer[MAXWORDS];
    char guess;
	  int playchoice = 1;

    FILE *ifp;
    ifp=fopen("words.txt","r");

	rules();

	
	//for (int game = 1; game <= ROUNDS; game++)
	do{
		
  		//printf("Enter word to guess: ");
  		//fflush(stdout);
  		//scanf(" %s", answer);
      fscanf(ifp,"%s", answer );

  		// Set the mask array - mask[i] is true if the
  		// character s[i] has been guessed.  The mask
  		// must be allocated, and initialized to all false

  		size = strlen(answer);
 		
		//maskWord(starword, strlen(answer));


        playRound(starword,answer);
        playAgain(&playchoice);
        
        
	}while(playchoice == 1);

fclose(ifp);

	printf("Thank you for playing!\n");
    
	return 0;
}



void rules(void)
{
	printf("Welcome to the Hangman Game!\n\n");
	printf("************************************************************************\n\n");
	printf("Here are the rules.\n\n");
	printf("I will provide you a set of * characters for each round.\n\n");
	printf("Each * represents a letter in the English Alphabet.\n\n");
	printf("You must figure out each letter of the missing word.\n\n");
	printf("For every correct letter guessed, I will reveal its place in the word.\n\n");
	printf("Each mistake will result in a strike.\n\n");
	printf("6 strikes will result in a loss that round.\n\n");
	printf("Are you ready? Here we go!\n\n");
	printf("************************************************************************\n\n");
}

void maskWord (char starword[], int size)
{
	
	int j=0;

//	printf("Letter(s) you have guessed:\n\n");
	
    	for (j = 0; j < size; j++) {

          starword[j] = '*';

        }

	starword[j] = '\0'; // insert end of string

}




int playRound(char starword[], char answer[])
{
    
    char guess;
    char guessword[MAXWORDS];
    char lettersGuessed[26];
    char letter;
	  int count=0, i, result = 0, found, num_guess=0;
 	  int size=0;
 	
	  size = strlen(answer);
	
	  printf("Welcome to the Round!\n\n");
	  printf("The size of the word has %d letters.\n\n",size);
	  printf("You currently have 0 strike(s).\n\n");	
	
	  maskWord(guessword, strlen(answer));
	

//	printf("\nHere are the letters guessed so far:");
	  printf("Letter(s) you have guessed:\n\n");
	

	for(i=0;i<num_guess;i++)
          printf("%c",lettersGuessed[i]);

    printf("\n");

    for(i=0;i<strlen(guessword);i++)
      printf("%c",guessword[i]);
          
   	printf("\n");


	    

  while(count < MAXSTRIKES && result ==0)
  {
        //printf("\n----------------");
	    printf("\nEnter your guess: ");
      fflush(stdout);
      scanf(" %c",&letter);
      if( (letter>='a' && letter<='z') || (letter>='A' && letter<='Z'))
      {
            letter = tolower(letter);
      

	    

	   for(i=0;i<num_guess;i++)
       {
             if(lettersGuessed[i] == letter)
              printf("\n");
         //       return letter;
       }


       lettersGuessed[num_guess] = letter;

       num_guess = num_guess + 1;

       //printf("%s",lettersGuessed);
	   //printf("%d\n",num_guess);

	   //for(i=0;i<num_guess;i++)
        //{
         // printf("%c",lettersGuessed[i]);
        //}
        
	    found=occurancesInWord(letter, answer);

	    updateStarWord(guessword, answer, letter);

	    if(found==1)
	    {
		    printf("\nThe letter %c is in the word.\n", letter);
		    
		    printf("\nYou currently have %d strike(s).\n", count);
		

          // display the secret word

        //    printf("\nSecret Word : ");

        //    for(i=0;i<strlen(guessword);i++)
        //        printf("%c",guessword[i]);
            
            printf("\n");
		// check if user won
            
            
	       if(strcmp(answer,guessword) == 0)
      		{
             		result = 1;
       		}

		     if(result == 1)
           	{
              printf("\nCongratulations! You won! The word was %s\n",answer);
            	printf("\n************************************************************************\n");

                break;
           	}
	       
	      }
	      else
	      {
		      count++;
		      printf("\nThe letter %c is NOT in the word.\n", letter);
		      printf("\nYou currently have %d strike(s).\n", count);
		
	      }
    
      }
      else 
      {
         printf("\nYou did not enter a letter from the alphabet.\n");
         printf("\nYou currently have %d strike(s).\n", count);
	}
    


	    printf("\nLetter(s) you have guessed: "); 	      
	    for(i=0;i<num_guess;i++)
	    {
          printf("%c",lettersGuessed[i]);
        }
	
	    printf("\n");

	    for(i=0;i<strlen(guessword);i++)
	    {
          printf("%c",guessword[i]);
	    }
    	//printf("%s",guessword);
    	printf("\n");

    }
    
    
    if(result == 0 )
   {
       	printf("\n************************************************************************\n\n");
        printf("Sorry you did not win the round. The word was %s.\n",answer);
       	printf("\n************************************************************************\n\n");

   }


	return 0;
	

}




int occurancesInWord(char userguess, char answer[])
{
	int i=0;

	int found = 0;

       for(i=0;i<strlen(answer);i++)
       {
             if(answer[i] == userguess)
             {
                   found = 1;
             }
       }
       return found;
}

void updateStarWord(char starword[], char answer[], char userguess)
{
       int i;

       int found = 0;

       for(i=0; i<strlen(answer);i++)
       {
             if(answer[i] == userguess)

             {
	            starword[i] = userguess;
                    found = 1;
             }
       }

}

void playAgain(int *play)
{
    int choice2;
    printf("\nWould you like to play another round? \n");
    printf("\n1: Yes\n");
    printf("\n2: No\n");
    printf("\nChoice: ");
    scanf("%d", play);
    printf("\n************************************************************************\n\n");
 	
}

