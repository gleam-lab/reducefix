#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll N, M; cin >> N >> M;
    vector<ll> A(N+1, 0), B(N+1, 0), C(N+1, 0), D(N+1, 0);
    for(int i=1;i<=M;i++){
        ll a, b; cin >> a >> b;
        A[a]++;
        B[b]++;
        C[a+b]++;
        D[a-b+N]++;
    }
    ll ans = 0;
    for(ll i=1;i<=N;i++) ans += N-A[i]-B[i]-C[i]-D[i];
    cout << ans << '\n';
    return 0;
}