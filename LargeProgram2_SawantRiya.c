//Riya Sawant
//Dr. Steinberg
//COP 3223 Section ??
//Large Program 2


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define Bottled_Water_PRICE 1.00
#define Chips_PRICE 2.13
#define Soda_PRICE 1.12
#define Wrap_PRICE 5.31
#define Candy_Bag_PRICE 3.21
#define Cheese_Pizza_PRICE 6.24
#define Chocolate_Brownie_PRICE 1.23
#define Chocolate_Chip_Cookie_PRICE 1.15

#define reload1 1.00
#define reload5 5.00
#define reload10 10.00

char answer;
int choice2;
double totalPrice;
double balance;

void Greeting(); //welcome the user to their dining account
void DisplayMenu(); //display food menu
void Purchase(double *balance); //user will make a purchase
//void Purchase2(); //user will make a purchase
void ViewAccount(double *balance); //display current account balance of user
//void ViewAccount2();
void Transaction(double *balance, double price); //transaction with user account
//void Transaction2(double price); //transaction with user account
void Reload(double *balance); //reload your account balance
//void Reload2(); //reload your account balance


int main()
{
   
    balance=0.00;
    totalPrice = 0.00;
    char choice;
    choice2=0;
    
    Greeting();
    

	do{
		printf("*********************************************************************\n");	
	
		printf("Please select one of the following options.\n");
		printf("P: Make a Purchase at Knightstop\n");
		printf("V: View Knight's Account Summary\n");
		printf("B: Browse Inventory at Knightstop\n");
		printf("R: Reload Knight's Account\n");
		printf("E: Exit\n");
		printf("*********************************************************************\n");
		printf("Please select what you would like to do.\n");
		printf("Option Selected: ");
	  scanf(" %c", &choice);
	  choice=toupper(choice);
	      
	    printf("\n");
		switch(choice)
		{
	        case 'P':
        	    	printf("You have selected the Purchase Option.\n");
	              printf("*********************************************************************\n");
	                //Purchase2();
	                Purchase(&balance);
            		break;
        	case 'V':
        	        {
            		//ViewAccount2();
            		ViewAccount(&balance);
            		break;
        	        }
	        case 'B':
	                printf("You selected Browse Option.\n");
	                printf("*********************************************************************\n");
        	    	DisplayMenu();
            		break;
        	case 'R':
        	        printf("You have selected the Reload Knight's Account Option.\n");
        	        printf("*********************************************************************\n");
        	        //Reload2();
        	        Reload(&balance);
            		break;
       		case 'E':
              printf("*********************************************************************\n");
              printf("You are now exiting the application!\n");
            	printf("You have now $%.2lf in your account balance.\n\n", balance);
			        break;
        	
        	default:
            //		printf("*** Error:  This is not on the menu. \n");
            	break;
		}
     
    } while (choice != 'E');
  
    
	printf("Have a great day!\n");
    printf("Go Knights! Charge On!\n");
	printf("*********************************************************************\n");

	return 0;
}



void DisplayMenu()
{
	//int choice2;
    
        printf("*********************************************************************\n");
        printf("Here is what we have in stock today!\n\n");
	  
		printf("1. Bottled Water         $%.2lf \n", Bottled_Water_PRICE);
        printf("2. Chips                 $%.2lf \n", Chips_PRICE);
        printf("3. Soda                  $%.2lf \n", Soda_PRICE);
        printf("4. Wrap                  $%.2lf \n", Wrap_PRICE);
        printf("5. Candy Bag             $%.2lf \n", Candy_Bag_PRICE);
        printf("6. Cheese Pizza          $%.2lf \n", Cheese_Pizza_PRICE);
        printf("7. Chocolate Brownie     $%.2lf \n", Chocolate_Brownie_PRICE);
        printf("8. Chocolate Chip Cookie $%.2lf \n", Chocolate_Chip_Cookie_PRICE);
		    printf("*********************************************************************\n");
        
		//printf("Option Selected: %c\n",choice2);
	    
}


//void Purchase2()
void Purchase(double *balance)
{
    DisplayMenu();
    double price=0.00;
    printf("Please select what you would like to do.\n");
    printf("Option Selected: ");
    scanf("%i", &choice2);
    printf("\n");
     switch(choice2){
        case 1:
            //totalPrice += Bottled_Water_PRICE;
            price = Bottled_Water_PRICE;
            printf("Bottled Water has been selected. Total cost is: $%.2lf\n\n", price);
        
            break;
        case 2:
            //totalPrice += Chips_PRICE;
            price = Chips_PRICE;
            printf("Chips has been selected. Total cost is: $%.2lf\n\n", price);
            break;
        case 3:
            //totalPrice += Soda_PRICE;
            price = Soda_PRICE;
            printf("Soda has been selected. Total cost is: $%.2lf\n\n", price);
            break;
        case 4:
            //totalPrice += Wrap_PRICE;
            price = Wrap_PRICE;
            printf("Wrap has been selected. Total cost is: $%.2lf\n\n", price);
            break;
        case 5:
            //totalPrice += Candy_Bag_PRICE;
            price = Candy_Bag_PRICE;
            printf("Candy Bag has been selected. Total cost is: $%.2lf\n\n", price);
            break;
        case 6:
            //totalPrice += Cheese_Pizza_PRICE;
            price = Cheese_Pizza_PRICE;
            printf("Cheese Pizza has been selected. Total cost is: $%.2lf\n\n", price);
            break;
        case 7:
            //totalPrice += Chocolate_Brownie_PRICE;
            price = Chocolate_Brownie_PRICE;
            printf("Chocolate Brownie has been selected. Total cost is: $%.2lf\n\n", price);
            break;
        case 8:
            //totalPrice += Chocolate_Chip_Cookie_PRICE;
            price = Chocolate_Chip_Cookie_PRICE;
            printf("Chocolate Chip Cookie has been selected. Total cost is: $%.2lf\n\n", price);
            break;
        
        default:
            printf("*** Error:  This is not on the menu. \n");
            break;
        }
         
        //printf("Total so far: $%.2lf\n\n", totalPrice);
        //Transaction2(price);
        Transaction(balance, price);
        
}

//void Reload2()
void Reload(double *balance)
{
    //printf("%.2lf balance_value\n", *balance);
    int choice3;
    
    printf("How much would you like to reload to your Knight's Account?\n");
 
        printf("1. $1.00\n");
        printf("2. $5.00\n");
        printf("3. $10.00\n");
       
        printf("Option Selected: ");
        scanf("%i", &choice3);
        printf("*********************************************************************\n");
 
        switch(choice3)
        {
        case 1:
            *balance += reload1;
            printf("$%.2lf has been added to your Knight's Account successfully!\n\n", reload1);
            break;
        case 2:
            *balance += reload5;
            printf("$%.2lf has been added to your Knight's Account successfully!\n\n", reload5);
            break;
        case 3:
            *balance += reload10;
            printf("$%.2lf has been added to your Knight's Account successfully!\n\n", reload10);
            break;
       
        }
         
        printf("*********************************************************************\n");
	
        //printf("Your total balance is $%.2lf \n\n", *balance);
}


void Greeting()
{
	printf("*********************************************************************\n");
	printf("Welcome to UCF's Knight's Account Services!\n");
	printf("This is where you will manage your Knight's Account for all your purchasing needs at UCF!\n");
	printf("How can we help you today?\n");
	printf("*********************************************************************\n");
}

void ViewAccount(double *balance)
//void ViewAccount2()
{
	printf("You selected View Account Summary Option.\n");	
	printf("*********************************************************************\n");
	
	printf("Here is your current Knight's Account balance.\n");
	printf("You have $%.2lf in your account.\n", *balance);
	printf("*********************************************************************\n");
	//printf("balance is : $%.2lf\n\n", balance);
}


//void Transaction2(double price)
void Transaction(double *balance, double price)
{
    printf("Beginning Transaction Process.\n");	
    if (price > *balance)
    {
        do
        {
            printf("You do not have enough in your account.\n");	
            printf("Please reload your account balance.\n");
            printf("*********************************************************************\n");
            //Reload2();
            Reload(balance);
        }while(price > *balance);
    }
    
    if(price < *balance)
    {
       	
        //printf("Beginning Transaction Process.\n");
        printf("Your account balance before official transaction:$%.2lf \n\n", *balance);
        printf("Billing $%.2lf to your account.\n\n", price);
        *balance = *balance - price;
        printf("Transaction was successful!\n\n");	
        printf("You have now $%.2lf in your account balance.\n\n", *balance);	
    }
    printf("*********************************************************************\n");
	  
    
}
