#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unordered_map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;

    if (n == 0 || n < 2) { // If there are less than 2 moves, no need for comparison
        cout << n << endl;
        return 0;
    }

    cin >> s;
    char last_move = beats[s[0]];
    int total = 1;

    for (int i = 1; i < n; i++) {
        if (beats[s[i]] != last_move) {
            total++;
            last_move = beats[s[i]];
        }
    }

    cout << total << endl;

    return 0;
}