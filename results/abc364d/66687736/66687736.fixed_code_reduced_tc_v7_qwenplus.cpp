#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vll vector<ll>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    sort(a.begin(), a.end());

    rep(qi, Q) {
        ll b;
        int k;
        cin >> b >> k;
        k--; // 0-indexed k

        // Binary search on the distance
        ll low = 0, high = 2e8 + 10;
        while (low < high) {
            ll mid = (low + high) / 2;
            ll left_bound = b - mid;
            ll right_bound = b + mid;

            // Count how many points in a are in [left_bound, right_bound]
            auto it1 = lower_bound(a.begin(), a.end(), left_bound);
            auto it2 = upper_bound(a.begin(), a.end(), right_bound);
            ll count = it2 - it1;

            if (count <= k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        // Now low is the smallest distance such that the number of points within 'low' of b is > k
        // But we want the k-th smallest distance, so check what happens at low-1
        ll dist = low - 1;
        ll left_bound = b - dist;
        ll right_bound = b + dist;
        auto it1 = lower_bound(a.begin(), a.end(), left_bound);
        auto it2 = upper_bound(a.begin(), a.end(), right_bound);
        ll count_leq = it2 - it1;

        if (count_leq > k) {
            cout << dist << '\n';
        } else {
            cout << low << '\n';
        }
    }
}