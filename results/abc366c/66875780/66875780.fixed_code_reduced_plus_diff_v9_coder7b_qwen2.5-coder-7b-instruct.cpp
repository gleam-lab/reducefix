#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;
    multiset<int> s;
    
    while(Q--) {
        int q;
        cin >> q;
        
        if(q == 1) {
            int x;
            cin >> x;
            s.insert(x);
        } 
        else if(q == 2) {
            int x;
            cin >> x;
            s.erase(s.find(x));
        } 
        else {
            cout << s.size() << '\n';
        }
    }

    return 0;
}