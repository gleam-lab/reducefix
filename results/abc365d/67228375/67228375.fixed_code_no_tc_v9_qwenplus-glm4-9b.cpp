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

    // Initialize counters for the two possible winning sequences
    int total_1 = 0;
    int total_2 = 0;

    // First pass through the string to find total_1
    for (int i = 0; i < n; i++) {
        if (beats[s[i]] == s[(i + 1) % n]) {
            total_1++;
        }
    }

    // Second pass through the string to find total_2
    int last_move = s[0];
    total_2 = 1;
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move) {
            total_2++;
            last_move = s[i];
        }
    }

    // Output the maximum of the two totals
    cout << max(total_1, total_2) << endl;

    return 0;
}