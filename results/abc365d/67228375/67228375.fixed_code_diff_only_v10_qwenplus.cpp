#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'S'}, {'P', 'R'}, {'S', 'P'}}; // Fixed: what each move beats
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    // Strategy 1: Start by playing the move that beats the first opponent's move
    int total_1 = 1;
    char current_move = beats[s[0]]; // Our first move beats opponent's first move
    
    for (int i = 1; i < n; i++) {
        // If our current move would lose to or draw with opponent's previous move,
        // we need to change our strategy at position i
        if (beats[s[i-1]] != current_move) {
            total_1++;
        }
        current_move = beats[s[i]];
    }

    // Strategy 2: Start by playing the same as opponent's first move
    int total_2 = 1;
    current_move = s[0];
    
    for (int i = 1; i < n; i++) {
        if (beats[s[i-1]] != current_move) {
            total_2++;
        }
        current_move = beats[s[i]];
    }

    cout << max(total_1, total_2) << endl;

    return 0;
}