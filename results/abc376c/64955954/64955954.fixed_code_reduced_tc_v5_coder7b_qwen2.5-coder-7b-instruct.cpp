#include <bits/stdc++.h>
using namespace std;

bool canStore(vector<int>& toys, vector<int>& boxes) {
    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());
    
    int j = 0;
    for(int i = 0; i < toys.size(); ++i) {
        while(j < boxes.size() && boxes[j] < toys[i]) {
            ++j;
        }
        if(j == boxes.size()) return false;
        ++j;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> toys(n), boxes(n-1);
    for(int i = 0; i < n; ++i) cin >> toys[i];
    for(int i = 0; i < n-1; ++i) cin >> boxes[i];
    
    if(canStore(toys, boxes)) {
        cout << *max_element(toys.begin(), toys.end()) << '\n';
    } else {
        cout << -1 << '\n';
    }
    
    return 0;
}