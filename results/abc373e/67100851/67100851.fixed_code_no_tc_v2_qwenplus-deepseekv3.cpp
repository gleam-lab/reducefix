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

    ll total_used = prefix[N];
    ll remaining = K - total_used;

    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        ll best = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll current_votes = A[i].a + mid;

            int pos = upper_bound(A.begin(), A.end(), Candidate{current_votes, -1}, compareA) - A.begin();

            int needed = N - M;
            if (pos <= needed) {
                low = mid + 1;
                continue;
            }

            ll sum = prefix[pos] - prefix[needed];
            ll req = current_votes * (pos - needed) - sum;

            if (req <= remaining - mid) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        res[A[i].idx] = best;
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}