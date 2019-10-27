long sum(int *gmu, long len);

int main() {
  int gmu[5] = {1,3,5,7,9};
  return sum(gmu, 5);
}

long sum(int *ary, long len) {
  long ans = 0;
  for(long i = 0; i < len; i++) {
    ans += ary[i];
  }
  return ans;
}
