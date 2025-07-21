#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

ll min_value(ll N, ll K, vector<ll>& A, vector<ll>& B) {
    vector<pair<ll, ll>> AB(N);
    for (ll i = 0; i < N; ++i) {
        AB[i] = {A[i], B[i]};
    }
    sort(AB.begin(), AB.end());
    
    ll max_A = 0, sum_B = 0;
    for (ll i = N - 1; i > N - K - 1; --i) {
        max_A = max(max_A, AB[i].first);
        sum_B += AB[i].second;
    }
    
    return max_A * sum_B;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        ll N, K;
        cin >> N >> K;
        vector<ll> A(N), B(N);
        for (ll i = 0; i < N; ++i) cin >> A[i];
        for (ll i = 0; i < N; ++i) cin >> B[i];
        
        cout << min_value(N, K, A, B) << '\n';
    }
    return 0;
}