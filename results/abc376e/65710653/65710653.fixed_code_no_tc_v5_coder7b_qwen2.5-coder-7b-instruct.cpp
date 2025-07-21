#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
long long A[MAXN], B[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }

        sort(A, A + n);
        sort(B, B + n);

        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            ans = max(ans, static_cast<long long>(A[i]) * B[n - i - 1]);
        }

        cout << ans << '\n';
    }

    return 0;
}