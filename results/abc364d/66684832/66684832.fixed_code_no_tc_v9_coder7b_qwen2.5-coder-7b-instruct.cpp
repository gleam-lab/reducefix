#include <iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
using namespace std;

#define int long long
#define endl '\n'

const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;
int n, q;
vector<int> a;

// Function to calculate the distance between two points
int distance(int x, int y) {
    return abs(x - y);
}

// Function to find the k-th smallest distance
int findKthSmallestDistance(int b_j, int k_j) {
    vector<int> distances;
    for (int i = 0; i < n; ++i) {
        distances.push_back(distance(a[i], b_j));
    }
    nth_element(distances.begin(), distances.begin() + k_j - 1, distances.end());
    return distances[k_j - 1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    while (q--) {
        int b_j, k_j;
        cin >> b_j >> k_j;
        cout << findKthSmallestDistance(b_j, k_j) << endl;
    }

    return 0;
}