#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

using namespace std;

string generatePassword(int totalLength, int numDigits, bool includeSymbols) {
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string digits = "0123456789";
    string symbols = "!@#$%^&*()";
    string allCharacters = letters + digits + (includeSymbols ? symbols : "");
    string password;

    for (int i = 0; i < numDigits; ++i) {
        password += digits[rand() % digits.size()];
    }

    for (int i = numDigits; i < totalLength; ++i) {
        password += allCharacters[rand() % allCharacters.size()];
    }

    random_device rd;
    mt19937 gen(rd());
    shuffle(password.begin(), password.end(), gen);

    return password;
}

int main() {
    srand(time(nullptr));

    try {
        int totalLength, numDigits;
        char needSymbols;

        cout << "Enter the total length of the password: ";
        cin >> totalLength;

        if (totalLength <= 0) {
            throw runtime_error("Password length must be positive!");
        }

        cout << "Enter the number of digits in the password: ";
        cin >> numDigits;

        if (numDigits < 0 || numDigits > totalLength) {
            throw runtime_error("The number of digits must be from 0 to the password length!");
        }

        cout << "Are the symbols needed? (y/n) ";
        cin >> needSymbols;

        bool includeSymbols = (needSymbols == 'y' || needSymbols == 'Y');

        string password = generatePassword(totalLength, numDigits, includeSymbols);
        cout << "Your password " << password << endl;

    }
    catch (const exception& e) {
        cerr << "Error " << endl;
        return 1;
    }

    return 0;
}