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
    char last_move = '\0';
    
    for (int i = 0; i < n; i++) {
        char current = s[i];
        if (last_move == '\0') {
            // First move: choose what beats current
            last_move = beats[current];
            wins++;
        } else {
            if (beats[current] != last_move) {
                // Can choose a move that beats current
                last_move = beats[current];
                wins++;
            } else if (current != last_move) {
                // Need to choose current to avoid losing
                last_move = current;
            }
        }
    }
    
    cout << wins << endl;
    return 0;
}