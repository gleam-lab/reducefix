#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    unordered_set<int> s;
    int n; cin >> n;
    while(n--) {
        int op, x; cin >> op >> x;
        if(op == 1) s.insert(x);
        else if(op == 2) s.erase(s.find(x));
        else cout << s.size() << '\n';
    }
    return 0;
}