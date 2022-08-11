//Riya Sawant
//Dr. Steinberg
//COP3223 Section 2
//Small Program 2



#include <stdio.h>
#include <math.h>
#include <features.h>

//Question 1 begins

double Hypotenuse(double a, double b);



double Hypotenuse(double a, double b) 
{
    double z = sqrt(a * a + b*b);
    return z;
}

//Question 1 ends



//Question 2 begins



float Parkingcharge();

float Parkingcharge()
{
	
	float charge= 2.49;
	float totalcharge;
        float totalhours;

    	printf("Enter the hours you plan to leave your car parked in the parking garage : ");
	scanf("%f",&totalhours);
	
	if(totalhours > 0)
	{
    		totalcharge =(totalhours * charge) ;
	}
	
	printf("The number of hours are : %.2f\n", totalhours);
	printf("The amount charged is : $%.2f\n", totalcharge);
	
}
//Question 2 ends

//Question 3 begins


double Population(int year) 
{
    int valid_year;
    int years_after_1990;
   
    double POPULATION_1990 = 52.966;

    years_after_1990 = year - 1990;
    double projected_population = POPULATION_1990 + ( 2.184 * years_after_1990);
    printf("Predicited Gotham City population for %d (in thousands) : %.3f\n",year, projected_population);
   
}
//Question 3 ends


//Question 4 begins

double FactorialApprox(int numvalue)
{
	double numvalue1 = (double)(numvalue);
	double compuvalue;
	const double PI = 3.141592659;
	
	double n1 = pow(numvalue1, numvalue1) ;
	double n2 = exp(-numvalue1);
	double n3 = ((2 * numvalue1) + .333334);
	double n4 = n3 * PI;
	double n5 =  sqrt(n4);
	
	compuvalue= n1 * n2 * n5;
		
	return compuvalue;
}

//Question 4 ends


int main(void) 
{
    
// Question 1 begins    
    double side1, side2;

    printf("Enter values for two sides: ");
    scanf("%lf %lf", &side1, &side2);
    printf("%.2f\n", Hypotenuse(side1, side2));
// Question 1 ends


// Question 2 begins

     Parkingcharge();

// Question 2 ends

// Question 3 begins

    int year;
    char incorrect = 'y';
    
    while (incorrect !='n' && incorrect != 'N') {
        printf("Enter a year after 1990 > ");
        scanf(" %d", &year);
     
        if (year <= 1990) {
            printf("Please enter a year greater than 1990 >\n");
            incorrect = 'y';
        } else {
            incorrect = 'n';
            Population(year); 
        }
    }
    
// Question 3 ends

// Question 4 begins

    int value1;
	double result1;

	printf("Enter a value for n> ");
	scanf("%d",&value1);
	
	printf("%d ! equals approximately %.5f\n", value1, FactorialApprox(value1));

// Question 4 ends

    return 0;
    
}

