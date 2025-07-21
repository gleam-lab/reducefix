#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Step 1: Identify the K elements that are most distant from each other
    vector<int> extreme_values(k * 2);
    int l = 0, r = 0, l_index = 0, r_index = 0;
    
    for (int i = 0; i < n && k > 0; ++i) {
        if ((i - r) > (r - l)) {
            r = i;
            r_index = l_index + 1;
        }
        if ((i - l) > (r - l)) {
            l = i;
            l_index = r_index;
        }
        if (l_index == k) {
            extreme_values[r_index] = A[r];
            extreme_values[l_index] = A[l];
            l = l_index = 0;
            r = r_index = 0;
            k -= 2;
        }
    }

    // If we still need to consider more elements, fill the extremes with the last possible pair
    while (k > 0) {
        extreme_values[r_index] = A[r];
        extreme_values[l_index] = A[l];
        k -= 2;
        if (k > 0) {
            r = l = 0;
            l_index = r_index = 0;
        }
    }

    // Step 2: Identify the extreme values from the remaining elements
    int left_max = 0, right_max = 0, left_min = INT_MAX, right_min = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (i < extreme_values[0] || i > extreme_values[1]) {
            if (A[i] > left_max) left_max = A[i];
            if (A[i] < right_min) right_min = A[i];
        }
    }
    for (int i = 2; i < extreme_values.size(); ++i) {
        if (i == extreme_values.size() - 1 || A[i - 1] > extreme_values[i]) {
            if (A[i] > right_max) right_max = A[i];
            if (A[i] < left_min) left_min = A[i];
        }
    }

    // Step 3: Calculate the minimum possible value of the maximum value of B minus the minimum value of B
    int result = max(max(left_max - right_min, extreme_values[0] - extreme_values[1]), right_max - left_min);
    cout << result << endl;

    return 0;
}