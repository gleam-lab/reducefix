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
    
    // Initialize the count of wins to 0
    int wins = 0;
    
    // Iterate through each move in the string
    for (int i = 0; i < n; ++i) {
        // If it's the first move or Takahashi's previous move beats Aoki's current move, increment wins
        if (i == 0 || beats[s[i - 1]] == s[i]) {
            ++wins;
        }
    }

    // Print the maximum number of games Takahashi could have won
    cout << wins << endl;

    return 0;
}