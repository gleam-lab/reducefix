#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int maxBlocks = 0;
    int currentBlocks = 0;
    char prevChar = 'X'; // Start with a character that cannot be the previous character in a winning block

    // Calculate the number of winning blocks from the start
    for (int i = 0; i < n; i++) {
        if (prevChar != 'X' && prevChar != win(s[i])) {
            maxBlocks = max(maxBlocks, currentBlocks);
            currentBlocks = 1;
        } else {
            currentBlocks++;
        }
        prevChar = s[i];
    }
    maxBlocks = max(maxBlocks, currentBlocks); // Check if the last sequence is the longest

    // Reset variables for the calculation from the end
    prevChar = 'X';
    currentBlocks = 0;

    // Calculate the number of winning blocks from the end
    for (int i = n - 1; i >= 0; i--) {
        if (prevChar != 'X' && prevChar != win(s[i])) {
            maxBlocks = max(maxBlocks, currentBlocks);
            currentBlocks = 1;
        } else {
            currentBlocks++;
        }
        prevChar = s[i];
    }
    maxBlocks = max(maxBlocks, currentBlocks); // Check if the last sequence is the longest

    cout << maxBlocks << endl;
    return 0;
}

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // Non-playable characters can be ignored for winning block calculation
}