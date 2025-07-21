#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool check(vector<ll>& A, vector<ll>& prefix, ll x, ll m, ll K) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        if (prefix[n] - prefix[i + 1] + A[i] + x < (n - i - 1) * (m + 1)) {
            return false;
        }
    }
    return true;
}

int main() {
    ll n, m, K;
    cin >> n >> m >> K;
    vector<ll> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + A[i];
    }

    vector<ll> ans(n, 0);
    for (int i = 0; i < n; ++i) {
        ll left = 0, right = K;
        while (left < right) {
            ll mid = (left + right) / 2;
            if (check(A, prefix, mid, m, K)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        ans[i] = left;
    }

    for (int i = 0; i < n; ++i) {
        if (ans[i] > K - prefix[n]) {
            ans[i] = -1;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}