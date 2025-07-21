#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, k, sum, cnt, a[N];

// Function to calculate the k-th smallest distance
int findKthSmallestDistance(int x, vector<int>& distances, int k) {
    nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
    return distances[k - 1];
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
        vector<int> distances(n);
        for (i = 1; i <= n; i++) {
            distances[i - 1] = abs(a[i] - x);
        }
        int result = findKthSmallestDistance(x, distances, k);
        cout << result << "\n";
    }

    return 0;
}