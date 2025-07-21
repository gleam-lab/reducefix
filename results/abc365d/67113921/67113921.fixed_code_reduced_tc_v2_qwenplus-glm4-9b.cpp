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

    // Initialize the winmove array where:
    // - winmove[R] is 'P' (Rock beats Scissors)
    // - winmove[P] is 'S' (Paper beats Rock)
    // - winmove[S] is 'R' (Scissors beats Paper)
    char winmove[3] = {'P', 'S', 'R'};
    
    char prev = 'a';
    for (char c : S) {
        if (winmove[c - 'R'] != prev) {
            wins++;
            prev = winmove[c - 'R'];
        }
    }

    cout << wins;

    return 0;
}