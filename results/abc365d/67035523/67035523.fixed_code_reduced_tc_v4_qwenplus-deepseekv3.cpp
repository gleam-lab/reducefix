#include <iostream>
#include <string>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // default case, though not expected
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int changes = 0;
    
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == win(s[i+1])) {
            continue; // current move beats the next, no change needed
        } else {
            changes++; // need to change either current or next move
            i++; // skip the next move since we've accounted for it
        }
    }
    
    cout << changes << endl;
    return 0;
}