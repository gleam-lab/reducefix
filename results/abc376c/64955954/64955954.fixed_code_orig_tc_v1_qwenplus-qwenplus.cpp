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

    // Try to assign each toy to a box greedily
    int j = 0;
    multiset<long long> boxes;
    for (int i = 0; i < N - 1; ++i) {
        boxes.insert(B[i]);
    }

    long long required_x = -1;

    for (int i = 0; i < N; ++i) {
        if (!boxes.empty() && A[i] <= *boxes.begin()) {
            // Try to use the smallest available box
            auto it = boxes.lower_bound(A[i]);
            if (it != boxes.end() && *it >= A[i]) {
                boxes.erase(it);
            } else {
                // Cannot place this toy in any existing box, must use new box
                if (required_x == -1)
                    required_x = A[i];
                else
                    required_x = max(required_x, A[i]);
            }
        } else if (!boxes.empty()) {
            // Use the smallest possible box larger or equal to A[i]
            auto it = boxes.lower_bound(A[i]);
            if (it != boxes.end() && *it >= A[i]) {
                boxes.erase(it);
            } else {
                // Cannot place this toy in any existing box, must use new box
                if (required_x == -1)
                    required_x = A[i];
                else
                    required_x = max(required_x, A[i]);
            }
        } else {
            // No more boxes left, must use new box
            if (required_x == -1)
                required_x = A[i];
            else
                required_x = max(required_x, A[i]);
        }
    }

    if (required_x == -1) {
        // All toys could be placed in existing boxes, so x can be arbitrarily small
        // But since we need to buy one box anyway, output the smallest toy size
        cout << A[0] << endl;
    } else {
        cout << required_x << endl;
    }

    return 0;
}