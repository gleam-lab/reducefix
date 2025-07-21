#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& sizes, int mid) {
    vector<int> boxes(mid + 1);
    priority_queue<int> pq;
    
    for(int size : sizes) {
        if(size > mid) return false;
        
        if(!pq.empty() && pq.top() <= size) {
            pq.pop();
        } else {
            pq.push(size);
        }
        
        if(pq.size() > mid) return false;
    }
    
    return true;
}

int minBoxSize(vector<int>& toys, vector<int>& boxes) {
    int left = 0, right = *max_element(toys.begin(), toys.end());
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(canPlace(boxes, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left == 0 ? -1 : left;
}

int main() {
    int n;
    cin >> n;
    vector<int> toys(n), boxes(n - 1);
    
    for(int i = 0; i < n; ++i) {
        cin >> toys[i];
    }
    
    for(int i = 0; i < n - 1; ++i) {
        cin >> boxes[i];
    }
    
    cout << minBoxSize(toys, boxes) << endl;
    
    return 0;
}