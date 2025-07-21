#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for(int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    while(Q--) {
        ll b, k;
        cin >> b >> k;
        int low = 0, high = N - 1;
        // Binary search to find the k-th closest element
        // The idea is to find the k-th smallest |a[i] - b|
        // To do this, we can use binary search to find the point where the differences are minimized
        
        // Alternative approach: find the position where the k-th smallest difference is
        // We can use two pointers or binary search on the answer
        // Here, we'll use binary search on the answer (the distance)
        ll left = -1, right = 2e18;
        while(left < right) {
            ll mid = left + (right - left) / 2;
            // Count the number of elements a[i] with |a[i] - b| <= mid
            auto it_l = lower_bound(a.begin(), a.end(), b - mid);
            auto it_r = upper_bound(a.begin(), a.end(), b + mid);
            int count = it_r - it_l;
            if(count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        // Now, find the k-th smallest distance. The smallest distance is 'left'
        // But we need to find the exact value, which is |a[i] - b| for the k-th smallest
        // So, collect all elements in [b - left, b + left], sort them by distance to b, then pick the k-th
        // But since the array is sorted, we can use two pointers to find the k-th smallest without sorting again
        auto it_l = lower_bound(a.begin(), a.end(), b - left);
        auto it_r = upper_bound(a.begin(), a.end(), b + left);
        vector<ll> candidates(it_l, it_r);
        sort(candidates.begin(), candidates.end(), [&](ll x, ll y) {
            return abs(x - b) < abs(y - b);
        });
        cout << abs(candidates[k - 1] - b) << '\n';
    }
    return 0;
}