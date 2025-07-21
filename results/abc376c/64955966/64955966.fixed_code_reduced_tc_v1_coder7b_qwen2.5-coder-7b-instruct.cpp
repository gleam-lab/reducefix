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
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < N-1; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    bool found = false;
    for(ll x = a[0]; !found && x <= b[0]; x += a[0]) {
        vector<bool> used(N-1, false);
        for(int i = 0; i < N; i++) {
            int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            while(idx >= 0 && (used[idx] || b[idx] < a[i])) {
                idx--;
            }
            if(idx >= 0) {
                used[idx] = true;
            } else {
                break;
            }
        }
        if(all_of(used.begin(), used.end(), [](bool v){ return v; })) {
            cout << x << endl;
            found = true;
        }
    }
    if(!found) {
        cout << -1 << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}