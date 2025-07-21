#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll remaining = K - total;
    
    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end(), greater<ll>());
    ll threshold = (M <= N) ? sortedA[M - 1] : 0;
    
    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        if (sortedA[M - 1] <= A[i]) {
            ans[i] = 0;
            continue;
        }
        ll required = sortedA[M - 1] - A[i] + 1;
        if (required <= remaining) {
            ans[i] = required;
        } else {
            ans[i] = -1;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        if (ans[i] == -1) {
            if (M == N) {
                ans[i] = 0;
            } else if (A[i] + remaining > sortedA[M]) {
                ans[i] = max(0LL, sortedA[M] - A[i] + 1);
            } else {
                ans[i] = -1;
            }
        }
    }
    
    for (int i = 0; i < N; ++i) {
        if (ans[i] != -1 && ans[i] > remaining) {
            ans[i] = -1;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}