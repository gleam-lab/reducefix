#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll n, m, K;
    cin >> n >> m >> K;
    
    vector<ll> a(n);
    ll sum_a = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum_a += a[i];
    }
    
    vector<ll> A = a;
    sort(A.begin(), A.end());
    
    vector<ll> ac(n + 1, 0);
    for (ll i = 0; i < n; ++i) {
        ac[i + 1] = ac[i] + A[i];
    }
    
    vector<ll> C(n, -1);
    
    for (ll i = 0; i < n; ++i) {
        ll na = a[i];
        ll r = lower_bound(A.begin(), A.end(), na) - A.begin();
        ll uppercnt = n - r;
        ll rem = K - sum_a;
        ll M = m - uppercnt;
        
        if (M <= 0) continue;
        
        ll l = max(0LL, (ll)r - M);
        ll len = r - l;
        bool flag = A[l] <= a[i];
        if (flag) --l;
        
        ll cnt = (na + 1) * len - (ac[r] - ac[l] - (flag ? a[i] : 0));
        
        if (rem >= cnt) {
            C[i] = 0;
        } else {
            C[i] = cnt - rem;
        }
    }
    
    for (ll i = 0; i < n; ++i) {
        cout << C[i] << " \n"[i + 1 == n];
    }
    
    return 0;
}