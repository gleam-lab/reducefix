#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // Consume the newline after reading n
    char s[200011];
    char c[200011];
    cin.getline(s, n + 1); // Use getline to read the string

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    int ans = 0;
    int sum = n;
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i - 1]) {
            c[i] = s[i];
            sum--;
        }
    }
    ans = max(ans, sum);

    memset(c, 0, sizeof(c)); // Reset c array
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    if (s[1] == s[2]) {
        c[1] = s[1];
        sum--;
        for (int i = 3; i <= n; i++) {
            if (c[i] == c[i - 1]) {
                c[i] = s[i];
                sum--;
            }
        }
    }
    ans = max(ans, sum);

    printf("%d", ans);
    return 0;
}