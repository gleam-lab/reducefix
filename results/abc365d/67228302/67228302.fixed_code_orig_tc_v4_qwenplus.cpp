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
    char last_move = s[0];

    for (int i = 1; i < n; i++) {
        // If current move is beaten by the last chosen move, we can continue the same sequence
        if (beats[last_move] == s[i]) {
            continue;
        }
        // If current move beats the last chosen move, we must start a new sequence
        else if (beats[s[i]] == last_move) {
            last_move = s[i];
            total++;
        }
        // If same move or non-beating, we can keep the same representative
        else {
            // When moves are the same or form a cycle (like R and S), 
            // we update to ensure consistency but don't increase count
            if (s[i] != last_move) {
                last_move = s[i];
            }
        }
    }

    cout << total << endl;

    return 0;
}