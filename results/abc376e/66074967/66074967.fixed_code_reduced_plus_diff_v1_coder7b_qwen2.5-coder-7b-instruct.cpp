#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

ll solve(vector<ll>& A, vector<ll>& B, int K) {
    int n = A.size();
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());

    ll ans = LLONG_MAX;
    for(int i = 0; i <= n - K; ++i) {
        ll max_A = A[i];
        ll sum_B = 0;
        for(int j = 0; j < K; ++j) {
            sum_B += B[i + j];
        }
        ans = min(ans, max_A * sum_B);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> A(n), B(n);
        for(int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for(int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        cout << solve(A, B, k) << '\n';
    }
    return 0;
}