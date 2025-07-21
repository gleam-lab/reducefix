#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int Q;
    cin >> Q;
    
    unordered_map<int, int> count;
    int distinct = 0;
    
    while (Q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            if (count[x] == 0) {
                distinct++;
            }
            count[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            count[x]--;
            if (count[x] == 0) {
                distinct--;
            }
        } else if (type == 3) {
            cout << distinct << "\n";
        }
    }
    
    return 0;
}