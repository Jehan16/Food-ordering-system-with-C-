#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	// variables
	int option, amount, num1, totamount;
	float bill, tot, discount, tempbill;
	float order[25];
	char burgerType, cont, mealType;
	char password[20];
	char receipt[3];
	char odnumber[][26] = {"B001", "B002", "B003", "B004", "B005", "B006", "B007", "B008", "B009", "B010", "B011", "B012", "B013", "B014", "B015", "B016", "B017", "B018", "B019", "B020", "B021", "B022", "B023", "B024", "B025"};
	
	int i;
	for (i = 0; i < sizeof(order)/sizeof(order[0]); i++) {
		order[i] = 0;
	}
	
	for (i = 0; i < 25;) {
		// menue
		printf("Welcome to Tasty Burgers \n");
		printf("Place your order here... \n");
		printf("\t 1. Order Meals \n");
		printf("\t 2. Order Burger \n");
		printf("\t 3. Order Chips \n");
		printf("\t 4. Order Cold Drinks \n");
		printf("\t 5. Process Order \n");
		printf("\t 6. Cancel \n");
		printf("\t 7. Exit \n\n");
		
		// select the options
		printf("Select your option: \n");
		scanf("%d", &option);
		
		// check the option
		if (option == 2) {
			while (1) {
				printf("\nSelect the burger type \n");
				printf("A - Chicken Burger - 15$ \n");
				printf("B - Ham Burger - 17$ \n");
				printf("C - Vegie Burger - 13$ \n");
				printf("X - To return to Main Menu \n\n");
				printf("Select your buger type \n");
				scanf("%*c%c", &burgerType);
				
				if(burgerType == 'A') {
					// amount of burgers
					printf("You have selected Chicken Burger. How many burgers you wish you order? \n");
					scanf("%d", &amount);
					totamount += amount;
					
					//calculate the bill for the order
					tempbill = amount * 15;
				} else if (burgerType == 'B') {
					// amount of burgers
					printf("You have selected Ham Burger. How many burgers you wish you order? \n");
					scanf("%d", &amount);
					totamount += amount;
					
					//calculate the bill for the order
					tempbill = amount * 17;
				} else if (burgerType == 'c') {
					// amount of burgers
					printf("You have selected Vegie Burger. How many burgers you wish you order? \n");
					scanf("%d", &amount);
					totamount += amount;
					
					//calculate the bill for the order
					tempbill = amount * 13;
				} else if (burgerType == 'X') {
					break;
				} else {
					printf("Invalid Input! \n\n");
				}
				
				printf("Your current bill value is $%.2f \n\n", tempbill);
				bill += tempbill;
				printf("Press \"Y\" to add more burgers into your order or Press \"N\" to process your order now.");
				scanf("%*c%c", &cont);
				if (cont == 'Y') {
					continue;
				} else if (cont == 'N') {
					break;
				}
			}
			
		} else if (option == 6) {
			printf("Please enter your Receipt Number. \n");
			scanf("%s", receipt);
			int h;
			int index;
			for (h = 0; h < sizeof(odnumber)/sizeof(odnumber[0]); h++) {
				int vall = strcmp(receipt, odnumber[h]);
	        	if (vall == 0) {
		            index = h;
		            break;
        		}
    		}
			order[index] = 0;
			printf("Your order has been cancelled. Thank you. \n");
			printf("<<Press Any key to show the main menue>> \n\n");
			getch();
		} else if (option == 7) {
			break;
		} else if (option == 1) {
			int selectMeal = 1;
			while (selectMeal) {
				printf("\nSelect the Meal Type \n");
				printf("A - Big Chicken Meal - 20$ \n");
				printf("B - Big Ham Meal - 22$ \n");
				printf("C - Big Vegie Meal - 18$ \n");
				printf("X - To return to Main Menu \n\n");
				
				printf("Select your meal type \n");
				scanf("%*c%c", &mealType);
				
				if (mealType == 'A') {
					printf("You have selected Big Chicken Meal. How many meals you wish you order? \n");
					scanf("%d", &amount);
					
					bill += amount * 20;
					printf("Your current bill value is $%.2f \n\n", bill);
				} else if (mealType == 'B') {
					printf("You have selected Big Ham Meal. How many meals you wish you order? \n");
					scanf("%d", &amount);
					
					bill += amount * 22;
					printf("Your current bill value is $%.2f \n\n", bill);
				} else if (mealType == 'C') {
					printf("You have selected Big vegi Meal. How many meals you wish you order? \n");
					scanf("%d", &amount);
					
					bill += amount * 18;
					printf("Your current bill value is $%.2f \n\n", bill);
				} else if (mealType == 'X') {
					break;
				}
				printf("Press \"Y\" to add more meals into your order or Press \"X\" to go back to the previous menu. \n");
				scanf(" %c", &cont);
				
				if (cont == 'Y') {
					continue;
				} else if (cont == 'X') {
					selectMeal = 0;
				}
			}
		} else if (option == 3) {
			printf("You have selected Chips. How many chips you wish you order? \n");
			scanf("%d", &amount);
			
			bill += amount * 5;
			printf("Your current bill value is $%.2f \n", bill);
		} else if (option == 4) {
			printf("You have selected Cold Drinks. How many Cold Drinks you wish you order? \n");
			scanf("%d", &amount);
			
			bill += amount * 5;
			printf("Your current bill value is $%.2f \n", bill);
		} else if (option == 5) {
			// display the bill
			printf("Your total bill value is $%.2f \n", bill);
			if (bill > 100) {
				discount = bill * 0.15;
				printf("Discount 15%% - $%.2f \n", discount);
				printf("Final bill value is $%.2f\n", bill - discount);
			} else if (totamount >= 5) {
				discount = bill * 0.1;
				printf("Discount 10%% - $%.2f \n", discount);
				printf("Final bill value is $%.2f\n", bill - discount);
			}
			bill -= discount;
			order[i] = bill;
			printf("Your recipt number is %s \n", odnumber[i]);
			printf("Please go to a register and make the payment by quoting the Receipt Number - %s \n\n", odnumber[i]);
			printf("<<Press Any key to show the main menue>> \n\n");
			getch();
			bill = 0;
			totamount = 0;
			i++;
		} else if (option == 9) {
			printf("Enter the password: \n");
			scanf("%s", password);
			
			int val = strcmp("TastyBurger", password);
			if (val == 0) {
				//	calculate the total ammount for all the bills
				int j;
				for (j = 0; j < sizeof(order)/sizeof(order[0]); j++) {
					tot += order[j];
				}
				printf("\nPassword Accepted\n");
				printf("Total Revenue for today: $%.2f \n", tot);
				printf("<<Press Any key to show the main menue>> \n\n");
				getch();
				tot = 0;
			} else {
				printf("Invalid Password \n");
				printf("<<Press Any key to show the main menue>> \n\n");
				getch();
			}
		}
	}
	
	return 0;
}
