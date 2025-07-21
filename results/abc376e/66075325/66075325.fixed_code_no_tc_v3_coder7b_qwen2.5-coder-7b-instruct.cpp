#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long

ll solve(int n, int k, vector<ll>& A, vector<ll>& B) {
    vector<pair<ll, int>> pairs(n);
    for (int i = 0; i < n; ++i) pairs[i] = {A[i], i};
    
    sort(pairs.begin(), pairs.end());
    sort(B.begin(), B.end());
    
    ll maxA = 0, sumB = 0, res = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        maxA = max(maxA, pairs[i].first);
        sumB += B[pairs[i].second];
        
        if (i >= k - 1) {
            res = min(res, maxA * sumB);
            sumB -= B[pairs[i - k + 1].second];
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<ll> A(n), B(n);
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int i = 0; i < n; ++i) cin >> B[i];
        cout << solve(n, k, A, B) << '\n';
    }
    return 0;
}