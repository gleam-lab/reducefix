#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Binary search for the k-th smallest distance from a sorted list of distances
ll kthSmallestDistance(vector<ll>& distances, int k) {
    return distances[k - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort A once since we'll query multiple times
    sort(A.begin(), A.end());

    for (int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;

        // Compute absolute differences and store in a temporary vector
        vector<ll> distances(N);
        for (int i = 0; i < N; ++i) {
            distances[i] = abs(A[i] - b);
        }

        // Sort distances to find k-th smallest
        sort(distances.begin(), distances.end());
        
        // Output the k-th smallest distance
        cout << kthSmallestDistance(distances, k) << endl;
    }

    return 0;
}