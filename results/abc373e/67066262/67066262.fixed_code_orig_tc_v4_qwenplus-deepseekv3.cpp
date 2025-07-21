#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end(), greater<ll>());
    ll threshold = (M <= N) ? sortedA[M - 1] : 0;
    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        if (M > N) {
            ans[i] = 0;
            continue;
        }
        ll required = max(0LL, threshold - A[i] + 1);
        if (required <= K - total) {
            ans[i] = required;
        } else {
            ans[i] = -1;
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}