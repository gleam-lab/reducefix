#include<bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    unordered_map<int, int> freq;
    set<int> distinct;
    
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            freq[x]++;
            if (freq[x] == 1) {
                distinct.insert(x);
            }
        } else if (a == 2) {
            int x;
            cin >> x;
            if (freq.find(x) != freq.end()) {
                freq[x]--;
                if (freq[x] == 0) {
                    distinct.erase(x);
                }
            }
        } else if (a == 3) {
            cout << distinct.size() << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}