#pragma once
class Account
{
private:
    double balance,
        interest,
        intRate;
    int transactions;

public:
    // Construtor
    Account(double rate = 0.045, double bal = 0.0)
    { 
        balance = bal;
        intRate = rate;
        interest = 0.0;
        transactions = 0;
    }

    // Make a method for deposit

    void makeDeposit(double amount)
    {
        balance += amount;
        transactions++;
    }

    // make a method of withdrawal

    bool withdraw(double amount); // we provide its defination in Account.cpp

    void calculateInterest()
    {
        interest = balance + intRate;
        balance += interest;
    }

    // now make a method to get balance in main

    double getBalance()
    {
        return balance;
    }

    // now make a method to get interest in main

    double getInterest()
    {
        return interest;
    }

    // now make a method to get transactions in main

    double getTransactions()
    {
        return transactions;
    }
};

bool Account::withdraw(double amount)
{
    if (balance < amount)
    {
        return false;
    }
    else
    {
        balance -= amount;
        transactions++;
        return true;
    }
}