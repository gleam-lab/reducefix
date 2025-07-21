#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<pair<int, int>> A(N);
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> A[i].first;
        A[i].second = i;
    }
    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        // Calculate distance from B_j to each point in A
        vector<int> distances;
        for (int j = 0; j < n; ++j) {
            int a = A[j].first;
            int idx = A[j].second;
            distances.push_back(abs(b - a));
        }
        // Sort distances to find the k-th smallest
        sort(distances.begin(), distances.end());
        // Output k-th smallest distance
        cout << distances[k - 1] << '\n';
    }
    return 0;
}