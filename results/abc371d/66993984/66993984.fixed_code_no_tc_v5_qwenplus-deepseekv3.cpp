#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n;
    vector<pair<int, int>> points(n);
    
    for(int i = 0; i < n; i++) {
        cin >> points[i].first;
    }
    for(int i = 0; i < n; i++) {
        cin >> points[i].second;
    }
    
    // Sort the points based on x values
    sort(points.begin(), points.end());
    
    // Create a prefix sum array
    vector<int> prefix(n+1, 0);
    for(int i = 0; i < n; i++) {
        prefix[i+1] = prefix[i] + points[i].second;
    }
    
    cin >> q;
    while(q--){
        int L, R;
        cin >> L >> R;
        
        // Find first element >= L
        auto it_l = lower_bound(points.begin(), points.end(), make_pair(L, 0));
        int c = distance(points.begin(), it_l);
        
        // Find first element > R
        auto it_r = upper_bound(points.begin(), points.end(), make_pair(R, INT_MAX));
        int d = distance(points.begin(), it_r);
        
        cout << prefix[d] - prefix[c] << endl;
    }
}