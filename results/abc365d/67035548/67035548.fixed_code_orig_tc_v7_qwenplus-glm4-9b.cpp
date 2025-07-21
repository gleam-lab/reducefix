#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    // We need to determine the sequence where the current character can win over the previous one
    vector<char> prevChar(n, 'X'); // Initialize with a non-relevant character
    int maxWinStreak = 0, curWinStreak = 0;
    
    for (int i = 0; i < n; ++i) {
        char currentChar = s[i];
        // Check if the current character can win over the previous one
        if ((currentChar == 'R' && prevChar[i-1] == 'P') ||
            (currentChar == 'P' && prevChar[i-1] == 'S') ||
            (currentChar == 'S' && prevChar[i-1] == 'R')) {
            curWinStreak++;
        } else {
            maxWinStreak = max(maxWinStreak, curWinStreak);
            curWinStreak = 0;
        }
        prevChar[i] = currentChar;
    }
    // Check the last streak
    maxWinStreak = max(maxWinStreak, curWinStreak);

    cout << maxWinStreak;
    return 0;
}