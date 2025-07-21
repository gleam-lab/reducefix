#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Candidate {
    ll votes;
    int idx;
};

bool compare(const Candidate& a, const Candidate& b) {
    return a.votes < b.votes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<Candidate> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].votes;
        A[i].idx = i;
    }

    // Sort candidates by current votes
    sort(A.begin(), A.end(), compare);

    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + A[i].votes;
    }

    vector<ll> result(N);
    ll remaining_votes = K - prefix_sum[N];

    // Prepare positions
    vector<int> pos(N);
    for (int i = 0; i < N; ++i) {
        pos[A[i].idx] = i;
    }

    for (int i = 0; i < N; ++i) {
        int need_more_than_me = M - 1;
        if (need_more_than_me == 0) {
            // This candidate just needs to stay ahead of others
            // So they don't need any additional votes
            result[A[i].idx] = 0;
            continue;
        }

        int l = 0, r = N;
        while (l < r) {
            int mid = (l + r) / 2;
            if (mid <= i) {
                // We can consider up to M-1 candidates ahead of us
                // So we must be better than at least one in the top M
                // So find how many candidates can get ahead of me with X votes
                ll min_needed = 0;
                int cnt = 0;
                for (int j = 0; j < N && cnt < need_more_than_me; ++j) {
                    if (j == i) continue;
                    ll target = A[i].votes + 1;
                    if (A[j].votes >= target) {
                        cnt++;
                    } else {
                        min_needed += target - A[j].votes;
                        cnt++;
                    }
                }
                if (cnt < need_more_than_me || min_needed > remaining_votes) {
                    // Need more votes
                    l = mid + 1;
                } else {
                    r = mid;
                }
            } else {
                r = mid;
            }
        }

        if (l == 0) {
            result[A[i].idx] = 0;
        } else {
            result[A[i].idx] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}