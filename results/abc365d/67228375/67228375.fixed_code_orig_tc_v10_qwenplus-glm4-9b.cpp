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

    // To count the maximum length of a sequence where characters beat the previous character
    int max_length = 1;
    int current_length = 1;

    // Iterate from the second character to the end of the string
    for (int i = 1; i < n; ++i) {
        // Check if the current character beats the previous character
        if (beats[s[i]] == s[i - 1]) {
            current_length++;
        } else {
            // Update the maximum length if the current sequence is longer
            if (current_length > max_length) {
                max_length = current_length;
            }
            // Reset the current length
            current_length = 1;
        }
    }
    // Update the maximum length after the last sequence
    if (current_length > max_length) {
        max_length = current_length;
    }

    cout << max_length << endl;

    return 0;
}