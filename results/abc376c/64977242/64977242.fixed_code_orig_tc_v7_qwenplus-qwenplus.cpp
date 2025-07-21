#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> A(N), B(N - 1);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if it's possible to place N-1 smallest toys into the N-1 boxes
    bool possible = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << -1 << '\n';
        return 0;
    }

    // Find the minimum x such that the largest toy fits in either one of the existing boxes or the new box x
    // The largest toy is A[N-1]
    // We need to find the first box in B (sorted) that can fit A[N-1], starting from the largest

    sort(B.begin(), B.end(), greater<long long>());
    long long max_toy = A[N - 1];
    long long required_x = max_toy;

    // Try to find a box in B that can contain max_toy
    for (int i = 0; i < N - 1; ++i) {
        if (B[i] >= max_toy) {
            // This box can be used, so we don't need to buy a new one
            required_x = 0;
            break;
        }
    }

    if (required_x == 0) {
        cout << 0 << '\n';
        return 0;
    }

    // If no box in B can fit the largest toy, we must buy a box that can fit it.
    // But we also want the minimal x.
    // We must check how many toys can be placed in the existing boxes.
    // We try to assign the smallest N-1 toys to the largest N-1 boxes greedily.

    sort(A.begin(), A.end(), greater<long long>());
    sort(B.begin(), B.end(), greater<long long>());

    int matched = 0;
    int a_ptr = 0;
    int b_ptr = 0;

    while (a_ptr < N && b_ptr < N - 1) {
        if (A[a_ptr] <= B[b_ptr]) {
            ++matched;
            ++a_ptr;
            ++b_ptr;
        } else {
            ++a_ptr;
        }
    }

    if (matched == N - 1) {
        // There is one toy left which is the largest (since we sorted descending)
        // So x needs to be at least A[0]
        cout << max_toy << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}