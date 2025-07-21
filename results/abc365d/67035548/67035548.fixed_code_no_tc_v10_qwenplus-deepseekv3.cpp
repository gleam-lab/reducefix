#include <iostream>
#include <string>
using namespace std;

char winning_move(char c) {
    if (c == 'R') return 'P';
    if (c == 'P') return 'S';
    if (c == 'S') return 'R';
    return ' '; // handle unexpected cases
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int wins = 0;
    char current = winning_move(s[0]);
    wins++;
    
    for (int i = 1; i < n; i++) {
        if (winning_move(s[i]) != current) {
            current = winning_move(s[i]);
            wins++;
        }
    }
    
    cout << wins << endl;
    return 0;
}