#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

struct Candidate {
    ll a;
    int idx;
};

bool compareA(const Candidate &x, const Candidate &y) {
    return x.a < y.a;
}

bool compareIdx(const Candidate &x, const Candidate &y) {
    return x.idx < y.idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<Candidate> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].a;
        A[i].idx = i;
    }

    sort(A.begin(), A.end(), compareA);

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + A[i].a;
    }

    ll remaining = K;
    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll low = 0;
        ll high = remaining;
        ll best = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = A[i].a + mid;

            int pos = upper_bound(A.begin(), A.end(), Candidate{new_votes, -1}, compareA) - A.begin();

            int rank = N - pos;
            if (pos > i) {
                rank = N - pos;
            } else {
                rank = N - pos - 1;
            }

            if (rank < M) {
                ll required = 0;
                int l = pos - (M - 1);
                if (l < 0) l = 0;
                required = (pos - l) * new_votes - (prefix[pos] - prefix[l]);

                if (required <= remaining - mid) {
                    best = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                low = mid + 1;
            }
        }

        res[A[i].idx] = best;
    }

    sort(A.begin(), A.end(), compareIdx);

    for (int i = 0; i < N; ++i) {
        if (res[i] != -1) {
            cout << res[i] << " ";
        } else {
            cout << -1 << " ";
        }
    }
    cout << endl;

    return 0;
}