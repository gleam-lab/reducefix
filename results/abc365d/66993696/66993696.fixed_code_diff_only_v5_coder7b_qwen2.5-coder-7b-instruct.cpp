#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200011;
char s[MAXN], c[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);

    // Initialize counter for each character type
    int count[3] = {0}; // P, R, S
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') ++count[0];
        else if (s[i] == 'R') ++count[1];
        else ++count[2];
    }

    // Determine the most frequent character to replace others with
    int max_count = *max_element(count, count + 3);
    char target_char;
    if (max_count == count[0]) target_char = 'P';
    else if (max_count == count[1]) target_char = 'R';
    else target_char = 'S';

    // Calculate the maximum number of characters that can be kept as is
    int ans = max_count;

    // Try replacing all other characters with the target character
    for (int i = 1; i <= n; ++i) {
        if (s[i] != target_char) ++ans;
    }

    printf("%d\n", ans);
    return 0;
}