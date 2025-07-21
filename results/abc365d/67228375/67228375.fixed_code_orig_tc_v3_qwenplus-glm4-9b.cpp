#include <iostream>
#include <unordered_map>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unordered_map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;

    int total_1 = 0; // Total number of winning moves for the first player
    int total_2 = 0; // Total number of winning moves for the second player
    char current_player = s[0]; // The player who starts the game

    for (int i = 1; i < n; ++i) {
        if (beats[s[i]] == current_player) {
            // Current player wins, so switch the player
            current_player = s[i];
            // Increment total_2 because the second player wins this turn
            total_2++;
        } else {
            // First player wins this turn
            total_1++;
        }
    }

    // Output the maximum of total_1 and total_2
    cout << max(total_1, total_2) << endl;

    return 0;
}