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

    // Count the number of times we need to change our move
    // We start by choosing the move that beats the first opponent's move
    int total_1 = 0;
    char current_move = beats[s[0]]; // Our move that beats opponent's first move
    for (int i = 0; i < n; i++) {
        if (current_move != beats[s[i]]) {
            total_1++;
            current_move = beats[s[i]];
        }
    }

    // Try starting with the same move as opponent's first move
    int total_2 = 0;
    current_move = s[0]; // Start with same move as opponent
    for (int i = 0; i < n; i++) {
        if (current_move != beats[s[i]]) {
            total_2++;
            current_move = beats[s[i]];
        }
    }

    // The answer is the minimum number of changes needed
    cout << min(total_1, total_2) << endl;

    return 0;
}