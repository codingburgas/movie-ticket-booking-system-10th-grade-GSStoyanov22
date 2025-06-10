#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

bool compare(const char* a, const char* b) {
    return strcmp(a, b) == 0;
}

struct Movie {
    string title;
    string genre;
    string duration;
    vector<string> showtimes;

    void addMovie() {
        int count;
        cout << "Movie title (no spaces): ";
        cin >> title;
        cout << "Genre (no spaces): ";
        cin >> genre;
        cout << "Duration (e.g. 2h10m): ";
        cin >> duration;
        cout << "How many showtimes? ";
        cin >> count;
        for (int i = 0; i < count; i++) {
            string time;
            cout << "Showtime " << i + 1 << " (e.g. 18:30): ";
            cin >> time;
            showtimes.push_back(time);
        }
        cout << "Movie added.\n";
    }

    void displayMovie() {
        cout << "\nNow Showing:\n";
        cout << "Title: " << title << "\n";
        cout << "Genre: " << genre << "\n";
        cout << "Duration: " << duration << "\n";
        cout << "Showtimes:\n";
        for (size_t i = 0; i < showtimes.size(); ++i) {
            cout << " - " << showtimes[i] << "\n";
        }
    }
};

class Administrator {
public:
    void changePass() {
        cout << "Password change placeholder.\n";
    }
};

class Customer {
public:
    void getData() {
        string name, phone;
        cout << "Enter your name (no spaces): ";
        cin >> name;
        cout << "Phone number: ";
        cin >> phone;
    }
};

class Menu {
public:
    Movie m;
    Administrator a;
    vector<Movie> movieList;

    void displayMenu() {
        int enter;
        system("cls");
        cout << "===================\n";
        cout << "    CINEMA CITY    \n";
        cout << "===================\n";
        cout << "1. Administrator Login\n";
        cout << "2. Exit\n";
        cin >> enter;

        if (enter == 1) {
            char userName[100], pass[100], user[100], userPass[100];
            int nCheck = 0, aCheck = 0;
            cout << "Username: ";
            cin >> userName;
            cout << "Password: ";
            cin >> pass;

            ifstream userData("admins.txt");
            while (userData >> user >> userPass) {
                if (compare(user, userName)) nCheck = 1;
                if (compare(userPass, pass)) aCheck = 1;
            }
            userData.close();

            if (nCheck && aCheck) {
                do {
                    int check;
                    system("cls");
                    cout << "=== ADMIN MENU ===\n";
                    cout << "1. Add movie\n";
                    cout << "2. Display all movies\n";
                    cout << "3. Admin settings\n";
                    cout << "4. Exit\n";
                    cin >> check;

                    switch (check) {
                    case 1: {
                        Movie newMovie;
                        newMovie.addMovie();
                        movieList.push_back(newMovie);
                        break;
                    }
                    case 2:
                        for (Movie& mv : movieList)
                            mv.displayMovie();
                        break;
                    case 3:
                        a.changePass();
                        break;
                    case 4:
                        return;
                    default:
                        cout << "Invalid choice.\n";
                    }
                } while (true);
            }
            else {
                cout << "Invalid credentials.\n";
            }
        }
        else if (enter == 2) {
            exit(0);
        }
    }
};

void startMenu() {
    Menu cinema;
    while (true) {
        int choice;
        system("cls");
        cout << "===================\n";
        cout << "    CINEMA CITY    \n";
        cout << "===================\n";
        cout << "1. Administrator\n";
        cout << "2. Customer\n";
        cout << "3. Exit\n";
        cin >> choice;

        if (choice == 1) {
            cinema.displayMenu();
        }
        else if (choice == 2) {
            Customer c;
            c.getData();
            if (cinema.movieList.empty()) {
                cout << "No movies available.\n";
            }
            else {
                cout << "\nNow Showing:\n";
                for (size_t i = 0; i < cinema.movieList.size(); ++i) {
                    cout << i + 1 << ". " << cinema.movieList[i].title << "\n";
                }
                int selection;
                cout << "Select a movie by number: ";
                cin >> selection;
                if (selection >= 1 && selection <= cinema.movieList.size()) {
                    system("cls");
                    cinema.movieList[selection - 1].displayMovie();
                    cout << "Enjoy your movie!\n";
                }
                else {
                    cout << "Invalid selection.\n";
                }
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid option.\n";
        }
    }
}

int main() {
    startMenu();
    return 0;
}
