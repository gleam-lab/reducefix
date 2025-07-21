#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char winning_move(char c) {
    if (c == 'R') return 'P';
    if (c == 'P') return 'S';
    if (c == 'S') return 'R';
    return ' '; // default case (shouldn't occur)
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int max_wins = 0;
    char current_move = winning_move(s[0]);
    max_wins = 1;
    
    for (int i = 1; i < n; i++) {
        if (winning_move(s[i]) != current_move) {
            max_wins++;
            current_move = winning_move(s[i]);
        }
    }
    
    // Check another possible optimal strategy (starting with different initial move)
    int alt_wins = 0;
    current_move = s[0]; // start by matching the first move (no win)
    
    for (int i = 1; i < n; i++) {
        if (winning_move(s[i]) != current_move) {
            alt_wins++;
            current_move = winning_move(s[i]);
        } else {
            current_move = s[i];
        }
    }
    
    cout << max(max_wins, alt_wins) << endl;
    return 0;
}