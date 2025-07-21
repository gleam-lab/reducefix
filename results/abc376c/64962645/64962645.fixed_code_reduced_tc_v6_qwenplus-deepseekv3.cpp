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
    
    int x = -1;
    // We need to find the smallest x such that:
    // There exists an A[k] that can be placed in x (x >= A[k])
    // And the other N-1 A's can be matched to B's (A <= B) in a way that each B is used at most once.
    // The minimal x is the minimal A[k] such that when we remove A[k], the remaining A's can be matched to B's.
    // To check this, the sorted A (without one element) should be element-wise <= sorted B.
    
    // We can try removing the largest element not covered by B.
    // So, we can check two scenarios:
    // 1. The largest A is in x: then A[1..n-1] must be <= B[0..n-2].
    bool possible = true;
    for (int i = 0; i < n - 1; ++i) {
        if (A[i + 1] > B[i]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        x = A[0];
    }
    
    // 2. Some other A[k] is in x: we need to find the smallest A[k] such that when removed,
    // the remaining A's can be matched to B's.
    // So for each A[k], we need: A[0..k-1] and A[k+1..n-1] must be <= B[0..n-2] when sorted.
    // Essentially, the merged array of A[0..k-1] and A[k+1..n-1] must be <= B when both are sorted.
    // To find such k, we can sort A, and for each k, check if the merged array is <= B.
    // The minimal x is the minimal A[k] for which this holds.
    
    vector<int> A_sorted = A;
    sort(A_sorted.begin(), A_sorted.end());
    sort(B.begin(), B.end());
    
    vector<int> merged_A;
    for (int k = 0; k < n; ++k) {
        merged_A.clear();
        for (int i = 0; i < n; ++i) {
            if (i != k) {
                merged_A.push_back(A_sorted[i]);
            }
        }
        bool ok = true;
        for (int i = 0; i < n - 1; ++i) {
            if (merged_A[i] > B[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            if (x == -1 || A_sorted[k] < x) {
                x = A_sorted[k];
            }
        }
    }
    
    cout << x << endl;
    
    return 0;
}