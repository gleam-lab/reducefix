#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> a;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        a.push_back(abs(x));
    }
    sort(a.begin(), a.end());
    for(int i = 1; i < a.size(); i++){
        a[i] += a[i - 1];
    }
    for(int i = 0; i < q; i++){
        ll x, k; cin >> x >> k;
        ll target = a[k - 1];
        auto it = lower_bound(a.begin(), a.end(), target);
        if(it == a.end()){
            cout << x - (*it - target) << endl;
        }else{
            cout << x - (*it - target) << endl;
        }
    }
    return 0;
}