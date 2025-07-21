#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);

    // Initial transformation to winning moves
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    int sum = n;
    // First pass to fix adjacent duplicates from left to right
    for (int i = 2; i <= n; ++i) {
        if (c[i] == c[i - 1]) {
            // Find a character that is different from both neighbors and wins against s[i]
            for (char ch : {'P', 'R', 'S'}) {
                if (ch != c[i - 1] && (i == n || ch != c[i + 1])) {
                    if ((s[i] == 'P' && ch == 'S') || 
                        (s[i] == 'R' && ch == 'P') || 
                        (s[i] == 'S' && ch == 'R')) {
                        c[i] = ch;
                        sum--;
                        break;
                    }
                }
            }
        }
    }

    // Second pass to fix any remaining issues from right to left
    for (int i = n - 1; i >= 1; --i) {
        if (c[i] == c[i + 1]) {
            for (char ch : {'P', 'R', 'S'}) {
                if (ch != c[i + 1] && (i == 1 || ch != c[i - 1])) {
                    if ((s[i] == 'P' && ch == 'S') || 
                        (s[i] == 'R' && ch == 'P') || 
                        (s[i] == 'S' && ch == 'R')) {
                        c[i] = ch;
                        sum--;
                        break;
                    }
                }
            }
        }
    }

    printf("%d\n", sum);
    return 0;
}