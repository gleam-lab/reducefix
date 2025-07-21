#include <iostream>
using namespace std;
#define endl '\n'
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;
    int total = 1; // Initialize total to 1 as the first move is always counted
    char last_move = s[0]; // Initialize the last move as the first character
    for (int i = 1; i < n; i++) {
        // Check if the current move beats the last move
        if (beats[s[i]] == last_move) {
            total += 1; // Increment total as it's a valid move
            last_move = s[i]; // Update last move to the current character
        }
    }
    cout << total << endl;

    return 0;
}