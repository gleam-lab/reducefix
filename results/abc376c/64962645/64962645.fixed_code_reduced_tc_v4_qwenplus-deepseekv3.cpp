#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    vector<int> possible_x;
    
    // Check if the largest toy is <= largest box, then we might not need a new box
    // But since we have N toys and N-1 boxes, we must have at least one toy that needs the new box
    // So the new box must accommodate at least one toy.
    // The possible candidates for x are the toys that are larger than all boxes.
    // Or, if all toys are <= boxes, then the new box can be the smallest toy (but we have N toys and N boxes, so one box is unused, but the new box must be used)
    
    // So the approach is to find the smallest x such that:
    // x >= one toy, and the rest can be matched to boxes (possibly excluding one box)
    
    // We need to find the minimal x that is >= one toy, and when we remove x, the remaining toys can be matched to boxes (possibly some box is unused)
    
    // The minimal x is the smallest among the toys that are not covered by boxes in a matching
    
    // The approach is:
    // Sort both A and B
    // For each position i, check if A[i] > B[i] (assuming B is padded with x)
    // The minimal x is the smallest A[i] that is not covered by B[i], or the largest A[i] that is left after matching
    
    // Alternative approach:
    // The new box must cover at least one toy. The minimal x is the smallest such x that allows the remaining N-1 toys to be placed in the N-1 boxes.
    // The new box should cover the largest toy that cannot be placed in any box, and the rest should be placeable in the existing boxes.
    
    // So first, try to match the largest N-1 toys to the N-1 boxes. If all can be matched, the new box can be the smallest toy (A[0]).
    // Otherwise, the new box must be the largest toy that cannot be placed, and the remaining N-1 toys must be placed in the N-1 boxes.
    
    // So, sort A and B in ascending order.
    // Check for each i from 0 to N-2 if A[i+1] <= B[i]. If yes, then the new box can be A[0].
    // If not, then the box must be at least A[i+1], and all A[j] for j <= i must be <= B[j].
    
    // So, the minimal x is the smallest x such that:
    // x >= one of the A[i], and the remaining N-1 toys can be placed in the N-1 boxes.
    // Which is equivalent to: x must be >= one A[i], and when removing that A[i], the remaining A's can be matched to B's with A_remaining[j] <= B[j].
    
    bool possible = false;
    int x_candidate = -1;
    
    // Check if the first N-1 toys can be placed in the B boxes (sorted ascending)
    // The new box would then have to be >= the last toy (A[n-1])
    bool all_match = true;
    for (int i = 0; i < n - 1; ++i) {
        if (A[i] > B[i]) {
            all_match = false;
            break;
        }
    }
    if (all_match) {
        x_candidate = A[n - 1];
        possible = true;
    } else {
        // Otherwise, the new box must be >= some A[k], and when removed, the remaining A's can be placed in the B's
        // The possible k is where A[k] is the one that is not <= any B[i], and the others can be matched.
        // So the candidate is the smallest A[k] such that:
        // when A[k] is removed, the remaining A's can be matched to B's with A[i] <= B[i] for i <k, and A[i+1] <= B[i] for i >=k.
        
        // To find this, we can try to find the single position k where A[k] is the only one not fitting into B's.
        // If there are multiple such positions, it's impossible.
        
        int cnt = 0;
        int k = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (A[i] > B[i]) {
                ++cnt;
                k = i;
            }
        }
        if (cnt == 1) {
            // Check if A[k] is the only one exceeding B[k]
            // Then, the new box must be >= A[k], and when we remove A[k], the remaining should fit:
            // For i <k: A[i] <= B[i]
            // For i >k: A[i] <= B[i-1]
            bool ok = true;
            for (int i = 0; i < k; ++i) {
                if (A[i] > B[i]) {
                    ok = false;
                    break;
                }
            }
            for (int i = k + 1; i < n; ++i) {
                if (i - 1 >= n - 1) {
                    ok = false;
                    break;
                }
                if (A[i] > B[i - 1]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                x_candidate = A[k];
                possible = true;
            }
        } else if (cnt == 0) {
            // This shouldn't happen since we have N toys and N-1 boxes, but all N-1 toys fit into boxes. So the new box must be the last toy.
            x_candidate = A[n - 1];
            possible = true;
        }
    }
    
    if (possible) {
        // Also, we need to check that the chosen x is >= the toy it is supposed to hold
        // But in the cases above, x_candidate is set to A[k], and the toy placed in the new box is x_candidate itself, so it is valid.
        cout << x_candidate << endl;
    } else {
        // Check another scenario: the new box takes the largest A, and the remaining N-1 toys are matched to B's
        // The new box must be >= A[n-1], and the remaining A[0..n-2] must fit into B[0..n-2]
        bool other_possible = true;
        for (int i = 0; i < n - 1; ++i) {
            if (A[i] > B[i]) {
                other_possible = false;
                break;
            }
        }
        if (other_possible) {
            cout << A[n - 1] << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}