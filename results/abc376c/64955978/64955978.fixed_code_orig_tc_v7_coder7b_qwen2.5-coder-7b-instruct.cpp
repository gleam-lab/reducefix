#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

void solve(){
    ll N;
    cin >> N;
    vector<ll> a(N), b(N-1);
    for(ll i = 0; i < N; i++) cin >> a[i];
    for(ll i = 0; i < N-1; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll mx = *max_element(a.begin(), a.end());
    bool found = false;

    for(ll i = 0; i < N-1; i++){
        if(mx <= b[i]){
            cout << b[i] << endl;
            found = true;
            break;
        }
    }

    if(!found){
        if(mx <= b[N-2]) cout << b[N-2] << endl;
        else cout << -1 << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}