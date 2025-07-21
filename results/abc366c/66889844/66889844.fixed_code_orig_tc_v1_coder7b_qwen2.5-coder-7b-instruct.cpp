#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    unordered_set<int> a;
    
    while(n--) {
        int x, t; cin >> t;
        if(t == 1) {
            cin >> x;
            a.insert(x);
        } else if(t == 2) {
            cin >> x;
            a.erase(a.find(x));
        } else {
            cout << a.size() << "\n";
        }
    }

    return 0;
}