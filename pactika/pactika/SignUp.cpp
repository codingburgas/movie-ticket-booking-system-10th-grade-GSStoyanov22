#include <iostream>
#include "SignUp.h"

using namespace std;

void SignUp::doSignUp() {
    string username, password;
    cout << "Choose username: ";
    cin >> username;
    cout << "Choose password: ";
    cin >> password;

    
    cout << "User " << username << " registered successfully.\n";

  
}
