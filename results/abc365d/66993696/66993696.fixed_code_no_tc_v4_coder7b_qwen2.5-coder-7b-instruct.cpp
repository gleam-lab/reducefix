#include<bits/stdc++.h>
using namespace std;

// Function to determine the winner of a single round of rock-paper-scissors
char getWinner(char a, char b) {
    if ((a == 'R' && b == 'S') || (a == 'S' && b == 'P') || (a == 'P' && b == 'R')) return 'A'; // Aoki wins
    else if ((b == 'R' && a == 'S') || (b == 'S' && a == 'P') || (b == 'P' && a == 'R')) return 'T'; // Takahashi wins
    else return 'D'; // Draw
}

int main() {
    int n;
    scanf("%d", &n);
    char s[n + 1]; // Array to store Aoki's moves
    scanf("%s", s + 1);

    int takahashiWins = 0; // Initialize Takahashi's win count

    // Iterate through each game
    for (int i = 1; i <= n; ++i) {
        // If it's not the first game, ensure Takahashi doesn't repeat his previous move
        if (i > 1) {
            while (getWinner(takahashiMoves[i - 1], s[i]) == 'T' || takahashiMoves[i] == takahashiMoves[i - 1]) {
                if (takahashiMoves[i] == 'R') takahashiMoves[i] = 'P';
                else if (takahashiMoves[i] == 'P') takahashiMoves[i] = 'S';
                else takahashiMoves[i] = 'R';
            }
        }

        // Determine the result of the current game
        char result = getWinner(takahashiMoves[i], s[i]);

        // If Takahashi wins, increment the win count
        if (result == 'T') takahashiWins++;
    }

    // Print the total number of games Takahashi won
    printf("%d\n", takahashiWins);

    return 0;
}