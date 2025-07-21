#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N - 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> B[i];
    }

    // Sort both arrays
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if the largest toy can fit in any existing box
    if (A.back() <= B.back()) {
        cout << "-1" << endl;
    } else {
        cout << A.back() << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}