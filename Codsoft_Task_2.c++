#include <iostream>

int main() {
    double a, b, result;
    char op;
    std::cout << "Enter first number: ";
    std::cin >> a;
    std::cout << "Enter operator (+ - * /): ";
    std::cin >> op;
    std::cout << "Enter second number: ";
    std::cin >> b;

    if (op == '+')
        result = a + b;
    else if (op == '-')
        result = a - b;
    else if (op == '*')
        result = a * b;
    else if (op == '/') {
        if (b != 0)
            result = a / b;
        else {
            std::cout << "Error: Division by zero\n";
            return 1;
        }
    } else {
        std::cout << "Invalid operator\n";
        return 1;
    }

    std::cout << "Result: " << result << "\n";
    return 0;
}
