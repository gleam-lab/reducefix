#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

void Solve() {
    int Q;
    cin >> Q;
    unordered_map<int, int> freq;
    unordered_set<int> distinct;

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            freq[x]++;
            distinct.insert(x);
        } else if (type == 2) {
            int x;
            cin >> x;
            freq[x]--;
            if (freq[x] == 0) {
                distinct.erase(x);
            }
        } else {
            cout << distinct.size() << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solve();
    
    return 0;
}