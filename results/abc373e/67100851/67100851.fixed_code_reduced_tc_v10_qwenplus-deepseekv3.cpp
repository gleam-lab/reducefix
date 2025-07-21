#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef struct {
    ll a;
    int idx;
} node;

bool compare_node_a(const node &x, const node &y) {
    return x.a < y.a;
}

bool compare_node_idx(const node &x, const node &y) {
    return x.idx < y.idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<node> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].a;
        A[i].idx = i;
    }

    sort(A.begin(), A.end(), compare_node_a);
    vector<ll> psum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        psum[i] = psum[i - 1] + A[i - 1].a;
    }

    ll remaining = K - psum[N];
    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll current = A[i].a;
        int pos = upper_bound(A.begin(), A.end(), node{current, -1}, compare_node_a) - A.begin();
        if (pos <= N - M) {
            // Need to ensure that candidate i is among the top M candidates
            // The worst case is when all other candidates receive as many votes as possible
            ll required = A[N - M].a + 1 - current;
            if (required < 0) required = 0;
            ll total_needed = required;
            if (total_needed <= remaining) {
                res[A[i].idx] = required;
            }
        } else {
            // Already among the top M candidates
            res[A[i].idx] = 0;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (res[i] == -1) {
            // Need to find the minimal X such that after adding X, candidate i is among the top M candidates
            ll current = A[i].a;
            ll low = 0, high = remaining;
            ll answer = -1;
            while (low <= high) {
                ll mid = (low + high) / 2;
                ll new_votes = current + mid;
                int count = 0;
                for (int j = 0; j < N; ++j) {
                    if (A[j].a > new_votes || (A[j].a == new_votes && j > i)) {
                        count++;
                    }
                }
                if (count < M) {
                    answer = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            res[A[i].idx] = answer;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}