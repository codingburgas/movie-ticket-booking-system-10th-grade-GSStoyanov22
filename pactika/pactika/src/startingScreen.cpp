#include <iostream>
#include <string>
#include "head.h"
#include "startingScreen.h"
#include "signUp.h"
#include "login.h"

void displayStartingScreen() {
    std::string purpleColor = "\033[35m";
    std::string whiteColor = "\033[37m";
    std::string resetColor = "\033[0m";

    printEndl(2);
    centerText(purpleColor + "==========================================" + resetColor);
    centerText(purpleColor + "         MOVIE TICKET BOOKING SYSTEM      " + resetColor);
    centerText(purpleColor + "==========================================" + resetColor);
    printEndl(1);
    centerText(whiteColor + "Select a choice: " + resetColor);
    printEndl(1);
    centerText(whiteColor + "1. SIGN UP " + resetColor);
    centerText(whiteColor + "2. LOGIN " + resetColor);
    printEndl(2);
    chooseAnswer();
}

void chooseAnswer() {
    std::string redColor = "\033[31m";
    std::string resetColor = "\033[0m";
    int choice;
    bool isValid = false;

    while (!isValid) {
        printEndl(1);
        printEndlRepeat(" ", 2);
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                isValid = true;
                clearScreen();
                signUp();
                break;
            case 2:
                isValid = true;
                clearScreen();
                login();
                break;
            default:
                std::cout << redColor << "Invalid choice. Please select 1 or 2." << resetColor << std::endl;
                break;
        }
    }
}
