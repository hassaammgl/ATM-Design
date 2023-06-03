#include <iostream>
#include <iomanip>
#include "Account.h"

using namespace std;

// make a display menu function

void displayMenu()
{
    cout << "\n\n            MENU" << endl
         << endl
         << "1) Display the account balance" << endl
         << "2) Display the number of transactions" << endl
         << "3) Display interset earned for this period" << endl
         << "4) Make a deposit" << endl
         << "5) Make a withdraw" << endl
         << "6) Add interest for this period" << endl
         << "6) Exit" << endl
         << endl
         << "Enter your choice: ";
}

// make a method to get choice validate choice and return choice to main method

char getChoice(char max)
{
    char choice = cin.get();
    cin.ignore();

    while (choice < '1' || choice > max)
    {
        cout << "Choice must between 1 and " << max << ". "
             << "Please re-enter choice: " << endl;
        choice = cin.get();
        cin.ignore();
    }
    return choice;
}

// now make a method for deposit which has an object parameter

void makeDeposit(Account &account)
{
    double dollars;

    cout << "Enter the amount of deposit: " << endl;
    cin >> dollars;
    cin.ignore();
    account.makeDeposit(dollars);
}

// make a method of withdrawl

void withdraw(Account &account)
{
    double dollars;

    cout << "Enter the amount of withdrawl" << endl;
    cin >> dollars;
    cin.ignore();
    if (!account.withdraw(dollars)) // if ammount is invalid
    {
        cout << "ERROR: Withdraw amount is too large." << endl
             << endl;
    }
}

main()
{
    const char MAX_CHOICE = '7';
    Account savings;
    char choice;

    cout << fixed << showpoint << setprecision(2);
    do
    {
        displayMenu();
        choice = getChoice(MAX_CHOICE);
        switch (choice)
        {
        case '1':
            cout << "The current balance is $"
                 << savings.getBalance()
                 << endl;
            break;
        case '2':
            cout << "There have been "
                 << savings.getTransactions()
                 << " transactions." << endl;
            break;
        case '3':
            cout << "Interst earned from this period $"
                 << savings.getInterest()
                 << endl;
            break;
        case '4':
            makeDeposit(savings);
            break;
        case '5':
            withdraw(savings);
            break;
        case '6':
            savings.calculateInterest();
            cout << "Interest added." << endl;
            break;

        default:
            break;
        }
    } while (choice != '7');
}