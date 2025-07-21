#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int> st;
    int q; cin >> q;
    while(q--){
        int type, value;
        cin >> type >> value;
        if(type == 1){
            st.insert(value);
        } else if(type == 2){
            st.erase(st.find(value));
        } else if(type == 3){
            cout << st.size() << '\n';
        }
    }
    return 0;
}