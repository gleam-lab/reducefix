#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    long long ans = 0;
    while (n--) {
        int h;
        cin >> h;
        ans += h / 3;  // Full sets of 3 attacks
        ans += (h % 3) / 1;  // Remainder attacks, which are always 1 per enemy
        if (h % 3 == 2) {
            ans++;  // If health is 2, we need an extra 1-point attack after the full sets
        }
    }
    cout << ans << endl;
    return 0;
}