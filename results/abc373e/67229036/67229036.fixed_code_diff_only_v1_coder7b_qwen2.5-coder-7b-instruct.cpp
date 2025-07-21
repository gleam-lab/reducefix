#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, k, sum, cnt;
vector<ll> a;

bool check(ll x, ll y) {
    // Calculate the rank of the candidate after receiving x + y votes
    auto it = upper_bound(begin(a), end(a), x + y);
    int z = it - begin(a);
    
    // Check if the candidate can still win even if all remaining votes go to other candidates
    return (x + y + 1) * (z - n + m) > k - y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    a.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    sort(begin(a), end(a));

    for(int i = 0; i < n; ++i) {
        ll l = 0, r = k + 1;
        while(l < r) {
            ll mid = (l + r) / 2;
            if(check(a[i], mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if(l <= k) {
            cout << l << " ";
        } else {
            cout << "-1 ";
        }
    }

    return 0;
}