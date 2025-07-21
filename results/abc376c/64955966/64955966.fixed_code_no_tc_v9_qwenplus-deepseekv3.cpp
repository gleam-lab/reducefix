#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N), b(N-1);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N-1; i++) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    
    ll x_needed = -1;
    int i = 0, j = 0;
    while (i < N && j < N-1) {
        if (a[i] <= b[j]) {
            i++;
            j++;
        } else {
            if (x_needed == -1) {
                x_needed = a[i];
                i++;
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    
    if (i < N) {
        if (x_needed == -1) {
            x_needed = a.back();
        } else {
            cout << -1 << endl;
            return;
        }
    }
    
    if (x_needed == -1) {
        x_needed = 1; // since we have to purchase one box, smallest possible is 1
    }
    
    cout << x_needed << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}