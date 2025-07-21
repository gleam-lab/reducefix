#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    char s[200011];
    char c[200011];

    // Read the string s
    scanf("%s", s + 1);

    // Initialize the transformation array
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    // Calculate the maximum time while keeping the same pattern or reverting to original
    int ans = n;
    int sum = n; // Start with the assumption that all characters are the same
    for (int i = 2; i <= n; ++i) {
        if (c[i] == c[i - 1]) {
            c[i] = s[i]; // Revert to original to try to get a longer sequence
            sum--;
        }
    }
    ans = max(ans, sum);

    // Reset if the first two characters are the same
    if (s[1] == s[2]) {
        sum = n;
        for (int i = 1; i <= n; ++i) {
            if (i > 1 && s[i] == c[i]) {
                c[i] = s[i]; // Revert to original to try to get a longer sequence
                sum--;
            }
        }
        ans = max(ans, sum);
    }

    printf("%d", ans);
    return 0;
}