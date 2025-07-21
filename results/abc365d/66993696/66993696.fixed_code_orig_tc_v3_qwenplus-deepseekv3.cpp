#include<bits/stdc++.h>
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
    
    int sum = n;
    for (int i = 2; i <= n; ++i) {
        if (c[i] == c[i-1]) {
            if (i + 1 <= n && c[i+1] == c[i]) {
                c[i] = s[i];
                sum--;
            } else {
                c[i-1] = s[i-1];
                sum--;
            }
        }
    }
    
    printf("%d\n", sum);
    return 0;
}