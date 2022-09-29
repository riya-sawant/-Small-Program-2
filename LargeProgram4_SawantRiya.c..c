//Riya Sawant
//Dr. Steinberg
//COP 3223C Section ??
//Large Program 4


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>


typedef struct{
	int id;
   	char fname[50];
	char lname[50];
	char house[50];
	double gpa;
}student;

void welcomeinfo(); 

student * createarray(int maxsize);

student * insert(student *studentrecord, int *maxsize, int *currentsize); // Insert new record

void displayrecords(student *studentrecord, int currentsize); // display records

void lookuprecord(student *studentrecord, int currentsize); // lookup record

void savetofile(student *studentrecord, int currentsize); // save to file

student * init(student *studentrecord, int *currentsize); // initialize array

int removerecord(student *studentrecord, int currentsize); // remove record

int removerecord(student *studentrecord, int currentsize)
{
    char tempfnameval[50];
    char templnameval[50];
    int n=0;
    int m=0;
    int i=0;
    int check2=0;
    
    printf("\n\n*************************************************************\n\n");
	printf("\n\nRemoving Student Function Invoked");
	
    printf("\n\nEnter the student's first name: ");
    scanf("%s", tempfnameval);
    	
    printf("\n\nEnter the student's last name: ");
	scanf("%s", templnameval);

    for(int m = 0; m < currentsize; m++)
    {
	    if((strcmp(studentrecord[m].fname,tempfnameval) == 0) && (strcmp(studentrecord[m].lname,templnameval) == 0))
	    {
		    for(int i = m ; i < currentsize-1 ; i++ )
                {
                    studentrecord[i] = studentrecord[i+1];
                }
                check2=1;
	    }
    }
    
    
  if (check2==0)
	{
	    printf("\nSorry, This record is not present in the system.\n");
	    //return currentsize;
	}
    else if(check2 ==1)
    {
        //return currentsize-1;
        currentsize--;
    }
    //printf("%d", currentsize);
    return currentsize;
}



student * createarray(int maxsize)
{
	return (student *) malloc(maxsize * sizeof(student));
}

student * init(student *studentrecord, int *currentsize)
{
	studentrecord[0].id=1;
	strcpy(studentrecord[0].fname , "Harry");
	strcpy(studentrecord[0].lname , "Potter");
	strcpy(studentrecord[0].house , "Gryffindor");
	studentrecord[0].gpa=3.87;

	++*currentsize;

  studentrecord[1].id=2;
	strcpy(studentrecord[1].fname , "Ron");
	strcpy(studentrecord[1].lname , "Wesley");
	strcpy(studentrecord[1].house , "Gryffindor");
	studentrecord[1].gpa=3.01;

	++*currentsize;
	
	studentrecord[2].id=3;
	strcpy(studentrecord[2].fname , "Hermonie");
	strcpy(studentrecord[2].lname , "Granger");
	strcpy(studentrecord[2].house , "Gryffindor");
	studentrecord[2].gpa=4.00;

	++*currentsize;
	
	studentrecord[3].id=4;
	strcpy(studentrecord[3].fname , "Draco");
	strcpy(studentrecord[3].lname , "Malfoy");
	strcpy(studentrecord[3].house , "Slytherin");
	studentrecord[3].gpa=2.57;

	++*currentsize;
	
	studentrecord[4].id=5;
	strcpy(studentrecord[4].fname , "Luna");
	strcpy(studentrecord[4].lname , "Lovegood");
	strcpy(studentrecord[4].house , "Ravenclaw");
	studentrecord[4].gpa=3.42;

	++*currentsize;
	
	studentrecord[5].id=6;
	strcpy(studentrecord[5].fname , "Cedric");
	strcpy(studentrecord[5].lname , "Diggory");
	strcpy(studentrecord[5].house , "Hufflepuff");
	studentrecord[5].gpa=3.38;

	++*currentsize;

	return studentrecord;
}


void displayrecords(student *studentrecord, int currentsize)
{
	for(int i=0; i < currentsize; i++ )
    {
       printf("Id:           %d\n",studentrecord[i].id);
       printf("First Name:   %s\n",studentrecord[i].fname);
       printf("Last Name:    %s\n",studentrecord[i].lname);
       printf("House:        %s\n",studentrecord[i].house);
       printf("GPA:          %.2f\n",studentrecord[i].gpa );
       
       printf("\n");
       printf("++++++++++++++++++++++++++++++++++++++++\n");
    }
}


void lookuprecord(student *studentrecord, int currentsize)
{
      char fnameval2[50];
      char lnameval2[50];
      int check=0;

      printf("\n\nEnter the student's first name: ");
      scanf("%s", fnameval2);
    	
    	printf("\n\nEnter the student's last name: ");
		  scanf("%s", lnameval2);

      for(int i = 0; i < currentsize; i++)
    	{
		    if((strcmp(studentrecord[i].fname,fnameval2) == 0) && (strcmp(studentrecord[i].lname,lnameval2) == 0))
		    {
		        printf("\n\nHere is the student info.\n\n");
		        printf("++++++++++++++++++++++++++++++++++++++++\n\n");
		        
		        printf("Id:           %d\n",studentrecord[i].id);
                printf("First Name:   %s\n",studentrecord[i].fname);
                printf("Last Name:    %s\n",studentrecord[i].lname);
                printf("House:        %s\n",studentrecord[i].house);
                printf("GPA:          %.2f\n",studentrecord[i].gpa );
	
		        printf("++++++++++++++++++++++++++++++++++++++++\n\n");
		        check=1;
		    }
	    }
	    if (check==0)
		{
		    printf("\nSorry, This record is not present in the system.\n");
		}
}

student * insert(student *studentrecord, int *maxsize, int *currentsize)
{
    double gpaval;
    char fnameval[50];
    char houseval[50];
    int choice2;
    
	if(*maxsize == *currentsize)
	{
		printf("We can not add any more records...\n");
	}
	else
  {
      //printf("currentsize:           %d\n",*currentsize);
      //printf("Id:           %d\n",studentrecord[*currentsize-1].id );
      
      studentrecord[*currentsize].id=studentrecord[*currentsize-1].id + 1;
    	
      printf("\nEnter the student's first name: ");
    	scanf("%s", fnameval);
		
		  strcpy(studentrecord[*currentsize].fname , fnameval);
		  printf("\nEnter the student's last name: ");
		  scanf("%s", studentrecord[*currentsize].lname);

        printf("\nPlease select one of the following for the student's house.\n");
		    printf("\n1. Gryffindor\n");
        printf("\n2. Hufflepuff\n");
        printf("\n3. Ravenclaw\n");
        printf("\n4. Slytherin\n");
        printf("\nEnter key: ");
        scanf("%i", &choice2);
        
        
        switch(choice2){
        case 1:
            strcpy( houseval, "Gryffindor");
            
            printf("\n\n%s Selected.\n\n", houseval);
            strcpy(studentrecord[*currentsize].house , houseval);
	
            break;
        case 2:
            strcpy( houseval,"Hufflepuff");
            printf("\n\n%s Selected.\n\n", houseval);
            strcpy(studentrecord[*currentsize].house , houseval);
	
            break;
        case 3:
            strcpy( houseval,"Ravenclaw");
            printf("\n\n%s Selected.\n\n", houseval);
            strcpy(studentrecord[*currentsize].house , houseval);
	
            break;
        case 4:
            strcpy( houseval, "Slytherin");
            printf("\n\n%s Selected.\n\n", houseval);
            strcpy(studentrecord[*currentsize].house , houseval);
	
            break;
        default:
            printf("*** Error:  This is not on the menu. \n");
            break;
        }    
            
		printf("What is the %s's GPA: ",fnameval);
		//scanf(" %.2f", &gpaval);
		scanf("%lf", &gpaval);
		printf("\n\n");
		studentrecord[*currentsize].gpa=(double)gpaval;

		++*currentsize;
	}

	return studentrecord;
}

void savetofile(student *studentrecord, int currentsize)
{
    FILE *fp = NULL;
    int i=0;
    int n,idval;
    double gpaval;
    char fnameval[50];
    char houseval[50];
    char lnameval[50];
    
    fp = fopen("Records.txt","wb+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    
    //fwrite (&studentrecord, sizeof(struct student), 1, fp);

    for (i = 0; i < currentsize; ++i) 
    {
        idval=studentrecord[i].id;
        strcpy(fnameval, studentrecord[i].fname );
	    strcpy(lnameval, studentrecord[i].lname );
	    strcpy(houseval, studentrecord[i].house );
	    gpaval=studentrecord[i].gpa; 
	    double gpaval2 = roundf(gpaval * 100) / 100;  
	    
	    fprintf(fp, "Id: %d \tFirstName: %s\t LastName:: %s \tHouse: %s \tGPA: %.2f\n", idval, fnameval, lnameval, houseval,gpaval2);
	    
    }

    fclose(fp);
    
}

    
   


int main()
{
	int size, i=0;
	int currentsize = 0;
	int maxsize;
	maxsize=30;

	student *studentrecord = createarray(30);

	init(studentrecord, &currentsize);

	welcomeinfo();
	char choice;
	
	do{
		printf("\n*************************************************************\n\n");
		printf("What would you like to do?\n\n");
		printf("A: Add Student Record\n\n");
		printf("R: Remove Student Record\n\n");
		printf("D: Display All Student Records\n\n");
		printf("L: Lookup Student Record\n\n");
		printf("E: Exit Program\n\n");

		printf("Enter here: ");
		scanf(" %c", &choice);
		choice=toupper(choice);

	
		switch(choice)
		{
	        case 'A':
        	    	printf("\n\n*************************************************************\n\n");
	              printf("Adding new student to the system.\n");
	              studentrecord = insert(studentrecord, &maxsize, &currentsize);
                
            		break;
        	case 'R':
			          printf("\n\n*************************************************************\n\n");
	                printf("Removing student from the system.\n");
	                currentsize = removerecord(studentrecord,currentsize);
                

            		break;
		    case 'D':
		            printf("\n\n*************************************************************\n\n");
	                printf("Displaying all student records.\n");
			            displayrecords(studentrecord, currentsize);

            		break;
		    case 'L':
			          printf("\n\n*************************************************************\n\n");
	              printf("Looking up a student record.\n");
			          lookuprecord(studentrecord, currentsize);

            		break;
		    case 'E':
            		printf("\n\n*************************************************************\n\n");
	                printf("Exiting the system and saving records to a text file called Records.txt.\n");
	                savetofile(studentrecord, currentsize);
            		
			break;
        	
        	default:
            		printf("*** Error:  This is not on the menu. \n");
            		break;
		}


	 } while (choice != 'E');
	
	free(studentrecord);
	
	studentrecord = NULL;

	return 0;
}


void welcomeinfo(void)
{
	printf("Welcome to the Hogwarts School Student Record System!\n");
	
}

