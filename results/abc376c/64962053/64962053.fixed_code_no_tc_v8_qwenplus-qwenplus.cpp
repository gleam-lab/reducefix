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

    // We need to assign N toys to N boxes: N-1 existing + 1 new.
    // Each toy must go to a box of size >= its size.
    // Each box can hold at most one toy.

    // The idea is to match the smallest possible toy to the smallest possible box.
    // If we sort both arrays, and try to assign A[i] to B[i], then if any A[i] > B[i], it's not possible.

    // However, since we can add one custom box, we can fix one mismatch.

    // Find all i such that A[i] > B[i]
    vector<int> bad_indices;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            bad_indices.push_back(i);
        }
    }

    // If more than one mismatch, cannot fix with one extra box
    if (bad_indices.size() > 1) {
        cout << -1 << endl;
        return 0;
    }

    // If no mismatches, we still need to buy a box for the largest toy
    if (bad_indices.empty()) {
        cout << A.back() << endl;
        return 0;
    }

    // One mismatch exists, let's handle it
    int idx = bad_indices[0];

    // The toy A[idx] couldn't fit in B[idx], so we use our custom box for it
    long long required_x = A[idx];

    // Now check if the rest of the toys can be matched with the remaining boxes
    // We remove B[idx] from B, and check if A matches B excluding that value

    // Construct a list of available boxes without B[idx]
    vector<long long> filtered_B;
    for (int i = 0; i < N - 1; ++i) {
        if (i != idx) {
            filtered_B.push_back(B[i]);
        }
    }

    // Also need to exclude A[idx] because it will go into the custom box
    vector<long long> filtered_A;
    for (int i = 0; i < N; ++i) {
        if (i != idx) {
            filtered_A.push_back(A[i]);
        }
    }

    bool ok = true;
    for (int i = 0; i < filtered_A.size(); ++i) {
        if (filtered_A[i] > filtered_B[i]) {
            ok = false;
            break;
        }
    }

    if (ok)
        cout << required_x << endl;
    else
        cout << -1 << endl;

    return 0;
}