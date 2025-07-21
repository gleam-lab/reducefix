#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 5;
int n, q, k, a[MAX];

// Function to find the k-th smallest distance
int findKthSmallest(int x, vector<int>& distances) {
    sort(distances.begin(), distances.end());
    return distances[k-1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) 
        cin >> a[i];

    while(q--) {
        int b, k;
        cin >> b >> k;

        // Calculate all distances from point B to points A
        vector<int> distances(n);
        for(int i = 1; i <= n; ++i) 
            distances[i-1] = abs(b - a[i]);

        // Find the k-th smallest distance
        int result = findKthSmallest(b, distances);
        cout << result << "\n";
    }

    return 0;
}