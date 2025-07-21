#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void Solve() {
    int Q;
    cin >> Q;
    unordered_map<int, int> count;
    unordered_set<int> unique_elements;
    
    while (Q--) {
        int query_type;
        cin >> query_type;
        
        if (query_type == 1) {
            int x;
            cin >> x;
            count[x]++;
            if (count[x] == 1) {
                unique_elements.insert(x);
            }
        } else if (query_type == 2) {
            int x;
            cin >> x;
            count[x]--;
            if (count[x] == 0) {
                unique_elements.erase(x);
            }
        } else if (query_type == 3) {
            cout << unique_elements.size() << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solve();
    
    return 0;
}