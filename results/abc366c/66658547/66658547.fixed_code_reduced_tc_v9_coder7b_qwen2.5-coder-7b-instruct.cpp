#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    unordered_set<int> us;
    int q; cin >> q;
    while(q--){
        int type, x;
        cin >> type;
        if(type == 1){
            cin >> x;
            us.insert(x);
        } else if(type == 2){
            cin >> x;
            us.erase(us.find(x));
        } else {
            cout << us.size() << "\n";
        }
    }
    return 0;
}