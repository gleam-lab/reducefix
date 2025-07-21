#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> prefix_sum(vector<ll>& arr) {
    vector<ll> res(arr.size() + 1, 0);
    for (int i = 0; i < arr.size(); ++i) {
        res[i + 1] = res[i] + arr[i];
    }
    return res;
}

bool can_win(vector<ll>& a, vector<ll>& pref, ll x, int m, int n) {
    for (int i = 0; i < n; ++i) {
        ll needed = max(0LL, a[i] + x - (pref[n] - pref[i + 1]));
        if (needed <= (n - i - 1 - (m - 1))) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    sort(a.rbegin(), a.rend());
    vector<ll> pref = prefix_sum(a);

    vector<ll> result(n, -1);
    for (int i = 0; i < n; ++i) {
        if (a[i] * 2 > pref[n]) {
            continue;
        }
        int left = 0, right = k + 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (can_win(a, pref, mid, m, n)) {
                result[i] = mid;
                break;
            } else {
                left = mid + 1;
            }
        }
    }

    for (auto &val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}