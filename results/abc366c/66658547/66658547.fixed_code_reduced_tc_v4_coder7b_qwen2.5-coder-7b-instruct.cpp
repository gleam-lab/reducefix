#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    unordered_set<int> st;
    int q; cin >> q;
    while(q--){
        int type, x;
        cin >> type;
        if(type == 1){
            cin >> x;
            st.insert(x);
        } else if(type == 2){
            cin >> x;
            st.erase(st.find(x));
        } else {
            cout << st.size() << '\n';
        }
    }
    return 0;
}