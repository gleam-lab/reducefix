#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
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
        return A[i] < A[j];
    });

    vector<ll> sortedA(N);
    for (int i = 0; i < N; ++i) {
        sortedA[i] = A[indices[i]];
    }

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }

    ll remaining = K - prefix[N];
    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        ll ans_votes = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_vote = sortedA[i] + mid;
            int pos = upper_bound(sortedA.begin(), sortedA.end(), new_vote) - sortedA.begin();
            int cnt = N - pos;
            if (cnt < M) {
                ll needed = 0;
                if (pos > i) {
                    needed = (new_vote + 1) * (pos - i - 1) - (prefix[pos] - prefix[i + 1]);
                }
                if (needed <= remaining - mid) {
                    ans_votes = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                low = mid + 1;
            }
        }
        res[indices[i]] = ans_votes;
    }

    for (int i = 0; i < N; ++i) {
        cout << (res[i] == -1 ? -1 : max(0LL, res[i])) << ' ';
    }

    return 0;
}