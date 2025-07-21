#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool check(vector<ll>& a, vector<ll>& b, ll mid) {
    int n = a.size(), m = b.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    int j = 0;
    for(int i = 0; i < n && j < m;) {
        if(a[i] <= b[j]) {
            i++;
        } else {
            j++;
        }
    }
    return i == n;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n-1; i++) cin >> b[i];

    ll low = *max_element(a.begin(), a.end()), high = 1e9;
    while(low < high) {
        ll mid = (low + high) / 2;
        if(check(a, b, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    if(check(a, b, low)) cout << low << endl;
    else cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}