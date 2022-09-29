//Riya Sawant
//Dr. Steinberg
//COP3223 Section 6
//Small Program 6

// Question 1 begins


#include <stdio.h>
#define MAXSize 5

void meanMinMax(int a[MAXSize])
{
 	int min,max,i;
 	float mean;
  	int sum;
   
  sum = 0;

  min=max=a[0];
 	
    for(i=1; i < MAXSize; i++)
    {
        if(min>a[i])
		       min=a[i];   
		    if(max<a[i])
		      max=a[i];       
    }
   
    for(i = 0; i < MAXSize; i++) 
    {
        sum+=a[i];
    }

    printf("Mean of array is : %.2f \n", sum/(float)MAXSize);
    printf("Minimum of array is : %d\n",min);
    printf("Maximum of array is : %d\n",max);
}
 
// Question 1 ends

// Question 2 begins

void organize(int a[MAXSize]);

void organize(int a[MAXSize])
{
    int i, j, temp;
    for(i=0;i< MAXSize-1; i++)
    {
        for(j=i+1; j< MAXSize; j++)
        {
            if(a[i]>a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    
    /* Displaying sorted array */
    printf("Array in ascending order is:\n");
    for(i=0;i< MAXSize;i++)
    {
        printf("%d\n", a[i]);
    }
}

// Question 2 ends

// Question 3 begins

void duplicate(int a[MAXSize], int b[MAXSize]);

void duplicate(int a[MAXSize], int b[MAXSize])
{
    int j;
    /* Copy elements of first array into second array.*/ 
    for(j=0; j < MAXSize; j++)
    {
        b[j] = a[j];
    }
}

// Question 3 ends

// Question 4 begins

int locate(int a[], int findvalue, int n)
{
	int k;
  	int pos=-1;
    for(k=0; k<n; k++)
   {
     if(a[k]==findvalue)
     {
	    pos= k+1;
      //printf("%d found at positionZZZZ %d\n", findvalue, pos);
     }
   }
	return pos;
}

// Question 4 ends


int main()
{
    int i,n,min,max;
    int arr1[MAXSize];

// Question 1 begins
   
    printf("Enter 5 values in the array : \n");
    for(i=0; i<MAXSize; i++)
    {
        scanf("%d",&arr1[i]);
    }

    meanMinMax(arr1);
    printf("\n\n");

// Question 1 ends   

// Question 2 begins

	printf("Enter 5 values in the array : \n");
    for(i=0; i<MAXSize; i++)
    {
        scanf("%d",&arr1[i]);
    }
 
    organize(arr1);
    printf("\n\n");

// Question 2 ends   

    
// Question 3 begins

//    int arr1[MAXSize], 
    int arr2[MAXSize];
//    int i, n;
	
    printf("Enter 5 values in the array : \n");
    for(i=0; i<MAXSize; i++)
    {
        scanf("%d",&arr1[i]);
    }
    
    duplicate(arr1,arr2);
    
    printf("\nThe values store into the array are : \n");
    for(i=0;i<MAXSize;i++)
    {
	    printf("% 5d",arr1[i]);
    }
 

    /* Prints the elements copied into the second array. */
    printf("\n\nThe elements copied into the second array are :\n");
    for(i=0; i< MAXSize; i++)
    {
        printf("% 5d", arr2[i]);
    }
	  printf("\n\n");

// Question 3 ends


// Question 4 begins

	//int i,n;
    //int arr1[MAXSize];

    int element, sizeofArray, location=0;
    
    printf("Enter size of the array : ");
    scanf("%d", &sizeofArray);

//MAXSize=n;

   printf("Enter array elements: \n");
   for(i=0; i < sizeofArray; i++)
   {
	  scanf("%d", &arr1[i]);
   }

   printf("Enter value of interest to locate : ");
   scanf("%d",&element);

   location=locate(arr1, element, sizeofArray);
   //printf("the position is %d\n",location);
   if (location > 0)
   {
       printf("%d found at position %d\n", element, location);
   }
   else 
   {
       printf("%d not found in the array\n", element);
   }
   
	printf("\n\n");


return 0;
}


