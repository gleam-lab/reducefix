#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (ll &a : A) cin >> a;
    ll remaining = K;
    for (ll a : A) remaining -= a;

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    vector<ll> prefix(N + 1, 0);
    for (ll i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    for (ll i = 0; i < N; ++i) {
        ll a_i = A[i];
        ll low = 0, high = remaining;
        ll answer = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_a = a_i + mid;
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), new_a);
            ll pos = it - sorted_A.begin();
            ll count_above = N - pos;
            if (count_above < M) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << answer << " \n"[i == N - 1];
    }
    return 0;
}