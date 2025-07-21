#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int required_x = -1;
    int i = 0, j = 0;
    vector<bool> used(N - 1, false);
    
    // First, try to match all toys to existing boxes without the new box
    // If all can be matched, no need for x, but the problem requires x to be positive and N >=2
    // So, but in this problem, we must have exactly N boxes (N-1 existing + 1 new)
    // So the new box must be used to place one toy, and the rest should be placed in the existing boxes
    
    // Alternative approach: find the minimal x such that when we place one toy in the new box (x >= toy size),
    // the remaining N-1 toys can be placed in the existing N-1 boxes
    
    // The minimal x is the smallest possible value that is >= the largest toy that cannot be placed in any existing box
    
    // To find this, we need to find the toy that, when removed, allows the remaining N-1 toys to be matched to the N-1 boxes
    // The minimal x is then the size of that toy
    
    // So, for each toy, check if the other N-1 toys can be matched to the N-1 boxes
    // The smallest such toy's size is the answer
    
    // But checking for each toy is O(N^2), which is too slow for N=2e5
    
    // Optimized approach: after sorting, for the toy at position k (0-based), the boxes must cover:
    // For all i < k: A[i] <= B[i]
    // For all i >= k: A[i+1] <= B[i]
    // The minimal x is A[k]
    // So, find the smallest k where this holds
    
    int k = -1;
    for (int candidate_k = 0; candidate_k <= N; ++candidate_k) {
        bool valid = true;
        for (int i = 0; i < candidate_k; ++i) {
            if (i >= N - 1 || A[i] > B[i]) {
                valid = false;
                break;
            }
        }
        if (!valid) continue;
        for (int i = candidate_k; i < N - 1; ++i) {
            if (A[i + 1] > B[i]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            k = candidate_k;
            break;
        }
    }
    
    if (k != -1) {
        required_x = A[k];
    }
    
    cout << required_x << endl;
    
    return 0;
}