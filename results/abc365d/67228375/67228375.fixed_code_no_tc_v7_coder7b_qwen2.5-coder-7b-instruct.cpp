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
    int total_1 = 0, total_2 = 0;
    char last_move_1 = s[0], last_move_2 = s[n-1];

    // Counting for the first strategy
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] != last_move_1) {
            total_1++;
            last_move_1 = beats[s[i]];
        }
    }

    // Counting for the second strategy
    for (int i = n - 2; i >= 0; i--) {
        if (beats[s[i]] != last_move_2) {
            total_2++;
            last_move_2 = beats[s[i]];
        }
    }

    // Output the maximum of the two strategies
    cout << max(total_1 + 1, total_2 + 1) << endl;

    return 0;
}