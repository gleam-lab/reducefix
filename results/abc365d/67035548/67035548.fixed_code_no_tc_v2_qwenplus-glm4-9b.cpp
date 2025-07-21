#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    // Initialize counters for the number of wins from left and right
    int win_from_left = 0, win_from_right = 0;

    // First pass: count wins from left to right
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') {
            if (i > 0 && s[i - 1] == 'P') win_from_left++;
        } else if (s[i] == 'S') {
            if (i > 0 && s[i - 1] == 'R') win_from_left++;
        }
    }

    // Second pass: count wins from right to left
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'R') {
            if (i < n - 1 && s[i + 1] == 'P') win_from_right++;
        } else if (s[i] == 'S') {
            if (i < n - 1 && s[i + 1] == 'R') win_from_right++;
        }
    }

    // The result is the maximum of the two counts
    cout << max(win_from_left, win_from_right) << endl;

    return 0;
}