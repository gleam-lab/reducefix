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

    multiset<long long> box_sizes;
    int j = 0;
    long long min_needed = -1;

    for (int i = 0; i < N; ++i) {
        while (j < N - 1 && B[j] < A[i]) {
            box_sizes.insert(B[j]);
            j++;
        }
        if (j < N - 1) {
            box_sizes.insert(B[j]);
            j++;
        }
        if (!box_sizes.empty()) {
            auto it = box_sizes.lower_bound(A[i]);
            if (it != box_sizes.end()) {
                box_sizes.erase(it);
            } else {
                // No suitable box found, this toy must go into the custom box
                if (min_needed == -1 || A[i] > min_needed) {
                    min_needed = A[i];
                }
            }
        } else {
            // No boxes left, must use custom box
            if (min_needed == -1 || A[i] > min_needed) {
                min_needed = A[i];
            }
        }
    }

    if (min_needed == -1) {
        // All toys fit in existing boxes
        cout << 1 << endl;
    } else {
        cout << min_needed << endl;
    }

    return 0;
}