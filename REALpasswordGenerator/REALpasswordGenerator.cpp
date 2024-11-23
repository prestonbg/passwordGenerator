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

    if (includeSymbols) {
        password = +symbols[rand() % symbols.size()];
    }

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
    setlocale(LC_ALL, "Russian");
    srand(time(nullptr));
    string lang;

    cout << "English or russian?/Английский или русский? (e or r): ";
    cin >> lang;
    switch (lang[0]) {
        case 'e':
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
                cout << "Thanks for using the passwordGenerator!";

            }
            catch (const exception& e) {
                cerr << "Error " << endl;
                return 1;
            }
            break;
        case 'r':
            try {
                int totalLength, numDigits;
                char needSymbols;

                cout << "Введите размер всего пароля: ";
                cin >> totalLength;

                if (totalLength <= 0) {
                    throw runtime_error("Размер пароля должен быть положительный!");
                }

                cout << "Введите кол-во цифр в пароле: ";
                cin >> numDigits;

                if (numDigits < 0 || numDigits > totalLength) {
                    throw runtime_error("Кол-во цифр должно быть от 0 до размера пароля!");
                }

                cout << "Нужны Вам символы в пароле? (д/н): ";
                cin >> needSymbols;

                bool includeSymbols = (needSymbols == 'д' || needSymbols == 'Д');

                string password = generatePassword(totalLength, numDigits, includeSymbols);
                cout << "Ваш пароль " << password << endl;
                cout << "Спасибо за использование passwordGenerator!";

            }
            catch (const exception& e) {
                cerr << "Ошибка " << endl;
                return 1;
            }
            break;
        default:
            cout << "Enter E or R depending on your language/Введите E или R в зависимости от вашего языка" << endl;
            return main();
    }

    return 0;
}