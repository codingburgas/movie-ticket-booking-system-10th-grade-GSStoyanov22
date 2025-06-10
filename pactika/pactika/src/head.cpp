
#include <iostream>
#include <string>

void printEndl(int count) {
    for (int i = 0; i < count; ++i)
        std::cout << std::endl;
}

void printEndlRepeat(std::string text, int count) {
    for (int i = 0; i < count; ++i)
        std::cout << text << std::endl;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void centerText(std::string text) {
    int width = 80;
    int len = text.length();
    int pos = (width - len) / 2;
    for (int i = 0; i < pos; ++i)
        std::cout << " ";
    std::cout << text << std::endl;
}
