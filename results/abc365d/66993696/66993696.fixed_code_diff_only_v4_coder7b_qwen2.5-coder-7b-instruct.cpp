#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200011;
char s[MAXN], c[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);

    // Initialize the counter for consecutive characters that need to be changed
    int changesNeeded = 0;

    // Calculate the number of changes needed to make all adjacent characters different
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i + 1]) {
            ++changesNeeded;
        }
    }

    // The maximum possible length of the resulting string is n - changesNeeded
    printf("%d\n", n - changesNeeded);

    return 0;
}