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

    // Try both starting possibilities: either start with the beat of first move or not
    int total_1 = 1; // Case 1: Start by playing the move that beats s[0]
    char last_move = beats[s[0]];
    
    for (int i = 1; i < n; i++) {
        // If current opponent move beats our last move, we must have lost and restarted
        if (beats[s[i]] == last_move) {
            total_1++;
            last_move = beats[s[i]];
        } else {
            // We can continue the sequence
            last_move = beats[s[i]];
        }
    }

    int total_2 = 1; // Case 2: Start by playing s[0] itself (so we tie or lose initially)
    last_move = s[0];
    
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move) {
            total_2++;
            last_move = beats[s[i]];
        } else {
            last_move = beats[s[i]];
        }
    }

    cout << max(total_1, total_2) << endl;

    return 0;
}