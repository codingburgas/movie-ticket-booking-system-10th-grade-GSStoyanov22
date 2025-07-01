#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

void guestMenu() {
    vector<string> cinemas = { "Arena Sofia", "Cine Grand Plovdiv", "Cinema City Varna" };
    vector<string> movies = { "Dune 2", "Inside Out 2", "Bad Boys 4" };
    int cinemaChoice, movieChoice;

    cout << "\nChoose a cinema:" << endl;
    for (int i = 0; i < cinemas.size(); i++) {
        cout << i + 1 << ". " << cinemas[i] << endl;
    }
    cout << "> ";
    cin >> cinemaChoice;
    if (cinemaChoice < 1 || cinemaChoice >(int)cinemas.size()) {
        cout << "Invalid cinema choice.\n";
        return;
    }

    cout << "\nChoose a movie:" << endl;
    for (int i = 0; i < movies.size(); i++) {
        cout << i + 1 << ". " << movies[i] << endl;
    }
    cout << "> ";
    cin >> movieChoice;
    if (movieChoice < 1 || movieChoice >(int)movies.size()) {
        cout << "Invalid movie choice.\n";
        return;
    }

    const int R = 5; // rows A-E
    const int C = 8; // cols 0-7
    vector<vector<bool>> taken(R, vector<bool>(C, false));
    // Add taken seats here if needed

    cout << "\nSeats layout (0 = free, X = taken):\n";
    const int cellW = 3;
    cout << setw(4) << " ";
    for (int c = 0; c < C; ++c)
        cout << setw(cellW) << c;
    cout << "\n";

    for (int r = 0; r < R; ++r) {
        cout << char('A' + r) << " | ";
        for (int c = 0; c < C; ++c) {
            cout << setw(cellW) << (taken[r][c] ? 'X' : '0');
        }
        cout << "\n";
    }

    cout << "\nEnter seat codes (e.g. A0 B1), enter 0 to finish:\n";

    vector<pair<int, int>> seats;
    string code;

    while (cin >> code && code != "0") {
        if (code.length() < 2) {
            cout << "Invalid code. Try again: ";
            continue;
        }

        char rowChar = toupper(code[0]);
        if (rowChar < 'A' || rowChar >= 'A' + R) {
            cout << "Invalid row. Try again: ";
            continue;
        }
        int row = rowChar - 'A';

        string colStr = code.substr(1);
        int col = -1;
        try {
            col = stoi(colStr);
        }
        catch (...) {
            cout << "Invalid column number. Try again: ";
            continue;
        }

        if (col < 0 || col >= C) {
            cout << "Column out of range. Try again: ";
            continue;
        }

        if (taken[row][col]) {
            cout << "Seat already taken. Try another: ";
            continue;
        }

        seats.push_back({ row, col });
        cout << "Added seat " << code << ". Add another or enter 0 to finish: ";
    }

    cout << "\n✅ Order successful!\n";
    cout << "Your seats: ";
    for (auto& s : seats) {
        cout << char('A' + s.first) << s.second << " ";
    }
    cout << "\nMovie: " << movies[movieChoice - 1] << "\nCinema: " << cinemas[cinemaChoice - 1] << endl;
}
