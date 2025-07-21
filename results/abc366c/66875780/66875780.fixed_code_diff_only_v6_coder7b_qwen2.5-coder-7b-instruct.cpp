#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <memory>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <tuple>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>

using namespace std;

// Fast IO
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Solve()
{
    ll Q;
    cin >> Q;
    set<ll> s;
    while (Q--)
    {
        ll a;
        cin >> a;
        if (a == 1)
        {
            ll tp;
            cin >> tp;
            s.insert(tp);
        }
        else if (a == 2)
        {
            ll tp;
            cin >> tp;
            s.erase(s.find(tp));
        }
        else
        {
            cout << s.size() << "\n";
        }
    }
}

int main()
{
    fastIO();
    Solve();
    return 0;
}