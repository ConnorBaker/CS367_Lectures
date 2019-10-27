int sum(int *gmu, int len);

int main() {
  int gmu[5] = {1,3,5,7,9};
  return sum(gmu, 5);
}

int sum(int *ary, int len) {
  int ans = 0;
  for(int i = 0; i < len; i++) {
    ans += ary[i];
  }
  return ans;
}
