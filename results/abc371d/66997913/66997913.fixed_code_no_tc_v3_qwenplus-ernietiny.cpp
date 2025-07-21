#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n; // 获取要处理的整数数量
  vector<int> x(n); // 创建一个整数向量x
  for (int i = 0; i < n; i++) cin >> x[i]; // 输入整数到向量x中
  
  // 假设向量p和s已经被正确地初始化和填充了数据
  // 这里省略了初始化p和s的代码，直接分析代码逻辑
  
  int q; // 读取询问次数
  cin >> q; // 读取询问次数
  vector<ll> p_temp(n), s_temp(n+1); // 创建临时向量存储中间结果
  for (int i = 0; i < q; i++) { // 处理每个询问
    int l, r; // 读取左端点和右端点
    cin >> l >> r; // 读取询问范围内的值
    int ans = s_temp[r] - s_temp[l]; // 计算答案并存储在ans变量中
    cout << ans << endl; // 输出结果
  }
  return 0;
}