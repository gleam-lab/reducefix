#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int j = 0; j < q; ++j) {
        int b, k;
        cin >> b >> k;
        // Binary search for the k-th closest point
        int low = 0, high = n;
        while (low < high) {
            int mid = (low + high) / 2;
            // Calculate the distance of the middle point to B_j and the k-th closest point from A
            int leftDist = abs(a[mid] - b);
            int rightDist = (mid + 1 < n) ? abs(a[mid + 1] - b) : INT_MAX;
            if (leftDist <= rightDist) {
                if (k == 1) {
                    cout << leftDist << endl;
                    break;
                } else {
                    k--;
                    low = mid + 1;
                }
            } else {
                high = mid;
            }
        }
    }

    return 0;
}