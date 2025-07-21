#include<bits/stdc++.h>
using namespace std;

string s, c;
int n;

bool canWin(char x, char y) {
    return (x == 'R' && y == 'S') || (x == 'S' && y == 'P') || (x == 'P' && y == 'R');
}

int main() {
    cin >> n >> s;
    c = s; // Copy Aoki's moves to Takahashi's initial guess

    // Adjust Takahashi's moves to ensure he doesn't lose and alternates moves
    for (int i = 1; i < n; ++i) {
        if (!canWin(c[i], c[i - 1])) {
            if (s[i] == 'R') c[i] = 'P';
            else if (s[i] == 'P') c[i] = 'S';
            else c[i] = 'R';
        }
    }

    int wins = 0;
    for (int i = 0; i < n; ++i) {
        if (canWin(c[i], s[i])) ++wins;
    }

    cout << wins << endl;
    return 0;
}