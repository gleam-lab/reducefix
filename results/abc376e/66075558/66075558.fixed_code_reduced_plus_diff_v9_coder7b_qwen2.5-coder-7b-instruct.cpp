#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

struct Node {
    int a, b;
    Node(int _a, int _b) : a(_a), b(_b) {}
};

bool cmp(const Node &a, const Node &b) {
    if (a.a == b.a) return a.b > b.b;
    return a.a < b.a;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<Node> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].a;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i].b;
        }
        
        // Sort nodes by a in ascending order, and by b in descending order for same a
        sort(a.begin(), a.end(), cmp);
        
        // Priority queue to maintain the sum of B values
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum_b = 0;
        
        // Initialize the first K elements
        for (int i = 0; i < k; ++i) {
            pq.push(a[i].b);
            sum_b += a[i].b;
        }
        
        // Result will store the minimum value
        int result = sum_b * a[k - 1].a;
        
        // Try replacing the smallest element in the current set with the next largest one
        for (int i = k; i < n; ++i) {
            sum_b -= pq.top();
            pq.pop();
            pq.push(a[i].b);
            sum_b += a[i].b;
            result = min(result, sum_b * a[i].a);
        }
        
        cout << result << '\n';
    }
    return 0;
}