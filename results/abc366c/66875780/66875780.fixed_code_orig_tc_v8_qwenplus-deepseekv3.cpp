#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int Q;
    cin >> Q;
    
    unordered_map<int, int> count;
    set<int> unique;
    
    while (Q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            if (count[x]++ == 0) {
                unique.insert(x);
            }
        } else if (type == 2) {
            int x;
            cin >> x;
            if (--count[x] == 0) {
                unique.erase(x);
            }
        } else {
            cout << unique.size() << '\n';
        }
    }
    
    return 0;
}