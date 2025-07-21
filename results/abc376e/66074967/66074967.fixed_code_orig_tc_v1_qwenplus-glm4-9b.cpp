#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long
const int MAX_N = 2e5 + 9;

int solve(int n, int k, vector<int> &a, vector<int> &b) {
    if (k == n) {
        return *max_element(a.begin(), a.end()) * accumulate(b.begin(), b.end(), 0LL);
    }
    
    sort(a.begin(), a.end(), greater<int>());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    long long sum = 0;
    long long best = LLONG_MAX;
    
    for (int i = 0; i < n; ++i) {
        pq.push(b[i]);
        sum += b[i];
        
        if (pq.size() > k) {
            sum -= pq.top();
            pq.pop();
        }
        
        if (pq.size() == k) {
            best = min(best, sum * a[i]);
        }
    }
    
    return best;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;
        
        cout << solve(n, k, a, b) << '\n';
    }
    
    return 0;
}