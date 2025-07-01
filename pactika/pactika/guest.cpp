#include <iostream>
#include <vector>
#include <string>
using namespace std;

void guestMenu() {
    vector<string> cinemas = { "Arena Sofia", "Cine Grand Plovdiv", "Cinema City Varna" };
    vector<string> movies = { "Dune 2", "Inside Out 2", "Bad Boys 4" };
    int cinemaChoice, movieChoice, seat;

    cout << "\nChoose a cinema:" << endl;
    for (int i = 0; i < cinemas.size(); i++) {
        cout << i + 1 << ". " << cinemas[i] << endl;
    }
    cout << "> ";
    cin >> cinemaChoice;

    cout << "\nChoose a movie:" << endl;
    for (int i = 0; i < movies.size(); i++) {
        cout << i + 1 << ". " << movies[i] << endl;
    }
    cout << "> ";
    cin >> movieChoice;

    cout << "\nChoose a seat (1–30): ";
    cin >> seat;

    cout << "\n✅ Order successful!" << endl;
    cout << "Your seat: " << seat << ", Movie: " << movies[movieChoice - 1]
        << ", Cinema: " << cinemas[cinemaChoice - 1] << endl;
}
