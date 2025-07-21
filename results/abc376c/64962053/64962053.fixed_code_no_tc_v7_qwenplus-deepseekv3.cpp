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
    
    // Check if we can place all toys without the new box (which is impossible since N toys and N-1 boxes)
    // So the new box must be used exactly once.
    // We need to find the smallest x such that:
    // There exists a toy that can be placed in x, and the rest can be placed in the existing boxes.
    
    // The approach is to find the smallest x >= some A[k], where the other A[i] can be matched to B[j] (with one B[j] unused)
    
    // The minimal x is the smallest A[i] that is larger than all possible B[j] or fits into a gap.
    // Specifically, after sorting, the problem reduces to finding the first A[i] > B[i] (0-based or 1-based)
    // Then x must be >= A[i], and the other A's must fit into B's with one B skipped.
    
    // So the minimal x is the maximum between:
    // - The A[k] that is placed in the new box (x >= A[k])
    // - The requirement that other A's fit into the remaining boxes (possibly with one box unused)
    
    // The correct minimal x is the maximum between:
    // - The A[i] that cannot be placed in any B[j], meaning x must be at least A[i]
    // - The B[j] that are not used must still be able to fit the remaining toys
    
    // After sorting A and B, we can compare A[i] with B[i]:
    // The first position where A[i] > B[i] indicates that A[i] must be placed in the new box.
    // Then, the new box size x must be >= A[i], and the other toys must fit into the boxes B[0..i-1] and B[i+1..n-2].
    // However, since B is sorted, the other toys must fit into B[0..n-2] except one, which is handled by x.
    
    // So the minimal x is the A[i] where A[i] > B[i], and for all j != i, A[j] <= B[j] (with B sorted such that B[j] is >= A[j] except for one j)
    
    int x = -1;
    for (int i = 0; i < n; ++i) {
        if (i < n - 1) {
            if (A[i] > B[i]) {
                // Toy i must go to the new box.
                x = A[i];
                break;
            }
        } else {
            // This is the Nth toy (since A is 0-based to n-1)
            // No B left, must go to new box.
            x = A[i];
            break;
        }
    }
    
    // Now verify that the other toys can fit into the existing boxes (excluding one box)
    // The existing boxes are B[0] to B[n-2], total n-1 boxes.
    // We place N-1 toys into these boxes, skipping the box that would have been paired with the toy placed in x.
    
    bool feasible = true;
    int skipped = -1;
    for (int i = 0, j = 0; i < n; ++i) {
        if (A[i] == x && skipped == -1) {
            skipped = i;
            continue;
        }
        if (j >= n - 1) {
            feasible = false;
            break;
        }
        if (A[i] > B[j]) {
            feasible = false;
            break;
        }
        ++j;
    }
    
    if (feasible) {
        cout << x << endl;
    } else {
        // Maybe x is not the first A[i] > B[i]. Try alternative approaches.
        // Alternative: the new box must be >= some A[k], and the other toys must fit into the B's.
        // Another approach: find the minimal x such that x is >= A[k] for some k, and the other N-1 toys can be placed in the existing boxes.
        
        // So the minimal x is the minimal A[k] where the other N-1 toys can be placed in the existing boxes.
        // So we need to find the smallest A[k] such that when we remove A[k], the remaining A's can be matched to B's with A[i] <= B[i].
        
        // To do this, for each possible k (0 to n-1), check if the other A's can be matched to B's.
        // However, this is O(n^2), which is not feasible for n up to 2e5.
        
        // So we need a smarter approach.
        
        // The observation is: after sorting A and B, the optimal x is either:
        // 1. The largest A[i] that is not covered by B[i] (since the new box must cover it)
        // 2. Or the largest A[i] in the case where all A[i] <= B[i] except the last A which has no B.
        
        // So our initial approach may have missed some cases where removing a different A[i] allows the others to fit.
        
        // So the fixed approach is to find the minimal x which is the maximum between:
        // - The largest A[i] that cannot be placed in any B (i.e., for i >= m where m is the number of B's)
        // - Or the largest A[i] that is greater than B[i]
        
        // So the correct minimal x is the maximum of all A[i] that cannot be placed in B[i] (or B[i-1] if we skip one B)
        // But this requires careful analysis.
        
        // Alternatively, the minimal x is the maximum of the A's that are not covered by any B in a matching.
        // The matching is such that N-1 toys are matched to N-1 boxes with A[i] <= B[j], and one toy is placed in x.
        
        // So, the minimal x is the smallest possible maximum unmatched A.
        
        // To find this, we can use binary search on possible x values.
        // But for simplicity, the problem can be solved by finding the minimal x as the maximum of:
        // - A[i] where i is the first position where A[i] > B[i] (if B is now sorted in non-decreasing order and A is sorted similarly)
        // - Or the last element of A if all A[i] <= B[i] for i < n-1
        
        // So the correct x is:
        x = -1;
        for (int i = 0; i < n; ++i) {
            if (i < n - 1) {
                if (A[i] > B[i]) {
                    x = A[i];
                    break;
                }
            } else {
                x = A[i];
                break;
            }
        }
        
        // Now check if the other A's can be placed in the B's, skipping one B.
        // The other A's must be <= B's, skipping one B.
        // So for the other A's, they must be <= B's in a way that can be matched with one B unused.
        
        // To do this, we can create a list where for each i, A[i] <= B[i] except for one.
        // So the minimal x is the A[i] that is the "extra" one.
        
        // So the correct x is the maximum A[i] that is not covered by B[i].
        // But sometimes, multiple A[i] are not covered. Then, it's impossible.
        
        // So the correct approach is to find the minimal x such that there is exactly one A[i] > B[i] (or the last A[i] if B is shorter)
        // and then x must be >= that A[i], and the other A's must be <= their corresponding B's.
        
        // So the initial code was on the right track but missed some cases.
        
        bool possible = false;
        int count = 0;
        int pos = -1;
        for (int i = 0; i < n; ++i) {
            if (i < n - 1) {
                if (A[i] > B[i]) {
                    count++;
                    pos = i;
                }
            } else {
                count++;
                pos = i;
            }
        }
        
        if (count == 1) {
            cout << A[pos] << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}