#include <iostream>
#include <map>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;
    int total_wins = 0;

    char last_move = beats[s[0]];
    int after_first_move = (beats[s[1]] == last_move) ? 1 : 0; // First move wins if the first and second move beat each other
    last_move = s[1]; // Update last_move to the second character of the sequence

    for (int i = 2; i < n; i++) {
        if (beats[s[i]] == last_move) {
            continue; // If the current move does not beat the last move, do nothing
        }
        if (beats[s[i]] == beats[s[i - 1]]) {
            total_wins++; // A win if the current move beats the previous move
        }
        last_move = s[i]; // Update last_move to the current move
    }

    if (after_first_move > 0) {
        total_wins += after_first_move; // Add the wins after the first move
    }

    cout << total_wins << endl;

    return 0;
}