#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

bool can_win(ll add, int idx, ll pre_sum) {
    ll remain = K - pre_sum;
    ll cur = A[idx] + add;
    ll tar = cur + 1;
    int L = 0, R = N - idx;
    while (L < R) {
        int MID = (L + R + 1) >> 1;
        ll need = tar * MID - (pre_sum - (pre_sum - pre_sum / N * (N - idx)));
        if (pre_sum - pre_sum / N * (N - idx) < idx) {
            need -= (add + 1);
        }
        if (need <= remain) L = MID;
        else R = MID - 1;
    }
    return R + (pre_sum - pre_sum / N * (N - idx) < idx) >= M;
}

int main() {
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (ll &a : A) cin >> a;

    sort(A.begin(), A.end(), greater<ll>());

    ll pre_sum = 0;
    for (ll a : A) pre_sum += a;
    K -= pre_sum;

    vector<ll> B(N);
    for (int i = 0; i < N; ++i) {
        B[i] = can_win(0, i, pre_sum);
    }

    for (int i = 0; i < N; ++i) {
        if (B[i]) cout << 0 << ' ';
        else {
            ll l = 0, r = K;
            while (l < r) {
                ll mid = (l + r + 1) >> 1;
                if (can_win(mid, i, pre_sum)) r = mid;
                else l = mid;
            }
            cout << l << ' ';
        }
    }

    return 0;
}