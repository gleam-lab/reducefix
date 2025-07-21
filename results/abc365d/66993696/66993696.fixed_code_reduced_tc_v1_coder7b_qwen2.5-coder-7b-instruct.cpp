#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> winCount(3, 0); // Array to count wins against R, P, S
    vector<char> lastMove(n + 1, '\0'); // To store the last move made by Takahashi

    for (int i = 1; i <= n; ++i) {
        char opponentMove = s[i - 1];
        if (opponentMove == 'R') {
            lastMove[i] = 'P'; // Takahashi plays Paper
            winCount[0]++;
        } else if (opponentMove == 'P') {
            lastMove[i] = 'S'; // Takahashi plays Scissors
            winCount[1]++;
        } else { // opponentMove == 'S'
            lastMove[i] = 'R'; // Takahashi plays Rock
            winCount[2]++;
        }

        // If the next move is the same as the current one, change it
        if (i < n && lastMove[i] == lastMove[i + 1]) {
            if (lastMove[i] == 'P') lastMove[i] = 'S';
            else if (lastMove[i] == 'R') lastMove[i] = 'P';
            else lastMove[i] = 'R';

            // Adjust the win count accordingly
            if (lastMove[i] == 'P') winCount[0]--;
            else if (lastMove[i] == 'R') winCount[1]--;
            else winCount[2]--;
        }
    }

    // The maximum number of games Takahashi could have won
    cout << *max_element(winCount.begin(), winCount.end()) << endl;

    return 0;
}