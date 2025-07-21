#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    vector<int> unmatched;
    while (i < n && j < n - 1) {
        if (a[i] <= b[j]) {
            ++i;
            ++j;
        } else {
            unmatched.push_back(a[i]);
            ++i;
        }
    }
    while (i < n) {
        unmatched.push_back(a[i]);
        ++i;
    }

    if (unmatched.empty()) {
        // All toys fit in existing boxes, but need one more box for the last toy
        // The new box can be of size 1, but per problem statement, we need to place each toy in separate boxes
        // Since all existing boxes are used, the new box must accommodate one toy, which can be any toy,
        // but the minimal x is the minimal toy size, but since all toys are placed, this scenario is not possible.
        // Wait, problem says that after purchasing x, we place each toy into one of N boxes (existing N-1 plus new one).
        // So if all toys fit into existing boxes, then the new box can be of size 1, but it's unused. But the toys must be placed in separate boxes.
        // So if all N-1 existing boxes are used, then the new box must be used for one toy. So x must be >= some toy.
        // The minimal x would be the minimal toy not placed in existing boxes, but if all are placed, then the new box can be size 1, but must still accommodate one toy, which is not needed.
        // This suggests that the answer is 1, but it's unclear. However, the problem statement says he wants to execute step 2 by purchasing a sufficiently large box, but to minimize x.
        // If all toys fit in existing boxes, then the minimal x is the smallest possible, which could be 1, but the problem expects us to return -1 if no x is needed.
        // But according to the problem, step 2 requires placing each toy into one of the N boxes (N-1 existing plus new one). So if N-1 boxes can hold N toys (one per box), then the new box isn't needed. But the toys are N, boxes are N-1, and we need to place each toy in one box, so one box must hold two toys, which is not allowed.
        // So unless N-1 boxes can hold N toys with one toy per box, which is impossible, the new box is always needed.
        // So the initial code might have misunderstood this.
        // The problem requires that after purchasing x, there are N boxes total (N-1 existing plus new one), and each toy is placed in a separate box (so one toy per box). Since there are N toys and N boxes, this is always possible if the boxes can accommodate the toys.
        // So if all toys can fit into the existing N-1 boxes with one toy per box, then the new box isn't needed, but the problem says he wants to execute step 2 by purchasing x. So perhaps the answer is -1 if all toys can be placed in existing boxes.
        // So the code should output -1 if all toys can be placed in existing boxes, else output the minimal x required to place the remaining toys.

        // So let's re-examine the logic.
        // After sorting, we pair toys to boxes. If all can be paired, then output -1.
        // Otherwise, the new box must be at least the size of the largest unpaired toy.

        // So in the unmatched vector, if it's empty, all toys are paired, output -1.
        // Else, the new box must be at least the size of the largest in unmatched.
        cout << -1 << endl;
    } else {
        cout << unmatched.back() << endl;
    }

    return 0;
}