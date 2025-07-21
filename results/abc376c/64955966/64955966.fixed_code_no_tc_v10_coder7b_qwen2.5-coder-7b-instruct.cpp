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
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < N - 1; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll min_size = INT_MAX;
    for(int i = 0; i < N - 1; i++) {
        if(a[i] > b[i]) {
            min_size = min(min_size, b[i]);
        }
    }
    if(a[N - 1] > b[N - 2]) {
        min_size = min(min_size, b[N - 2]);
    }
    if(min_size == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_size << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}