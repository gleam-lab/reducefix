#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    set<int> a;
    
    while(n--) {
        int x, y; cin >> x;
        if(x == 1) {
            cin >> y;
            a.insert(y);
        } 
        else if(x == 2) {
            cin >> y;
            a.erase(a.find(y));
        } 
        else {
            cout << a.size() << endl;
        }
    }

    return 0;
}