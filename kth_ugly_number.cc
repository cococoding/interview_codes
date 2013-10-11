// Get kth ugly number, which is consist of 2,3,5

int GetKthUglyNum(int k) {
  int * u_arr = new int[k];
  int i2 = 0, i3=0, i5=0;
  u_arr[0] = 1;
  int max_ugly_num = 1;
  for (int i = 1; i < k; ++i) {
    while(u_arr[i2]*2 < max_ugly_num) i2++;
    while(u_arr[i3]*3 < max_ugly_num) i3++;
    while(u_arr[i5]*5 < max_ugly_num) ++i5;
    u_arr[i] = min(u_arr[i2]*2, u_arr[i3]*3, u_arr[i5]*5);
  }
  return u_arr[k-1];
}

int main() {
  GetKthUglyNum();
  return 0;
}
