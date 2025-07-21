#include <vector>
#include <iostream>
#include <algorithm>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;

int main() {
	
	m_int n, q; cin >> n >> q;
	vector<m_int> a(n);
	
	for(m_int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	while(q--) {
		
		m_int b, k; cin >> b >> k;

		auto f = [&](m_int x) -> bool {
			
			// count of points within distance x
			int cnt = 0;
			for(auto &ai : a) {
				if(abs(ai - b) <= x) {
					++cnt;
				}
			}
			return cnt >= k;
		};

		m_int l = -1, r = 1e8 + 1;
		while(l + 1 < r) {
			
			m_int mid = (l + r) / 2;
			if(f(mid)) {
				r = mid;
			} else {
				l = mid;
			}
		}
		cout << r << "\n";
	}
}