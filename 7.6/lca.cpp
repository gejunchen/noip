#include<bits/stdc++.h>
using namespace std;
int cnt, n, m, nxt[100002], head[100002], g[100002];
int dep[100002], sum[100002], fa[100002][22];
void addedge(int x, int y)
{
    cnt++;
    g[cnt] = y;
    nxt[cnt] = head[x];
    head[x] = cnt;
}
int dfs(int x, int father, int dept)
{
    int res = 0;
    fa[x][0] = father;
    dep[x] = dept;
    for(int i = head[x]; i; i = nxt[i])
    {
        if(g[i] != father){
            res += dfs(g[i], x, dept);
        }
    }
    sum[x] = res;
    return res;
}
void init()
{
    for(int i = 1; i <= 20; i++)
        for(int j = 1; j <= n; j++)
           fa[j][i] = fa[fa[j][i-1]][i-1];
}
int main()
{
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        int x, y;
        addedge(x, y);
        addedge(y, x);
    }
    int ccc = dfs(1, 0, 0);
    scanf("%d", &m);
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        if(dep[x] < dep[y]) swap(x, y);
        for(int i = 19; i >= 0; i--){
            if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
        }
        for(int i = 19; i >= 0; i--){
            if(fa[x][i] != )
        }
    }
}