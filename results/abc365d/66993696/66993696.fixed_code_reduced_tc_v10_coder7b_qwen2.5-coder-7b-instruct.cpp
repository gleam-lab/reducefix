#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200011;

int main() {
    int n;
    scanf("%d", &n);
    char s[MAXN], t[MAXN];
    scanf("%s", s + 1);

    // Create a copy of the original string
    strcpy(t, s + 1);

    // First transformation: replace P with S, R with P, L with R
    for (int i = 1; i <= n; ++i) {
        if (t[i] == 'P') t[i] = 'S';
        else if (t[i] == 'R') t[i] = 'P';
        else t[i] = 'R';
    }

    // Count the number of consecutive identical characters
    int maxLen = 0, currentLen = 1;
    for (int i = 2; i <= n; ++i) {
        if (t[i] == t[i - 1]) {
            currentLen++;
        } else {
            maxLen = max(maxLen, currentLen);
            currentLen = 1;
        }
    }
    maxLen = max(maxLen, currentLen);

    // Second transformation: replace P with S, R with P, L with R again
    for (int i = 1; i <= n; ++i) {
        if (t[i] == 'P') t[i] = 'S';
        else if (t[i] == 'R') t[i] = 'P';
        else t[i] = 'R';
    }

    // Check the first character separately
    if (s[1] == s[2]) {
        t[1] = s[1];
        currentLen = 1;
        for (int i = 3; i <= n; ++i) {
            if (t[i] == t[i - 1]) {
                currentLen++;
            } else {
                maxLen = max(maxLen, currentLen);
                currentLen = 1;
            }
        }
        maxLen = max(maxLen, currentLen);
    }

    printf("%d\n", maxLen);
    return 0;
}