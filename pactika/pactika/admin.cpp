#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> adminMovies;

void addMovie() {
    string movie, genre, language;
    int releaseYear;
    cout << "Enter movie name: ";
    cin.ignore();
    getline(cin, movie);
    cout << "\nEnter movie language: ";
    getline(cin, language);
    cout << "\nEnter movie genre: ";
    getline(cin, genre);
    cout << "\nEnter movie release year: ";
    cin >> releaseYear;
    adminMovies.push_back(movie);
    cout << "Movie \"" << movie << "\" has been added.\n";
}

void listMovies() {
    if (adminMovies.empty()) {
        cout << "No movies added yet.\n";
        return;
    }
    else {
        cout << "Added movies:\n";
        for (size_t i = 0; i < adminMovies.size(); ++i) {
            cout << i + 1 << ". " << adminMovies[i] << endl;
        }
    }
}

void adminMenu() {
    int choice;
    do {
        cout << "\nAdministrator Menu:\n";
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
