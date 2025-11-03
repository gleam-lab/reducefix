#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'S'}, {'P', 'R'}, {'S', 'P'}}; // Fixed: corrected what each move beats
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    int total = 1;
    char opponent_move = s[0];
    
    for (int i = 1; i < n; i++) {
        // We need to choose a move that beats the current opponent's move
        char our_move = beats[opponent_move];
        
        // If our winning move against previous opponent move also beats current opponent move
        if (beats[our_move] == s[i]) {
            // We don't need to change our strategy
            opponent_move = s[i];
            continue;
        }
        
        // Otherwise we need a new round with a new strategy
        total++;
        opponent_move = s[i];
    }
    
    cout << total << endl;
    return 0;
}