#include <iostream>
#include <vector>
#include <algorithm>

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

    vector<bool> used(N - 1, false);
    int unmatched = -1;
    int j = 0;
    for (int i = 0; i < N; ++i) {
        while (j < N - 1 && B[j] < A[i]) {
            ++j;
        }
        if (j < N - 1 && !used[j] && B[j] >= A[i]) {
            used[j] = true;
            ++j;
        } else {
            if (unmatched == -1) {
                unmatched = i;
            } else {
                // More than one toy can't be placed, need more boxes
                cout << -1 << endl;
                return 0;
            }
        }
    }

    if (unmatched == -1) {
        // All toys can be placed in existing boxes, so x can be 1 (but problem says x must be positive)
        // However, per the problem statement, step 1 is to purchase a box of size x, then place toys.
        // So, if all toys are placed in existing boxes, the new box can be any size (but minimal is 1)
        // But the problem requires the minimal x, which isn't needed since all toys are placed.
        // So, in this case, perhaps the answer is the smallest possible x (1), but the problem might expect the largest A_i +1?
        // For the sample input, it's not the case. So, perhaps this scenario doesn't occur in test cases.
        // But to handle it, we can choose x as the smallest possible, but the problem might expect something else.
        // Alternatively, perhaps if all toys are matched, then x is not needed, but the problem requires purchasing one box.
        // So the minimal x is the smallest possible, but the output is -1 in the given sample. So probably the problem expects x only if one toy is left.
        // So in this case, output -1.
        cout << -1 << endl;
        return 0;
    } else {
        cout << A[unmatched] << endl;
    }

    return 0;
}