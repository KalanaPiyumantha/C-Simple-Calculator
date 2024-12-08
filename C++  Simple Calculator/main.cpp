#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <limits>
using namespace std;

double add(double x, double y) {
    return x + y;
}

double sub(double x, double y) {
    return x - y;
}

double mul(double x, double y) {
    return x * y;
}

double div(double x, double y) {
    if (y == 0) {
        throw invalid_argument("Division by zero is not allowed.");
    }
    return x / y;
}

void displayMenu() {
    cout << R"(
                                   _
   ____      _           _         | |_       ____
  / ___|__ _| | ___ _   _| | __ _| | _ |__   | __|
 | |   / _` | |/ __| | | | |/ _` | | |/  _  ) | |
 | |__| (_| | | (__| |_| | | (_| | | (_ | |  || |
  \____\__,_|_|\___|\__,_|_|\__,_|_|_|\__ __) |_|
    )" << endl;
    cout << "Select Operation:" << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;
}

int main() {
    char choice;
    do {
        displayMenu();
        int operation;
        cout << "Enter choice (1 / 2 / 3 / 4): ";
        cin >> operation;

        if (operation < 1 || operation > 4) {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        double num1, num2;
        try {
            cout << "Enter your first number: ";
            cin >> num1;
            if (cin.fail()) throw invalid_argument("Invalid input. Please enter a number.");

            cout << "Enter your second number: ";
            cin >> num2;
            if (cin.fail()) throw invalid_argument("Invalid input. Please enter a number.");

            double result;
            switch (operation) {
                case 1:
                    result = add(num1, num2);
                    cout << fixed << setprecision(2) << num1 << " + " << num2 << " = " << result << endl;
                    break;
                case 2:
                    result = sub(num1, num2);
                    cout << fixed << setprecision(2) << num1 << " - " << num2 << " = " << result << endl;
                    break;
                case 3:
                    result = mul(num1, num2);
                    cout << fixed << setprecision(2) << num1 << " * " << num2 << " = " << result << endl;
                    break;
                case 4:
                    result = div(num1, num2);
                    cout << fixed << setprecision(2) << num1 << " / " << num2 << " = " << result << endl;
                    break;
            }
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "Let's do the next calculation? (yes/no): ";
        string nextCalculation;
        cin >> nextCalculation;

        if (nextCalculation != "yes" && nextCalculation != "no") {
            cout << "Invalid input. Assuming 'no'." << endl;
            break;
        } else if (nextCalculation == "no") {
            cout << "Thank you.........! Come Again" << endl;
            break;
        }

    } while (true);

    return 0;
}
