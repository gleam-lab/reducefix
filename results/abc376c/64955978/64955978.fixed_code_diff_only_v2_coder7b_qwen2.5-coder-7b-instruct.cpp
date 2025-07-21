#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

void solve(){
    ll N;
    cin >> N;
    vector<ll> a(N), b(N - 1);
    for(ll &x: a) cin >> x;
    for(ll &x: b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    bool found = false;
    for(ll i = 0; i < N - 1; ++i){
        if(a[i] <= b[0]) {
            found = true;
            break;
        }
    }

    if(!found && a[N - 1] > b[N - 2]){
        cout << -1 << endl;
        return;
    }

    if(found)
        cout << *max_element(a.begin(), a.end()) << endl;
    else
        cout << b[N - 2] + 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}