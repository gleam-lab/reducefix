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
    char winmove = 'R';  // Initial winning move for 'R'
    char prev = 'R';      // Previous move is initially 'R'
    for (char c : S) {
        if (c == 'R') {
            winmove = 'P';  // If previous was 'R', the winning move now is 'P'
        } else if (c == 'P') {
            winmove = 'S';  // If previous was 'P', the winning move now is 'S'
        } else if (c == 'S') {
            winmove = 'R';  // If previous was 'S', the winning move now is 'R'
        }

        if (prev != 'R' && c == winmove && prev != c) {
            wins++;  // Increment wins if the current move is the winning move and it's not the exact same move
            prev = c;  // Update the previous move to the current one
        } else {
            prev = winmove;  // The previous move is now the winning move
        }
    }
    cout << wins;
}