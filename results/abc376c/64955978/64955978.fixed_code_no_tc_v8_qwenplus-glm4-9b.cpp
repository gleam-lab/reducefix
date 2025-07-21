#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N - 1);
    
    // Read toy sizes
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Read box sizes
    for (ll i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }
    
    // Sort toy sizes in descending order
    sort(A.begin(), A.end(), greater<ll>());
    
    // Sort box sizes in descending order
    sort(B.begin(), B.end(), greater<ll>());
    
    // Find the opposite pair index
    ll oppositePairIndex = -1;
    for (ll i = 0; i < N - 1; ++i) {
        if (A[i] <= B[i]) {
            oppositePairIndex = i;
            break;
        }
    }
    
    if (oppositePairIndex == -1) {
        // All toys can fit in their respective boxes
        cout << A[0] << endl;
    } else {
        // Check if the smallest box can accommodate the largest toy
        if (A[N - 1] <= B[oppositePairIndex]) {
            cout << A[N - 1] << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}