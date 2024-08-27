struct trie {
  int nex[100000][26], cnt;
  // nex表示节点，第一维表示它的唯一id，第二维表示它下方的边（最多26【a-z】条边）
  // cnt是当前节点数，在insert函数中添加时会为每个节点赋一个唯一id
  bool exist[100000];  // 该结点结尾的字符串是否存在，改为int可以记录相同的字符串有多少

  void insert(char *s, int l) {  // 插入字符串
    int p = 0;
    for (int i = 0; i < l; i++) {
      int c = s[i] - 'a';
      if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
      p = nex[p][c];
    }
    exist[p] = 1;
  }

  bool find(char *s, int l) {  // 查找字符串
    int p = 0;
    for (int i = 0; i < l; i++) {
      int c = s[i] - 'a';
      if (!nex[p][c]) return 0;
      p = nex[p][c];
    }
    return exist[p];
  }
};