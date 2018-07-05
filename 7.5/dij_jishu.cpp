#include<bits/stdc++.h>
using namespace std;
int n, m;
const int INF = 0x3f3f3f3f;
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x][y] = z;
    }
    dis[1] = 0;
    for(int i = 1; i <= n; i++){
        int Min = INf, u;
        for(int j = 1; j <= n; j++){
            if(Min > dis[j] && used[j] != 1){
                  Min = dis[j], u = j;
            }
        }
        used[u] = 1;
        for(int j = 1; j <= n; j++){
            if(dis[u] + g[u][y] < dis[j]){
                
            }
        }
    }
}