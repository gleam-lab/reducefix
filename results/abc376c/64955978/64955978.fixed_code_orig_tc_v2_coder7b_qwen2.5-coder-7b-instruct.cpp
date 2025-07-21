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
    for(ll &x : a) cin >> x;
    for(ll &x : b) cin >> x;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll i = 0, j = 0;
    while(i < N && j < N-1){
        if(a[i] <= b[j]){
            i++;
        }else{
            j++;
        }
    }

    if(i == N){
        cout << "YES\n";
    }else{
        cout << "-1\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}