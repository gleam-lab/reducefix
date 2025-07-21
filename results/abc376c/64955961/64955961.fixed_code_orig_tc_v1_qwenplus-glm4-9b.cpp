#include<bits/stdc++.h>
using namespace std;

int solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) cin >> b[i];

    sort(a.begin(), a.end(), greater<int>());  // Sort toys in descending order
    sort(b.begin(), b.end());  // Sort boxes in ascending order

    int left = a[0], right = 1e9 + 1;  // Possible range for the new box size

    while (left < right) {
        int mid = left + (right - left) / 2;
        int i = 0, j = 0;  // i is the index for toys, j is the index for boxes
        while (i < n) {
            // Try to fit toy a[i] into box b[j]
            while (j < n - 1 && b[j] < mid) j++;
            if (j >= n - 1) {  // No box can fit the toy
                left = mid + 1;
                break;
            }
            j++;  // Use this box and move to the next toy
            i++;
        }
        if (i == n) right = mid;  // All toys can be placed in the boxes of size 'mid'
    }

    return left;  // The smallest box size that works
}

int main() {
    cout << solve() << endl;
    return 0;
}