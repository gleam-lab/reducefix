#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    int wins = 0;
    char prev = 'a';  // Initialize prev to 'a' to ensure the first character comparison is not skipped
    for (int i = 1; i < N; ++i) {  // Start from the second character to compare with the previous character
        if (prev == 'R' && S[i] == 'S') {
            wins++;
        } else if (prev == 'P' && S[i] == 'R') {
            wins++;
        } else if (prev == 'S' && S[i] == 'P') {
            wins++;
        }
        prev = S[i - 1];  // Update prev to the current character
    }
    cout << wins;
}