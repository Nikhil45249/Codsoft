#include <iostream>
using namespace std;
int main() {
    int choice;
    do {
        cout << "MINI CALCULATOR "  << endl;
        cout << "---------------------------" << endl;

        int Number1, Number2;
        cout << "Enter Number 1:";
        while (!(cin >> Number1)) {
            cout << "Invalid input! Please enter a number:";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Enter Number 2 :";
        while (!(cin >> Number2)) {
            cout << "Invalid input! Please enter a number:";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        char Operand;
        cout << "Choose operation (+, -, *, /):";
        cin >> Operand;

        cout <<"\nResult:";

        if (Operand == '+') {
            cout << Number1 + Number2 << endl;
        } 
        else if (Operand == '-') {
            cout << Number1 - Number2 << endl;
        } 
        else if (Operand == '*') {
            cout << Number1 * Number2 << endl;
        } 
        else if (Operand == '/') {
            if (Number2 == 0)
                cout << "Cannot divide by zero!" << endl;
            else
                cout << (float)Number1 / Number2 << endl;
        } 
        else {
            cout << "Incorrect Operand Chosen!!!" << endl;
        }

        cout << "\nEnter 1 to continue or any other key to exit:";
        cin >> choice;
    } while (choice == 1);

    cout << "\nThank you for using the Mini Calculator!" << endl;
    return 0;
}