#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    char expected = '\0';
    for (char c : S) {
        if (expected == '\0') {
            ans++;
            if (c == 'P') expected = 'S';
            else if (c == 'R') expected = 'P';
            else if (c == 'S') expected = 'R';
        } else {
            if (c == expected) {
                ans++;
                if (c == 'P') expected = 'S';
                else if (c == 'R') expected = 'P';
                else if (c == 'S') expected = 'R';
            } else {
                expected = '\0';
            }
        }
    }
    cout << ans << endl;
    return 0;
}