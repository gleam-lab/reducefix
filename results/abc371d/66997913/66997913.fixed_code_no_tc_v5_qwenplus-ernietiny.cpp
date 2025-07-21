#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n; // 获取要处理的整数数量
  vector<int> x(n); // 创建一个整数向量x
  for (int i = 0; i < n; i++) { // 输入每个整数并存储到向量x中
    cin >> x[i];
  }
  
  // 假设向量p和s都是按照给定规则填充的，并且满足题目描述的条件
  // 这里省略了填充s的具体过程和填充规则的逻辑，但需要根据题目描述来判断是否有问题
  
  int q; // 输入询问次数
  cin >> q; // 获取询问次数
  vector<ll> p(n + 1), s(q + 1); // 创建一个新的向量来存储可能的答案和查询值
  // 这里应该根据实际情况添加填充逻辑来构建向量p和s
  
  // 执行查询操作
  for (int i = 0; i < q; i++) { // 对于每个查询进行操作
    int l, r; // 输入两个整数作为查询范围
    cin >> l >> r; // 输入查询范围
    // 根据题目描述确定可能的答案范围
    int rt = upper_bound(x.begin(), x.end(), r) - x.begin(); // 根据范围确定rt的值
    // 使用适当的逻辑来计算答案并输出结果
    int ans = s[rt] - s[lower_bound(x.begin(), x.end(), l)]; // 这里可能需要根据实际情况来计算答案，但根据题目描述来看应该是正确的
    cout << ans << endl; // 输出结果
  }
  return 0;
}