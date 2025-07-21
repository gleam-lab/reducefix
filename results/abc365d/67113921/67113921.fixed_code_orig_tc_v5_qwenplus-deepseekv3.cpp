#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    int wins = 0;
    char prev_move = '\0'; // Tracks the previous move in S
    char prev_winmove = '\0'; // Tracks the previous winning move used

    for (char c : S) {
        char winmove;
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else { // 'S'
            winmove = 'R';
        }
        if (winmove != prev_winmove) {
            wins++;
            prev_winmove = winmove;
        } else {
            // If the same winning move is used consecutively, it's only counted once per segment
            // So we skip counting until the segment changes
        }
        prev_move = c;
    }
    cout << wins;
    return 0;
}