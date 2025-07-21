#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    deque<int> dq;
    
    // Read the sequence and push all elements to the deque
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        dq.push_back(a);
    }
    
    // Sort the deque to facilitate the minimum and maximum operations
    sort(dq.begin(), dq.end());
    
    // We want to remove exactly K elements, so we keep N-K elements
    // Note: If K is more than half of N, we should consider the second half of the sorted deque
    int keep = n - k;
    int ans = INT_MAX;
    
    // If K is odd, we can remove K elements, leave N-K elements, and consider the max-min of the middle elements
    if (k % 2 == 1) {
        // Calculate the range after removing K elements
        ans = min(dq[keep - 1] - dq[keep], dq[keep + 1] - dq[0]);
    } else {
        // If K is even, we can remove K/2 elements from both ends and consider the range between them
        int half_k = k / 2;
        ans = dq[keep + half_k] - dq[keep - half_k];
    }
    
    // Output the result
    cout << ans << endl;
    return 0;
}