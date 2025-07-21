#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

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

    ll remaining = K - prefix[N];

    vector<ll> res(N);
    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        ll low = 0, high = remaining;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current + mid;

            auto it = upper_bound(sortedA.begin(), sortedA.end(), new_votes);
            int cnt = sortedA.end() - it;

            if (cnt < M) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (ans != -1) {
            // Now check if it's possible to distribute the remaining votes to maintain cnt < M
            auto it = upper_bound(sortedA.begin(), sortedA.end(), current + ans);
            int idx = it - sortedA.begin();
            int cnt = N - idx;

            if (cnt >= M) {
                ans = -1;
            } else {
                // Check if the remaining votes can be distributed to make sure cnt < M
                // The worst case is to distribute the votes to the candidates with votes <= new_votes to push them above new_votes
                ll needed = 0;
                ll s = 0;
                int left = idx;
                int right = N;
                while (left < right) {
                    int mid_pos = (left + right) / 2;
                    ll total = sortedA[mid_pos] * (mid_pos - idx + 1) - (prefix[mid_pos + 1] - prefix[idx]);
                    if (total <= remaining - ans) {
                        left = mid_pos + 1;
                    } else {
                        right = mid_pos;
                    }
                }
                int possible = left - idx;
                if (N - left < M) {
                    // Valid
                } else {
                    ans = -1;
                }
            }
        }

        res[i] = ans;
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}