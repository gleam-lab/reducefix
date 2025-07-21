#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5 + 5;
ll a[N], b[N];

bool check(ll mid, int n) {
    vector<ll> extra_boxes;
    for (int i = 0; i < n - 1; ++i) {
        if (b[i] >= mid) continue;
        extra_boxes.push_back(mid - b[i]);
    }
    sort(extra_boxes.begin(), extra_boxes.end());
    for (int i = 0; i < n; ++i) {
        if (a[i] <= mid) continue;
        if (extra_boxes.empty() || a[i] > extra_boxes.back()) return false;
        extra_boxes.pop_back();
    }
    return true;
}

int main() {
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    for (ll i = 1; i < n; i++) cin >> b[i];
    
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n);
    
    ll l = max(*max_element(a + 1, a + n + 1), *max_element(b + 1, b + n));
    ll r = 1e9;
    
    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid, n)) r = mid;
        else l = mid + 1;
    }
    
    cout << (check(l, n) ? l : -1) << endl;
    
    return 0;
}