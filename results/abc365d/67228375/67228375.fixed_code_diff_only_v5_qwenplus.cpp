#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'S'}, {'P', 'R'}, {'S', 'P'}}; // Correct: what each move beats
    map<char, char> beaten_by = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}}; // What beats each move
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    // Strategy 1: Start by playing what beats the first opponent's move
    int total_1 = 1;
    char last_move = beaten_by[s[0]]; // Our first move
    for (int i = 1; i < n; i++) {
        // If our previous move beats opponent's current move, we can repeat it
        if (beats[last_move] == s[i]) {
            // We continue with the same move
            continue;
        } else {
            // We need to change our move to beat opponent's current move
            last_move = beaten_by[s[i]];
            total_1++;
        }
    }
    
    // Strategy 2: Start by playing the same as opponent's first move
    int total_2 = 1;
    last_move = s[0]; // Our first move
    for (int i = 1; i < n; i++) {
        // If our previous move beats opponent's current move, we can repeat it
        if (beats[last_move] == s[i]) {
            continue;
        } else {
            // We need to change our move to beat opponent's current move
            last_move = beaten_by[s[i]];
            total_2++;
        }
    }
    
    cout << max(total_1, total_2) << endl;
    
    return 0;
}