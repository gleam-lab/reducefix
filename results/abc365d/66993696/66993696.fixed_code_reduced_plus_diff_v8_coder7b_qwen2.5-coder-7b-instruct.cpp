#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    string s(n + 1);
    cin >> s;
    
    // Count occurrences of each character
    int count[3] = {0};
    for (char c : s) {
        count[c - 'P']++;
    }
    
    // Calculate maximum possible score
    int max_score = min(count[0], count[1]) + min(count[1], count[2]) + min(count[2], count[0]);
    
    printf("%d\n", max_score);
    
    return 0;
}