#include <iostream>
#include <set>
#include <vector>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q;
    std::cin >> q;

    std::vector<std::string> queries(q);
    std::string line;
    for (int i = 0; i < q; ++i) {
        std::getline(std::cin, line);
        queries[i] = line;
    }

    std::istringstream iss;
    std::set<int> st;
    for (const std::string& query : queries) {
        iss.clear();
        iss.str(query);
        int op;
        if (!(iss >> op)) {
            std::cerr << "Error parsing query: " << query << "\n";
            return 1;
        }

        if (op == 1) {
            int x;
            if (!(iss >> x)) {
                std::cerr << "Error parsing query: " << query << "\n";
                return 1;
            }
            st.insert(x);
        } else if (op == 2) {
            int x;
            if (!(iss >> x)) {
                std::cerr << "Error parsing query: " << query << "\n";
                return 1;
            }
            st.erase(x);
        } else if (op == 3) {
            std::cout << st.size() << "\n";
        }
    }

    return 0;
}