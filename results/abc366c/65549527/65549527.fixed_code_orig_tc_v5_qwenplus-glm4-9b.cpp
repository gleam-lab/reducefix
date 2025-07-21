#include <iostream>
#include <set>
#include <vector>

void solve() {
    int q;
    std::cin >> q;
    std::set<int> st;
    std::vector<int> results;

    for (int i = 0; i < q; i++) {
        int a;
        std::cin >> a;
        if (a == 1) {
            int x;
            std::cin >> x;
            st.insert(x);
        } else if (a == 2) {
            int y;
            std::cin >> y;
            st.erase(y);
        } else if (a == 3) {
            results.push_back(st.size());
        }
    }

    for (int result : results) {
        std::cout << result << std::endl;
    }
}

int main() {
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }
}