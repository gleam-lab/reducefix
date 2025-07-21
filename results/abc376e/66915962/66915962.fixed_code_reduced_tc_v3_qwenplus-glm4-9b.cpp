#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        VI a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // Pairing A and B and sort by B values descending
        vector<pair<int, int>> C(n);
        for (int i = 0; i < n; ++i) {
            C[i] = {a[i], b[i]};
        }
        sort(C.begin(), C.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.second > p2.second;
        });

        // Calculate the minimum possible value of the expression
        ll ans = 1e18;
        ll sumB = 0;
        for (int i = 0; i < k; ++i) {
            sumB += C[i].second;
        }
        ans = min(ans, (ll)C[0].first * sumB);

        for (int i = 0; i < k - 1; ++i) {
            // Subtract the current B and add the next B
            sumB = sumB - C[i].second + C[i + 1].second;
            ans = min(ans, (ll)C[i].first * sumB);
        }

        cout << ans << '\n';
    }
}