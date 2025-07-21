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
    int total = 1; // We start with 1 because we assume the first move doesn't beat any move
    char last_move = beats[s[0]];
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move) {
            continue; // Do nothing because beat condition is already met by the previous move
        }
        // If the current move does not beat the previous move, reset last_move and increment total
        last_move = s[i];
        total++;
    }
    cout << total << endl;

    return 0;
}