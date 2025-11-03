#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
int n, q;
vector<long long> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    while (q--) {
        long long b;
        int k;
        cin >> b >> k;

        // Binary search on the distance
        long long left = 0, right = 2e8 + 10;
        long long ans = right;

        while (left <= right) {
            long long mid = (left + right) / 2;
            long long count = 0;

            // Count points in [b-mid, b+mid]
            auto it1 = lower_bound(a.begin(), a.end(), b - mid);
            auto it2 = upper_bound(a.begin(), a.end(), b + mid);
            count = it2 - it1;

            if (count >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}