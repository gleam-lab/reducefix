#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'S'}, {'P', 'R'}, {'S', 'P'}}; // Fixed: R beats S, P beats R, S beats P
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    int total = 1;
    char our_last_move = beats[s[0]]; // Our move that beats opponent's first move

    for (int i = 1; i < n; i++) {
        char our_current_beat = beats[s[i]]; // What we need to play to beat opponent's current move
        
        // If our previous move doesn't interfere or we can use the same winning strategy
        // We need to check if we can have a continuous sequence
        if (our_current_beat != our_last_move) {
            total++;
        }
        our_last_move = our_current_beat;
    }

    cout << total << endl;

    return 0;
}