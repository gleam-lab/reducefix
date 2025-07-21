#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<int> st;
    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        if(x == 1){
            int t; cin >> t;
            st.insert(t);
        } else if(x == 2){
            int t; cin >> t;
            st.erase(st.find(t));
        } else {
            cout << st.size() << "\n";
        }
    }
    return 0;
}