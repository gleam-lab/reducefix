#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll binary_search(ll left, ll right, const vector<ll>& A, const vector<ll>& ac, ll M, ll K, ll a_i, int i) {
    while (left < right) {
        ll mid = left + (right - left) / 2;
        ll na = a_i + mid;
        ll r = upper_bound(A.begin(), A.end(), na) - A.begin();
        ll uppercnt = n - r;
        ll rem = K - mid;
        ll m = M - uppercnt;
        if (m <= 0) {
            right = mid;
        } else {
            ll l = r - m;
            ll len = r - l;
            bool flag = A[l] <= a_i;
            if (flag) l--;
            ll cnt = (na + 1) * len - (ac[r] - ac[l] - (flag ? a_i : 0));
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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> A = a;
    sort(A.begin(), A.end());
    vector<ll> ac(n + 1, 0);
    for (int i = 0; i < n; i++) {
        ac[i + 1] = ac[i] + A[i];
    }

    for (int i = 0; i < n; i++) {
        ll a_i = a[i];
        ll ok = K, ng = -1;
        while (abs(ok - ng) > 1) {
            ll mid = ok + (ng - ok) / 2;
            if (binary_search(mid, ok, A, ac, m, K, a_i, i) != -1) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        if (binary_search(ok, ok, A, ac, m, K, a_i, i) != -1) {
            cout << ok << " ";
        } else {
            cout << "-1 ";
        }
    }
    cout << endl;

    return 0;
}