//Riya Sawant
//Dr. Steinberg
//COP3223 Section 3
//Small Program 3

//Question 1 begins

#include <stdio.h>
#include <math.h>

double Coordinates(double x, double y);

double Coordinates(double x, double y)
{
    if (x > 0 && y > 0)
        printf("(%.2f, %.2f) is in the quandrant I\n",x,y);
    else if (x < 0 && y > 0)
        printf("(%.2f, %.2f) is in the quandrant II\n",x,y);
    else if (x < 0 && y < 0)
        printf("(%.2f, %.2f) is in the quandrant III\n",x,y);
    else if (x > 0 && y < 0)
        printf("(%.2f, %.2f) is in the quandrant IV \n",x,y);
    else if (x == 0 && y == 0)
        printf("(%.2f, %.2f) is at the origin\n",x,y);
    else if (y==0)
	    printf("(%.2f, %.2f) is on the X-axis \n",x,y);
    else if (x==0)
	    printf("(%.2f, %.2f) is on the y-axis \n",x,y);
    
}

//Question 1 ends

//Question 2 begins
double Hurricane(double windspeed);
double Hurricane(double windspeed)
{
    if (windspeed >= 74 && windspeed <= 95 )
        printf("Category 1\n");
    else if (windspeed >= 96 && windspeed <= 110)
        printf("Category 2\n");
    else if (windspeed >= 111 && windspeed <= 129)
        printf("Category 3(Major)\n");
    else if (windspeed >= 130 && windspeed <= 156)
        printf("Category 4(Major)\n");
    else if (windspeed >= 157 )
        printf("Category 5(Major)\n");
    
}

//Question 2 ends

//Question 3 begins

char Menu()
{
	int choice;
	
	printf("*********************\n");
	printf("Select an option\n");
	printf("1: Blue Button\n");
	printf("2: Green Button\n");
	printf("3: Red Button\n");
	printf("4: Yellow Button\n");
	printf("*********************\n");
        printf("Option: ");
	scanf("%d",&choice);
	
    switch (choice)
	{
	    case 1: 
		{
		printf("Blue Button Selected\n");
		break;
		}
		case 2: 
		{
		printf("Green Button Selected\n");
		break;
		}
	    case 3: 
		{
		printf("Red Button Selected\n");
		break;
		}
	    case 4: 
		{
		printf("Yellow Button Selected\n");
		break;
		}
	
	default:
		printf("Wrong option");
	
	}
}

//Question 3 ends

//Question 4 begin

float NumSolutions()
{
	float a, b, c;
	float root1, root2;
	float d;

	printf("The formula to calculate the discriminant is: b*b - 4ac\n");
	printf("Enter the values of a, b, c of quadratic equation ( ax*x + bx + c) : ");
	scanf("%f%f%f",&a, &b, & c);

	d = (b*b) - ( 4 * a * c);
	
	//printf("%f\n",d);
    if (d < 0)
    {
        printf("No Solutions");
    }
    else if (d==0)
    {
        printf("One Solution");
    }
    else if (d > 0)
    {
        printf("Two Solutions");
    }
    return 0;
}

//Question 4 ends


int main(void) 
{

// Question 1 begins   
    float co1, co2;

    printf("Enter the x-coordinate: ");
    scanf("%f", &co1);
    printf("Enter the y-coordinate: ");
    scanf("%f", &co2);

    Coordinates(co1, co2);
    printf("\n");

// Question 1 ends
   
//Question 2 begins

    float speed1;

    printf("Enter the wind speed: ");
    scanf("%f", &speed1);
 
    Hurricane(speed1);
    printf("\n");

//Question 2 ends

// Question 3 begins

    Menu();
    printf("\n");
//Question 3 ends

//Question 4 begins


	NumSolutions();
	printf("\n");
	return(0);
}

// Question 4 ends