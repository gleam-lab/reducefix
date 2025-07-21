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

    int longest_sequence = 0;
    int current_sequence = 1;
    char last_move = beats[s[0]];

    // First pass to find the longest sequence starting from the first character
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] != last_move) {
            current_sequence++;
            if (current_sequence > longest_sequence) {
                longest_sequence = current_sequence;
            }
        } else {
            current_sequence = 1;
        }
        last_move = s[i];
    }
    // If the last sequence was the longest
    if (current_sequence > longest_sequence) {
        longest_sequence = current_sequence;
    }

    // Reset for second pass
    current_sequence = 1;
    last_move = s[0];

    // Second pass to find the longest sequence
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] != last_move) {
            current_sequence++;
            if (current_sequence > longest_sequence) {
                longest_sequence = current_sequence;
            }
        } else {
            current_sequence = 1;
        }
        last_move = s[i];
    }

    cout << longest_sequence << endl;

    return 0;
}