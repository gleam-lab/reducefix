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

    int total = 0; // Initialize total to 0 since we can't have a total of 1 in the given context
    char last_move = beats[s[0]]; // Get the last known move
    for (int i = 1; i < n; i++) { // Start from the second character
        char next_move = beats[s[i]]; // Determine the next move that beats the current one
        if (next_move != last_move) { // If the next move beats the current move, increment total
            total++;
            last_move = next_move; // Update last_move to the current move
        }
    }
    cout << total << endl;

    return 0;

}