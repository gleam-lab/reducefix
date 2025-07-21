#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll &x:v){
        cin >> x;
    }

    ll t = 0;
    for(auto x:v){
        t += ceil(x / 3.0);
    }
    cout << t << '\n';

    return 0;
}