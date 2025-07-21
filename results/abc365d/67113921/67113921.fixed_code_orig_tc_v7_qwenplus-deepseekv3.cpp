#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    int wins = 0;
    char prev = '\0'; // Initialize to null character

    for (char c : S) {
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else { // 'S'
            winmove = 'R';
        }

        if (winmove != prev) {
            wins++;
            prev = winmove;
        } else {
            // Try to find an alternative move that still wins or at least doesn't lose
            // For example, if previous move was 'P' (counter to 'R'), and current is 'R' again,
            // we can't use 'P' again, so we might choose 'S' which ties with 'R' or another move.
            // But since we want to maximize wins, we might skip this move.
            // Alternatively, if the next move is different, we can use the optimal move then.
            // For now, just skip this move to avoid consecutive same moves.
            prev = '\0'; // Reset to allow next move to be chosen freely
        }
    }

    cout << wins << endl;
    return 0;
}