//Riya Sawant
//Dr. Steinberg
//COP3223 Section 8
//Small Program 8


//Small Program 8 Skeleton
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[50];
	int age;
}record_t;

record_t * createarray(int maxsize);
record_t * insert(record_t *myarray, int *maxsize, int *currentsize);
void display(record_t *myarray, int currentsize);
record_t *doubleit(record_t *arr, int size); //problem 1
int removerecord(record_t *arr, int size, int maxsize, int index); //problem 2


//fucntion to remove an record from Array
int removerecord(record_t *arr, int size, int maxsize, int index)

{
    if(index > size)
    {
        return size;
    }
    for(int i=index;i<size-1;i++)
    {
        arr[i]=arr[i+1];
    }
    return size-1;
}

//double it function to double array size
record_t *doubleit(record_t *arr,int size)
{
    //creating new array with double size
    //printf("\n");
    //printf("inside %d----\n",size);
    
    record_t *newarr=(record_t*)malloc(sizeof(record_t)*(size*2));

    for(int i=0;i<size;i++)
    {
        newarr[i]=arr[i];
       // printf("%d ",arr[i]);
    }
    //de allocating the old array
    free(arr);
    arr=NULL;
    //returung new array
    return newarr;
}


int main(void)
{

	int maxsize;

	printf("Enter a size for the dynamic array: ");
	scanf("%d", &maxsize);


	record_t *myarray = createarray(maxsize);
	int currentsize = 0;


	int option = -1;

	while(option != 0)
    {
        printf("What would you like to do?\n");
        printf("1: Insert a record\n");
        printf("2: Display records\n");
        printf("3: Remove record\n");
        printf("4: Exit\n");
        printf("Enter an option:");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Insert was selected...\n");
                myarray = insert(myarray, &maxsize, &currentsize);
                break;

            case 2:
                printf("Display was selected...\n");
                display(myarray, currentsize);
                break;

            case 3:
                printf("Remove was selected...\n");
                printf("Select an index of record to remove...\n");
                int index;
                scanf("%d", &index);
                currentsize = removerecord(myarray,currentsize,maxsize,index);
                break;

            case 4:
                printf("Exiting...\n");
                option = 0;
				break;

            default:
                printf("Invalid Selection...\n");


        }

    }

	free(myarray);

	myarray = NULL;

	return 0;
}

record_t * createarray(int maxsize)
{
	return (record_t *) malloc(maxsize * sizeof(record_t));
}



record_t * insert(record_t *myarray, int *maxsize, int *currentsize)
{
	if(*maxsize == *currentsize)
	{
		printf("Array is full...Need to doubleit...\n");
		myarray = doubleit(myarray, *maxsize);
	
	    *maxsize = *maxsize * 2;
    
	}

    printf("Enter the last name: ");
	scanf("%s", myarray[*currentsize].name);

	printf("Enter an age: ");
	scanf("%d", &myarray[*currentsize].age);

	++*currentsize;

	return myarray;
}

void display(record_t *myarray, int currentsize)
{
	printf("---------------------------------\n");

	for(int x = 0; x < currentsize; ++x)
	{
	    printf("myarray[%d].name = %s\n", x, (x + myarray)->name); //try it with myarray[x].name
		printf("myarray[%d].age = %d\n", x, (x + myarray)->age); //try it with myarray[x].age
	}

	printf("---------------------------------\n");


}

