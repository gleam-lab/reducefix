#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2 * 100011;

int main() {
    int n;
    cin >> n;
    string s(n + 1);
    cin >> s;

    vector<char> c(n + 1);

    // Determine Takahashi's moves based on Aoki's moves
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    // Count the number of wins
    int wins = 0;
    for (int i = 1; i <= n; ++i) {
        if ((s[i] == 'P' && c[i] == 'R') || 
            (s[i] == 'R' && c[i] == 'S') || 
            (s[i] == 'S' && c[i] == 'P')) {
            wins++;
        }
    }

    cout << wins << endl;
    return 0;
}