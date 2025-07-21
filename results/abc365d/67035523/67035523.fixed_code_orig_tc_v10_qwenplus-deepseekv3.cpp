#include <iostream>
#include <string>

using namespace std;

char getWinningMove(char move) {
    if (move == 'R') return 'P';
    if (move == 'P') return 'S';
    if (move == 'S') return 'R';
    return ' '; // should never happen for valid input
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int wins = 0;
    char prev = ' ';
    
    for (int i = 0; i < n; i++) {
        char current = getWinningMove(s[i]);
        if (current != prev) {
            wins++;
            prev = current;
        } else {
            // If same as previous, we need to choose a different move that doesn't lose
            // Find the next different move in the sequence
            int j = i + 1;
            while (j < n && s[j] == s[i]) j++;
            if (j < n) {
                char next_win = getWinningMove(s[j]);
                if (next_win != prev) {
                    prev = next_win;
                    wins++;
                    i = j - 1; // skip ahead to j
                    continue;
                }
            }
            // If all remaining are same, can't win more
            prev = s[i]; // choose to play the same as opponent (no win/loss)
        }
    }
    
    cout << wins << endl;
    return 0;
}