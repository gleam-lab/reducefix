#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    
    unordered_set<int> s;
    for(int i = 0; i < n; ++i) {
        int op, x;
        cin >> op >> x;
        
        switch(op) {
            case 1:
                s.insert(x);
                break;
                
            case 2:
                s.erase(s.find(x));
                break;
                
            case 3:
                cout << s.size() << '\n';
                break;
        }
    }

    return 0;
}