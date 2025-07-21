#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200100;
int a[N];

int main() {
    int n, q;
    cin >> n >> q;
    memset(a, 0, sizeof(a));
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }
    
    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        // Using binary search to find the k-th closest point
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // Check if the k-th closest point is within the range [mid, mid+1]
            if (a[mid] < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        // Calculate the distance to the k-th closest point
        cout << abs(x - left) << endl;
    }
    
    return 0;
}