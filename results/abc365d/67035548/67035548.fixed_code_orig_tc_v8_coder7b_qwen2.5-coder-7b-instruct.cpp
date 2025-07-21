#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int maxWins = 0;
    int currentWins = 0;
    int maxLosses = 0;
    int currentLosses = 0;

    char prev = 'A';

    for (int i = 0; i < n; ++i) {
        char move = s[i];

        if (move == 'X') {
            break;
        }

        if (prev != move) {
            if (move == 'R' && prev == 'P') {
                currentWins = 1;
                currentLosses = 0;
            } else if (move == 'P' && prev == 'S') {
                currentWins = 1;
                currentLosses = 0;
            } else if (move == 'S' && prev == 'R') {
                currentWins = 1;
                currentLosses = 0;
            } else {
                currentWins = 0;
                currentLosses = 1;
            }
        } else {
            if (move == 'R' && prev == 'P') {
                currentWins++;
                currentLosses = 0;
            } else if (move == 'P' && prev == 'S') {
                currentWins++;
                currentLosses = 0;
            } else if (move == 'S' && prev == 'R') {
                currentWins++;
                currentLosses = 0;
            } else {
                currentWins = 0;
                currentLosses++;
            }
        }

        maxWins = max(maxWins, currentWins);
        maxLosses = max(maxLosses, currentLosses);

        prev = move;
    }

    cout << max(maxWins, maxLosses) << endl;

    return 0;
}