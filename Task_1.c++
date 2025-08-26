#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    int target = std::rand() % 100 + 1;
    int guess;
    std::cout << "Guess the number (1-100):\n";
    while (true) {
        std::cin >> guess;
        int diff = guess - target;
        if (diff == 0) {
            std::cout << "Correct! The number was " << target << ".\n";
            break;
        }
        if (std::abs(diff) <= 5) {
            if (diff > 0)
                std::cout << "Just a little high. Try again:\n";
            else
                std::cout << "Just a little low. Try again:\n";
        } else {
            if (diff > 0)
                std::cout << "Much too high. Try again:\n";
            else
                std::cout << "Much too low. Try again:\n";
        }
    }
    return 0;
}
