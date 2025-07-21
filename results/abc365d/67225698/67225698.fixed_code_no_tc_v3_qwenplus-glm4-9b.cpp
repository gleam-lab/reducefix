#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 1e9 + 7
#define LL long long

void solve() {
    LL n;
    cin >> n;
    string s;
    cin >> s;
    LL ans = 0;
    LL cnt = 1;  // Initialize cnt to 1, as the first character also starts a new segment

    for (LL i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            cnt++;  // If the current direction is the same as the previous one, increment cnt
        } else {
            ans += (cnt + 1) / 2;  // Each segment adds (cnt + 1) / 2 to the answer
            cnt = 1;  // Reset cnt for the new direction
        }
    }

    ans += (cnt + 1) / 2;  // Add the last segment to the answer

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}