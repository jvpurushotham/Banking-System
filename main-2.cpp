#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAccount {
private:

    string accountHolderName;
    int accountNumber;
    double balance;

public:

    BankAccount(string name, int number, double initialBalance) 
        : accountHolderName(name), accountNumber(number), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit Successful! New Balance: " << balance << endl;
        } else {
            cout << "Invalid Deposit Amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal Successful! New Balance: " << balance << endl;
        } else {
            cout << "Insufficient Balance or Invalid Withdrawal Amount!" << endl;
        }
    }

    void displayAccountDetails() const {
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    int getAccountNumber() const {
        return accountNumber;
    }
    
};

class Bank {
private:
    vector<BankAccount> accounts;

public:
    void createAccount(const string& name, int number, double initialBalance) {
        accounts.emplace_back(name, number, initialBalance);
        cout << "Account Created Successfully!" << endl;
    }

    BankAccount* findAccount(int accountNumber) {
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                return &account;
            }
        }
        return nullptr;
    }

    void performOperations() {
        int choice, accountNumber;
        double amount;
        string name;

        while (true) {
            cout << "\n--- Bank Menu ---\n";
            cout << "1. Create Account\n";
            cout << "2. Deposit\n";
            cout << "3. Withdraw\n";
            cout << "4. Display Account Details\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter Account Holder Name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter Account Number: ";
                    cin >> accountNumber;
                    cout << "Enter Initial Balance: ";
                    cin >> amount;
                    createAccount(name, accountNumber, amount);
                    break;

                case 2:
                    cout << "Enter Account Number: ";
                    cin >> accountNumber;
                    cout << "Enter Amount to Deposit: ";
                    cin >> amount;
                    if (BankAccount* account = findAccount(accountNumber)) {
                        account->deposit(amount);
                    } else {
                        cout << "Account Not Found!" << endl;
                    }
                    break;

                case 3:
                    cout << "Enter Account Number: ";
                    cin >> accountNumber;
                    cout << "Enter Amount to Withdraw: ";
                    cin >> amount;
                    if (BankAccount* account = findAccount(accountNumber)) {
                        account->withdraw(amount);
                    } else {
                        cout << "Account Not Found!" << endl;
                    }
                    break;

                case 4:
                    cout << "Enter Account Number: ";
                    cin >> accountNumber;
                    if (BankAccount* account = findAccount(accountNumber)) {
                        account->displayAccountDetails();
                    } else {
                        cout << "Account Not Found!" << endl;
                    }
                    break;

                case 5:
                    cout << "Exiting... Thank you for using the Bank System!" << endl;
                    return;

                default:
                    cout << "Invalid Choice! Try Again." << endl;
            }
        }
    }
    
};

int main() {
    Bank bank;
    bank.performOperations();
    
    return 0;
}