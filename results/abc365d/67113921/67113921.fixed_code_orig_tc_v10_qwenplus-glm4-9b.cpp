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
    char winmove, prev = 'a';
    for (char c : S) {
        if (c == 'R') {
            winmove = 'P';
        } else if (c == 'P') {
            winmove = 'S';
        } else if (c == 'S') {
            winmove = 'R';
        }
        // Check if the current character is different from the previous winning move
        if (c != winmove && c != prev) {
            wins++;
            prev = winmove;  // Update prev to the current winning move only if it is different from the previous character
        } else {
            prev = c;  // Otherwise, update prev to the current character
        }
    }
    cout << wins;
}