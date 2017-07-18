#include <cstdio>
#include <cstring>

const int MAX = 50 + 1;
int con[MAX][MAX];
bool vis[MAX], finish;

void check(int now) {
  vis[now] = true;
  for (int i = 0; i < MAX; i++) {
    if (con[now][i] && !vis[i]) {
      check(i);
    }
  }
}

void print(int now) {
  for (int i = 0; i < MAX; i++) {
    if (con[now][i]) {
      con[now][i]--;
      con[i][now]--;
      print(i);
      printf("%d %d\n", i, now);
    }
  }
}

int main() {
  freopen("input.txt","r",stdin);
  int T, C = 1;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    int need = 0, rec[MAX] = {};
    memset(con, 0, sizeof(con));
    memset(vis, 0, sizeof(vis));
    while (N--) {
      int a, b;
      scanf("%d%d", &a, &b);
      need++;
      rec[a]++;
      rec[b]++;
      con[a][b]++;
      con[b][a]++;
    }
    bool solved = true;
    for (int i = 0; i < MAX; i++) {
      if (rec[i] & 1) {
        solved = false;
      }
    }
    printf("Case #%d\n", C++);
    if (solved) {
      for (int i = 0; i < MAX; i++) {
        if (rec[i]) {
          check(i);
          for (int j = 0; j < MAX; j++) {
            if (rec[j] && !vis[j]) {
              solved = false;
            }
          }
          if (solved) {
            print(i);
          }
          break;
        }
      }
    }
    if (!solved) {
      puts("some beads may be lost");
    }
    if (T) {
      puts("");
    }
  }
  return 0;
}
