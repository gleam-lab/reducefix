#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    
    cin >> n >> s;

    // The transformation function
    auto transform = [](char c) -> char {
        if (c == 'R') return 'P';  // Rock beaten by Paper
        if (c == 'P') return 'S';  // Paper beaten by Scissors
        if (c == 'S') return 'R';  // Scissors beaten by Rock
        return '?';                // Shouldn't happen
    };

    // We'll try all 3 possible initial transformations and see which gives the best result
    int maxScore = 0;

    for (int start = 0; start < 3; ++start) {
        vector<char> c(n);
        int score = n;

        // Initial transformation
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R') c[i] = 'P';
            else if (s[i] == 'P') c[i] = 'S';
            else c[i] = 'R';

            // Apply rotation based on starting point
            if (i == 0 && start > 0) {
                // Rotate the first character's transformation
                if (start == 1) {  // First transformation is R->P, P->S, S->R, now shift once
                    if (c[i] == 'P') c[i] = 'S';
                    else if (c[i] == 'S') c[i] = 'R';
                    else c[i] = 'P';
                } else if (start == 2) {  // Shift twice
                    if (c[i] == 'P') c[i] = 'R';
                    else if (c[i] == 'S') c[i] = 'P';
                    else c[i] = 'S';
                }
            }

            // If current transformation matches previous, we change it to original s[i]
            if (i > 0 && c[i] == c[i-1]) {
                c[i] = s[i];
                --score;
            }
        }

        maxScore = max(maxScore, score);
    }

    cout << maxScore << "\n";
    return 0;
}