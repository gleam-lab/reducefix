#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    while (Q--) {
        ll b, k;
        cin >> b >> k;
        k--; // convert to 0-based index

        // Binary search the k-th smallest distance
        ll left = 0, right = 2e14;
        ll answer = 0;
        while (left <= right) {
            ll mid = (left + right) / 2;
            // Count the number of elements <= a[i] <= b + mid and >= b - mid
            ll lower = b - mid;
            ll upper = b + mid;
            auto it_l = lower_bound(a.begin(), a.end(), lower);
            auto it_u = upper_bound(a.begin(), a.end(), upper);
            ll count = it_u - it_l;

            if (count <= k) {
                left = mid + 1;
            } else {
                answer = mid;
                right = mid - 1;
            }
        }

        // Now find the exact k-th distance
        vector<ll> distances;
        auto it_l = lower_bound(a.begin(), a.end(), b - answer);
        auto it_u = upper_bound(a.begin(), a.end(), b + answer);
        for (auto it = it_l; it != it_u; ++it) {
            distances.push_back(abs(*it - b));
        }
        sort(distances.begin(), distances.end());
        cout << distances[k] << '\n';
    }

    return 0;
}