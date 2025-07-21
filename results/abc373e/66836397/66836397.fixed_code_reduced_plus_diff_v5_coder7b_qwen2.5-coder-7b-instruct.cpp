#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

bool check(vector<ll>& a, vector<ll>& ac, ll m, ll k, ll x, int i) {
    ll na = a[i] + x;
    ll r = lower_bound(ac.begin(), ac.end(), na) - ac.begin();
    ll uppercnt = n - r;
    ll rem = k - sum(x);
    ll M = m - uppercnt;
    if (M <= 0) return false;
    ll l = r - M;
    ll len = r - l;
    bool flag = ac[l] <= a[i];
    if (flag) l--;
    ll cnt = (na + 1) * len - (ac[r] - ac[l] - (flag ? a[i] : 0));
    if (rem >= cnt) return false;
    return true;
}

ll binarySearch(vector<ll>& a, vector<ll>& ac, ll m, ll k, int i) {
    ll left = 0, right = k - sum(a);
    while (left < right) {
        ll mid = left + (right - left) / 2;
        if (check(a, ac, m, k, mid, i)) {
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
    
    ll n, m, k;
    cin >> n >> m >> k;
    
    vector<ll> a(n);
    vector<ll> ac(n + 1);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ac[i + 1] = ac[i] + a[i];
    }
    
    for (int i = 0; i < n; i++) {
        ll result = check(a, ac, m, k, 0, i) ? 0 : binarySearch(a, ac, m, k, i);
        cout << result << " ";
    }
    
    return 0;
}