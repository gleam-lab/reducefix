#include <iostream>
#include <set>

int main() {
    std::set<int> st;
    int q;
    std::cin >> q;
    while (q--) {
        int x;
        std::cin >> x;
        if (x == 1) {
            int t;
            std::cin >> t;
            st.insert(t);
        } else if (x == 2) {
            int t;
            std::cin >> t;
            st.erase(t);
        } else if (x == 3) {
            std::cout << st.size() << "\n";
        }
    }
    return 0;
}