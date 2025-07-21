#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

typedef long long ll;

ll binary_search(vector<ll>& A, vector<ll>& ac, ll n, ll m, ll k, ll i, ll lowerbound) {
    ll left = lowerbound, right = k + 1;
    while (left < right) {
        ll mid = left + (right - left) / 2;
        ll na = A[i] + mid;
        ll r = upper_bound(begin(A), end(A), na) - begin(A);
        ll uppercnt = n - r;
        ll rem = k - mid;
        ll M = m - uppercnt;
        if (M <= 0) {
            right = mid;
        } else {
            ll l = max(r - M, 0LL);
            ll len = r - l;
            bool flag = A[l] <= A[i];
            if (flag) l--;
            ll cnt = (na + 1) * len - (ac[r] - ac[l] - (flag ? A[i] : 0));
            if (rem >= cnt) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
    }
    return left;
}

int main() {
    ll n, m, K;
    cin >> n >> m >> K;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> A = a;
    sort(begin(A), end(A));
    vector<ll> ac(n + 1, 0);
    for (ll i = 0; i < n; ++i) {
        ac[i + 1] = ac[i] + A[i];
    }
    vector<ll> results(n);
    for (ll i = 0; i < n; ++i) {
        ll lowerbound = 0;
        if (i > 0) {
            lowerbound = max(lowerbound, A[i - 1] - A[i] + 1);
        }
        results[i] = binary_search(A, ac, n, m, K, i, lowerbound);
    }
    for (ll i = 0; i < n; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;
    return 0;
}