#include <iostream>
#include <string>
using namespace std;

char getWinner(char prev) {
    if (prev == 'R') return 'P';
    if (prev == 'P') return 'S';
    if (prev == 'S') return 'R';
    return ' '; // default case, though prev shouldn't be ' ' here
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
    char prev = s[0];
    
    for (int i = 1; i < n; ++i) {
        if (s[i] == prev) {
            changes++;
            prev = getWinner(prev);
        } else {
            prev = s[i];
        }
    }
    
    cout << changes << endl;
    return 0;
}