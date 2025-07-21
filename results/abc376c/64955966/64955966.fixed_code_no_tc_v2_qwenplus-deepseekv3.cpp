#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N-1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N-1; ++i) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    
    int i = 0, j = 0;
    ll required_x = 0;
    while (i < N && j < N-1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            required_x = max(required_x, A[i]);
            ++i;
        }
    }
    
    while (i < N) {
        required_x = max(required_x, A[i]);
        ++i;
    }
    
    if (required_x == 0) {
        // All toys fit into existing boxes, x can be any positive integer, smallest is 1
        cout << 1 << endl;
    } else {
        cout << required_x << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}