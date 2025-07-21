#include<bits/stdc++.h>
using namespace std;

vector<int> A, B;

void solve() {
    int n, q; cin >> n >> q;
    A.resize(n); B.resize(q);
    
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    for(int i = 0; i < q; ++i) {
        cin >> B[i] >> A[i];
    }
    
    for(int i = 0; i < q; ++i) {
        auto it = lower_bound(A.begin(), A.end(), B[i]);
        int dist = abs(B[i] - *it);
        if(it != A.begin()) dist = min(dist, abs(B[i] - *(--it)));
        cout << dist << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}