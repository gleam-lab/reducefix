#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200011;

int main() {
    int n;
    scanf("%d", &n);
    char s[MAXN];
    scanf("%s", s + 1);

    // Function to check if two characters form a valid match
    auto isValidMatch = [](char a, char b) -> bool {
        return (a == 'P' && b == 'S') || (a == 'R' && b == 'P') || (a == 'S' && b == 'R');
    };

    // Function to swap characters at positions i and j
    auto swapChars = [&](int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    };

    int swaps = 0;
    for (int i = 1; i < n; ++i) {
        if (!isValidMatch(s[i], s[i + 1])) {
            swapChars(i, i + 1);
            ++swaps;
        }
    }

    printf("%d\n", swaps);
    return 0;
}