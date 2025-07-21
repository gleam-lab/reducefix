#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    char s[n + 1], t[n + 1];
    scanf("%s", s + 1);

    // Transform the string according to the given rules
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'P') t[i] = 'S';
        else if (s[i] == 'R') t[i] = 'P';
        else t[i] = 'R';
    }

    // Function to calculate the maximum score after removing consecutive duplicates
    auto maxScore = [&](const char* str) -> int {
        int ans = 0, sum = n;
        for (int i = 2; i <= n; ++i) {
            if (str[i] == str[i - 1]) {
                str[i] = s[i]; // Revert to original character
                --sum;
            }
        }
        return max(ans, sum);
    };

    // Calculate scores for both transformed strings
    int score1 = maxScore(t);
    int score2 = maxScore(s); // Considering the original string as well

    printf("%d\n", max(score1, score2));
    return 0;
}