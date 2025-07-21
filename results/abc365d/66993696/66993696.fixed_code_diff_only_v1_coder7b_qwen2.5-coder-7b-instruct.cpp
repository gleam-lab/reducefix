#include<bits/stdc++.h>
using namespace std;

void process(char *s, int n) {
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') s[i] = 'S';
        else if (s[i] == 'R') s[i] = 'P';
        else s[i] = 'R';
    }
}

int calculateScore(char *s, int n) {
    int ans = 0, sum = n;
    for (int i = 2; i <= n; i++) {
        if (s[i] == s[i - 1]) {
            s[i] = s[i + 1]; // Change to next character to avoid consecutive same
            sum--;
        }
    }
    return max(ans, sum);
}

int main() {
    int n;
    scanf("%d", &n);
    char s[200011];
    scanf("%s", s + 1);

    process(s, n);
    int score = calculateScore(s, n);

    if (s[1] == s[2]) {
        s[1] = s[2] == 'P' ? 'S' : 'R'; // Toggle first character
        score = max(score, calculateScore(s, n));
    }

    printf("%d\n", score);
    return 0;
}