#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N - 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int i = 0, j = 0;
    int required_x = -1;
    vector<int> unmatched;
    
    while (i < N && j < N - 1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            unmatched.push_back(A[i]);
            ++i;
        }
    }
    while (i < N) {
        unmatched.push_back(A[i]);
        ++i;
    }
    
    if (unmatched.size() == 1) {
        required_x = unmatched[0];
    } else if (unmatched.size() > 1) {
        required_x = -1;
    } else {
        // All toys matched, but we still need to buy a box of size x
        // Now, find the smallest x such that one toy can be placed in x
        // and the rest in boxes (which they already fit)
        // The smallest x is the smallest toy, but we need to see if replacing
        // any existing box assignment allows this.
        // Alternatively, x must be >= some toy's size not covered by boxes.
        // Since all are covered, perhaps x can be 1 (but toy sizes >=1)
        // So, the minimal x is the minimal toy size, but check if it's possible.
        // Actually, in this scenario, any x >= any toy size can work, but the minimal is A[0].
        required_x = A[0];
    }
    
    if (required_x != -1) {
        // Verify if required_x allows placement
        // We need to ensure that all toys can be placed in boxes (N boxes total)
        // So, one toy goes to the new box of size x, and the rest in existing boxes.
        // existing boxes must be able to hold N-1 toys (each toy <= box size)
        // So, we need to match N-1 toys to N-1 boxes, sorted.
        // The new box can hold the largest remaining toy.
        // So, the minimal x is the largest A[i] not matched when boxes are sorted.
        // Previous approach might not capture this correctly.
        // Alternative approach: after sorting, for the N toys and N boxes (N-1 existing + 1 new)
        // The minimal x is such that in the worst case, the largest toy is placed in x.
        // So, when we have N-1 boxes, sorted, and N toys, sorted, the minimal x is the largest toy
        // that cannot be placed in the first N-1 boxes.
        
        // So, the previous approach was partially correct, but missed some cases.
        // Let's redo the matching:
        // We need to find the minimal x such that when we add x to B, and sort, the toys can be matched 1-to-1 with boxes.
        // The minimal x is the smallest x >= some toy size, such that the matching is possible.
        // The correct way is to find, after sorting both A and B, the first N-1 toys can be matched with B's boxes (A[i] <= B[i]), and the last toy must be <= x.
        // So, x must be >= A[N-1], and the first N-1 toys must fit in the first N-1 boxes.
        // So, check if A[i] <= B[i] for i < N-1. If not, no solution; else, x is A[N-1].
        bool possible = true;
        for (int k = 0; k < N - 1; ++k) {
            if (A[k] > B[k]) {
                possible = false;
                break;
            }
        }
        if (possible) {
            required_x = A.back();
        } else {
            required_x = -1;
        }
    }
    
    cout << required_x << endl;
    
    return 0;
}