#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> v;
vector<int> idx;

int bs(ll x){
    int l = 0, r = v.size() - 1;
    while(l < r){
        int m = l + (r - l) / 2;
        if(v[m] < x) l = m + 1;
        else r = m;
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; ++i){
        ll x; cin >> x;
        v.push_back(x);
        idx.push_back(i);
    }
    sort(idx.begin(), idx.end(), [&](int a, int b){return v[a] < v[b];});
    vector<int> cnt(n + 1, 0);
    for(int i = 0; i < n; ++i){
        ++cnt[idx[i]];
    }
    vector<ll> pre(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i - 1] + cnt[i];
    }

    while(q--){
        ll x, k; cin >> x >> k;
        int pos = bs(x);
        int need = pre[pos] + k - 1;
        if(need > n){
            cout << x + abs(need - n) << '\n';
        }else{
            int ans = lower_bound(pre.begin(), pre.end(), need) - pre.begin();
            cout << x - v[ans] << '\n';
        }
    }
    return 0;
}