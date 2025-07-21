#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5 + 5;
ll a[N], b[N];

bool check(ll mid, vector<ll>& v, vector<ll>& w) {
    int j = 0;
    for(int i = 0; i < v.size(); i++) {
        while(j < w.size() && w[j] < v[i]) j++;
        if(j == w.size()) return false;
        if(w[j] >= v[i]) j++;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    for(ll i = 0; i < n; i++)
        cin >> a[i];

    for(ll i = 0; i < n - 1; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + n - 1);

    ll lo = 0, hi = 1e9;
    while(lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if(check(mid, a, b)) hi = mid;
        else lo = mid + 1;
    }

    if(lo == 1e9)
        cout << "-1";
    else
        cout << lo;

    return 0;
}