#include<bits/stdc++.h>
using namespace std;

char s[200011], t[200011];

char transform(char c) {
    if (c == 'P') return 'S';
    if (c == 'R') return 'P';
    return 'R';
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    
    for (int i = 0; i < n; ++i) {
        t[i] = transform(s[i]);
    }
    
    int maxLongest = 0;
    int currentLongest = 1;
    
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            currentLongest++;
        } else {
            maxLongest = max(maxLongest, currentLongest);
            currentLongest = 1;
        }
    }
    maxLongest = max(maxLongest, currentLongest);
    
    printf("%d", maxLongest);
}