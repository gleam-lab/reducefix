#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

ll a[MAXN];

// Binary search to find the k-th smallest distance from b
ll query(ll b, int k, int n) {
    vector<ll> diffs;
    for (int i = 0; i < n; ++i) {
        diffs.push_back(abs(a[i] - b));
    }
    sort(diffs.begin(), diffs.end());
    return diffs[k - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    sort(a, a + N);  // Sort A for binary search usage

    // We will use a different approach: for each query, perform binary search on distance
    // and count how many points have distance <= mid using binary search in A

    auto kth_distance = [&](ll b, int k) {
        ll low = 0, high = 2e8;  // Max possible distance is 2*1e8
        ll answer = high;

        while (low <= high) {
            ll mid = (low + high) / 2;
            // Find number of elements in A within [b - mid, b + mid]
            ll left = b - mid, right = b + mid;

            int l = lower_bound(a, a + N, left) - a;
            int r = upper_bound(a, a + N, right) - a;
            int count = r - l;

            if (count >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return answer;
    };

    for (int i = 0; i < Q; ++i) {
        ll b;
        int k;
        cin >> b >> k;
        cout << kth_distance(b, k) << "\n";
    }

    return 0;
}