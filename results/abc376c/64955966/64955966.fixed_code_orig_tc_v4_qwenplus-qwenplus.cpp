#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N - 1);

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    multiset<ll> toys(A.begin(), A.end());

    // Try to fit the smallest toy into the smallest box
    for (int i = 0; i < N - 1; ++i) {
        auto it = toys.lower_bound(B[i]);
        if (it == toys.end() || *it > B[i]) {
            cout << -1 << endl;
            return;
        }
        toys.erase(it);
    }

    // The remaining toy is the one we need to put in the new box
    cout << *toys.begin() << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}