#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long binary_search(long long left, long long right, int n, vector<long long>& A, int M, long long total_votes_left) {
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long count = 0;
        
        for (int i = 0; i < n; ++i) {
            long long needed = mid - A[i];
            if (needed > 0) {
                count += min(needed, total_votes_left);
                total_votes_left -= needed;
            }
        }
        
        if (count < M) {
            return mid;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    long long k;
    cin >> n >> m >> k;
    
    vector<long long> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    long long total_votes_left = k - accumulate(A.begin(), A.end(), 0LL);
    
    for (int i = 0; i < n; ++i) {
        long long result = binary_search(A[i], total_votes_left, n, A, M, total_votes_left);
        cout << result << " ";
    }
    
    return 0;
}