#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<int> possible_x;
    // Check the case where the new box is not needed (all toys fit in existing boxes)
    bool all_fit = true;
    for (int i = 0; i < n; ++i) {
        if (i < n - 1) {
            if (A[i] > B[i]) {
                all_fit = false;
                break;
            }
        } else {
            // No box left for the last toy
            all_fit = false;
        }
    }
    if (all_fit) {
        cout << 1 << endl;
        return 0;
    }

    // Now, we need to find minimal x such that when we add x to B, we can match all toys to boxes >= their size
    // The minimal x must be >= some A[i] that cannot be placed in existing boxes.
    // We can use binary search to find the minimal x.

    // Gather all candidates for x: the A[i] that are not covered by existing boxes
    // Also, the new box must cover at least one A[i].
    // The minimal x is the maximum of such A[i] that cannot be placed in existing boxes.

    // So, possible x candidates are the A[i] that are larger than all B[j].
    // But we need a smarter way: for each A[i], find if it can be placed in any B[j] >= A[i], then the remaining must be placed in the new box.

    // Alternative idea: after sorting, the largest toy not covered by existing boxes must be placed in the new box.
    // So, x must be >= that toy's size. The minimal x is that toy's size.

    // Let's try to match toys to boxes (n-1 boxes) as many as possible, and the remaining toy must be <= x.
    // So, pair the largest n-1 toys to the largest n-1 boxes, and the smallest toy must be <= x.

    int i = 0, j = 0;
    int cnt = 0;
    int last_unmatched = -1;
    while (i < n && j < n - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
            ++cnt;
        } else {
            last_unmatched = A[i];
            ++i;
        }
    }
    while (i < n) {
        last_unmatched = A[i];
        ++i;
    }

    if (cnt == n - 1) {
        // All except one toy are placed in existing boxes. The remaining toy must be <= x.
        cout << last_unmatched << endl;
    } else if (cnt < n - 1) {
        // More than one toy cannot be placed in existing boxes. You need more boxes, but you can only add one.
        cout << -1 << endl;
    } else {
        // All toys placed in existing boxes. The new box can be 1.
        cout << 1 << endl;
    }

    return 0;
}