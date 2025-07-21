#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

struct Element {
    int a, b;
};

bool cmp(const Element &a, const Element &b) {
    return a.a < b.a;
}

int solve(int n, int k, vector<int> &A, vector<int> &B) {
    vector<Element> pairs(n);
    for (int i = 0; i < n; ++i) {
        pairs[i] = {A[i], B[i]};
    }
    
    // Sort pairs based on A values
    sort(pairs.begin(), pairs.end(), cmp);
    
    // Min-heap to store the sums of B values
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        pq.push(pairs[i].b);
        sum += pairs[i].b;
    }
    
    int minResult = sum * pairs[k - 1].a;
    
    for (int i = k; i < n; ++i) {
        sum += pairs[i].b - pq.top();
        pq.pop();
        pq.push(pairs[i].b);
        minResult = min(minResult, sum * pairs[i].a);
    }
    
    return minResult;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> A(n), B(n);
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