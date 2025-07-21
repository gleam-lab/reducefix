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

    // Strategy 1: Choose the move that beats the first character initially
    int total_1 = 1;
    char last_move_1 = beats[s[0]];
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move_1) {
            last_move_1 = s[i];  // opponent's current move becomes the new last move
        } else {
            last_move_1 = beats[s[i]];  // choose the move that beats current opponent move
            total_1++;
        }
    }

    // Strategy 2: Start with the opponent's first move
    int total_2 = 0;
    char last_move_2 = s[0];
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move_2) {
            last_move_2 = s[i];  // opponent's current move becomes the new last move
        } else {
            last_move_2 = beats[s[i]];  // choose the move that beats current opponent move
            total_2++;
        }
    }

    cout << max(total_1, total_2) << endl;

    return 0;
}