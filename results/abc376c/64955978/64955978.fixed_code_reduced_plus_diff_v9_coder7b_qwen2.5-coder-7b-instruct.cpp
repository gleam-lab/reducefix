#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

bool check(vector<ll> &a, vector<ll> &b, ll x) {
    int n = a.size();
    int m = b.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int j = 0;
    for(int i = 0; i < n; ++i) {
        while(j < m && a[i] > b[j]) ++j;
        if(j == m) return false;
        ++j;
    }
    return true;
}

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N), b(N - 1);
    for(ll i = 0; i < N; ++i) cin >> a[i];
    for(ll i = 0; i < N - 1; ++i) cin >> b[i];

    if(check(a, b, *max_element(a.begin(), a.end()))) {
        cout << *max_element(a.begin(), a.end()) << '\n';
    } else {
        cout << "-1\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}