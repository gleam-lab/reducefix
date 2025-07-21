#include <vector>
#include <iostream>
#include <algorithm>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;

int main() {
	
	m_int n,q; cin>>n>>q;
	vector<m_int> a(n), distances;
	
	for(m_int i=0;i<n;++i) {
		cin >> a[i];
	}
	
	while(q--) {
		m_int b, k;cin>>b>>k;
		
		distances.clear();
		for(const auto& ai : a) {
			distances.push_back(abs(ai - b));
		}
		
		std::nth_element(distances.begin(), distances.begin()+k-1, distances.end());
		
		cout << distances[k-1] << "\n";
	}
}