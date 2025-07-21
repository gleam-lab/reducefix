#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int wins = 0;
    char current = beats[s[0]];
    wins++;
    
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            // No need to change if same move continues
            continue;
        }
        // Change to the move that beats the current opponent move
        current = beats[s[i]];
        wins++;
    }
    
    cout << wins << endl;
    
    return 0;
}