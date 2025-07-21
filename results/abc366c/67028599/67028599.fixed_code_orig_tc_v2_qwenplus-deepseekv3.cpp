#include<bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    
    unordered_map<int, int> count;
    set<int> distinct;
    
    while(q--) {
        int type;
        cin >> type;
        
        if(type == 1) {
            int x;
            cin >> x;
            count[x]++;
            if(count[x] == 1) {
                distinct.insert(x);
            }
        } else if(type == 2) {
            int x;
            cin >> x;
            count[x]--;
            if(count[x] == 0) {
                distinct.erase(x);
            }
        } else {
            cout << distinct.size() << endl;
        }
    }
    
    return 0;
}