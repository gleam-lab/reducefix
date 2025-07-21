#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int maxStreak = 0;
    int currentStreak = 1;

    // Calculate the maximum streak from the start
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            currentStreak++;
            if (currentStreak > maxStreak) {
                maxStreak = currentStreak;
            }
        } else {
            currentStreak = 1;
        }
    }

    // Calculate the maximum streak from the end
    currentStreak = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] != s[i + 1]) {
            currentStreak++;
            if (currentStreak > maxStreak) {
                maxStreak = currentStreak;
            }
        } else {
            currentStreak = 1;
        }
    }

    cout << maxStreak << endl;
    return 0;
}