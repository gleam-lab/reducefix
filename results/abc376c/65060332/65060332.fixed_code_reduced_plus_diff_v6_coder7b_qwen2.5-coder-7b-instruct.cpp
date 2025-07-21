#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& a, vector<int>& b, int x) {
    priority_queue<int> pq;
    for(int i = 0; i < b.size(); i++) {
        pq.push(b[i]);
    }
    
    sort(a.begin(), a.end());
    
    for(int i = 0; i < a.size(); i++) {
        if(pq.empty() || pq.top() < a[i]) return false;
        pq.pop();
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n-1);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n-1; i++) cin >> b[i];
    
    sort(b.begin(), b.end());
    
    int left = *max_element(a.begin(), a.end()), right = 1e9;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(canPlace(a, b, mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << left << endl;
    
    return 0;
}