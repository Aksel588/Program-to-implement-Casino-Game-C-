#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void rules() {
    cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}

int main() {
    string playerName;
    int balance; // stores player's balance
    int bettingAmount;
    int guess;
    int dice; // stores the random number
    char choice;

    srand(time(0)); // "Seed" the random generator

    cout << "\n\t\t========WELCOME TO THE CASINO WORLD=======\n\n";
    cout << "Enter your name: ";
    getline(cin, playerName);

    cout << "Enter the starting balance to play game: $";
    cin >> balance;

    do {
        system("clear"); // For Windows use system("cls");
        rules();
        cout << "Your current balance is $ " << balance << "\n";

        // Get player's betting balance
        do {
            cout << "Hey, " << playerName << ", enter amount to bet: $";
            cin >> bettingAmount;
            if (bettingAmount > balance)
                cout << "Betting balance can't be more than current balance!\n"
                     << "\nRe-enter balance\n ";
        } while (bettingAmount > balance);

        // Get player's numbers
        do {
            cout << "Guess any betting number between 1 & 10: ";
            cin >> guess;
            if (guess <= 0 || guess > 10)
                cout << "Number should be between 1 to 10\n"
                     << "Re-enter number:\n ";
        } while (guess <= 0 || guess > 10);

        dice = rand() % 10 + 1; // Will hold the randomly generated integer between 1 & 10

        if (dice == guess) {
            cout << "\n\nYou are in luck!! You have won $" << bettingAmount * 10;
            balance += bettingAmount * 10;
        } else {
            cout << "Oops, better luck next time !! You lost $ " << bettingAmount << "\n";
            balance -= bettingAmount;
        }

        cout << "\nThe winning number was: " << dice << "\n";
        cout << "\n" << playerName << ", Your balance is $ " << balance << "\n";

        if (balance == 0) {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is $ " << balance << "\n\n";
    return 0;
}
