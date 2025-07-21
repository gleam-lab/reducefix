#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200011;
char s[MAXN], t[MAXN];

int solve() {
    int n;
    scanf("%d%s", &n, s + 1);
    
    // Apply the transformation once to generate t
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'R') t[i] = 'P';
        else if (s[i] == 'P') t[i] = 'S';
        else t[i] = 'R';
    }

    int max_score = 0, cnt = 0;

    // Try all possible starting positions (0 or 1) and parity (even/odd)
    for (int start = 0; start <= 1; ++start) {
        for (int parity = 0; parity <= 1; ++parity) {
            char temp[MAXN];
            memcpy(temp, t, sizeof(t));

            bool used[MAXN] = {0};
            int total = n;

            // First pass: handle forced conflicts
            for (int i = 1; i <= n; ++i) {
                if (i % 2 == parity) {
                    if (i > 1 && temp[i] == temp[i - 1]) {
                        temp[i] = s[i];
                        total--;
                    }
                    if (i < n && temp[i] == temp[i + 1]) {
                        temp[i] = s[i];
                        total--;
                    }
                }
            }

            // Second pass: resolve remaining conflicts greedily
            for (int i = 2; i <= n; ++i) {
                if (temp[i] == temp[i - 1]) {
                    temp[i] = s[i];
                    total--;
                }
            }

            max_score = max(max_score, total);
        }
    }

    return max_score;
}

int main() {
    printf("%d\n", solve());
    return 0;
}