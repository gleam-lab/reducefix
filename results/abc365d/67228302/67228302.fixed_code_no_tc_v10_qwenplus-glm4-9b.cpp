#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;

    char last_move = s[0];  // The first character determines the initial last_move
    bool is_better = (last_move == beats[s[1]]);  // Check if the second character beats the first

    for (int i = 2; i < n; i++) {
        // Update last_move to the one that beats s[i]
        last_move = beats[s[i]];
        
        // Check if the current move beats the last move
        if (last_move == s[i]) {
            is_better = !is_better;  // Toggle the is_better state
        }
    }

    // Output the result based on whether there was an alternating switch of beats
    cout << (is_better ? 1 : 0) << endl;

    return 0;
}