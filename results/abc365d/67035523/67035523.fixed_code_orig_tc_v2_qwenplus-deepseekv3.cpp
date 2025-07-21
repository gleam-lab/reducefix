#include <iostream>
#include <string>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'P') return 'S';
    if (x == 'S') return 'R';
    return 'X'; // should not happen if input is valid
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
    char prev_optimal = 'X'; // initialize to an invalid move
    
    for (int i = 0; i < n; ++i) {
        char current_optimal = win(s[i]);
        if (current_optimal != prev_optimal) {
            changes++;
            prev_optimal = current_optimal;
        }
    }
    
    cout << changes << endl;
    return 0;
}