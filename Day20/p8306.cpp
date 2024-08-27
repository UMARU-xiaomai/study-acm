#include<bits/stdc++.h>

using namespace std;

struct trie {
  int nex[100000][26], cnt;
  int exist[100000];  // 该结点结尾的字符串是否存在
  int ans;
  void insert(string s, int l) {  // 插入字符串
    int p = 0;
    for (int i = 0; i < l; i++) {
      int c = s[i] - 'a';
      if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
      p = nex[p][c];
    }
    exist[p] += 1;
  }

  int find(string s, int l) {  // 查找字符串
    int p = 0;
    for (int i = 0; i < l; i++) {
      int c = s[i] - 'a';
      if (!nex[p][c]) return 0;
      p = nex[p][c];
    }
    return exist[p];
  }

  bool get_pre(string s, int l) {  // 查找字符串
    int p = 0;
    for (int i = 0; i < l; i++) {
      int c = s[i] - 'a';
      if (!nex[p][c]) return 0;
      p = nex[p][c];
    }
    
    // 开始查找后面的字符串有多少
    ans = 0;
    dfs(0);
    return ans;
  }
  void dfs(int p)
  {
    for (int i = 0;i<26;i++)
    {
        if(exist[p])
            ans+=exist[p];
        if (nex[p][i])
           dfs(nex[p][i]);
    }
  }
};

trie m_trie;
int t;
vector<int> ans;
int main()
{
    cin>>t;
    for(int i = 0;i<t;i++)
    {
        int n,q;
        cin>>n>>q;

        m_trie = trie();
        for(int j=0;j<n;j++)
        {
            string tmp;
            cin>>tmp;
            m_trie.insert(tmp,tmp.length());
        }
        for(int j=0;j<n;j++)
        {
            string tmp;
            cin>>tmp;
          ans.push_back(m_trie.get_pre(tmp,tmp.length()));

        }
    }

    for (int i = 0;i<ans.size();i++)
    {
      cout<<ans[i]<<endl;
    }
}