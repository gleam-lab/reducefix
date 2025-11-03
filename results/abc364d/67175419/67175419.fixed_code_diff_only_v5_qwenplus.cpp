#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, q;
long long a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a, a + n);
    
    while (q--) {
        long long b;
        int k;
        cin >> b >> k;
        
        // Create vector of distances from B to each A_i
        vector<long long> distances;
        for (int i = 0; i < n; i++) {
            distances.push_back(abs(a[i] - b));
        }
        
        // Find the k-th smallest distance using nth_element for efficiency
        nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}