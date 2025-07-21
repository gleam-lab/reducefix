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
    
    // Initialize variables to store counts of valid sequences
    int total_1 = 1; // Start with 1 because we always count the first move
    int total_2 = 1;
    char last_move_1 = s[0]; // Track the last move for the first sequence
    char last_move_2 = s[n-1]; // Track the last move for the second sequence
    
    // Iterate from the start to find the longest valid sequence starting with s[0]
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move_1) {
            last_move_1 = s[i];
            continue;
        }
        last_move_1 = s[i];
        total_1 += 1;
    }
    
    // Iterate from the end to find the longest valid sequence ending with s[n-1]
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == beats[last_move_2]) {
            last_move_2 = s[i];
            continue;
        }
        last_move_2 = s[i];
        total_2 += 1;
    }
    
    // Output the maximum of the two counts
    cout << max(total_1, total_2) << endl;

    return 0;
}