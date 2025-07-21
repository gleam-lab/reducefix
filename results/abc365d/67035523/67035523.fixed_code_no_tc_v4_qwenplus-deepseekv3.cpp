#include <iostream>
#include <string>

using namespace std;

char get_winning_move(char move) {
    if (move == 'R') return 'P';
    if (move == 'P') return 'S';
    if (move == 'S') return 'R';
    return move; // should not happen for valid input
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int changes = 0;
    char current = get_winning_move(s[0]);
    
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            // Need to change if consecutive moves are same
            changes++;
            // Set to something that beats both current and next (if any)
            if (i+1 < n) {
                current = get_winning_move(s[i+1]);
            } else {
                current = get_winning_move(s[i]);
            }
            i++; // Skip next as we've handled it
        } else {
            current = get_winning_move(s[i]);
        }
    }
    
    cout << changes << endl;
    return 0;
}