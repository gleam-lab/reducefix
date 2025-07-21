#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define fi first
#define se second

// Function to perform binary search in a sorted array
int count_less_or_equal(const vi &a, int target) {
    return upper_bound(a.begin(), a.end(), target) - a.begin();
}

int count_ge_or_equal(const vi &a, int target) {
    return a.end() - lower_bound(a.begin(), a.end(), target);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    vi A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());

    while (Q--) {
        int b;
        int k;
        cin >> b >> k;

        // Binary search on distance
        int l = 0, r = 200000000; // max possible distance is 2e8
        int ans = r;

        while (l <= r) {
            int mid = (l + r) / 2;
            int left = b - mid;
            int right = b + mid;

            int cnt_left = count_less_or_equal(A, right);
            int cnt_right = count_ge_or_equal(A, left);

            if (cnt_left >= k && (N - cnt_right + 1) >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}