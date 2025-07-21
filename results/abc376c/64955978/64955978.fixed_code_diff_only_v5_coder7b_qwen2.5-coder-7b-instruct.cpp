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
    for(ll &x : a)
        cin >> x;
    for(ll &y : b)
        cin >> y;
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    if(a[0] < b.back()){
        cout << -1 << endl;
        return;
    }
    for(ll i = 0; i < N - 1; ++i){
        if(a[i] > b[i])
            continue;
        else{
            for(; i + 1 < N && a[i + 1] <= b[i]; ++i);
            if(i == N - 1 || a[i + 1] > b[i])
                cout << a[i] << endl;
            else
                cout << -1 << endl;
            return;
        }
    }
    cout << a[N - 1] << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}