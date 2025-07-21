#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // We need to assign each toy to a box such that:
    // - Each box contains exactly one toy.
    // - Box size >= Toy size.

    // Since we have N toys and N-1 existing boxes, we need to add one more box.
    // The goal is to find the minimal x (size of new box) such that we can assign all toys.

    // Greedy approach: Try to match largest toys with largest available boxes.

    int j = N - 2; // pointer for B (existing boxes)
    multiset<long long> unused_boxes;
    for (int i = N - 1; i >= 0; --i) {
        // While we have no box left or current toy doesn't fit in available box
        while (j >= 0 && (B[j] < A[i] || unused_boxes.count(B[j]))) {
            // Add this box to unused set
            unused_boxes.insert(B[j]);
            --j;
        }

        if (j >= 0) {
            // Found a suitable box
            --j;
        } else if (!unused_boxes.empty()) {
            // Use an unused box
            auto it = unused_boxes.upper_bound(A[i]);
            if (it != unused_boxes.end()) {
                unused_boxes.erase(it);
            } else {
                // No suitable box found
                cout << -1 << endl;
                return 0;
            }
        } else {
            // No suitable box found
            cout << -1 << endl;
            return 0;
        }
    }

    // If we are here, it's possible to assign all toys
    // The minimum required size of new box is the maximum toy size not matched yet
    // But since we added one box, one toy will go into it
    // So the answer is the smallest unmatched toy size

    // Since we sorted A, and we tried to match from largest to smallest,
    // the unmatched toy is the smallest one that couldn't be matched
    // However, we didn't track unmatched toys directly, so let's think differently

    // Actually, since we processed all toys, the required new box size is just the smallest value that could fit any leftover toy
    // But we only added one extra box, so exactly one toy went into it
    // We can compute it as the minimal size that hasn't been matched by existing boxes

    // Alternative: Since we were able to match all toys, the minimal x needed is the smallest toy that was forced to use the new box
    // Let's simulate again but record which toy uses the new box

    // Reset
    j = N - 2;
    vector<bool> used_A(N, false);
    multiset<long long> ms_B;
    for (long long b : B) ms_B.insert(b);

    // Match toys from largest to smallest
    for (int i = N - 1; i >= 0; --i) {
        if (ms_B.count(A[i])) {
            ms_B.erase(ms_B.find(A[i]));
            used_A[i] = true;
        } else {
            auto it = ms_B.lower_bound(A[i]);
            if (it != ms_B.end()) {
                ms_B.erase(it);
                used_A[i] = true;
            }
        }
    }

    long long min_unmatched = numeric_limits<long long>::max();
    for (int i = 0; i < N; ++i) {
        if (!used_A[i]) {
            min_unmatched = min(min_unmatched, A[i]);
        }
    }

    cout << min_unmatched << endl;

    return 0;
}