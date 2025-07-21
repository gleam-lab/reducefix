#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::string S;
    std::cin >> N;
    std::cin >> S;

    // Using a map to store the winning move for each move
    std::map<char, char> winMove = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};

    int wins = 0;
    char prev = 'a';
    for (char c : S) {
        // Get the winning move for the current character
        char currentWinMove = winMove[c];
        // Check if the current winning move is different from the previous one
        if (currentWinMove != prev) {
            wins++;  // Increment wins if the move is different
            prev = currentWinMove;  // Update prev to the current winning move
        } else {
            prev = c;  // Update prev to the current character if no win
        }
    }

    std::cout << wins;

    return 0;
}