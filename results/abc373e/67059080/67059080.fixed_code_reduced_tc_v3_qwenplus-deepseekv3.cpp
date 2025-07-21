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

    vector<int> indices(N);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return A[i] > A[j];
    });

    vector<ll> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = A[indices[i]];
    }

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    ll remaining = K - prefix[N];
    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll current_votes = sorted_A[i] + mid;
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), current_votes, greater<ll>()) - sorted_A.begin();
            if (pos < M) {
                best = mid;
                high = mid - 1;
            } else {
                ll needed = current_votes * (pos - (i < pos ? 1 : 0)) - (prefix[pos] - (i < pos ? sorted_A[i] : 0));
                if (needed <= remaining - mid) {
                    best = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        res[indices[i]] = best != -1 ? best : -1;
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }

    return 0;
}