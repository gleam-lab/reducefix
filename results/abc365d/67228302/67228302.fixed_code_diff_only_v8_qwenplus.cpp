#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'S'}, {'P', 'R'}, {'S', 'P'}}; // Correct mapping: what each move beats
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
        // If current opponent move is the same as what we beat, we can continue with same strategy
        if (s[i] == s[i-1]) {
            continue;
        }
        // Otherwise, we need a new strategy
        total++;
    }
    
    cout << total << endl;
    return 0;
}