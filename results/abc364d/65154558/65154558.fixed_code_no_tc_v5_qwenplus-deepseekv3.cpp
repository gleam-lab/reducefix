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
        ll b;
        int k;
        cin >> b >> k;
        int left = 0, right = N - 1;
        // Binary search to find the k-th closest element
        // We can use the fact that the array is sorted to find the closest elements
        // The k-th closest can be found by considering the distances in sorted order
        vector<ll> distances(N);
        for (int i = 0; i < N; ++i) {
            distances[i] = abs(a[i] - b);
        }
        // We need to find the k-th smallest distance
        // To do this efficiently, we can use a priority queue or quickselect
        // However, for N=1e5 and Q=1e5, O(Q*N) is too slow
        // Instead, we can use binary search on the answer
        // Let's binary search the distance d such that there are at least k points with distance <= d
        ll low = 0, high = 1e18;
        ll answer = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            int cnt = 0;
            // Find the number of elements in a with |a_i - b| <= mid
            auto it1 = lower_bound(a.begin(), a.end(), b - mid);
            auto it2 = upper_bound(a.begin(), a.end(), b + mid);
            cnt = it2 - it1;
            if (cnt >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << answer << '\n';
    }

    return 0;
}