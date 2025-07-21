#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    // Initialize variables to keep track of the maximum wins
    int maxWins = 0;
    int currentWins = 0;

    // Iterate through the sequence of moves
    for (int i = 0; i < n; ++i) {
        char prevMove = (i == 0 ? 'A' : s[i - 1]);
        char currentMove = s[i];

        // Check if the current move beats the previous move
        if ((currentMove == 'P' && prevMove == 'S') ||
            (currentMove == 'R' && prevMove == 'P') ||
            (currentMove == 'S' && prevMove == 'R')) {
            currentWins++;
        } else {
            currentWins = 1;
        }

        // Update the maximum wins found so far
        maxWins = max(maxWins, currentWins);
    }

    cout << maxWins << endl;
    return 0;
}