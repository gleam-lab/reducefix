#include <bits/stdc++.h>
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

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    // Strategy 1: Start by playing what beats the first opponent move
    int total_1 = 1;
    char my_move = beats[s[0]];
    for (int i = 1; i < n; i++) {
        // If my current move beats opponent's current move, I survive
        if (beats[s[i]] != my_move) {
            total_1++;
        }
        my_move = beats[s[i]]; // For next round, play what beats opponent's current move
    }

    // Strategy 2: Start by playing the same as first opponent move
    int total_2 = 1;
    my_move = s[0];
    for (int i = 1; i < n; i++) {
        // If my current move beats opponent's current move, I survive
        if (beats[s[i]] != my_move) {
            total_2++;
        }
        my_move = beats[s[i]]; // For next round, play what beats opponent's current move
    }

    cout << max(total_1, total_2) << endl;

    return 0;
}