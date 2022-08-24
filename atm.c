#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// FUNCTIONS
void mainMenu();

int main()
{
    int option, age, accountPin, accountNum, depositAmount, withdrawalAmount, totalAmount;
    totalAmount = 0;
    int receiptAccountNum, transferAmount;
    char receipientName[225];
    char fname[20];
    char lname[20];
    char accountType[20];
    bool again = true;

    srand(time(0));

    while (again)
    {
        mainMenu();
        printf("Enter option: ");
        scanf("%d", &option);

        system("cls");

        switch (option)
        {
        case 1:
            printf("\nEnter First Name: ");
            scanf(" %s", fname);
            printf("Enter Last Name: ");
            scanf(" %s", lname);
            printf("Enter age: ");
            scanf("%d", &age);
            printf("Enter Account type: ");
            scanf(" %s", accountType);
            printf("Create Account Pin: ");
            scanf("%d", &accountPin);

            system("cls");

            if (age >= 18)
            {
                printf("\n Account Creation Successful! \n");
                printf("Here are you details: \n\n");

                printf("Account Name: %s %s \n", fname, lname);
                printf("Account Type: %s \n", accountType);
                printf("Account Number: ");

                for (accountNum = 0; accountNum < 10; accountNum++)
                {
                    printf("%d", (rand() % 10));
                }
                printf("\n Account Pin: %d \n", accountPin);
            }
            else
            {
                printf("Account Creation failed! \n");
                printf("You are underage!\n\n");
            }
            break;
        case 2:
            printf("Deposit Amount: ");
            scanf("%d", &depositAmount);
            printf("Enter Account Pin: ");
            scanf("%d", &option);

            if (option == accountPin)
            {
                totalAmount += depositAmount;
                printf("Deposit of %d Successful!\n\n", depositAmount);
            }
            else
            {
                printf("Incorrect Pin!\n\n");
            }
            system("cls");
            break;

        case 3:
            printf("Enter Receipient Account Number: ");
            scanf("%d", &receiptAccountNum);
            printf("Enter Receipient Name: ");
            scanf("%s", receipientName);
            printf("Enter Deposit Amount: ");
            scanf("%d", &transferAmount);
            printf("Enter Account Pin: ");
            scanf("%d", &accountPin);

            if (totalAmount < transferAmount)
            {
                printf("Insufficient Balance\n\n");
            }
            else if (accountPin != accountPin)
            {
                printf("Invalid Pin \n\n");
            }
            else
            {
                printf("Transaction Successful!\n\n");
                totalAmount -= transferAmount;
            }
            break;

        case 4:
            printf("Enter Withdrwal Amount: ");
            scanf("%d", &withdrawalAmount);
            printf("Enter Account Pin: ");
            scanf("%d", &accountPin);
            break;

        default:
            printf("Invalid");
            break;
        }
    }

    return 0;
}

void mainMenu()
{
    printf("******************************* \n");
    printf("** WELCOME TO SAFE CASH BANK ** \n");
    printf("******************************* \n\n");

    printf("Press 1 - ACCOUNT CREATION \n");
    printf("Press 2 - DEPOSIT \n");
    printf("Press 3 - TRANSFER FUND \n");
    printf("Press 4 - WITHDRAW CASH \n");
    printf("Press 5 - CHANGE PAYMENT PIN \n\n");
}
