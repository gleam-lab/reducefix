#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define P pair<int, int>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vi A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort the A array for binary search usage
    sort(A.begin(), A.end());
    
    for (int q = 0; q < Q; ++q) {
        int b, k;
        cin >> b >> k;
        
        // Binary search to find the k-th closest point
        int left = 0, right = N - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (A[mid] <= b) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        // Now, left is the index of the first element > b or last element if all <= b
        
        // Use two pointers to expand around the closest point
        int l = left - 1, r = left;
        int count = 0;
        int result = 0;
        
        while (count < k) {
            if (l < 0) {
                result = abs(A[r++] - b);
            } else if (r >= N) {
                result = abs(A[l--] - b);
            } else if (abs(A[l] - b) <= abs(A[r] - b)) {
                result = abs(A[l--] - b);
            } else {
                result = abs(A[r++] - b);
            }
            count++;
        }
        
        cout << result << "\n";
    }
    
    return 0;
}