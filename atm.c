#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// FUNCTIONS
void mainMenu();
void menuExit();

int main()
{
    int option, age, accountPin, accountNum, depositAmount, withdrawalAmount, totalAmount;
    totalAmount = 0;
    int receiptAccountNum, transferAmount, newAccountPin, choose;
    char receipientName[225];
    char fname[20];
    char lname[20];
    char accountType[20];
    bool again = true;

    srand(time(0));

    // insert code here...

    while (again)
    {
        mainMenu();
        printf("Enter option: ");
        scanf("%d", &option);

        system("cls");

        switch (option)
        {
        case 1: // create account...
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
                printf("\n Account Pin: %d \n\n\n", accountPin);
            }
            else
            {
                printf("Account Creation failed! \n");
                printf("You are underage!\n\n");
            }
            break;

        case 2: // deposit money
            printf("Deposit Amount: ");
            scanf("%d", &depositAmount);
            printf("Enter Account Pin: ");
            scanf("%d", &option);

            system("cls");

            if (option == accountPin)
            {
                totalAmount += depositAmount;
                printf("Deposit of %d Successful!\n\n", depositAmount);

                // generate receipt
                FILE *fpointer = fopen("deposit.pdf", "w");
                fprintf(fpointer, "You Deposited %d Successfully!", depositAmount);
                fclose(fpointer);
            }
            else
            {
                printf("Incorrect Pin!\n\n");
            }

            break;

        case 3: // transfer funds
            printf("Enter Receipient Account Number: ");
            scanf("%d", &receiptAccountNum);
            printf("Enter Receipient Name: ");
            scanf("%s", receipientName);
            printf("Enter Transfer Amount: ");
            scanf("%d", &transferAmount);
            printf("Enter Account Pin: ");
            scanf("%d", &accountPin);

            if (totalAmount < transferAmount)
            {
                printf("Insufficient Balance\n\n");
            }
            else
            {
                printf("Transaction Successful!\n\n");
                totalAmount -= transferAmount;

                // generate receipt
                FILE *fpointer = fopen("transfer.pdf", "a");
                fprintf(fpointer, "Transferred the sum of $%d to the following details: \n", transferAmount);
                fprintf(fpointer, "Account Name: %c \n", receipientName);
                fprintf(fpointer, "Account Number: %d", receiptAccountNum);
                fclose(fpointer);
            }
            break;

        case 4: // withdraw funds
            printf("Enter Withdrwal Amount: ");
            scanf("%d", &withdrawalAmount);
            printf("Enter Account Pin: ");
            scanf("%d", &accountPin);

            if (totalAmount < withdrawalAmount)
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
                totalAmount -= withdrawalAmount;

                // generate receipt
                FILE *fpointer = fopen("withdraw.pdf", "w");
                fprintf(fpointer, "You Withdrew %d Successfully!", withdrawalAmount);
                fclose(fpointer);
            }
            break;

        case 5: // change account pin
            printf("Enter Old Account Pin: ");
            scanf("%d", &accountPin);
            printf("Enter New Account Pin");
            scanf("%d", &newAccountPin);

            if (accountPin == accountPin)
            {
                printf("Pin Changed Successful!\n");
                accountPin = newAccountPin;
            }
            else
            {
                printf("Failed!\n\n");
            }

            break;

        case 6: // check balance
            printf("Your Current Balance: $%d\n\n", totalAmount);
            break;
        default:
            printf("Invalid Operation");
            break;
        }

        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Would you like to do another transaction:\n");
        printf("< 1 > Yes\n");
        printf("< 2 > No\n\n");

        printf("Enter Option: ");
        scanf("%d", &choose);

        system("CLS");

        if (choose == 2)
        {
            again = false;
            menuExit();
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
    printf("Press 5 - CHANGE PAYMENT PIN \n");
    printf("Press 6 - CHECK BALANCE \n\n");
} // main menu

void menuExit()
{
    printf("--------------Take your receipt!!!------------------\n");
    printf("-----Thank you for using ATM Banking Machine!!!-----\n");
    printf("-----BROUGHT TO YOU BY sourcecode.com-----\n");

} // exit menu
