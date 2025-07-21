#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
char s[MAXN], c[MAXN];

int solve(int n) {
    int ans = 0;
    // Try all three possible initial transformations
    for (int init = 0; init < 3; ++init) {
        // Apply transformation
        for (int i = 1; i <= n; ++i) {
            if (s[i] == 'P') c[i] = "SPR"[init];
            else if (s[i] == 'R') c[i] = "PSR"[init];
            else c[i] = "PRS"[init];
        }
        
        // Count valid sequences
        int cnt = 1;
        for (int i = 2; i <= n; ++i) {
            if (c[i] != c[i-1]) {
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    printf("%d\n", solve(n));
    return 0;
}