#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
    long long a;
    int idx;
    long long votes_needed;
} node;

int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<node> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].a;
        A[i].idx = i;
    }

    sort(A.begin(), A.end(), [](const node &a, const node &b) {
        return a.a < b.a;
    });

    vector<long long> votes_counted(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        votes_counted[A[i].idx + 1] = A[i].a;
    }

    for (int i = N; i < 0; --i) {
        votes_counted[i] = votes_counted[i + 1] - A[i].a;
    }

    long long remaining_votes = K - votes_counted[0];
    for (int i = 0; i < N; ++i) {
        long long current_votes = votes_counted[i + 1];
        long long votes_beaten = (i - N + M < 0) ? 0 : votes_counted[i - N + M];
        long long required_votes = M - 1 - (current_votes - votes_beaten);

        if (required_votes > remaining_votes) {
            A[i].votes_needed = -1;
        } else {
            A[i].votes_needed = remaining_votes - required_votes;
        }
    }

    sort(A.begin(), A.end(), [](const node &a, const node &b) {
        return a.idx < b.idx;
    });

    for (int i = 0; i < N; ++i) {
        cout << A[i].votes_needed << " ";
    }
    cout << "\n";

    return 0;
}