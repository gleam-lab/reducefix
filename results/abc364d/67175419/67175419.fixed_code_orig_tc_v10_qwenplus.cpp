#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
int n, q;
long long a[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    while (q--) {
        long long b;
        int k;
        cin >> b >> k;

        // Find the position where b would be inserted
        auto it = lower_bound(a, a + n, b);
        int pos = it - a;

        // We'll consider candidates from left and right of pos
        vector<long long> distances;
        
        // Add distances from elements to the left of pos (in reverse order)
        for (int i = pos - 1; i >= 0 && (int)distances.size() < k; i--) {
            distances.push_back(abs(a[i] - b));
        }
        
        // Add distances from elements at pos and to the right
        for (int i = pos; i < n && (int)distances.size() < k; i++) {
            distances.push_back(abs(a[i] - b));
        }
        
        // If we don't have enough elements on the right, add more from the left
        if ((int)distances.size() < k) {
            for (int i = pos - (int)distances.size(); i >= 0; i--) {
                distances.push_back(abs(a[i] - b));
            }
        }

        // Sort distances to find the k-th smallest
        sort(distances.begin(), distances.end());
        
        cout << distances[k-1] << '\n';
    }

    return 0;
}