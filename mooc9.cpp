#include <iostream>

int main() {
    int feet, inches;
    std::cin >> feet >> inches;

    int totalInches = feet * 12 + inches;
    totalInches--;

    
    if (totalInches < 0) {
        totalInches = 0;
    }

    feet = totalInches / 12;
    inches = totalInches % 12;

    std::cout << feet << "'" << inches << "\"" << std::endl;

    return 0;
}
