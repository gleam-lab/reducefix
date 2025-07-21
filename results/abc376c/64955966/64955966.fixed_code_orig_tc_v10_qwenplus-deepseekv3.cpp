#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N-1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N-1; i++) cin >> B[i];

    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());

    bool possible = true;
    for (int i = 0; i < N-1; i++) {
        if (A[i] > B[i]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << A.back() << endl;
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