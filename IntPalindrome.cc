
// Judge whether an Int number is palindrome using 
// Judge the int number from two ends,

bool JudgePalin(int a) {
  if (a < 0) return false;
  int d = 1;
  while(a/d >= 10) {
    d*=10;
  }
  while(d >= 10) {
    if (a%10 != a/d) return false;
    a = (a % d) / 10;
    d/=100;
  }
  return true;
}

int main() {
  JudgePalin(1221);
  return 0;
}
