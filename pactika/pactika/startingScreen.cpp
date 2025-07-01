#include <iostream>
#include <thread>
#include <chrono>
#include "startingScreen.h"

void showStartingScreen() {
    std::cout << "==============================\n";
    std::cout << "     MOVIE BOOKING SYSTEM     \n";
    std::cout << "==============================\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}