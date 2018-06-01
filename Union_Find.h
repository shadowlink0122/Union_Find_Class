#ifndef
#define UnionFind

class UnionFind{
private:
  int par[200000],rank[200000];

public:
  void init(int x){
    for(int i = 0;i < x;i++){
      par[i] = i;
      rank[i] = 0;
    }
  }

  int find(int x){
    if(par[x] == x)return x;
    return par[x] = find(par[x]);
  }

  void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y)return;
    if(rank[x] < rank[y])par[x] = y;
    else{
      par[y] = x;
      if(rank[x] == rank[y])rank[x]++;
    }
    return;
  }

  bool same(int x,int y){
    return find(x) == find(y);
  }
};

#endif /* UnionFind */