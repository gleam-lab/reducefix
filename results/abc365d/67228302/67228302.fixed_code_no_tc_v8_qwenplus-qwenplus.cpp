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

    int total = 1; // At least one move is needed
    char last_used = beats[s[0]]; // First move is the counter of opponent's move

    for (int i = 1; i < n; ++i) {
        char current_counter = beats[s[i]];

        // If the current counter is the same as the last used move, we continue using it
        if (current_counter == last_used) {
            continue;
        }

        // Otherwise, we switch to the new move
        last_used = current_counter;
        total += 1;
    }

    cout << total << endl;

    return 0;
}