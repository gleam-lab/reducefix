#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N), b(N - 1);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> b[i];
    }
    
    // Find the maximum size among all toys
    ll maxToySize = *max_element(a.begin(), a.end());
    
    // Check if the maximum toy size is greater than or equal to the largest box size
    if (maxToySize <= *max_element(b.begin(), b.end())) {
        cout << maxToySize << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}