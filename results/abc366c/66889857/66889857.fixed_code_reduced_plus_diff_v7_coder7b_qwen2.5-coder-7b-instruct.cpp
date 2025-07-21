#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    unordered_set<int> s;

    while(n--) {
        int t, x;
        cin >> t >> x;
        
        if(t == 1) {
            s.insert(x);
        } else if(t == 2) {
            s.erase(s.find(x));
        } else if(t == 3) {
            cout << s.size() << '\n';
        }
    }

    return 0;
}