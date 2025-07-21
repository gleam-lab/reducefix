#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Create a copy of Aoki's moves to simulate Takahashi's moves
    vector<char> takahashi(n + 1);

    // Determine Takahashi's moves based on Aoki's moves
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == 'P') takahashi[i] = 'S';
        else if (s[i - 1] == 'R') takahashi[i] = 'P';
        else takahashi[i] = 'R';
    }

    // Function to check if Takahashi's move beats Aoki's move
    auto beats = [](char t, char a) -> bool {
        return (t == 'P' && a == 'R') || (t == 'R' && a == 'S') || (t == 'S' && a == 'P');
    };

    // Count the number of wins
    int wins = 0;
    for (int i = 1; i <= n; ++i) {
        if (beats(takahashi[i], s[i - 1])) {
            wins++;
        }
    }

    cout << wins << endl;

    return 0;
}