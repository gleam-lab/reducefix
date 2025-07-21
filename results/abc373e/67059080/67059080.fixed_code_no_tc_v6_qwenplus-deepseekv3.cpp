#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<pair<ll, int>> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.rbegin(), A.rend());

    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + A[i].first;
    }

    ll total = prefix[N];
    ll remaining = K - total;

    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll low = 0;
        ll high = remaining;
        ll best = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_vote = A[i].first + mid;
            
            auto it = upper_bound(A.begin(), A.end(), make_pair(new_vote, N), greater<pair<ll, int>>());
            int pos = it - A.begin();
            
            if (pos < M) {
                best = mid;
                high = mid - 1;
            } else {
                ll sum_extra = 0;
                if (pos > 0) {
                    sum_extra = new_vote * pos - prefix[pos];
                }
                if (sum_extra <= remaining - mid) {
                    best = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        res[A[i].second] = best;
    }

    for (int i = 0; i < N; ++i) {
        if (res[i] == -1) {
            auto it = upper_bound(A.begin(), A.end(), make_pair(A[i].first, N), greater<pair<ll, int>>());
            int pos = it - A.begin();
            if (pos < M) {
                res[i] = 0;
            }
        }
        cout << res[i] << ' ';
    }

    return 0;
}