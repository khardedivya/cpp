#include <iostream>
#include <cstdlib> // For rand()

using namespace std;

// Constant variables
const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';

// Function to get computer choice
char getComputerchoice() {
    // Generate a random number between 1 and 3
    int num = rand() % 3 + 1;
    if (num == 1) return ROCK;
    if (num == 2) return PAPER;
    if (num == 3) return SCISSORS;
}

// Function to get user's choice
char getUserchoice() {
    char c;
    cout << "Rock, Paper, and Scissors Game!" << endl;
    cout << "Choose your option:"  << endl;
    cout << " r for rock " << endl;
    cout << " p for paper" << endl;
    cout << " s for scissors " << endl;
    cin >> c;
    
    // Validate user's input
    while (c != 'r' && c != 'p' && c != 's') {
        cout << "Invalid input! Please enter one of the following options: r, p, or s" << endl;
        cin >> c;
    }

    return c;
}

// Function to show selected choice
void showSelectedchoice(char option) {
    if (option == ROCK) cout << "Rock" << endl;
    if (option == PAPER) cout << "Paper" << endl;
    if (option == SCISSORS) cout << "Scissors" << endl;
}

// Function to choose winner
void chooseWinner(char uChoice, char cChoice) {
    if (uChoice == ROCK && cChoice == PAPER) {
        cout << "Computer Wins! Paper wraps Rock."<< endl;
    }
    else if (uChoice == PAPER && cChoice == SCISSORS) {
        cout << "Computer Wins! Scissors cut Paper."<< endl;
    }
    else if (uChoice == SCISSORS && cChoice == ROCK) {
        cout << "Computer Wins! Rock smashes Scissors."<< endl;
    }
    else if (uChoice == ROCK && cChoice == SCISSORS) {
        cout << "You Win! Rock smashes Scissors."<< endl;
    }
    else if (uChoice == PAPER && cChoice == ROCK) {
        cout << "You Win! Paper wraps Rock."<< endl;
    }
    else if (uChoice == SCISSORS && cChoice == PAPER) {
        cout << "You Win! Scissors cut Paper."<< endl;
    }
    else {
        cout << "It's a Tie!" << endl;
    }
}

int main() {
    int ch = 0;

    do {
        char uChoice, cChoice;
        
        // Get user's choice
        uChoice = getUserchoice();
        cout << "Your choice is: ";
        showSelectedchoice(uChoice);
        
        // Get computer's choice
        cout << "Computer's choice is: ";
        cChoice = getComputerchoice();
        showSelectedchoice(cChoice);
        
        // Determine winner
        chooseWinner(uChoice, cChoice);
        
        // Ask user if they want to continue
        cout << "Do you want to continue? (0/1): ";
        cin >> ch;
    } while (ch != 0);

    return 0;
}
