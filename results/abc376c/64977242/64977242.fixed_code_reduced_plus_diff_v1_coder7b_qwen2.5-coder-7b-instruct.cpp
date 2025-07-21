#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n - 1; ++i) cin >> b[i];
    
    sort(a.rbegin(), a.rend()); // Sort in descending order
    sort(b.rbegin(), b.rend()); // Sort in descending order
    
    priority_queue<int> pq; // Max heap to store the sizes of boxes
    
    for(int i = 0; i < n - 1; ++i) {
        pq.push(b[i]);
    }
    
    int idx = 0;
    while(!pq.empty()) {
        int top = pq.top();
        pq.pop();
        
        if(top >= a[idx]) {
            ++idx;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    
    cout << a[0] << endl; // The minimum size needed is the largest toy size
    
    return 0;
}