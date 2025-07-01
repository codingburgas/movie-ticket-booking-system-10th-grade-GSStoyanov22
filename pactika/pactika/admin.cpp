#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> adminMovies;

void addMovie() {
    string movie;
    cout << "Enter movie name: ";
    cin.ignore();
    getline(cin, movie);
    adminMovies.push_back(movie);
    cout << "✅ Movie \"" << movie << "\" has been added.\n";
}

void listMovies() {
    if (adminMovies.empty()) {
        cout << "❗ No movies added yet.\n";
        return;
    }
    cout << "🎬 Added movies:\n";
    for (size_t i = 0; i < adminMovies.size(); ++i) {
        cout << i + 1 << ". " << adminMovies[i] << endl;
    }
}

void adminMenu() {
    int choice;
    do {
        cout << "\n📋 Administrator Menu:\n";
        cout << "1. Add movie\n";
        cout << "2. Show all movies\n";
        cout << "0. Exit\n";
        cout << "> ";
        cin >> choice;

        switch (choice) {
        case 1: addMovie(); break;
        case 2: listMovies(); break;
        case 0: cout << "Exiting menu.\n"; break;
        default: cout << "Invalid choice.\n"; break;
        }
    } while (choice != 0);
}
