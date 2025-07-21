#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;

    int wins = 0;
    char prev = S[0]; // Initialize prev to the first character in the string

    // If the string is empty after removing the first character, no wins are possible
    if (S.empty()) {
        cout << wins << endl;
        return 0;
    }

    for (size_t i = 1; i < S.length(); ++i) { // Start from the second character
        if (S[i] != prev) { // Different character, increment wins
            wins++;
            prev = S[i]; // Update prev to the current character
        }
    }

    cout << wins << endl;
}