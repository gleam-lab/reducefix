#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, k, sum, cnt, a[N];

// Function to find the k-th smallest element in the array 'arr' of size 'size'
int kthSmallest(int arr[], int size, int k) {
    nth_element(arr, arr + k - 1, arr + size);
    return arr[k - 1];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int i, j, x, y;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    while (m--) {
        cin >> x >> k;
        // Calculate distances from point B_j to all points A_i
        vector<int> distances(n);
        for (i = 1; i <= n; i++) {
            distances[i - 1] = abs(x - a[i]);
        }

        // Find the k-th smallest distance
        int result = kthSmallest(distances.data(), n, k);

        cout << result << "\n";
    }

    return 0;
}