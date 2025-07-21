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

    // Try both starting options: first move is either the one that beats s[0], or not
    auto calc_moves = [&](char start) {
        int total = 1;
        char last_move = start;
        for (int i = 0; i < n; ++i) {
            if (i == 0 && start == beats[s[0]]) continue; // already counted initial move
            if (beats[s[i]] == last_move) {
                last_move = s[i];
            } else {
                last_move = beats[s[i]];
                total += 1;
            }
        }
        return total;
    };

    // First option: start with what beats first character
    int total_1 = calc_moves(beats[s[0]]);
    
    // Second option: start with the first character itself
    int total_2 = calc_moves(s[0]);

    cout << max(total_1, total_2) << endl;

    return 0;
}