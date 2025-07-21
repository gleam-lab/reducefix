#include <iostream>
#include <string>
using namespace std;

// Function to determine if one move beats another
bool beats(char a, char b) {
    return (a == 'R' && b == 'S') || (a == 'S' && b == 'P') || (a == 'P' && b == 'R');
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int wins = 0;
    char last_move = 'X'; // Initialize with a move that can't be beaten
    
    for (int i = 0; i < n; ++i) {
        if (!beats(last_move, s[i])) {
            wins++; // Takahashi wins this round
            last_move = s[i]; // Update last move to current move
        } else {
            // Find a move that beats Aoki's move and doesn't equal the previous move
            for (char move = 'R'; move <= 'S'; ++move) {
                if (move != last_move && beats(move, s[i])) {
                    last_move = move;
                    wins++;
                    break;
                }
            }
        }
    }
    
    cout << wins << endl;
    return 0;
}