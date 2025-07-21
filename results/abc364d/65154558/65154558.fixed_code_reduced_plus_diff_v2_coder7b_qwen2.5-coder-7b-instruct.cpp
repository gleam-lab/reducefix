#include<bits/stdc++.h>
using namespace std;

vector<int> A, B;

// Function to find the k-th smallest distance
int findKthSmallestDistance(int b, int k) {
    vector<int> distances;
    for (int a : A) {
        distances.push_back(abs(a - b));
    }
    sort(distances.begin(), distances.end());
    return distances[k - 1];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, Q; cin >> N >> Q;
    A.resize(N);
    B.resize(Q);

    // Read coordinates of A points
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Read coordinates of B points and corresponding k values
    for (int i = 0; i < Q; ++i) {
        cin >> B[i] >> A[i]; // Here A[i] holds the k value
    }

    // Process each query
    for (int i = 0; i < Q; ++i) {
        int result = findKthSmallestDistance(B[i], A[i]);
        cout << result << '\n';
    }

    return 0;
}