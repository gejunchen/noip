#include<bits/stdc++.h>
using namespace std;
int n, k, ru[1000002], cnt;
priority_queue<int, vector<int>, greater<int> > q;
int anext[2000002], g[2000002], head[1000002];
priority_queue<int, vector<int>, greater<int> > ansq;
void addedge(int x, int y){
    cnt++;
    g[cnt] = y;
    anext[cnt] = head[x];
    head[x] = cnt;
}
int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 1; i < n; i++){
        int x , y;
        scanf("%d %d", &x, &y);
        addedge(y, x);
        addedge(x, y);
        ru[x]++;
        ru[y]++;
    }
    int ans_ned = k;
    for(int i = 1; i <= n; i++){
        if(ru[i] == 1){
            q.push(i);
        }
    }
    while(k--){
        int x = q.top();
        q.pop();
        for(int i = head[x]; i; i = anext[i]){
            ru[g[i]]--;
            if(ru[g[i]]==1) {
                q.push(g[i]);
            }
        }
        ansq.push(x);
    }
    for(int c = 1; c <= ans_ned; c++){
        printf("%d ", ansq.top());
        ansq.pop();
    }
}
