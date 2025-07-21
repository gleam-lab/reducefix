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
    for(ll i = 0; i < N; ++i) cin >> a[i];
    for(ll i = 0; i < N-1; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll j = 0;
    for(ll i = 0; i < N-1; ++i){
        while(j < N && a[j] <= b[i]) ++j;
        if(j == N) {
            cout << "-1\n";
            return;
        }
    }

    cout << a[j-1] << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}