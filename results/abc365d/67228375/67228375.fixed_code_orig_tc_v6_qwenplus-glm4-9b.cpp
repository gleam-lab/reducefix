#include <iostream>
#include <map>
#include <string>
using namespace std;

#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int max_consecutive_wins = 1; // Initialize with the first move
    char last_move = s[0]; // The first move cannot be a win
    for (int i = 1; i < n; i++) {
        if (beats[s[i]] == last_move) {
            max_consecutive_wins++;
            last_move = s[i];
        } else {
            max_consecutive_wins = 1;
            last_move = s[i];
        }
    }

    cout << max_consecutive_wins << endl;

    return 0;
}