#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int wins = 0;
    char last_move = ' ';
    
    for (int i = 0; i < n; ++i) {
        if (last_move == ' ') {
            // First move can be anything
            last_move = s[i];
            continue;
        }
        
        if ((last_move == 'R' && s[i] == 'P') ||
            (last_move == 'P' && s[i] == 'S') ||
            (last_move == 'S' && s[i] == 'R')) {
            // If we can win, do it
            last_move = s[i];
            ++wins;
        } else {
            // Otherwise, just play the same as last time
            last_move = s[i];
        }
    }
    
    cout << wins << endl;
    return 0;
}