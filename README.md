# CODE

以下為 Code Style 規範：

### 禁止同一行過度擁擠
例如變數宣告、條件判斷貨輸入輸出等，
多用一些空格，不要讓 Code 看你來很擠。

```cpp
for(int i = 0; i < n; i++) {
  int tmp = 0;
  cin >> n;
  if(n % 2 == 0) {
    cout << "Odd\n";
  } else {
    cout << "Even\n";
  }
}
```

### 左大括放同一行
諸如 if-else, for, while, struct 等，
左大括寫在同一行。

```cpp
struct Demo {
  string demo;
};

signed main() {
  for(int i = 0; i < n; i++) {
    int tmp = 0;
    if(n % 2 == 0) {
      cout << "Odd\n";
    } else {
      cout << "Even\n";
    }
  }
}
```

### 其餘待補充 點點點
