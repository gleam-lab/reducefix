#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    unordered_set<int> st;
    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int x; cin >> x;
            st.insert(x);
        } else if(type == 2){
            int x; cin >> x;
            st.erase(x);
        } else if(type == 3){
            cout << st.size() << "\n";
        }
    }
    return 0;
}