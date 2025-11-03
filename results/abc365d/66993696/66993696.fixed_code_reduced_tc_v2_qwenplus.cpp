#include<bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int solve(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // Build the transformed string
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    int changes = 0;
    // Count consecutive duplicates and simulate fixing them greedily
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i-1]) {
            // We can break the sequence by reverting c[i] back to s[i]
            // But we need to check if that causes new conflicts
            char original = c[i];
            c[i] = s[i];
            // After changing, we don't need to check backward again because
            // we're going left to right and only current affects future
            changes++;
            // Note: even after change, we keep c[i] modified for next iteration
        }
    }
    
    return n - changes;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s+1);
    
    // Try two strategies:
    // Strategy 1: Normal transformation with greedy fix from left
    // Strategy 2: Force first character to stay same (i.e. no transformation on first)
    
    int ans = 0;
    
    // Strategy 1: Transform all and fix consecutive duplicates
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    int count = n;
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i-1]) {
            c[i] = s[i];  // revert to original to break duplicate
            count--;
        }
    }
    ans = max(ans, count);
    
    // Strategy 2: Keep first character unchanged (use s[1] instead of transformed)
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    // Force first char to be original
    c[1] = s[1];
    count = n - 1;  // already lost one transformation
    
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i-1]) {
            c[i] = s[i];
            count--;
        }
    }
    ans = max(ans, count);
    
    // Strategy 3: Try keeping any single position unchanged? 
    // Actually, the key insight is that we can choose any subset to transform.
    // But optimal strategy is either transform all or break at minimal points.
    // The above two cover major cases.
    
    // However, let's consider a better approach: we can simulate from left,
    // making optimal choice at each step.
    
    // Actually, simpler: try both possibilities for first element,
    // then greedily extend.
    
    // Let's do DP-like greedy:
    // Option 1: best result when we transform first
    // Option 2: best result when we don't transform first
    
    // We already tried both above, but let's reframe:
    
    // Actually, our first two strategies are sufficient.
    // But in the failing case "PPR":
    //   Strategy 1: 
    //      s:  P P R
    //      c:  S S P -> conflict at pos2, fix: S P P -> still conflict at pos3? 
    //          Actually: after fixing pos2: c[2]=s[2]='P', so c: S P P -> conflict at pos3
    //          then fix pos3: c[3]=s[3]='R', so c: S P R -> no more conflicts -> count = 3 - 2 = 1
    //   Strategy 2: 
    //      c[1] = s[1] = 'P'
    //      c[2] = 'S' (transformed), now c[1]='P', c[2]='S' -> ok
    //      c[3] = 'P' (transformed), c[2]='S', c[3]='P' -> ok
    //      so count = 2 (because we didn't transform first) -> 3-1=2
    //   So ans = max(1,2)=2 -> correct.
    
    // But our code wasn't doing strategy 2 correctly in the second part.
    // In the original code, second strategy only applied conditionally if s[1]==s[2].
    // That was wrong – we should always try this alternative.
    
    // So we fixed it: always try both strategies.
    
    printf("%d", ans);
    return 0;
}