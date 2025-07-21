#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;

constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        // Sort both arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // Calculate initial sum of the smallest K elements in B
        ll sumB = accumulate(b.begin(), b.begin() + k, 0LL);

        // Initialize the answer with the product of the largest element in A and the sum of the first K elements in B
        ll ans = a[n - 1] * sumB;

        // Use sliding window to find the minimum value
        for (int i = 1; i <= n - k; ++i) {
            sumB += b[i + k - 1] - b[i - 1];
            ans = min(ans, a[n - 1 - i] * sumB);
        }

        cout << ans << '\n';
    }

    return 0;
}