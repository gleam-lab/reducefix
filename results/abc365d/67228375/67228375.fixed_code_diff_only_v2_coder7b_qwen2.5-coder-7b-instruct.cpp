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
    
    // Initialize counters for both strategies
    int total_1 = 1; // Strategy where we always play what beats the previous move
    int total_2 = 1; // Strategy where we always play the same as the previous move
    
    char last_move_1 = beats[s[0]]; // Last move for strategy 1
    char last_move_2 = s[0];       // Last move for strategy 2
    
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move_1) { // Check if current move beats the last move of strategy 1
            last_move_1 = s[i];
            continue;
        }
        last_move_1 = beats[s[i]];
        total_1 += 1;
    }
    
    for (int i = 1; i < n; i++) {
        if (s[i] == last_move_2) { // Check if current move is the same as the last move of strategy 2
            last_move_2 = s[i];
            continue;
        }
        last_move_2 = s[i];
        total_2 += 1;
    }
    
    cout << max(total_1, total_2) << endl;

    return 0;
}