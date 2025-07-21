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
    
    // Initialize counters for wins when starting with each move
    int win_start_R = 0;
    int win_start_P = 0;
    int win_start_S = 0;
    
    // Determine initial moves based on the first character of Aoki's moves
    char first_char = s[0];
    if (first_char == 'R') win_start_R++;
    else if (first_char == 'P') win_start_P++;
    else win_start_S++;
    
    // Iterate through Aoki's moves to determine optimal responses for Takahashi
    for (int i = 1; i < n; i++) {
        if (s[i] == 'R') {
            if (last_move == 'S') win_start_R++;
            else if (last_move == 'P') win_start_P--;
        } else if (s[i] == 'P') {
            if (last_move == 'R') win_start_P++;
            else if (last_move == 'S') win_start_S--;
        } else { // s[i] == 'S'
            if (last_move == 'P') win_start_S++;
            else if (last_move == 'R') win_start_R--;
        }
        last_move = beats[s[i]];
    }
    
    // Output the maximum number of wins
    cout << max({win_start_R, win_start_P, win_start_S}) << endl;

    return 0;

}