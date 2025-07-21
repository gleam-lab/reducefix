#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    
    unordered_map<int, int> counts;
    unordered_set<int> distinct;
    
    while (Q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            counts[x]++;
            if (counts[x] == 1) {
                distinct.insert(x);
            }
        } else if (type == 2) {
            int x;
            cin >> x;
            counts[x]--;
            if (counts[x] == 0) {
                distinct.erase(x);
            }
        } else {
            cout << distinct.size() << '\n';
        }
    }
    
    return 0;
}