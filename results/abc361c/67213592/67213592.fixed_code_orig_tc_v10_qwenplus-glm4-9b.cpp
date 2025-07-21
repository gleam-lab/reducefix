#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    // We need to find the smallest difference between the maximum and minimum
    // of the remaining elements after removing K elements.
    // We can use a sliding window approach with two pointers to maintain a sorted subarray
    // of length n - k.

    // First, sort the array
    sort(v.begin(), v.end());

    // We need to keep track of the sum of the largest and smallest elements
    // at any point in our sliding window.
    int min_sum = 0, max_sum = 0;
    int min_sum_index = 0, max_sum_index = n - 1;

    // We start with the smallest sum possible, which is the first n-k elements.
    for (int i = 0; i < n - k; ++i) {
        min_sum += v[i];
    }
    for (int i = n - k; i < n; ++i) {
        max_sum += v[i];
    }

    int min_difference = max_sum - min_sum;

    // Now we slide the window across the array:
    // We try to remove elements from the ends of the sorted array to minimize the difference
    // between the maximum and minimum of the remaining elements.
    for (int i = 1; i <= k; ++i) {
        if (v[min_sum_index] < v[max_sum_index]) {
            min_sum -= v[min_sum_index];
            min_sum_index++;
        } else {
            max_sum -= v[max_sum_index];
            max_sum_index--;
        }
        max_sum += v[min_sum_index + k - 1]; // Add the new minimum after removal
        min_sum -= v[min_sum_index - 1];    // Remove the old minimum after addition
        min_difference = min(min_difference, max_sum - min_sum);
    }

    cout << min_difference << endl;
    return 0;
}