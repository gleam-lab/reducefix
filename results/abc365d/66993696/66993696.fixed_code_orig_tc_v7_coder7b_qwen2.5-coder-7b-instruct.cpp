#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200011;

int main() {
    int n;
    scanf("%d", &n);
    char s[MAXN], c[MAXN];
    scanf("%s", s + 1);

    // Initialize the counter for each character type
    int cnt[3] = {0};
    for (int i = 1; i <= n; ++i) {
        cnt[s[i] - 'P']++;
    }

    // Calculate the maximum number of characters that can be changed
    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) continue;
            ans = max(ans, cnt[i] + cnt[j]);
        }
    }

    printf("%d\n", ans);
    return 0;
}