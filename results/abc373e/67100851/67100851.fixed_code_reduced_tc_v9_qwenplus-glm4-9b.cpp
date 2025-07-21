#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    long long a;
    int idx;
} node;

bool canWin(long long k, const vector<node> &A, long long psum, long long K) {
    long long maxVotes = psum + (N - M + 1) * k;
    long long required = maxVotes - psum;
    return required <= K - M + 1;
}

int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<node> A(N);
    long long psum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i].a;
        psum += A[i].a;
    }

    // Sort candidates by votes received in descending order
    sort(A.begin(), A.end(), [](const node &a, const node &b) {
        return a.a > b.a;
    });

    vector<long long> votesNeeded(N);
    for (int i = 0; i < N; i++) {
        // Calculate the minimum votes needed for the current candidate to win
        votesNeeded[i] = (M - 1) * A[i].a;
        if (i > 0) {
            votesNeeded[i] -= A[i - 1].a - M * A[0].a;
        }
        if (canWin(votesNeeded[i], A, psum, K)) {
            votesNeeded[i] = -1; // This candidate can already win
        } else {
            votesNeeded[i] -= K - psum;
            if (votesNeeded[i] < 0) {
                votesNeeded[i] = -1; // This candidate cannot win
            }
        }
    }

    // Sort the votes needed by index to output in the correct order
    sort(votesNeeded.begin(), votesNeeded.end(), [&](int a, int b) {
        return A[a].idx < A[b].idx;
    });

    // Output the result
    for (const auto &v : votesNeeded) {
        cout << v << ' ';
    }
    cout << endl;

    return 0;
}