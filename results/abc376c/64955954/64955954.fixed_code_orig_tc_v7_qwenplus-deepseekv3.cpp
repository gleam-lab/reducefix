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
    
    // We need to find the smallest x such that:
    // The N toys can be matched to N boxes (N-1 existing + x)
    // Each toy is <= box size, and each box is used at most once.
    
    // The approach is to check if the largest toy not matched to the largest N-1 boxes can be placed in x.
    
    // Pair the largest N-1 toys with the largest N-1 boxes. The remaining toy (the smallest) can be placed in x.
    // Or, if among the largest N toys, one is not covered by the largest N-1 boxes, it must be placed in x.
    
    int x_candidate1 = -1;
    // Scenario 1: The largest N-1 toys are matched to the largest N-1 boxes.
    // The remaining toy (the smallest) is placed in x.
    bool possible1 = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i + 1] > B[i]) {
            possible1 = false;
            break;
        }
    }
    if (possible1) {
        x_candidate1 = A[0];
    }
    
    int x_candidate2 = -1;
    // Scenario 2: The largest N-1 toys are matched to the largest N-1 boxes.
    // The remaining toy (the largest) is placed in x.
    possible1 = true;
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] > B[i]) {
            possible1 = false;
            break;
        }
    }
    if (possible1) {
        x_candidate2 = A.back();
    }
    
    // Another scenario: the missing toy is in the middle.
    // For example, toy at position N-1 is larger than box N-1, so it must go to x.
    // Then, the remaining toys must fit into the boxes.
    int x_candidate3 = -1;
    bool found = false;
    for (int k = 0; k < N; ++k) {
        // Check if toys without A[k] can be matched to B.
        vector<int> remaining_toys;
        for (int i = 0; i < N; ++i) {
            if (i != k) {
                remaining_toys.push_back(A[i]);
            }
        }
        sort(remaining_toys.begin(), remaining_toys.end());
        bool possible = true;
        for (int i = 0; i < N - 1; ++i) {
            if (remaining_toys[i] > B[i]) {
                possible = false;
                break;
            }
        }
        if (possible) {
            if (x_candidate3 == -1 || A[k] < x_candidate3) {
                x_candidate3 = A[k];
                found = true;
            }
        }
    }
    
    // Now, determine the minimal x among the possible candidates.
    vector<int> candidates;
    if (x_candidate1 != -1) candidates.push_back(x_candidate1);
    if (x_candidate2 != -1) candidates.push_back(x_candidate2);
    if (found) candidates.push_back(x_candidate3);
    
    if (candidates.empty()) {
        cout << -1 << endl;
    } else {
        cout << *min_element(candidates.begin(), candidates.end()) << endl;
    }
    
    return 0;
}