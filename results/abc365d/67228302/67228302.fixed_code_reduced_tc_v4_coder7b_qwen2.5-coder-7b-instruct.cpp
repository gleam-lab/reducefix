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
    
    // Initialize variables
    int total_wins = 0;
    char last_takahashi_move = 'X'; // Initial value that will be overwritten
    
    for (int i = 0; i < n; i++) {
        char takahashi_move = s[i];
        
        // If it's the first move or Takahashi hasn't lost yet
        if (i == 0 || beats[last_takahashi_move] != s[i]) {
            total_wins++;
            last_takahashi_move = takahashi_move;
        } else {
            // Find a move that beats Aoki's current move
            for (auto& [move, beaten_by] : beats) {
                if (beaten_by == s[i]) {
                    takahashi_move = move;
                    break;
                }
            }
            total_wins++;
            last_takahashi_move = takahashi_move;
        }
    }

    cout << total_wins << endl;

    return 0;
}