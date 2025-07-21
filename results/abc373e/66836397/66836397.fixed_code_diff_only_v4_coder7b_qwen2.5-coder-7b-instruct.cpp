#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(vector<ll>& A, ll K, ll M, int i) {
    ll sum = accumulate(A.begin(), A.end(), 0ll);
    ll needed_votes = max(0LL, (M + A[i]) * (A.size() - M) - sum + A[i]);
    return needed_votes <= K;
}

vector<ll> solve(int N, int M, ll K, vector<ll>& A) {
    vector<ll> ans(N, 0);
    for (int i = 0; i < N; ++i) {
        if (check(A, K, M, i)) continue;
        ans[i] = -1;
        for (ll j = 1; ; ++j) {
            A[i] += j;
            if (check(A, K, M, i)) {
                ans[i] = j;
                break;
            }
            A[i] -= j;
        }
    }
    return ans;
}

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector<ll> result = solve(N, M, K, A);
    for (int i = 0; i < N; ++i) cout << result[i] << " ";
    cout << endl;
    return 0;
}