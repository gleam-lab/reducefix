#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }
    char prev = S[0];
    int ans = 0;
    for (int i = 1; i < N; ++i) {
        char curr = S[i];
        if (prev == 'P') {
            if (curr == 'S') {
                ans++;
                prev = 'S';
            } else {
                prev = curr;
            }
        } else if (prev == 'R') {
            if (curr == 'P') {
                ans++;
                prev = 'P';
            } else {
                prev = curr;
            }
        } else if (prev == 'S') {
            if (curr == 'R') {
                ans++;
                prev = 'R';
            } else {
                prev = curr;
            }
        }
    }
    cout << ans << endl;
    return 0;
}