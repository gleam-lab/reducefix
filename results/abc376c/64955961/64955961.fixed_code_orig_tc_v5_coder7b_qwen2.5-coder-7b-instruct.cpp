#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool check(vector<ll>& a, vector<ll>& b, ll mid) {
    int n = a.size(), m = b.size();
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for(int i = 0; i < n; ++i) {
        if(a[i] <= mid) pq.push({mid - a[i], i});
    }
    for(int i = 0; i < m; ++i) {
        while(!pq.empty() && pq.top().first > b[i]) pq.pop();
        if(pq.empty()) return false;
        pq.pop();
    }
    return true;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(ll i = 0; i < n-1; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll low = 1, high = 1e9, ans = -1;
    while(low <= high) {
        ll mid = low + (high - low) / 2;
        if(check(a, b, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}

int main()
{
    solve();
}