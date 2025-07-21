#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int Q;
    cin >> Q;
    
    unordered_map<int, int> count;
    unordered_set<int> unique;
    
    while (Q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            count[x]++;
            if (count[x] == 1) {
                unique.insert(x);
            }
        } else if (type == 2) {
            int x;
            cin >> x;
            count[x]--;
            if (count[x] == 0) {
                unique.erase(x);
            }
        } else if (type == 3) {
            cout << unique.size() << '\n';
        }
    }
    
    return 0;
}