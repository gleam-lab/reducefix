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

    // Check if the largest toy can fit into any box
    if(a.back() > b.back()) {
        cout << -1 << endl;
        return;
    }

    // Find the smallest box that can fit the largest toy
    int idx = upper_bound(b.begin(), b.end(), a.back()) - b.begin();
    cout << b[idx] << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}