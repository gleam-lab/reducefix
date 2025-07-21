#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unordered_map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};

    int n;
    cin >> n;
    string s;
    cin >> s;

    // Initialize variables to keep track of counts
    int count_same = 1;
    int count_diff = 0;

    // Iterate through the string starting from the second character
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i-1]) {
            // If current move is the same as the previous, increment count_same
            count_same++;
        } else {
            // If current move is different, update count_diff
            count_diff = max(count_diff, count_same + 1);
            count_same = 1;
        }
    }

    // Final check for the last segment
    count_diff = max(count_diff, count_same + 1);

    // The result is the maximum of count_diff and count_same
    cout << max(count_diff, count_same) << endl;

    return 0;
}