#include <stdio.h>
#include <stdbool.h>


void displayFoodItems() 
{
    printf("Available Food Items:\n");
    printf("1. Pizza - $10.99\n");
    printf("2. Burger - $5.49\n");
    printf("3. Pasta - $7.99\n");
    printf("4. Salad - $4.99\n");
}


void getUserSelection(int *item, int *quantity) 
{
    printf("Enter the item number you want to order: ");
    scanf("%d", item);
    printf("Enter the quantity: ");
    scanf("%d", quantity);
}


float calculateTotalBill(int order[], int quantities[], int itemCount) 
{
    float prices[] = {10.99, 5.49, 7.99, 4.99};
    float totalBill = 0.0;
    int i;
    for ( i = 0; i < itemCount; i++) 
	{
        totalBill += prices[order[i] - 1] * quantities[i];
    }
    return totalBill;
}

int main() 
{
    int order[100], quantities[100];
    int itemCount = 0;
    char more;

    printf("Welcome to the Food Ordering System!\n");

    do {
        displayFoodItems();

        
        getUserSelection(&order[itemCount], &quantities[itemCount]);
        itemCount++;

        
        float totalBill = calculateTotalBill(order, quantities, itemCount);
        printf("Current total bill: $%.2f\n", totalBill);

        
        printf("Do you want to order more items? (y/n): ");
        scanf(" %c", &more);
    } while (more == 'y' || more == 'Y');

    int i;
    printf("\nFinal Order Summary:\n");
    for (i= 0; i < itemCount; i++) 
	{
        switch (order[i]) {
            case 1:
                printf("Pizza x %d - $%.2f\n", quantities[i], 10.99 * quantities[i]);
                break;
            case 2:
                printf("Burger x %d - $%.2f\n", quantities[i], 5.49 * quantities[i]);
                break;
            case 3:
                printf("Pasta x %d - $%.2f\n", quantities[i], 7.99 * quantities[i]);
                break;
            case 4:
                printf("Salad x %d - $%.2f\n", quantities[i], 4.99 * quantities[i]);
                break;
            default:
                printf("Invalid item selected\n");
                break;
        }
    }

   
    float totalBill = calculateTotalBill(order, quantities, itemCount);
    printf("\nTotal Bill: $%.2f\n", totalBill);
    printf("Thank you for your order!\n");

    
}

