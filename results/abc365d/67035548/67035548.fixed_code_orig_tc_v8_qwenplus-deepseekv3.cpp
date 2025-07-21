#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return ' ';
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int wins = 0;
    char prev = ' ';
    
    for (int i = 0; i < n; i++) {
        char current = s[i];
        char optimal = win(current);
        
        if (optimal != prev) {
            wins++;
            prev = optimal;
        } else {
            // If we can't choose the optimal move, choose one that doesn't lose
            // This allows us to potentially win the next round
            prev = current;
        }
    }
    
    // Also try the reverse strategy to find maximum
    prev = ' ';
    int reverse_wins = 0;
    for (int i = n-1; i >= 0; i--) {
        char current = s[i];
        char optimal = win(current);
        
        if (optimal != prev) {
            reverse_wins++;
            prev = optimal;
        } else {
            prev = current;
        }
    }
    
    cout << max(wins, reverse_wins) << endl;
    
    return 0;
}