#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int Q;
    cin >> Q;
    
    unordered_map<int, int> count_map;
    int unique_count = 0;
    
    while (Q--) {
        int query_type;
        cin >> query_type;
        
        if (query_type == 1) {
            int x;
            cin >> x;
            if (count_map[x] == 0) {
                unique_count++;
            }
            count_map[x]++;
        } else if (query_type == 2) {
            int x;
            cin >> x;
            count_map[x]--;
            if (count_map[x] == 0) {
                unique_count--;
            }
        } else if (query_type == 3) {
            cout << unique_count << "\n";
        }
    }
    
    return 0;
}