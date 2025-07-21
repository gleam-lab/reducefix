#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define pb push_back

// Binary search to find the k-th smallest distance from B_j to A points
int solveQuery(int b, int k, const vi &a_sorted) {
    int left = 0;
    int right = 1e9; // max possible distance is 2e8
    while (left < right) {
        int mid = (left + right) / 2;
        // Count how many a_i satisfy |a_i - b| <= mid
        int l = lower_bound(all(a_sorted), b - mid) - a_sorted.begin();
        int r = upper_bound(all(a_sorted), b + mid) - a_sorted.begin();
        if (r - l >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    vi a(N);
    rep(i, N) cin >> a[i];
    
    sort(all(a)); // Sort A points once
    
    rep(q, Q) {
        int b, k;
        cin >> b >> k;
        cout << solveQuery(b, k, a) << "\n";
    }

    return 0;
}