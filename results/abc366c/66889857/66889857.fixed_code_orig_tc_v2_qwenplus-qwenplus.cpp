#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    
    map<int, int> countMap;
    set<int> uniqueSet;
    
    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            countMap[x]++;
            uniqueSet.insert(x);
        } else if (type == 2) {
            int x;
            cin >> x;
            countMap[x]--;
            if (countMap[x] == 0) {
                uniqueSet.erase(x);
                countMap.erase(x); // Optional: clean up memory
            }
        } else if (type == 3) {
            cout << uniqueSet.size() << "\n";
        }
    }
    
    return 0;
}