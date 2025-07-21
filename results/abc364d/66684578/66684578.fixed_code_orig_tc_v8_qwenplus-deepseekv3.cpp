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
        
        int low = 0, high = N - 1;
        // We will use a binary search approach to find the k-th closest element.
        // The idea is to find the smallest distance D such that there are at least k elements <= b + D and >= b - D.
        // But another approach is to use two pointers or binary search on the sorted array.
        
        // Alternative approach: find the k-th smallest |a[i] - b|.
        // To do this, we can use binary search on the possible distances.
        ll left = -1, right = 2e14;
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            // Count the number of elements in a with |a[i] - b| <= mid
            auto it_l = lower_bound(a.begin(), a.end(), b - mid);
            auto it_r = upper_bound(a.begin(), a.end(), b + mid);
            int count = it_r - it_l;
            if (count >= k) {
                right = mid;
            } else {
                left = mid;
            }
        }
        cout << right << '\n';
    }
    
    return 0;
}