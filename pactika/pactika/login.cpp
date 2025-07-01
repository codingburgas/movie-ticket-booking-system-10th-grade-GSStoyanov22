#include <iostream>
#include <string>
#include "login.h"
#include "guest.h"

void login() {
    std::string username, password;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    if (username == "admin" && password == "admin123") {
        std::cout << "Welcome, Administrator!\n";
    } else {
        std::cout << "Welcome, Guest!\n";
        guestMenu();
    }
}