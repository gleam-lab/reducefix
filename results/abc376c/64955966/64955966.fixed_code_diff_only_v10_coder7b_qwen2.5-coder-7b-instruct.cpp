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
    for(ll i = 0; i < N; ++i){
        cin >> a[i];
    }
    for(ll i = 0; i < N - 1; ++i){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Check if the largest toy can fit in the largest box
    if(a.back() > b.back()){
        cout << -1 << endl;
        return;
    }

    // Find the smallest box that can fit the largest toy
    ll x = *max_element(b.begin(), b.end()) + 1;

    // Check if we can place all toys using this box
    bool possible = true;
    for(ll i = 0; i < N - 1 && possible; ++i){
        if(a[i] <= x && a[i + 1] <= x){
            continue;
        }else{
            possible = false;
        }
    }

    if(possible){
        cout << x << endl;
    }else{
        cout << -1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}