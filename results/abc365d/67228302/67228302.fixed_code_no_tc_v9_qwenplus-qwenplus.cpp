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
    char last_used = beats[s[0]]; // First move is countering the first character

    for (int i = 1; i < n; ++i) {
        char current_counter = beats[s[i]];

        if (current_counter == last_used) {
            // No change needed, continue using same move
            continue;
        } else {
            // Need to switch move
            last_used = current_counter;
            total++;
        }
    }

    cout << total << endl;

    return 0;
}