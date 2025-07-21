#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define ll long long

struct Element {
    int a, b;
    bool operator<(const Element &other) const {
        return a > other.a || (a == other.a && b < other.b);
    }
};

ll minExpressionValue(int n, int k, vector<ll>& A, vector<ll>& B) {
    vector<Element> elements(n);
    for (int i = 0; i < n; ++i) {
        elements[i] = {A[i], B[i]};
    }
    
    sort(elements.begin(), elements.end());
    
    ll sum = 0;
    priority_queue<int> pq;
    
    for (int i = 0; i < k; ++i) {
        sum += elements[i].b;
        pq.push(-elements[i].b); // Use negative for max-heap using priority queue
    }
    
    ll result = -elements[k-1].a * sum;
    
    for (int i = k; i < n; ++i) {
        sum -= pq.top(); pq.pop();
        sum += elements[i].b;
        pq.push(-elements[i].b);
        result = min(result, -elements[i].a * sum);
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
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
        
        cout << minExpressionValue(n, k, A, B) << '\n';
    }
    
    return 0;
}