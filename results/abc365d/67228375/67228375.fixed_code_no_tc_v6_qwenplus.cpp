#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'S'}, {'P', 'R'}, {'S', 'P'}}; // Fixed: R beats S, P beats R, S beats P
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    // Try both starting options: start with the move that beats first opponent move, or start with first opponent move
    int total_1 = 1; // Starting with the move that beats s[0]
    char last_move = beats[s[0]];
    
    for (int i = 1; i < n; i++) {
        // If our last move loses to current opponent move, we need to change strategy
        if (beats[last_move] == s[i]) {
            last_move = beats[s[i]];
            total_1 += 1;
        }
        // Otherwise, we can keep the same move
    }
    
    int total_2 = 1; // Starting with s[0] itself
    last_move = s[0];
    
    for (int i = 1; i < n; i++) {
        // If our last move loses to current opponent move, we need to change strategy
        if (beats[last_move] == s[i]) {
            last_move = beats[s[i]];
            total_2 += 1;
        }
        // Otherwise, we can keep the same move
    }
    
    cout << max(total_1, total_2) << endl;
    
    return 0;
}