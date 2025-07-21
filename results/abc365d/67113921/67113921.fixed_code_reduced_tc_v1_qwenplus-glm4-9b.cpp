#include <iostream>
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
            winmove = 'P'; // Rock beats Scissors
        } else if (c == 'P') {
            winmove = 'S'; // Paper beats Rock
        } else if (c == 'S') {
            winmove = 'R'; // Scissors beats Paper
        }
        // Increment wins if the current winning move is different from the previous one
        if (winmove != prev) {
            wins++;
            prev = winmove;
        }
    }
    cout << wins;
}