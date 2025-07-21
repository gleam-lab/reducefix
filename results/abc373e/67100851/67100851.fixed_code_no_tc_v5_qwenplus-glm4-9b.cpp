#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    long long a;
    int idx;
} node;

int N, M, K;
long long psum[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    psum[0] = 0;
    node A[200000];

    for (int i = 0; i < N; i++) {
        cin >> A[i].a;
        A[i].idx = i;
        psum[i + 1] = psum[i] + A[i].a;
    }

    sort(A, A + N, [](node a, node b) { return a.a < b.a; });

    long long remaining_votes = K - psum[N];
    for (int i = 0; i < N; i++) {
        // We need to find the minimum X such that candidate A[i].a + X is enough to
        // beat the next M-1 candidates.
        long long votes_needed = (i + 1 >= M) ? psum[N] - psum[i + 1 - M] : 0;
        long long current_votes = A[i].a + remaining_votes;

        if (current_votes >= votes_needed) {
            cout << 0 << " ";
        } else {
            // Calculate the minimum additional votes needed
            long long additional_votes = votes_needed - A[i].a;
            cout << additional_votes << " ";
        }
    }

    cout << "\n";
    return 0;
}