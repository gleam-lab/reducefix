#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

typedef long long ll;

// Max heap to maintain k smallest distances
priority_queue<ll> pq;

ll abs(ll x) {
    return x < 0 ? -x : x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<ll> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    
    // Sort A for binary search
    sort(A.begin(), A.end());

    while (q--) {
        ll b;
        int k;
        cin >> b >> k;

        // Binary search to find the closest index to b in A
        int idx = lower_bound(A.begin(), A.end(), b) - A.begin();

        int left = idx - 1;
        int right = idx;

        // Use max heap to store the k smallest distances
        priority_queue<pair<ll, ll>> max_heap;

        while (max_heap.size() < k) {
            ll dl = (left >= 0) ? abs(A[left] - b) : LLONG_MAX;
            ll dr = (right < n) ? abs(A[right] - b) : LLONG_MAX;

            if (dl <= dr) {
                max_heap.push({dl, A[left]});
                --left;
            } else {
                max_heap.push({dr, A[right]});
                ++right;
            }
        }

        // The top of the heap is the k-th smallest distance
        cout << max_heap.top().first << endl;
    }

    return 0;
}