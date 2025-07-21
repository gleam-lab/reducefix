#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200011;
char s[MAXN], c[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);

    // Initialize the counter for each character type
    int count[3] = {0};
    for (int i = 1; i <= n; ++i) {
        count[s[i] - 'R']++;
    }

    // Calculate the maximum number of characters that can be removed
    int remove = min(count[0], min(count[1], count[2]));
    count[0] -= remove;
    count[1] -= remove;
    count[2] -= remove;

    // The result is the total length minus twice the number of removals
    printf("%d\n", n - 2 * remove);

    return 0;
}