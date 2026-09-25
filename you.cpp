#include <iostream>
#include <string>
#include <vector>


using namespace std;

// كلاس يمثل الحساب البنكي
class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    // مشيّد الحساب (Constructor)
    BankAccount(string name, int accNum, double initialBalance) {
        accountHolder = name;
        accountNumber = accNum;
        balance = initialBalance;
    }

    // الحصول على رقم الحساب
    int getAccountNumber() {
        return accountNumber;
    }

    // إيداع الأموال
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "💵 the deposit has been processed successfully for " << amount << " $/syp.\n";
        } else {
            cout << "❌ invalid deposit amount is not available.\n";
        }
    }

    // سحب الأموال
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "❌ your balance is insufficient. your current balance is: " << balance << "\n";
        } else if (amount <= 0) {
            cout << "❌ invalid withdrawal amount is not available.\n";
        } else {
            balance -= amount;
            cout << "💸 the withdrawal has been processed successfully for " << amount << " $/syp.\n";
        }
    }

    // عرض تفاصيل الحساب
    void displayAccountInfo() {
        cout << "\n--- Account Information ---" << endl;
        cout << "👤 Name of Account Holder: " << accountHolder << endl;
        cout << "🔢 Account Number: " << accountNumber << endl;
        cout << "💰 Current Balance: " << balance << " $/syp" << endl;
        cout << "---------------------\n";
    }
};

int main() {
    vector<BankAccount> bank; // قائمة لتخزين الحسابات
    int choice;

    cout << "🏪 welcome to the simple bank management system 🏪\n";

    do {
        cout << "\nmain menu\n";
        cout << "1. createan new account\n";
        cout << "2. inserting money\n";
        cout << "3. withdrawing money\n";
        cout << "4. viow account details\n";
        cout << "5.Exit\n";
        cout << "Please enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int accNum;
            double initialDeposit;

            cout << "enter name of account holder: ";
            cin.ignore(); // لتنظيف ذاكرة الإدخال
            getline(cin, name);
            cout << "enter account number: ";
            cin >> accNum;
            cout << "enter the amount of initial deposit: ";
            cin >> initialDeposit;

            // إضافة الحساب الجديد إلى البنك
            bank.push_back(BankAccount(name, accNum, initialDeposit));
            cout << "✅ the amount was enterd successfully \n";

        } else if (choice == 2 || choice == 3 || choice == 4) {
            int accNum;
            cout << "enter the account number: ";
            cin >> accNum;

            // البحث عن الحساب
            bool found = false;
          //  for (size_back = 0; bank.size(); i++) // تعديل بسيط للبحث داخل الـ Vector
            for (auto &account : bank) {
                if (account.getAccountNumber() == accNum) {
                    found = true;
                    if (choice == 2) {
                        double amount;
                        cout << "enter the amount to be deposited: ";
                        cin >> amount;
                        account.deposit(amount);
                    } else if (choice == 3) {
                        double amount;
                        cout << "enter the amount you want to withdraw: ";
                        cin >> amount;
                        account.withdraw(amount);
                    } else if (choice == 4) {
                        account.displayAccountInfo();
                    }
                    break;
                }
            }
            if (!found) {
                cout << "❌ the account number could not be found.\n";
            }
        } else if (choice == 5) {
            cout << "👋 thank you for using our banking system. see you later!\n";
        } else {
            cout << "❌ invalid choice. please try again.\n";
        }

    } while (choice != 5);

    return 0;
}