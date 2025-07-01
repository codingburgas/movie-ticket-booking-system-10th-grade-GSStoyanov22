#include <iostream>
#include <string>
#include "Booking.h"

using namespace std;

void Booking::makeBooking() {
    string movie;
    int tickets;

    cout << "Enter movie name: ";
    cin.ignore();
    getline(cin, movie);

    cout << "Enter number of tickets: ";
    cin >> tickets;

    cout << "You have booked " << tickets << " tickets for " << movie << ".\n";
}
