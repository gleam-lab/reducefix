#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M), B(M);
    unordered_set<ll> cols, diag1, diag2;

    for(int i=0;i<M;i++){
        cin >> A[i] >> B[i];
        cols.insert(B[i]);
        diag1.insert(A[i] + B[i]);
        diag2.insert(A[i] - B[i]);
    }

    ll ans = N*N - (M + cols.size() + diag1.size() + diag2.size());
    cout << ans << '\n';

    return 0;
}