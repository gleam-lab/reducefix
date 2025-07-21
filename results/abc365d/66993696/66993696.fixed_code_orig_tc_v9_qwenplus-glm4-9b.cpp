#include<bits/stdc++.h>
using namespace std;

int s[200011]; // Change to int to save memory for character comparison
int c[200011];
int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) { // Start from 0
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }

    // First pass
    int sum = n;
    for (int i = 0; i < n; i++) {
        if (c[i] == c[i + 1]) {
            c[i + 1] = s[i + 1]; // Assign original char to prevent further changes
            sum--;
        }
    }

    // Second pass
    int ans = sum;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    for (int i = 0; i < n - 1; i++) {
        if (c[i] == c[i + 1]) {
            sum--;
        }
    }
    ans = max(ans, sum);

    printf("%d", ans);
}