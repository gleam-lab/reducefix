#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll sum = 0;
    for (ll& a : A) {
        cin >> a;
        sum += a;
    }
    ll rem = K - sum;
    
    if (M == N) {
        for (int i = 0; i < N; ++i) {
            cout << 0 << " \n"[i == N-1];
        }
        return 0;
    }
    
    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end(), greater<ll>());
    ll threshold = sorted_A[M-1];
    
    for (ll a : A) {
        if (a >= threshold) {
            cout << 0 << ' ';
        } else {
            ll needed = threshold - a;
            if (needed > rem) {
                cout << -1 << ' ';
            } else {
                cout << needed << ' ';
            }
        }
    }
    cout << '\n';
    
    return 0;
}