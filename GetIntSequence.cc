// 和为N的连续正数序列
// 1. init two int i from 1, j from 2, sum = i+j
// 2. if sum < n, ++j, and update sum until sum > n or sum == n,
// then ++i and update sum, because if sum > n there is no result begin from i

int GetIntSequence(int n) {
  if (n < = 0)
    return -1;
  int sum = 3;    
  for (int i = 1, j = 2; i < j;) {
    if (sum == n) {
      printf("[%d, %d]", i, j);
      sum -= i++;
    } else if (sum > n) {
      sum -= i++;
    } else {
      sum += ++j;
    }
  }
  return 0;
}

int main() {
  GetIntSequence(n);
  return 0;
}
