#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N - 1);
    
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (ll i = 0; i < N - 1; i++) {
        cin >> B[i];
    }
    
    sort(B.begin(), B.end());
    
    ll min_x = LLONG_MAX;
    for (ll i = 0; i < N - 1; i++) {
        bool can_place_all = true;
        for (ll j = 0; j < N; j++) {
            if (A[j] > B[i] && A[j] < B[i + 1]) {
                can_place_all = false;
                break;
            }
        }
        if (can_place_all) {
            min_x = B[i + 1];
            break; // As we're iterating in ascending order of box sizes, this will be the smallest such x
        }
    }
    
    if (min_x == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_x << endl;
    }
    
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}