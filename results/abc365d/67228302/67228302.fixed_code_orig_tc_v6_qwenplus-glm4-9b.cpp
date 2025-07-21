#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int total = 0;
    int current_streak = 1;

    // Loop through the string to calculate the number of winning streaks
    for (int i = 1; i < s.length(); i++) {
        // Check if the current move beats the previous move
        if (s[i-1] == 'R' && s[i] == 'P') {
            current_streak++;
        } else if (s[i-1] == 'P' && s[i] == 'S') {
            current_streak++;
        } else if (s[i-1] == 'S' && s[i] == 'R') {
            current_streak++;
        } else {
            // If the current move does not continue a winning streak, check if there was a streak
            if (current_streak > 1) {
                total += current_streak;
                current_streak = 1; // Reset the streak counter
            }
        }
    }

    // Check for the last streak at the end of the string
    if (current_streak > 1) {
        total += current_streak;
    }

    cout << total << endl;

    return 0;
}