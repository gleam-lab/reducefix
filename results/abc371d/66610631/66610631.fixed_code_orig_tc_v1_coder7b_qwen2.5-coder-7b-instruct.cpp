#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6 + 7;

// Function to calculate prefix sum array
void calculatePrefixSum(vector<int>& a, vector<LL>& c) {
    c[0] = 0;
    for(int i = 1; i <= a.size(); ++i) {
        c[i] = c[i - 1] + a[i - 1];
    }
}

// Binary search function to find the position of x
int binarySearch(const vector<int>& a, int x) {
    int left = 0, right = a.size();
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(a[mid] >= x) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    vector<LL> c(n + 1);
    
    // Input array a
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Calculate prefix sum array for a
    calculatePrefixSum(a, c);
    
    // Input array b
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        
        // Find positions using binary search
        int pos_l = binarySearch(b, l);
        int pos_r = binarySearch(b, r);
        
        // Adjust positions based on conditions
        if(pos_l == n || b[pos_l] != l) --pos_l;
        if(pos_r == n || b[pos_r] != r) ++pos_r;
        
        // Output the result based on the positions
        if(pos_r > pos_l) cout << c[pos_r] - c[pos_l] << '\n';
        else cout << c[pos_r] << '\n';
    }
    return 0;
}