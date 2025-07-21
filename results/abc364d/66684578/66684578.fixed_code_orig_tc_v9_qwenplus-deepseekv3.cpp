#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end());

    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        k--; // convert to 0-based index

        // Binary search the k-th smallest distance
        ll low = 0, high = 2e14;
        ll answer = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            // Count the number of elements <= b + mid and >= b - mid
            auto left = lower_bound(a.begin(), a.end(), b - mid);
            auto right = upper_bound(a.begin(), a.end(), b + mid);
            int count = right - left;
            if (count <= k) {
                low = mid + 1;
            } else {
                answer = mid;
                high = mid - 1;
            }
        }

        // Now, find the exact k-th distance
        vector<ll> distances;
        for (ll num : a) {
            distances.push_back(abs(num - b));
        }
        nth_element(distances.begin(), distances.begin() + k, distances.end());
        cout << distances[k] << '\n';
    }

    return 0;
}