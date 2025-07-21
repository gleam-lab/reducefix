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
    
    // Initialize counters
    int total_1 = 1;
    int total_2 = 1;
    char last_move_1 = beats[s[0]];
    char last_move_2 = s[0];

    // Iterate through the string to count moves
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move_1) {
            last_move_1 = s[i];
            continue;
        } else {
            last_move_1 = beats[s[i]];
            total_1++;
        }

        if (s[i] == last_move_2) {
            last_move_2 = s[i];
            continue;
        } else {
            last_move_2 = s[i];
            total_2++;
        }
    }

    // Output the maximum of the two counts
    cout << max(total_1, total_2) << endl;

    return 0;
}