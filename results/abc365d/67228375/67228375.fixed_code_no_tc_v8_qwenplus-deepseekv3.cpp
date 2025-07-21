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
    
    int wins = 0;
    char last_move = beats[s[0]];
    wins++;  // First move always wins
    
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            // If same as previous, we can win by continuing same move
            last_move = beats[s[i]];
            wins++;
        } else {
            // Otherwise, choose move that beats current opponent
            last_move = beats[s[i]];
            wins++;
        }
    }
    
    cout << wins << endl;
    
    return 0;
}