#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
ll a[N], sm[N];

bool can_win(ll k, int m, int n, vector<ll>& A) {
    vector<ll> B = A;
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());

    for (int i = 0; i < n; ++i) {
        if (B[i] > k) return false;
        k -= B[i];
    }

    int above = 0;
    for (int i = 0; i < n; ++i) {
        if (B[i] > k) ++above;
        else break;
    }

    return above < m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> A(a, a + n);
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    for (int i = 0; i < n; ++i) {
        sm[i + 1] = sm[i] + A[i];
    }

    vector<ll> res(n);
    for (int i = 0; i < n; ++i) {
        ll lo = 0, hi = k - sm[i];
        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            if (can_win(k - mid, m, n, A)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        res[i] = lo;
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}