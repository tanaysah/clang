#include <stdio.h>
int main() {
    int shares;
    double profit, currentPrice, purchasePrice;
    
    printf("Enter the number of shares: ");  // Prompt user for number of shares
    // Read the number of shares from user input
    scanf("%d", &shares);
    // Prompt user for current price per share  
    printf("Enter the current price per share: ");     // Prompt user for current price
    // Read the current price from user input
    scanf("%lf", &currentPrice);        //  Read the current price from user input
    
    printf("Enter the purchase price per share: "); // Prompt user for purchase price
    scanf("%lf", &purchasePrice); // Read the purchase price from user input
    
    profit = (currentPrice - purchasePrice) * shares;  // Calculate profit by multiplying the difference between current price.
        printf("Total profit: $%.2lf\n", profit); // Print the total profit formatted to two decimal places
    
    return 0;
}
