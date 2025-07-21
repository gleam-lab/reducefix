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
    int total = 0; // Initialize total to 0
    char last_move = beats[s[0]]; // Calculate last_move based on the first character
    for (int i = 1; i < n; i++) {
        char current = beats[s[i]]; // Get the beat character for the current character
        if (current != last_move) { // Check if the current move beats the previous one
            last_move = current; // Update last_move to be the current beat character
            total++; // Increment total
        }
    }
    cout << total << endl;

    return 0;

}