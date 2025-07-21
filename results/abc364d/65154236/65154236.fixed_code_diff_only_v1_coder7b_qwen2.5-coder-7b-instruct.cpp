#include <bits/stdc++.h>
using namespace std;

vector<int> A, B;

void solve() {
    int n, q; cin >> n >> q;
    A.resize(n); B.resize(q);
    for(int i = 0; i < n; i++) cin >> A[i];
    sort(A.begin(), A.end());
    for(int i = 0; i < q; i++) {
        cin >> B[i]; int k; cin >> k;
        auto it = lower_bound(A.begin(), A.end(), B[i]);
        int idx = it - A.begin();
        int dist = abs(A[idx] - B[i]);
        if(idx != 0 && abs(A[idx - 1] - B[i]) < dist) dist = abs(A[idx - 1] - B[i]);
        if(idx != n - 1 && abs(A[idx + 1] - B[i]) < dist) dist = abs(A[idx + 1] - B[i]);
        cout << dist << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}