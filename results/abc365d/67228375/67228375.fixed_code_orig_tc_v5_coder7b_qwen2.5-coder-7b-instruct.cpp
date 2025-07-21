#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> lengths(n, 1); // Lengths of consecutive identical moves
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            lengths[i] = lengths[i - 1] + 1;
        }
    }

    int total_moves = 0;
    for (int length : lengths) {
        total_moves += (length + 1) / 2;
    }

    cout << total_moves << endl;

    return 0;
}