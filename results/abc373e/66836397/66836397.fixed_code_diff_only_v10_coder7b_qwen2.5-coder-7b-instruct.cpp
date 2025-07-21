#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll n, m, K;
    cin >> n >> m >> K;
    vector<ll> a(n);
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    
    vector<ll> A = a;
    sort(A.begin(), A.end());
    vector<ll> ac(n + 1, 0);
    for (ll i = 0; i < n; ++i) {
        ac[i + 1] = ac[i] + A[i];
    }
    
    vector<ll> C(n, -1);
    for (ll i = 0; i < n; ++i) {
        if (a[i] >= K - sum) {
            C[i] = 0;
            continue;
        }
        
        ll left = 0, right = K - sum;
        while (left < right) {
            ll mid = (left + right) / 2;
            ll na = a[i] + mid;
            ll r = upper_bound(A.begin(), A.end(), na) - A.begin();
            ll uppercnt = n - r;
            ll rem = K - sum - mid;
            ll M = m - uppercnt;
            
            if (M <= 0) {
                left = mid + 1;
            } else {
                ll l = max(0LL, r - M);
                ll len = r - l;
                bool flag = A[l] <= a[i];
                if (flag) l--;
                ll cnt = (na + 1) * len - (ac[r] - ac[l] - (flag ? a[i] : 0));
                if (rem >= cnt) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }
        
        if (left != 0) {
            C[i] = left;
        }
    }
    
    for (ll c : C) {
        cout << c << " ";
    }
    cout << endl;
    
    return 0;
}