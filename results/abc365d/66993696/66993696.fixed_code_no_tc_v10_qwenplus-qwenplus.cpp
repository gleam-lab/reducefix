#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
char s[MAXN];
char c[MAXN];

int solve() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1); // 1-based indexing

    // Try all three possible starting transformations
    char first_moves[] = {'P', 'R', 'S'};
    int max_points = 0;

    for (int fm = 0; fm < 3; ++fm) {
        c[1] = first_moves[fm];

        // If the first move is not a valid transformation, skip it
        if ((s[1] == 'P' && c[1] != 'S') ||
            (s[1] == 'R' && c[1] != 'P') ||
            (s[1] == 'S' && c[1] != 'R'))
            continue;

        int points = 1;
        for (int i = 2; i <= n; ++i) {
            // Compute the correct counter move
            if (s[i] == 'P') c[i] = 'S';
            else if (s[i] == 'R') c[i] = 'P';
            else c[i] = 'R';

            // Ensure no consecutive equal moves
            if (c[i] == c[i - 1]) {
                c[i] = s[i]; // revert to original to avoid conflict
            } else {
                points++;
            }
        }

        max_points = max(max_points, points);
    }

    printf("%d\n", max_points);
    return 0;
}

int main() {
    solve();
    return 0;
}