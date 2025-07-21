#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    char s[200011], c[200011];
    for (int i = 0; i < n; i++) {
        scanf(" %c", &s[i]);  // notice the space before %c to consume any leftover whitespace characters
        c[i] = s[i];         // initialize c with the same values of s
    }
    
    int ans = 0, sum = n;
    // First pass to count all 'R's initially
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') sum--;
    }
    ans = sum;
    
    // Modify the string to count maximum 'R's by following the rules
    for (int i = 0; i < n; i++) {
        if (i > 0 && c[i] == c[i - 1]) {
            // Swap only if it's not the same as the previous character
            // This means we keep 'PP', 'RR', and 'SS' as they are
            // and only swap 'PR' or 'RS'
            if ((c[i] == 'P' && s[i] == 'R') || (c[i] == 'R' && s[i] == 'P')) {
                // Swap characters only if the rule is applicable
                swap(c[i - 1], c[i]);
            }
        }
    }
    
    // Second pass to count 'R's after making all possible swaps
    sum = n;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') sum--;
    }
    ans = max(ans, sum);
    
    printf("%d\n", ans);
    return 0;
}