#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;

bool canPlaceAllToys(vector<ll>& a, vector<ll>& b, ll x) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int i = 0, j = 0;
    while(i < a.size() && j < b.size()) {
        if(a[i] <= x && b[j] >= a[i]) {
            i++;
        } else {
            j++;
        }
    }
    
    return i == a.size();
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    for(ll i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    
    sort(b.begin(), b.end());
    
    ll low = *max_element(a.begin(), a.end()), high = LLONG_MAX;
    while(low < high) {
        ll mid = low + (high - low) / 2;
        
        if(canPlaceAllToys(a, b, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    if(low > *max_element(a.begin(), a.end())) {
        cout << -1 << endl;
    } else {
        cout << low << endl;
    }
    
    return 0;
}