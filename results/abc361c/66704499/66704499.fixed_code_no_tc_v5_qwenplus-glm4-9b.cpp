#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    // We need to find the minimum difference between max and min in the remaining sequence
    // after removing exactly K elements. We do a binary search on the possible minimum values
    // of the resulting sequence B.

    int left = INT_MAX;
    int right = INT_MIN;

    // Find the global minimum and maximum in the array
    for (int i = 0; i < n; i++) {
        left = min(left, a[i]);
        right = max(right, a[i]);
    }

    // Binary search on the possible minimum values
    while (left < right) {
        int mid = (left + right) / 2;
        int count = 0;
        int removed_min = INT_MAX;

        // Count how many elements are less than mid and need to be removed to have
        // the remaining elements all greater than or equal to mid
        for (int i = 0; i < n; i++) {
            if (a[i] < mid) {
                removed_min = min(removed_min, a[i]);
                count++;
            }
        }

        // If we can remove more elements than K, it means we need to consider a lower minimum
        // If we can't remove enough elements, it means we need to consider a higher minimum
        if (count > k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    // The result is the difference between the global maximum and the smallest possible minimum
    // of the remaining sequence after removing K elements
    cout << right - removed_min << endl;

    return 0;
}