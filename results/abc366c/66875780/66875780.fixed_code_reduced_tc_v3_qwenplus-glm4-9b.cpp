#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main() {
    long long Q;
    cin >> Q;
    unordered_set<long long> s;
    while (Q--) {
        long long a;
        cin >> a;
        if (a == 1) {
            long long x;
            cin >> x;
            s.insert(x);
        } else if (a == 2) {
            long long x;
            cin >> x;
            s.erase(x);
        } else {
            cout << s.size() << "\n";
        }
    }
    return 0;
}