#include <bits/stdc++.h>
using namespace std;

char s[200011];
char c[200011];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') c[i] = 'S';
        else if (s[i] == 'R') c[i] = 'P';
        else c[i] = 'R';
    }
    
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
        if (c[i] == c[i - 1]) {
            char original = s[i];
            char best;
            if (original == 'P') best = 'S';
            else if (original == 'R') best = 'P';
            else best = 'R';
            
            if (i < n) {
                char next_original = s[i + 1];
                char next_best;
                if (next_original == 'P') next_best = 'S';
                else if (next_original == 'R') next_best = 'P';
                else next_best = 'R';
                
                if (best != c[i - 1] && best != next_best) {
                    c[i] = best;
                } else {
                    char alternative1, alternative2;
                    if (original == 'P') {
                        alternative1 = 'R';
                        alternative2 = 'P';
                    } else if (original == 'R') {
                        alternative1 = 'S';
                        alternative2 = 'R';
                    } else {
                        alternative1 = 'P';
                        alternative2 = 'S';
                    }
                    
                    if (alternative1 != c[i - 1] && alternative1 != next_best) {
                        c[i] = alternative1;
                    } else if (alternative2 != c[i - 1] && alternative2 != next_best) {
                        c[i] = alternative2;
                    } else {
                        c[i] = best;
                    }
                }
            } else {
                if (best != c[i - 1]) {
                    c[i] = best;
                } else {
                    char alternative;
                    if (original == 'P') alternative = 'R';
                    else if (original == 'R') alternative = 'S';
                    else alternative = 'P';
                    c[i] = alternative;
                }
            }
        }
        if (c[i] != c[i - 1]) {
            ans++;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}