#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'S'}, {'P', 'R'}, {'S', 'P'}}; // Fixed: who each move beats
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    int total = 1;
    char opponent_move = s[0];
    char my_last_move = beats[opponent_move]; // My move that beats first opponent move

    for (int i = 1; i < n; i++) {
        char current_opponent = s[i];
        
        // If my previous move can also beat current opponent move
        if (beats[my_last_move] == current_opponent) {
            // I don't need to change my move
            continue;
        } else {
            // I need to change my move to beat current opponent move
            my_last_move = beats[current_opponent];
            total++;
        }
    }

    cout << total << endl;

    return 0;
}