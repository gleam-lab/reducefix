#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f

struct Node {
    int val, idx;
};

bool cmp(const Node &a, const Node &b) {
    return a.val > b.val;
}

ll solve(int n, int k, vector<ll> &A, vector<ll> &B) {
    vector<Node> a(n), b(n);
    
    // Store A and B with their indices
    for (int i = 0; i < n; ++i) {
        a[i] = {A[i], i};
        b[i] = {B[i], i};
    }
    
    // Sort based on the values in descending order
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);
    
    // Min-heap to keep track of the smallest elements
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sum = 0;
    
    // Select the top k elements from A and corresponding elements from B
    for (int i = 0; i < k; ++i) {
        pq.push(b[a[i].idx]);
        sum += b[a[i].idx];
    }
    
    ll result = INF;
    
    // Iterate through the remaining elements to find the minimum result
    for (int i = k; i < n; ++i) {
        result = min(result, (sum + b[a[i].idx]) * a[i].val);
        
        // Remove the smallest element from the current sum and add the new one
        sum -= pq.top();
        pq.pop();
        pq.push(b[a[i].idx]);
        sum += b[a[i].idx];
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<ll> A(n), B(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        
        cout << solve(n, k, A, B) << '\n';
    }
    
    return 0;
}