#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
char s[MAXN];
char c[MAXN];

int compute_max(int n) {
    int ans = 0;
    // Try all possible starting transformation
    for (int start = 0; start < 3; ++start) {
        int sum = n;
        for (int i = 1; i <= n; ++i) {
            if (s[i] == 'P') c[i] = 'S';
            else if (s[i] == 'R') c[i] = 'P';
            else c[i] = 'R';
            
            // Apply starting modification
            if (i == 1 && start == 1) c[i] = s[i];
            if (i == 2 && start == 2) c[i] = s[i];
            
            if (i > 1 && c[i] == c[i-1]) {
                c[i] = s[i];
                sum--;
            }
        }
        ans = max(ans, sum);
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    int result = compute_max(n);
    printf("%d\n", result);
    return 0;
}