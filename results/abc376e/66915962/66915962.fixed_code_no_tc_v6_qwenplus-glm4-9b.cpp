#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<P> a(n);
        vector<ll> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> b[i];
            a[i].second = b[i];
        }
        sort(a.begin(), a.end());

        ll ans = LLONG_MAX;
        ll sumB = 0;
        set<ll> sB;
        // Only consider the first k elements for initial sumB
        for (int i = 0; i < k; ++i) {
            sumB += a[i].second;
            sB.insert(a[i].second);
        }
        // Calculate the minimum possible value for the first k elements
        ans = min(ans, a[k - 1].first * sumB);

        // Adjust sumB and the set sB for the rest of the elements
        for (int i = k; i < n; ++i) {
            // Remove the smallest element (since we are increasing A[i])
            auto it = sB.lower_bound(*sB.begin());
            if (it != sB.end()) {
                sumB -= *it;
                sB.erase(it);
            }
            // Add the current B[i] to sumB and set sB
            sB.insert(a[i].second);
            sumB += a[i].second;
            // Calculate the minimum possible value for the current A[i]
            ans = min(ans, a[i].first * sumB);
        }

        cout << ans << '\n';
    }
    return 0;
}