#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

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
    
    int total = 1;
    char current = beats[s[0]];
    
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) {
            current = beats[s[i]];
            total++;
        } else if (i < n-1 && beats[s[i+1]] == current) {
            // If the next move would be beaten by current choice, keep it
            continue;
        } else {
            // Otherwise change to beat this move
            current = beats[s[i]];
            total++;
        }
    }
    
    cout << total << endl;

    return 0;
}