#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool check(vector<ll>& a, vector<ll>& b, ll x) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    int j = 0;
    for(int i = 0; i < a.size(); i++) {
        while(j < b.size() && b[j] >= a[i]) {
            j++;
        }
        if(j == b.size()) return false;
    }
    return true;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n-1; i++) cin >> b[i];

    ll low = *max_element(a.begin(), a.end()), high = 1e9, ans = -1;
    while(low <= high) {
        ll mid = (low + high) / 2;
        if(check(a, b, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}