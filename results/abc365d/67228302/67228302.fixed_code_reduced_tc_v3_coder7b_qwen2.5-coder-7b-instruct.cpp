#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;
    int total = 0;
    char last_move = '.';
    for (int i = 0; i < n; i++) {
        if (s[i] != last_move && beats[last_move] != s[i]) {
            last_move = s[i];
            total += 1;
        } else if (last_move == '.' || beats[last_move] == s[i]) {
            if (i == n - 1) {
                total += 1;
            } else {
                last_move = beats[s[i]];
                total += 1;
            }
        }
    }
    cout << total << endl;

    return 0;
}