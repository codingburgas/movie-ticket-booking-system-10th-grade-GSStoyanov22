#include <iostream>
#include "Login.h"

using namespace std;

void Login::doLogin() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    cout << "Login successful for user: " << username << "\n";

}
