#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
	srand(time(0));
	int input;
	int lastIndex = 0;
	char name[100][100] = {};
	char destination[100][100] = {};
	char type[100][100] = {};
	int quantity[100] = {};
	char date[100][100] = {};
	int random[10] = {5,10,15,20,25,30,35,40,45,50};
	int disc;
	float harga[lastIndex] = {};
	int choice = 0;
	
	do {
		puts("===================");
		puts("| Bluejack Pillow |");
		puts("===================");
		printf("\n");
		puts("1. Order Pillow");
		puts("2. View Order");
		puts("3. Remove Order");
		puts("4. Exit");
		printf(">> ");
		scanf("%d", &input);
		getchar();
		
		if (input == 1) {
			do {
				printf("Input user name [10-25 chars]: ");
				scanf("%[^\n]", name[lastIndex]);
				getchar();
			} while (strlen(name[lastIndex]) < 10 || strlen(name[lastIndex]) > 25);
			
			int x = 0;
			do {
				x = 0;
				printf("Input destination [Alphanumeric and spaces only] [Cannot end with space]: ");
				scanf("%[^\n]", destination[lastIndex]);
				getchar();
				
				for (int i = 0; i < strlen(destination[lastIndex]); i++) {
                    if (isalnum(destination[lastIndex][i]) == 0) {
                    	x++;
					}
                }
			} while (destination[lastIndex][0] == ' ' || destination[lastIndex][strlen(destination[lastIndex]) - 1] == ' ' || x > 0);
			
			do {
				printf("Input Pillow Type [Feather | Latex | Microfiber]: ");
				scanf("%s", type[lastIndex]);
				getchar();
				if (strcmp(type[lastIndex], "Feather") == 0 || strcmp(type[lastIndex], "Microfiber") == 0 || strcmp(type[lastIndex], "Latex") == 0) break;
			} while (strcmp(type[lastIndex], "Feather") != 0 || strcmp(type[lastIndex], "Microfiber") != 0 || strcmp(type[lastIndex], "Latex") != 0);
			
			do {
				printf("Input Quantity [between 1-10]: ");
				scanf("%d", &quantity[lastIndex]);
				getchar();
			} while (quantity[lastIndex] < 1 || quantity[lastIndex] > 10);
			
			int y;
			do {
				y = 0;
				printf("Input order date [dd/mm/yyyy]: ");
				scanf("%s", &date[lastIndex]);
				getchar();
				for (int i = 0; i < strlen(date[lastIndex]); i++) {
					if (isdigit(date[lastIndex][i] == 0)) {
						y++;
					}
				}
			} while (date[lastIndex][2] != '/' || date[lastIndex][5] != '/' || y != 0);
			
			disc = random[rand() % 10];
			harga[lastIndex] = 100000;
			if (strcmp(type[lastIndex], "Feather") == 0) harga[lastIndex] += 350000;
			if (strcmp(type[lastIndex], "Latex") == 0) harga[lastIndex] += 150000;
			if (strcmp(type[lastIndex], "Microfiber") == 0) harga[lastIndex] += 250000;
			harga[lastIndex] = harga[lastIndex] * quantity[lastIndex];
			harga[lastIndex] = harga[lastIndex] - ((float) disc/100 * harga[lastIndex]);
			
			printf("\n");
			puts("Thank you for your order....");
			printf("Congrats, %d%% was deducted from ur purchase!\n", disc);
			printf("Amount to be paid: %.2f\n", harga[lastIndex]);
			printf("Press any key to continue...");
			getchar();
			
			lastIndex++;
			
		} else if (input == 2) {
			if (lastIndex == 0) {
				printf("There is no order yet...\n");
				getchar();
				continue;
			} else {
				puts("===================================================================================================================");
				puts("| No. | Item                        | Destination    | Type          | Quantity   | Date          | Price         |");
				puts("===================================================================================================================");
				for (int i = 0; i < lastIndex; i++) {
					printf("| %-3d | %-27s | %-14s | %-13s | %-10d | %-13s | %-13.2f |\n", i+1, name[i], destination[i], type[i], quantity[i], date[i], harga[i]);
				}
				puts("===================================================================================================================");
				
				puts("Enter any key to continue...");
				getchar();
			}
		} else if (input == 3) {
			if (lastIndex == 0) {
				printf("There is no order yet...\n");
				getchar();
				continue;
			} else {
				puts("===================================================================================================================");
				puts("| No. | Item                        | Destination    | Type          | Quantity   | Date          | Price         |");
				puts("===================================================================================================================");
				for (int i = 0; i < lastIndex; i++) {
					printf("| %-3d | %-27s | %-14s | %-13s | %-10d | %-13s | %-13.2f |\n", i+1, name[i], destination[i], type[i], quantity[i], date[i], harga[i]);
				}
				puts("===================================================================================================================");
				printf("\n");
				
				do {
					printf("Choose the number to remove [1...%d] [0 to return to main menu]: ", lastIndex);
					scanf("%d", &choice);
				} while (choice < 1 || choice > lastIndex);
				
				if (choice == 0) {
					printf("Cancelling...");
					getchar();
					continue;
				} else {
					for (int i = choice-1; i < lastIndex-1; i++) {
						strcpy(name[i], name[i+1]);
						strcpy(type[i], type[i+1]);
						strcpy(date[i], date[i+1]);
						strcpy(destination[i], destination[i+1]);
					}
					for (int j = choice-1; j < lastIndex; j++) {
						quantity[j] = quantity[j+1];
						harga[j] = harga[j+1];
					}
					lastIndex--;
				}
			}
		} else if (input == 4) {
			printf("Thanks for using this app! :D\n");
		} else {
			printf("Please input a valid number.\n");
			getchar();
			continue;
		}
	} while (input != 4);
	
	return 0;
}
