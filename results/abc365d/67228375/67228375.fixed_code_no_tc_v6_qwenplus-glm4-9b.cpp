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

    int total_1 = 0; // This should be initialized to 0
    char last_move = beats[s[0]]; // Correct, as we start with the first character
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move) {
            last_move = s[i];
            continue;
        }
        total_1++; // Increment only when the current character beats the last move
    }

    // For efficiency, we can use the same last_move value from the first loop
    int total_2 = 0;
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] != last_move) {
            total_2++; // Increment only when the current character does not beat the last move
            last_move = s[i]; // Update the last move
        }
    }

    cout << max(total_1, total_2) << endl;

    return 0;
}