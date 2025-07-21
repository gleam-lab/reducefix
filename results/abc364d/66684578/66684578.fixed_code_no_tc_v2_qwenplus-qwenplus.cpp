#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define vi vector<int>

// Binary search to find the k-th smallest absolute difference
int solveQuery(int b, int k, const vi &a_sorted) {
    int left = 0, right = (int)1e8 + 5;
    while (left < right) {
        int mid = (left + right) / 2;
        // Find number of elements in a that are in [b-mid, b+mid]
        int l = lower_bound(a_sorted.begin(), a_sorted.end(), b - mid) - a_sorted.begin();
        int r = upper_bound(a_sorted.begin(), a_sorted.end(), b + mid) - a_sorted.begin();
        if (r - l >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vi a(N);
    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end());
    rep(i, Q) {
        int b, k;
        cin >> b >> k;
        cout << solveQuery(b, k, a) << "\n";
    }
}