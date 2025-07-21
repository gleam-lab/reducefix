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
    
    // Initialize variables to count wins and track the last move
    int wins = 0;
    char last_move = s[0];
    bool first_turn = true;
    
    for (int i = 0; i < n; i++) {
        if (first_turn || s[i] != last_move) {
            wins++;
            last_move = beats[s[i]];
            first_turn = false;
        } else {
            last_move = s[i];
        }
    }

    cout << wins << endl;

    return 0;
}