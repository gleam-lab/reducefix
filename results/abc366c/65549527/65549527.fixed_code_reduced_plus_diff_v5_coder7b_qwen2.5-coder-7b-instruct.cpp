#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    cin >> q;
    
    set<int> uniqueElements;
    unordered_set<int> countMap;
    
    while (q--) {
        int a;
        cin >> a;
        
        if (a == 1) {
            int x;
            cin >> x;
            if (countMap.find(x) == countMap.end()) {
                uniqueElements.insert(x);
            }
            countMap[x]++;
        } else if (a == 2) {
            int y;
            cin >> y;
            if (countMap[y] > 1) {
                countMap[y]--;
            } else {
                uniqueElements.erase(uniqueElements.find(y));
                countMap.erase(y);
            }
        } else if (a == 3) {
            cout << uniqueElements.size() << endl;
        }
    }
    
    return 0;
}