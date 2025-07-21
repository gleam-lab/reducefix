#include<bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    unordered_map<int, int> count; // To keep track of counts of each number
    set<int> distinct; // To keep track of distinct numbers
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            if (count[x] == 0) {
                distinct.insert(x);
            }
            count[x]++;
        } else if (a == 2) {
            int y;
            cin >> y;
            count[y]--;
            if (count[y] == 0) {
                distinct.erase(y);
            }
        } else if (a == 3) {
            cout << distinct.size() << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}