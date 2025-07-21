#include <iostream>
#include <set>

int main() {
    int q;
    std::cin >> q;
    std::set<int> st;
    
    for (int i = 0; i < q; ++i) {
        int type, x;
        std::cin >> type;
        if (type == 1) {
            std::cin >> x;
            st.insert(x);
        } else if (type == 2) {
            std::cin >> x;
            st.erase(x);
        } else if (type == 3) {
            std::cout << st.size() << std::endl;
        }
    }
    
    return 0;
}