#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if the first N-1 toys can be placed in the first N-1 boxes
    bool canStoreAll = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            canStoreAll = false;
            break;
        }
    }

    if (!canStoreAll) {
        cout << -1 << endl;
        return 0;
    }

    // Now, find the minimal x such that the largest toy not fitting in any box is <= x
    // The largest toy not fitting is A[N-1], but we need to find if any existing box can cover it
    long long required_x = A[N - 1];
    bool found = false;

    // Check if any existing box can cover the largest toy
    for (int i = 0; i < N - 1; ++i) {
        if (B[i] >= required_x) {
            found = true;
            break;
        }
    }

    if (found) {
        // The existing boxes can cover all toys, no need for additional box
        // But the problem requires purchasing one additional box, but the minimal x is 0?
        // According to problem statement, we must purchase one box, so the minimal x is the minimal possible, but existing boxes may cover all.
        // So the minimal x is the smallest possible, which is 1, but to store the toy, it must be >= A_i, but if all toys are already stored, x can be any value >=1, but the minimal is 1.
        // However, the problem might imply that the additional box must be used. So the minimal x is the smallest value that can cover any toy not covered by existing boxes.
        // So in this case, since all toys are covered, perhaps x can be 1, but the problem expects us to use the box, so maybe the toy is placed in the new box.
        // But the problem states we must purchase one box, so the minimal x is the size that can accommodate at least one toy not placed in existing boxes.
        // But in this case, all toys can be placed in existing boxes, so purchasing any box is redundant, but the problem requires purchasing one.
        // This suggests the expected solution is to find that if all toys can be placed in existing boxes, then the minimal x is the smallest toy size (but the problem says x must be positive).
        // So this is confusing. Alternatively, the problem requires that the new box must be used to place at least one toy, so if all toys can fit in existing boxes, then we need to find the smallest x such that moving one toy to the new box is possible.

        // Alternative approach: the minimal x is the smallest value that can cover at least one toy not covered by existing boxes, but existing boxes cover all, so perhaps it's the smallest A_i.
        // But the problem's expected output suggests that x should be A[N-1] if it's not covered by existing boxes, else -1. But initially, we saw some test case where output is 641.
        // So perhaps the issue is if all but the largest toy are covered, then the minimal x is A[N-1], else if the largest toy is also covered, then x can be any value >=1, smallest is 1, but the problem's sample expects 641, suggesting that in some cases x is the largest A_i not covered.
        // So the correct approach is: the minimal x is the largest A_i that is not covered by any B_i >= A_i, which in this case would be A[N-1] if it's larger than all B_i, else x can be 1 (but the problem expects us to use the box to place at least one toy, so x must be at least the smallest toy size not placed, which could be any toy if all are placed in existing boxes).

        // Given the confusion, let's proceed with the assumption that the new box must be used to place at least one toy, so the minimal x is the smallest toy size not placed in existing boxes, which is the min A_i, but in the initial case, all are placed, so perhaps we can set x to 1.
        // But the problem's sample expects 641, which suggests that when the largest toy is not covered by any existing box, x should be that toy's size.
        // So for the case where all toys up to N-1 are covered, the minimal x is the max between the largest toy not covered (A[N-1]) and any other toy that might not be covered after N-1 placements.

        // So the correct approach is: if all N toys can be placed in the N-1 boxes, then output -1 (but the problem requires purchasing one box, so this can't be). Otherwise, x is the largest A_i not covered by existing boxes.

        // Wait, in the problem statement, step 2 says place each of the N toys into one of the N boxes (N-1 existing + 1 new). So the existing boxes might have more capacity than needed, but we must use one new box.

        // So the correct approach is: find the minimal x such that when we add a box of size x, all toys can be placed in the boxes (existing + new), with each toy in a box of size >= its size, and no two toys in the same box.

        // So the algorithm should:
        // 1. Sort A and B in ascending order.
        // 2. Check if the largest toy is <= the largest box. If yes, then the new box can be of size 1 (assuming we can rearrange existing placements), but the problem requires it to be used. So perhaps the minimal x is the smallest A_i not covered by existing boxes, but if all are covered, then x can be 1.
        // 3. If the largest toy is larger than all boxes, then x must be at least that toy's size.

        // So the code should:
        // - If the largest toy in A is <= the largest box in B, then x can be 1 (since we can place one toy in the new box of size 1, and the others in existing boxes. But 1 may not cover any toy unless some toy is size 1. So the minimal x is the minimal A_i, if covered by existing boxes.

        // This is confusing. Re-reading the problem statement: "he wants to purchase the smallest possible box." So x is chosen such that all toys can be placed with the new box, and x is minimal.

        // So the minimal x is the smallest value such that:
        // - All toys can be placed in N boxes (N-1 existing + 1 new), with each toy in a box >= its size, and no two toys in the same box.

        // So the approach:
        // 1. Sort A and B.
        // 2. Check if the first N-1 toys can be placed in the first N-1 boxes (A[i] <= B[i] for i=0..N-2), and the Nth toy can be placed in Оставшиеся boxes or новый box.
        // 3. If the first N-1 toys can be placed in the first N-1 boxes, then the new box must be >= A[N-1], so the minimal x is A[N-1].
        // 4. If any of the first N-1 toys cannot be placed, then it's impossible, so output -1.

        // So in the initial code, the error was in not covering the case where the first N-1 toys fit in the first N-1 boxes, and the new box is needed for the Nth toy, which would have size A[N-1], so the minimal x is A[N-1].

        required_x = A[N - 1];
    } else {
        // The largest toy is not covered by any existing box, so x must be at least A[N-1].
        required_x = A[N - 1];
    }

    // However, we need to ensure that the first N-1 toys are placed in existing boxes.
    // So the minimal x is the required_x, provided that the first N-1 toys can be placed in the first N-1 boxes.
    // But earlier, we checked canStoreAll, which is true here.

    cout << required_x << endl;
    return 0;
}