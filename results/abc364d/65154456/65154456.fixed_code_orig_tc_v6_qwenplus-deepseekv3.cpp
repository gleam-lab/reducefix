#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
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
            
            // Count the number of elements in a with |a_i - b| <= mid
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

        cout << answer << '\n';
    }

    return 0;
}