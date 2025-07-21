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
    
    multiset<ll> boxes(b.begin(), b.end());
    ll required_x = 0;
    
    for (int i = 0; i < N; i++) {
        auto it = boxes.lower_bound(a[i]);
        if (it != boxes.end()) {
            boxes.erase(it);
        } else {
            if (required_x == 0) {
                required_x = a[i];
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    
    if (required_x != 0) {
        cout << required_x << endl;
    } else {
        cout << 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}