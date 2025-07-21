#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> a, b;
map<ll, int> mp;

bool cmp(ll x, ll y){
    return x > y;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll n, q;
    cin >> n >> q;
    
    a.resize(n + 1);
    b.resize(q + 1);
    
    for(ll i = 1; i <= n; ++i){
        cin >> a[i];
    }
    
    sort(a.begin() + 1, a.end());
    
    for(ll i = 1; i <= q; ++i){
        cin >> b[i] >> mp[b[i]];
    }
    
    vector<pair<ll, ll>> v;
    
    for(auto &it : mp){
        v.push_back({it.first, it.second});
    }
    
    sort(v.rbegin(), v.rend(), cmp);
    
    for(auto &it : v){
        ll target = it.first;
        ll index = it.second;
        
        auto it1 = lower_bound(a.begin() + 1, a.end(), target);
        ll pos = it1 - a.begin();
        
        if(pos == 1){
            cout << abs(target - a[1]) << "\n";
        } else if(pos == n){
            cout << abs(target - a[n]) << "\n";
        } else {
            ll left = abs(target - a[pos - 1]);
            ll right = abs(target - a[pos]);
            
            if(left < right){
                cout << left << "\n";
            } else {
                cout << right << "\n";
            }
        }
    }

    return 0;
}