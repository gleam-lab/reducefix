#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'S'}, {'P', 'R'}, {'S', 'P'}}; // Fixed: Correct what each move beats
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
        char needed_move = beats[s[i]]; // What we need to play to beat opponent's current move
        
        // If our previous move can also beat the current opponent move, we don't need to change
        if (s[i] == s[i-1]) {
            // Same opponent move - we can keep using the same winning move
            continue;
        } else {
            // Different opponent move - we need to switch to the move that beats it
            total++;
        }
    }
    
    cout << total << endl;
    return 0;
}