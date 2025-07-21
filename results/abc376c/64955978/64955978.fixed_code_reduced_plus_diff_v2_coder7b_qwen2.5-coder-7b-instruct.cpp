#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N-1);
    for(ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    for(ll i = 0; i < N-1; i++) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // The largest box we need is at least as big as the largest toy
    ll requiredSize = *max_element(A.begin(), A.end());

    bool found = false;
    for(ll i = 0; i < N-1 && !found; i++) {
        if(B[i] >= requiredSize) {
            found = true;
        }
    }

    if(found) {
        cout << requiredSize << endl;
    } else {
        cout << "-1" << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}