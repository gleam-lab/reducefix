#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
    long long a;
    int idx;
} node;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<node> A(N);
    A[0].a = 0; // Adjust the first element to handle 0 votes in the sum
    long long psum = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i].a;
        A[i].idx = i;
        psum += A[i].a;
    }

    // Sort candidates by votes received in descending order
    sort(A.begin() + 1, A.end(), [](node a, node b) {
        return a.a > b.a;
    });

    // Calculate prefix sums
    psum += A[1].a;
    for (int i = 2; i <= N; ++i) {
        psum += A[i].a;
        A[i].a = psum;
    }

    K -= A[N].a; // Reduce the remaining votes by the highest votes already received

    vector<long long> additional_votes(N);
    for (int i = 0; i < N; ++i) {
        long long max_votes_needed = A[i].a + ((N - M - i) * (A[i].a + 1) + i * (A[i + 1].a + 1)) - (K - psum);
        if (max_votes_needed <= 0) {
            additional_votes[i] = -1; // Cannot secure victory
        } else {
            additional_votes[i] = max_votes_needed - A[i].a;
        }
    }

    // Sort by original indices to maintain the order
    sort(additional_votes.begin(), additional_votes.end(), [&](const long long a, const long long b) {
        return A[a].idx < A[b].idx;
    });

    for (int i = 0; i < N; ++i) {
        cout << additional_votes[i] << (i < N - 1 ? " " : "\n");
    }

    return 0;
}