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
    int total = 0;
    char last_move = beats[s[0]];
    for (int i = 1; i < n; i++) {
        if (s[i] == last_move) {
            last_move = beats[s[i]];
            continue;
        } else if (beats[last_move] == s[i]) {
            total += 1;
        }
        last_move = beats[s[i]];
    }
    cout << total + 1 << endl; // Add one for the first move

    return 0;

}