#include <iostream>
#include <string>
#include <limits>
using namespace std;

class ATM {
private:
  int balance = 0;
  string account_number;
  string pin;

public:
  ATM(string account_number, string pin) {
    this->account_number = account_number;
    this->pin = pin;
  }

  void deposit(int amount) {
    balance += amount;
    cout << "Deposit successful. New balance: " << balance << endl;
  }

  void withdraw(int amount) {
    if (balance >= amount) {
      balance -= amount;
      cout << "Withdrawal successful. New balance: " << balance << endl;
    } else {
      cout << "Insufficient funds." << endl;
    }
  }

  void check_balance() {
    cout << "Your balance is: " << balance << endl;
  }

  bool authenticate(string account_number, string pin) {
    return this->account_number == account_number && this->pin == pin;
  }
};

int main() {
  ATM atm("1234567890", "1234");

  string account_number;
  string pin;

  cout << "Welcome to the ATM." << endl;
  cout << "Please enter your account number: ";
  cin >> account_number;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Please enter your PIN: ";
  cin >> pin;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  if (atm.authenticate(account_number, pin)) {
    int choice;
    do {
      cout << "What would you like to do?" << endl;
      cout << "1. Check balance" << endl;
      cout << "2. Deposit" << endl;
      cout << "3. Withdraw" << endl;
      cout << "4. Exit" << endl;
      cin >> choice;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      switch (choice) {
        case 1:
          atm.check_balance();
          break;
        case 2: {
          int amount;
          cout << "Enter amount to deposit: ";
          cin >> amount;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          atm.deposit(amount);
          break;
        }
        case 3: {
          int amount;
          cout << "Enter amount to withdraw: ";
          cin >> amount;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          atm.withdraw(amount);
          break;
        }
        case 4:
          cout << "Goodbye." << endl;
          break;
        default:
          cout << "Invalid choice." << endl;
          break;
      }
    } while (choice != 4);
  } else {
    cout << "Authentication failed." << endl;
  }

  return 0;
}
