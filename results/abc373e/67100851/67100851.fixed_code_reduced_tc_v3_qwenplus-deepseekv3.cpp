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

    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + A[i].a;
    }

    ll total_used = prefix_sum[N];
    ll remaining = K - total_used;

    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll low = 0;
        ll high = remaining;
        ll best = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = A[i].a + mid;

            // Find the first candidate in the sorted array with a > new_votes
            auto it = upper_bound(A.begin(), A.end(), Candidate{new_votes, 0}, compareA);
            int count = A.end() - it;

            if (count < M) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (best != -1) {
            res[A[i].idx] = best;
        } else {
            res[A[i].idx] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}