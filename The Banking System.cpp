#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

int numberOfAccounts = 2; // Initialize with 2 pre-existing accounts
int accountNumber[100];
string accountUser[100];
double accountBalances[100];
string accountPasswords[100];
string transactionHistory[100][100];
int transactionCount[100] = {0};
double loanAmounts[100] = {0.0};
double loanInterestRates[100] = {5.0};
bool loanStatus[100] = {false};

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void displayMenu() {
	system("cls");
	setColor(10);
    cout << "\t   ____\n";
    cout << "\t /     \\   \n";
    cout << "\t| BANK |\n";
    cout << "\t ____ /\n"; 
    cout << " ----------------------- \n";
    cout << "|  THE BANKING SYSTEM   |\n";
    cout << "|-----------------------|\n";
    cout << "| 1. Create Account     |\n";
    cout << "| 2. Login              |\n";
    cout << "| 3. Exit               |\n";
    cout << "|                       |\n";
    cout << " -----------------------\n";
}

void createAccount() {
	system("cls");
	setColor(10);
	
	cout << "|---------------------------|\n";
	cout << "|    CREATE ACCOUNT MENU    |\n";
    cout << "|---------------------------|\n";
    cout << "Enter the User's name: ";
    cin.ignore();
    getline(cin, accountUser[numberOfAccounts]);
    cout << "Enter the account number: ";
    cin >> accountNumber[numberOfAccounts];
    cout << "Enter password: ";
    cin >> accountPasswords[numberOfAccounts];
    accountBalances[numberOfAccounts] = 0.0;
    transactionHistory[numberOfAccounts][0] = "Initial deposit of $0.0";
    transactionCount[numberOfAccounts] = 1;
    numberOfAccounts++;
    cout << "Account created successfully!\n";
    cout << "|---------------------------|\n";
    cout << " ---------------------------\n";
}
    bool found = false;
    int loggedInAccount = -1;
    
void login(){
	system("cls");
	setColor(10);
	cout << " ---------------------------\n";
	cout << "|     LOGIN ACCOUNT MENU    |\n";
    cout << " ---------------------------\n";
    cout << "Enter account number: ";
    int number;
    cin.ignore();
    cin >> number;
    cout << "Enter password: ";
    string password;
    cin >> password;
         
    for (int i = 0; i < numberOfAccounts; i++) {
        if (accountNumber[i] == number && accountPasswords[i] == password) {
            found = true;
            loggedInAccount = i;
            break;
        }
    }
    cout << "|---------------------------|\n";
    cout << " ---------------------------\n";
}

int main() {
	
    // Pre-existing account 1
    accountUser[0] = "Muhammad Saad";
    accountNumber[0] = 1234;
    accountPasswords[0] = "pass1";
    accountBalances[0] = 1000.0;
    transactionHistory[0][0] = "Initial deposit of $1000.0";
    transactionCount[0] = 1;

    // Pre-existing account 2
    accountUser[1] = "Zain - ul - Hassan";
    accountNumber[1] = 5678;
    accountPasswords[1] = "pass2";
    accountBalances[1] = 500.0;
    transactionHistory[1][0] = "Initial deposit of $500.0";
    transactionCount[1] = 1;
    setColor(10);

    while (true) {
    displayMenu();
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
        	createAccount();
        } else if (choice == 2) {
        	login();
            if (found) {
            	system("cls");
                cout << "Login successful!\n" << endl;
                while (true) {
                	cout << " -------------------------------\n";
                    cout << "|       THE SERVICES MENU       |\n";
                    cout << "|-------------------------------|\n";
                    cout << "| 1. Deposit Money \t\t|" << endl;
                    cout << "| 2. Withdraw Money\t\t|" << endl;
                    cout << "| 3. Balance Inquiry \t\t|" << endl;
                    cout << "| 4. Transaction History\t|" << endl;
                    cout << "| 5. Transfer Money\t\t|" << endl;
                    cout << "| 6. Update Account Information |" << endl;
                    cout << "| 7. Get a Loan \t\t|" << endl;
                    cout << "| 8. Logout \t\t\t|" << endl;
                    cout << "| 9. Exit\t\t\t|" << endl;
                    cout << "|-------------------------------|\n";
                    cout << " -------------------------------\n";
                    
                    cout << "Enter your choice: ";
                    int choice;
                    cin >> choice;
                    if (choice == 1) {
                    	system("cls");
                    	cout << " ---------------------------\n";
	                    cout << "|        DEPOSIT MENU       |\n";
                        cout << " ---------------------------\n";
                        cout << "Enter amount to deposit: ";
                        double amount;
                        cin >> amount;
                        if (loanStatus[loggedInAccount]) {
                            double tax = amount * 0.05;
                            accountBalances[loggedInAccount] += amount - tax;
                            transactionHistory[loggedInAccount][transactionCount[loggedInAccount]] = "There was a Deposit of $" + to_string(amount) + " with tax $" + to_string(tax);
                            transactionCount[loggedInAccount]++;
                        } else {
                            accountBalances[loggedInAccount] += amount;
                            transactionHistory[loggedInAccount][transactionCount[loggedInAccount]] = "There was a Deposit of $" + to_string(amount);
                            transactionCount[loggedInAccount]++;
                        }
                        cout << "The Deposit was successful!\n" << endl;
                    } else if (choice == 2) {
                    	system("cls");
                    	cout << " ---------------------------\n";
	                    cout << "|        WITHDRAW MENU       |\n";
                        cout << " ---------------------------\n";
                        cout << "Enter amount to withdraw: ";
                        double amount;
                        cin >> amount;
                        if (accountBalances[loggedInAccount] >= amount) {
                            accountBalances[loggedInAccount] -= amount;
                            transactionHistory[loggedInAccount][transactionCount[loggedInAccount]] = "There was a Withdrawal of $" + to_string(amount);
                            transactionCount[loggedInAccount]++;
                            cout << "The Withdrawal was successful!\n" << endl;
                        } else {
                            cout << "The Balance is insufficient!\n" << endl;
                        }
                    }
                        else if (choice == 3) {
                        	system("cls");
                        cout << " ---------------------------\n";
	                    cout << "|        BALANCE MENU       |\n";
                        cout << " ---------------------------\n";
                        cout << "Account balance: " << accountBalances[loggedInAccount] << "\n" << endl;
                    } else if (choice == 4) {
                        cout << "Transaction history:\n";
                        for (int i = 0; i < transactionCount[loggedInAccount]; i++) {
                            cout << transactionHistory[loggedInAccount][i] << endl << endl;
                        }
                    } else if (choice == 5) {
                    	system("cls");
                    	cout << " ---------------------------\n";
	                    cout << "|     MONEY TRANSFER MENU   |\n";
                        cout << " ---------------------------\n";
                        cout << "Enter receiver's account number: ";
                        int receiverNumber;
                        cin >> receiverNumber;
                        cout << "Enter the amount to transfer: ";
                        double amount;
                        cin >> amount;
                        bool receiverFound = false;
                        int receiverIndex = -1;
                        for (int i = 0; i < numberOfAccounts; i++) {
                            if (accountNumber[i] == receiverNumber) {
                                receiverFound = true;
                                receiverIndex = i;
                                break;
                            }
                        }
                        if (receiverFound) {
                            if (accountBalances[loggedInAccount] >= amount) {
                                accountBalances[loggedInAccount] -= amount;
                                accountBalances[receiverIndex] += amount;
                                transactionHistory[loggedInAccount][transactionCount[loggedInAccount]] = "There was a transfer of $" + to_string(amount) + " to account " + to_string(receiverNumber);
                                transactionCount[loggedInAccount]++;
                                transactionHistory[receiverIndex][transactionCount[receiverIndex]] = "$" + to_string(amount) + " was recieved from account " + to_string(accountNumber[loggedInAccount]);
                                transactionCount[receiverIndex]++;
                                cout << "Transfer successful!\n" << endl;
                            } else {
                                cout << "Insufficient balance!\n" << endl;
                            }
                        } else {
                            cout << "Receiver's account not found!\n" << endl;
                        }
                    } else if (choice == 6) {
                    	system("cls");
                    	cout << " -----------------------------\n";
	                    cout << "|   INFORMATION UPDATE MENU   |\n";
                        cout << " -----------------------------\n";
                        cout << "Enter a new Name: ";
                        cin.ignore();
                        getline(cin, accountUser[numberOfAccounts]);
                        cout << "Enter new password: ";
                        cin >> accountPasswords[loggedInAccount];
                        cout << "Your account information has been updated successfully!\n" << endl;
                    } else if (choice == 7) {
                    	system("cls");
                    	cout << " ---------------------------\n";
	                    cout << "|          LOAN MENU        |\n";
                        cout << " ---------------------------\n";
                        cout << "Enter loan amount: ";
                        double loanAmount;
                        cin >> loanAmount;
                        loanAmounts[loggedInAccount] = loanAmount;
                        loanStatus[loggedInAccount] = true;
                        accountBalances[loggedInAccount] += loanAmount;
                        transactionHistory[loggedInAccount][transactionCount[loggedInAccount]] = "Loan of $" + to_string(loanAmount) + " with interest rate of " + to_string(5) + "%";
                        transactionCount[loggedInAccount]++;
                        cout << "Loan granted successfully!\n" << endl;
                    } else if (choice == 8) {
                        cout << "Logging out...\n" << endl;
                        break;
                    } else if (choice == 9) {
                        cout << "Exiting...\n" << endl;
                        return 0;
                    } else {
                        cout << "Invalid choice. Please try again.\n";
                    }
                }
            } else {
                cout << "Invalid account number or password. Please try again.\n";
            }
        }
		 else if (choice == 3) {
            cout << "Exiting...\n";
            return 0;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}