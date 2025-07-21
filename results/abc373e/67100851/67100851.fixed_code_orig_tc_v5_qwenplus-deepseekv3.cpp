#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

struct Candidate {
    ll a;
    int idx;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].a;
        candidates[i].idx = i;
    }

    // Sort candidates based on their current votes in descending order
    sort(candidates.begin(), candidates.end(), [](const Candidate &x, const Candidate &y) {
        return x.a > y.a;
    });

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i+1] = prefix[i] + candidates[i].a;
    }

    ll remaining = K - prefix[N];
    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = candidates[i].a + mid;
            // Find the first position where the votes are <= new_votes (since sorted in descending order)
            auto it = lower_bound(candidates.begin(), candidates.end(), new_votes, 
                [](const Candidate &c, ll val) {
                    return c.a > val;
                });
            int pos = it - candidates.begin();
            if (pos < M) {
                // The candidate is in the top M
                ll required = 0;
                if (pos > 0) {
                    required = pos * new_votes - prefix[pos];
                }
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
        res[candidates[i].idx] = best;
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}