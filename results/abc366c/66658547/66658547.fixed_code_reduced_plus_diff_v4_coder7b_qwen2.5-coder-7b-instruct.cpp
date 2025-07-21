#include <iostream>
#include <unordered_set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::unordered_set<int> s;
    int q;
    std::cin >> q;

    for(int i = 0; i < q; ++i) {
        int type, x;
        std::cin >> type >> x;

        if(type == 1) {
            s.insert(x);
        } else if(type == 2) {
            s.erase(s.find(x));
        } else if(type == 3) {
            std::cout << s.size() << '\n';
        }
    }

    return 0;
}