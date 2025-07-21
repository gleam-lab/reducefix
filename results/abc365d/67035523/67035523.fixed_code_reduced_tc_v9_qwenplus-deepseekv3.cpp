#include <iostream>
#include <string>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // should not happen
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int changes = 0;
    
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i+1]) {
            // No immediate issue, but might need to change if previous changes affect
            continue;
        }
        if (win(s[i]) != s[i+1]) {
            changes++;
            s[i+1] = win(s[i]); // change s[i+1] to lose to s[i]
        }
    }
    
    cout << changes << endl;
    return 0;
}