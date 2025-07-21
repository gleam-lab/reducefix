#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q;
int a[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (q--) {
        int b, k;
        cin >> b >> k;
        // Calculate the distance between each point A_i and B
        vector<pair<int, int>> distances;
        for (int i = 0; i < n; i++) {
            int distance = abs(a[i] - b);
            distances.emplace_back(distance, i);
        }
        
        // Sort distances by the actual distance
        sort(distances.begin(), distances.end());
        
        // The k-th closest point to B is the k-th element in the sorted distances
        int closestDistance = distances[k - 1].first;
        cout << closestDistance << "\n";
    }

    return 0;
}