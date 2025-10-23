#include <iostream>
#include <random>
#include <cstdlib>  // for system("cls") or system("clear")
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);
    int num = dist(gen);

    int guess, attempts = 10;
    cout << "\033[1;36m=========================================\033[0m\n";
    cout << "\033[1;33m🎯  WELCOME TO THE NUMBER GUESSING GAME 🎯\033[0m\n";
    cout << "\033[1;36m=========================================\033[0m\n\n";

    cout << "🤖 Guess the number between \033[1;32m1\033[0m and \033[1;32m100\033[0m.\n";
    cout << "💡 You have \033[1;31m" << attempts << "\033[0m attempts to guess it!\n\n";

    for (int i = 1; i <= attempts; i++) {
        cout << "\033[1;35mAttempt " << i << ":\033[0m Enter your guess 👉 ";
        cin >> guess;

        if (guess > num) {
            cout << "\033[1;31m📉 Too high!\033[0m Try a smaller number.\n\n";
        } 
        else if (guess < num) {
            cout << "\033[1;34m📈 Too low!\033[0m Try a larger number.\n\n";
        } 
        else {
            cout << "\033[1;32m🎉 Congratulations!\033[0m You guessed the correct number "
                 << num << " in " << i << " attempts! 🏆\n";
            return 0;
        }

        cout << "🕒 Attempts left: " << attempts - i << "\n\n";
    }

    cout << "\033[1;31m❌ Game Over!\033[0m The correct number was \033[1;33m" << num << "\033[0m.\n";
    cout << "Better luck next time! 🍀\n";
    return 0;
}
