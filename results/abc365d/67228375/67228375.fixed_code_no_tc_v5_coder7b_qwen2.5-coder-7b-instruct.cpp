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
    int win_count = 0;
    char last_move = beats[s[0]];
    for (int i = 1; i < n; i++) {
        if (s[i] != last_move && beats[last_move] != s[i]) {
            win_count++;
        }
        last_move = s[i];
    }
    cout << win_count + 1 << endl; // Adding 1 because we always win at least one game

    return 0;
}