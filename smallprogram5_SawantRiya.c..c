//Riya Sawant
//Dr. Steinberg
//COP3223 Section 5
//Small Program 5

//Question 1 begins

#include <stdio.h>

void Change(double *d, double *p);

void Change(double *d, double *p)
{
    double total =  *p - *d;

    //printf("%.2f\n", *d);
    //printf("%.2f\n", *p);
    //printf("%.2f\n",total);
    
    int penniestotal;
    int dlr;
    int qtr;
    int dim;
    int nkl;
    int pny;
    int reminder;
    int reminder2;
    int reminder3;
    
    penniestotal = total * 100;
    
    dlr = penniestotal / 100;
    reminder = penniestotal % 100;

    qtr = reminder / 25;
    reminder2 = reminder % 25;

    dim = reminder2 / 10;
    reminder3 = reminder2 % 10;

    nkl = reminder3 / 5;
    pny = reminder3 % 5;

    printf("Change\n");
    printf("%d dollars\n",dlr);
    printf("%d quarters\n",qtr);
    printf("%d dimes\n",dim);
    printf("%d nickels\n",nkl);
    printf("%d pennies\n",pny);
}

//Question 1 ends

//Question 2 begins

void MultTable(int *irows, int *jcolumns);

void MultTable(int *irows, int *jcolumns)
{
    int ival = *irows;
    int jval = *jcolumns;
    int a, b;
    
    for(a=1; a<=ival; a++)
    {
        for(b=1; b<=jval; b++)
        {
           printf("%d\t", a*b);
        }
        printf("\n");
    }
   
}

//Question 2 ends

//Question 3 begins

void Maximum(int *i, int *j);

void Maximum(int *i, int *j)
{
    if (*i > *j)
    {
        printf("%d is greater than %d.\n", *i,*j);
    }
    else if (*i < *j)
    {
        printf("%d is greater than %d.\n", *j,*i);
    }
    else
    {
        printf("Both the values are equal %d.\n", *i);   
    }
   
}

//Question 3 ends


//Question 4 begins
int IncrementUpdate(int *val);

int IncrementUpdate(int *val)
{
    //printf("%d",*val);
    *val= *val + 1;
    return *val;
}

//Question 4 ends



int main()
{
    //Question 1 begins

    //variables
    double paid;
    double due;
    

    printf( "Amount Due: " );
    scanf( "%lf", &due );

    printf( "Amount Paid: " );
    scanf( "%lf", &paid );

    Change(&due, &paid);
    
    printf("\n");

    //Question 2 begins

    int rows;
    int columns;

    printf( "Enter numbers of rows: " );
    scanf( "%d", &rows );

    printf( "Enter numner of columns: " );
    scanf( "%d", &columns );

    MultTable(&rows, &columns);

    printf("\n");
    //Question 2 ends


   //Question 3 begins
   //variables
    int num1;
    int num2;

    printf( "Enter num1: " );
    scanf( "%d", &num1 );

    printf( "Enter num2: " );
    scanf( "%d", &num2 );

    Maximum(&num1, &num2);

    printf("\n");
  //Question 3 ends

 //Question 4 begins
    //variables


	 
    int inputval=0;
    int option=0;
    int val=0;
    
    printf( "Before calling IncrementUpdate\n" );
    printf("val = 0\n");
   
    while(option==0)
    {
        val=IncrementUpdate(&val);

        printf("Updating val now...\n" );
        printf("Would you like to update...\n" );
        printf("Enter 0 if you would like to update again. Anything else will exit the update\n" );

        printf("Option: ");
        scanf("%d",&option);  
            
    }

    printf( "val is now updating...\n" );
    printf( "After calling IncrementUpdate\n" );
    
    printf( "val = %d\n", val);

    
    return 0;

    
    //Question 4 ends
   
}



