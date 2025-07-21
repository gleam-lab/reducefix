#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    int wins = 0;
    char winmove = 'a';
    char prev = 'a';

    // Mapping the winning moves for each character
    char move_map[3] = {'P', 'S', 'R'};

    for (int i = 0; i < N; ++i) {
        if (S[i] == 'R') {
            winmove = 'P';
        } else if (S[i] == 'P') {
            winmove = 'S';
        } else if (S[i] == 'S') {
            winmove = 'R';
        }

        // Increment wins if the current winning move is different from the previous one
        if (winmove != prev) {
            wins++;
            prev = winmove;
        }
    }

    cout << wins;
}