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
    int total = 1;
    char last_move = s[0]; // Initialize with the first move
    for (int i = 1; i < n; i++) {
        if (s[i] == beats[last_move]) { // Check if the current move beats the last move
            last_move = s[i];
            continue;
        }
        last_move = s[i];
        total += 1;
    }
    cout << total << endl;

    return 0;
}