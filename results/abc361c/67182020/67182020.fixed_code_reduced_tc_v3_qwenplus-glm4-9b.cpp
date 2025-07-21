#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    
    sort(A.begin(), A.end());

    vector<long long> min_diffs;
    long long min_val = A[0], max_val = A[N-1];
    min_diffs.push_back(max_val - min_val);  // Initial range without removing any elements

    // Try removing pairs of elements and calculate the new min and max
    for (int i = 0; i < N - 1; ++i) {
        if (K > 0) {
            // Remove the current and next element
            vector<long long> new_A(A.begin() + i + 2, A.end());
            long long new_min = *min_element(new_A.begin(), new_A.end());
            long long new_max = *max_element(new_A.begin(), new_A.end());
            min_diffs.push_back(new_max - new_min);
            K -= 2;
            if (K < 0) break;  // We have removed more than K elements
        }
    }
    
    // Output the minimum difference found
    cout << *min_element(min_diffs.begin(), min_diffs.end()) << endl;
    return 0;
}