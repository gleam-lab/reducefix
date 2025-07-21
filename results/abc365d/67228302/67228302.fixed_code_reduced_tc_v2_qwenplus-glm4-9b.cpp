#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n < 2) {
        // If there is only one move, there's only one sequence.
        cout << 1 << endl;
    } else {
        int total = 2; // There are at least two sequences: [PPR] and [RPP]
        char last_move = beats[s[0]];
        for (int i = 2; i < n; i++) {
            if (beats[s[i]] == last_move) {
                // If the current move beats the last move, it's a new sequence.
                total++;
                last_move = s[i];
            }
        }
        cout << total << endl;
    }

    return 0;
}