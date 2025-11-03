#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X';
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    // Try all possible starting gestures for the first round
    int max_wins = 0;
    
    vector<char> options = {'R', 'P', 'S'};
    for (char start : options) {
        int wins = 0;
        char current_gesture = start;
        
        for (int i = 0; i < n; i++) {
            if (current_gesture == win(s[i])) {
                wins++;
                // Continue with the same gesture
            } else {
                // Switch to the winning gesture against opponent's move
                current_gesture = win(s[i]);
                wins++;
            }
        }
        max_wins = max(max_wins, wins);
    }
    
    cout << max_wins << endl;
    return 0;
}