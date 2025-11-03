#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'S'}, {'P', 'R'}, {'S', 'P'}}; // Corrected: beats[X] should give what X beats
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    int total = 1;
    char opponent_last = s[0];
    
    for (int i = 1; i < n; i++) {
        // We can use the same move as long as it beats current opponent's move
        // If our previous move doesn't beat current opponent move, we need a new move
        if (beats[opponent_last] != s[i]) {
            total++;
        }
        opponent_last = s[i];
    }
    
    cout << total << endl;
    return 0;
}