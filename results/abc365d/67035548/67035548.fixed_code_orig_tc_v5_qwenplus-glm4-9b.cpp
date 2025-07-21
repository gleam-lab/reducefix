#include <iostream>
#include <string>

using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // 'X' should not be in the move set
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ansMax = 0; // To store the maximum number of consecutive wins
    int currentCount = 0; // To store the current count of consecutive wins

    // First pass, moving from left to right
    for (int i = 0; i < n; i++) {
        if (s[i] == win(s[i - 1])) { // If the current move is a win for the player
            currentCount++;
        } else if (s[i] != s[i - 1]) { // If the current move is a win for the opponent
            currentCount = 1; // Reset the win count
        }
        ansMax = max(ansMax, currentCount); // Update the maximum win count
    }

    // Second pass, moving from right to left
    currentCount = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == win(s[i + 1])) {
            currentCount++;
        } else if (s[i] != s[i + 1]) {
            currentCount = 1;
        }
        ansMax = max(ansMax, currentCount);
    }

    cout << ansMax << endl;

    return 0;
}