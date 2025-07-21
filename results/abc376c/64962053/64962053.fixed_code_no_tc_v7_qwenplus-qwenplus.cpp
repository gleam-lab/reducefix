#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    vector<long long> B(N - 1);

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // We need to assign the largest toy to a box.
    // For all but one toy, we can match with B's boxes.
    // Try to leave out one toy (the one that will go into the purchased box),
    // and see if all others can be placed in the boxes.

    // To find minimum x, we want to minimize max(toy left out, A[i] <= B[i] for rest)

    // First, check if all A[i] <= B[i] (for N-1 pairs), then no need to buy large box
    // But since B has only N-1 boxes and A has N toys, we must leave one A out

    // Try leaving out each toy and see what is the minimum required size of new box

    long long min_x = LLONG_MAX;
    bool possible = false;

    // Use two pointers approach:
    // Try to assign A[0], A[1], ..., A[i-1], A[i+1], ..., A[N-1] to B[0], ..., B[N-2]
    // and use new box for A[i]

    vector<long long> prefix_max_B(N - 1);
    vector<long long> suffix_max_B(N - 1);

    // prefix_max_B[i] = max(B[0], ..., B[i])
    prefix_max_B[0] = B[0];
    for (int i = 1; i < N - 1; ++i)
        prefix_max_B[i] = max(prefix_max_B[i - 1], B[i]);

    // suffix_max_B[i] = max(B[i], ..., B[N-2])
    suffix_max_B[N - 2] = B[N - 2];
    for (int i = N - 3; i >= 0; --i)
        suffix_max_B[i] = max(suffix_max_B[i + 1], B[i]);

    for (int i = 0; i < N; ++i) {
        // Try putting A[i] in the new box
        bool valid = true;
        int b_idx = 0;

        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            if (A[j] > B[b_idx++]) {
                valid = false;
                break;
            }
        }

        if (valid) {
            min_x = min(min_x, A[i]);
            possible = true;
        }
    }

    if (possible)
        cout << min_x << endl;
    else
        cout << -1 << endl;

    return 0;
}