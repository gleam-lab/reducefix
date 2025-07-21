#include <iostream>
#include <string>
using namespace std;

char winning_move(char opponent) {
    if (opponent == 'R') return 'P';
    if (opponent == 'P') return 'S';
    if (opponent == 'S') return 'R';
    return ' '; // should never happen for valid input
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0;
        return 0;
    }
    
    int changes = 0;
    char current = winning_move(s[0]);
    changes++;
    
    for (int i = 1; i < n; i++) {
        if (winning_move(s[i]) != current) {
            changes++;
            current = winning_move(s[i]);
        }
    }
    
    cout << changes;
    return 0;
}