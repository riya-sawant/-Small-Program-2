//Riya Sawant
//Dr. Steinberg
//COP3223 Section 7
//Small Program 7


#include <stdio.h>
#include <string.h>
#define SIZE 30

char deblank(char inputstring[SIZE])
{
	int i = 0, j = 0, check;
	
	while(inputstring[i]!='\0') 
	{
    check=0;
    if(inputstring[i]==' ') 
		{
    	j=i;
      while(inputstring[j-1]!='\0') 
			{
      	inputstring[j] = inputstring[j+1];
      	j++;
      }
      check = 1;
    }
    if(check==0)
    	i++;
  }

	return inputstring[SIZE];
}

void pluralize (char inputword[]);


void pluralize (char inputword[])
{
    int length;
    char noun;
    length=1;
    length = strlen(inputword);
    
    //if noun ends with "y" remove y with "ies"
   	if (inputword[length - 1] == 'y') 
 	  {   inputword[length - 1] = 'i';
     		inputword[length] = 'e';
    		inputword[length + 1] = 's';
    		inputword[length + 2] = '\0';  
  	}

  /* if word ends in "s" "ch" or "sh" add "es" */
 	  else if (inputword[length - 1] == 's' ||
    		(inputword[length - 2] == 'c' && inputword[length - 1] == 'h') ||
    		(inputword[length - 2] == 's' && inputword[length - 1] == 'h'))
  	  {  
  	    strcat(inputword, "es");
  	  }

  	else
 	  {   
 	    strcat(inputword, "s");
   	} 
	return;
}


char fact(char oneword[SIZE])
{
    printf("%s starts with the letter %c\n", oneword, oneword[0]);
    return 0;
}



int substring(char inputstring2[SIZE], char word[10])
{

  int i=0, j=0, Flag=0, n, m;
	n = strlen(inputstring2);	
	m = strlen(word);
	


	// if size of wrd is bigger then str then str can never contain wrd
	if (m > n)
		return 0;

		
	for(i = 0; inputstring2[i] != '\0'; i++)
	{
		if(inputstring2[i] == word[0])
		{
			Flag = 1;
			for(j = 0; word[j] != '\0'; j++)
			{
				if(inputstring2[i + j] != word[j])
				{
					Flag = 0;
					break;
				}
			}	
		}
		if(Flag == 1)
		{
			break;
		} 
	}
	
	
	if (Flag == 0)
	{   
	    return 0;
	}
	else 
	{
	    return i;
	}
	
}




int main()
{
  char inputphrase[SIZE];
	char outputstring[SIZE];

// Question 1 begins
    
	printf("Enter a string: ");
   	
   	fgets(inputphrase, sizeof(inputphrase), stdin);
    
    printf("Input String: %s",inputphrase);
	printf("\n");

	deblank(inputphrase);
	
	printf("Output String: %s",inputphrase);
	
	printf("\n\n");

// Question 1 ends   

// Question 2 begins

	char noun[SIZE];   

    	printf("Enter a noun : ");
    	scanf("%s", noun);

    	pluralize (noun);
    	printf("The plural form is %s\n", noun);

	printf("\n\n");

// Question 2 ends   

// Question 3 begins

	char inputword[SIZE];  

    	printf("Enter a word: ");
    	scanf("%s", inputword);

    	fact(inputword);

	
// Question 3 ends   

// Question 4 begins

	char inputword2[SIZE];
	char findword[10];
	int result;

    printf("\n\n");

	printf("Please Enter any String : ");
  	//fgets( inputword2, sizeof(inputword2), stdin);
  	scanf("%s",inputword2);

      	
	printf("\nPlease Enter the Word to search in the String : ");
  	//fgets(findword, sizeof(findword), stdin);
  	scanf("%s",findword);
  

	result=substring(inputword2, findword);
	//printf("%d",result);
	
	if (result == 0)
	{
		printf("NULL")	;
	}
	else
	{
		printf("\nThe word %s at position %d ", findword, result + 1);
	}



// Question 4 ends

	return 0;

}

