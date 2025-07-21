#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end());

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
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

            ll new_vote = A[i] + mid;
            auto it = upper_bound(sortedA.begin(), sortedA.end(), new_vote);
            int cnt = sortedA.end() - it;

            if (cnt < M) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (best != -1) {
            ll new_vote = A[i] + best;
            auto it = upper_bound(sortedA.begin(), sortedA.end(), new_vote);
            int cnt = sortedA.end() - it;

            ll sum = 0;
            if (cnt > 0) {
                sum = new_vote * cnt - (prefix[N] - prefix[N - cnt]);
            }

            if (sum <= remaining - best) {
                res[i] = best;
            } else {
                res[i] = -1;
            }
        } else {
            res[i] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;
}