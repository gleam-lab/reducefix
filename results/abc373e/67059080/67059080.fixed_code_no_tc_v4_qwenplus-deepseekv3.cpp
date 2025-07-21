#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    ll remaining = K - prefix[N];
    if (remaining < 0) {
        remaining = 0;
    }

    vector<ll> ans(N);

    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        ll low = 0;
        ll high = remaining;
        ll best_X = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = current + mid;

            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), new_val);
            int cnt = sorted_A.end() - it;

            if (cnt < M) {
                best_X = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (best_X != -1) {
            ll total_used = best_X;
            ll new_val = current + best_X;
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), new_val);
            int cnt = sorted_A.end() - it;

            if (cnt >= M) {
                best_X = -1;
            } else {
                ll used = total_used;
                ll remaining_after = remaining - used;
                if (remaining_after >= 0) {
                    ans[i] = best_X;
                } else {
                    best_X = -1;
                }
            }
        }

        if (best_X == -1) {
            ans[i] = -1;
        } else {
            ans[i] = best_X;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}