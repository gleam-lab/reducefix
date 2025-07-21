#include<bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    unordered_map<int, int> countMap;
    set<int> distinctElements;
    
    for (int i = 0; i < q; i++) {
        int queryType;
        cin >> queryType;
        
        if (queryType == 1) {
            int x;
            cin >> x;
            countMap[x]++;
            if (countMap[x] == 1) {
                distinctElements.insert(x);
            }
        } else if (queryType == 2) {
            int x;
            cin >> x;
            if (countMap.find(x) != countMap.end()) {
                countMap[x]--;
                if (countMap[x] == 0) {
                    distinctElements.erase(x);
                }
            }
        } else if (queryType == 3) {
            cout << distinctElements.size() << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}