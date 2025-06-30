#include <iostream>
#include "Menu.h"
#include "Login.h"
#include "SignUp.h"

using namespace std;

void Menu::showMainMenu() {
    int choice;
    do {
        cout << "=== Movie Booking System ===\n";
        cout << "1. Login\n";
        cout << "2. Sign Up\n";
        cout << "3. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Login login;
            login.doLogin();
            break;
        }
        case 2: {
            SignUp signup;
            signup.doSignUp();
            break;
        }
        case 3:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid option!\n";
        }
    } while (choice != 3);
}
