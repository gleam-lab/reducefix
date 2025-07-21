#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<int, int>> a(n), b(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        // Sort in descending order based on the first element of the pair
        sort(a.begin(), a.end(), greater<pair<int, int>>());
        sort(b.begin(), b.end(), greater<pair<int, int>>());
        
        // Find the indices of the top K elements in both arrays
        vector<int> a_indices(k), b_indices(k);
        for (int i = 0; i < k; ++i) {
            a_indices[i] = a[i].second;
            b_indices[i] = b[i].second;
        }
        
        // Sort the indices to find the smallest subset
        sort(a_indices.begin(), a_indices.end());
        sort(b_indices.begin(), b_indices.end());
        
        int result = 0;
        for (int i = 0; i < k; ++i) {
            result += b[b_indices[i]].first;
        }
        
        // Get the maximum element from the top K elements of A
        int max_A = a[a_indices[k-1]].first;
        
        // Calculate the final result
        cout << result * max_A << '\n';
    }
    
    return 0;
}