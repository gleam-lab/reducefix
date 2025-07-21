#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    char s[n + 1], c[n + 1];
    scanf("%s", s + 1);

    // Mapping based on given transformation
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    // Calculate sum of elements in c that can be transformed
    int sum = n;
    for (int i = 1; i <= n; i++) {
        if (c[i] == 'S') c[i] = 'P'; // Map 'S' to 'P' to consider for transformation
        else if (c[i] == 'P') c[i] = 'R'; // Map 'P' to 'R' to consider for transformation
        else c[i] = 'S'; // Map 'R' to 'S' to consider for transformation
    }

    // Calculate maximum sum of consecutive same characters
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i - 1]) {
            c[i] = s[i]; // Restore original character
            sum--;
        }
    }
    ans = max(ans, sum);

    // Handle the case where s[1] == s[2]
    if (s[1] == s[2]) {
        c[1] = s[1]; // Restore original character
        sum--;
        for (int i = 3; i <= n; i++) {
            if (c[i] == c[i - 1]) {
                c[i] = s[i]; // Restore original character
                sum--;
            }
        }
    }
    ans = max(ans, sum);

    printf("%d", ans);
}