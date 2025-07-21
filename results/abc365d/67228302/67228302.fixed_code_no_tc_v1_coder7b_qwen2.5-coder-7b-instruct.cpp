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
    
    // Initialize the count of wins and the last move taken by Takahashi
    int wins = 0;
    char last_takahashi_move = ' '; // This will store Takahashi's last move
    
    for (int i = 0; i < n; i++) {
        // If Takahashi can win against Aoki's current move, he should do so
        if (s[i] != beats[last_takahashi_move]) {
            wins++;
        }
        
        // Update Takahashi's last move to something that doesn't lose to Aoki's current move
        if (s[i] == 'R') {
            last_takahashi_move = 'P';
        } else if (s[i] == 'P') {
            last_takahashi_move = 'S';
        } else { // s[i] == 'S'
            last_takahashi_move = 'R';
        }
    }

    cout << wins << endl;

    return 0;
}