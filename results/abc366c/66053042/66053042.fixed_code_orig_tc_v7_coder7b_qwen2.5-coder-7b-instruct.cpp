#include <iostream>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::map<int, int> m;
    int Q;
    std::cin >> Q;

    while (Q--) {
        int type;
        std::cin >> type;

        if (type == 1) {
            int x;
            std::cin >> x;
            if (m.find(x) != m.end()) {
                m[x]++;
            } else {
                m[x] = 1;
            }
        } else if (type == 2) {
            int x;
            std::cin >> x;
            if (m.find(x) != m.end()) {
                if (--m[x] == 0) {
                    m.erase(x);
                }
            }
        } else if (type == 3) {
            std::cout << m.size() << '\n';
        }
    }

    return 0;
}