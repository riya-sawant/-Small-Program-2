//Riya Sawant
//Dr. Steinberg
//COP3223 Section 4
//Small Program 4

//Question 1 begins

#include <stdio.h>
#include <stdlib.h>

int Triangle();

int Triangle()
{
    int numrows, i, j, k = 1;   
   
    char incorrect = 'y';

    while (incorrect !='n' && incorrect != 'N') 
    {
        printf( "Enter the number of rows greater than or equal to 3: ");  
        scanf( "%d", &numrows); 
        
        if (numrows < 3) 
	    {
            printf("You have enter rows less than 3, ");
            incorrect = 'y';
        } 
        else 
        {
            incorrect = 'n';
            // use nested for loop  
    	    // outer for loop define the rows and check rows condition  
    	    for (i = 1; i <= numrows; i++)  
    	    {  
        	    // inner loop check j should be less than equal to 1 and print the data.  
        	    for (j = 1; j <= i; j++)  
        	    {  
            		printf(" *"); // print the star  
              
        	    }  
        	  printf( "\n");  
            }     
        
        }
    
    }
       
}


char AdvancedMenu();
 
char AdvancedMenu()
{
	int choice;
	
	do{
        printf("Select an option\n");
	
	printf("1. Blue Button Pressed\n");
	printf("2. Green Button Pressed\n");
	printf("3. Red Button Pressed\n");
	printf("4. Yellow Button Pressed\n");
        printf("5. Exit\n\n");

        printf("Enter Option: ");
	scanf("%d",&choice);
	
    	switch (choice)
      {
          case 1: 
        {
            printf("Blue Button Selected\n\n");
            break;
        }
        case 2: 
        {
            printf("Green Button Selected\n\n");
            break;
        }
          case 3: 
        {
            printf("Red Button Selected\n\n");
            break;
        }
          case 4: 
        {
            printf("Yellow Button Selected\n\n");
            break;
        }
            case 5 :
            {
                break;
            }
        default:
            printf("Wrong option. \n\n");
          break;
      }
          
     
    } while (choice != 5);
	
}

int Fibonacci(int nvalue);

int Fibonacci(int nvalue)
{

  int i;

  // initialize first and second terms
  int t1 = 0, t2 = 1;

  // initialize the next term (3rd term)
  int nextTerm = t1 + t2;

  for (i = 3; i <= nvalue; ++i) 
  {
    t1 = t2;
    t2 = nextTerm;
    nextTerm = t1 + t2;
  }

  return nextTerm;

}

//Question 4 begins

int CountdownTwo()
{
	int inputvalue;  
  	int i;     
  	int maxtime;

  	printf("Enter a number: ");
  	scanf("%d",&inputvalue);

  	maxtime= (int)(inputvalue/2);
  	int sum=inputvalue;
    
  	printf("%d\n",sum);

  	for (i = 0; i < maxtime; i=i+1) 
  	{
    		sum = sum - 2;  
    		printf("%d\n",sum);
    
    		if (sum <=0)
    		{
      		break;
    		}
  	} 
  return 0;
}
//Question4 ends

int main(void) 
{
    //Question 1 begins
    Triangle();
    printf("\n");
    //Question 1 ends

    //Question2 begins
    AdvancedMenu();
    printf("\n");
    //Questions 2 ends
    
    //Question 3 begins
    int n;
  	
	  char incorrect2 = 'y';
    int result;

   	while (incorrect2 !='n' && incorrect2 != 'N') 
    {
    	printf("Enter the value of n greater than or equal to 2 : ");
  	  scanf("%d", &n);
    	printf("\n");

    	if (n < 2) 
	   	{
        	printf("You have enter value less than 2, \n");
        	incorrect2 = 'y';
        } 
        else 
        {
            incorrect2 = 'n';
            result=Fibonacci(n);
            printf("Result of the Sequence: %d", result);
        }
    }
   
    printf("\n\n");
    //Question 3 ends

    //Question 4 Begins
    CountdownTwo();
    //Question 4 ends
    return 0;	
}