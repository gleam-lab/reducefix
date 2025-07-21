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
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N-1; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    bool found = false;
    for(ll x = a[0]; x <= a[N-1]; ++x){
        vector<bool> used(N-1, false);
        bool valid = true;
        for(int i = 0; i < N; ++i){
            int idx = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
            if(idx == N-1 && !used[idx] && a[i] <= b[idx]){
                used[idx] = true;
            }else if(idx > 0 && !used[idx-1] && a[i] <= b[idx-1]){
                used[idx-1] = true;
            }else{
                valid = false;
                break;
            }
        }
        if(valid){
            cout << x << endl;
            found = true;
            break;
        }
    }
    if(!found) cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}