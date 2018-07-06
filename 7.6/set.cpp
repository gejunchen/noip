#include<bits/stdc++.h>
using namespace std;
int n, m;
pair<long long, int> b[200010];
set<pair<long long, int> > s;
int ans[200010];
struct note
{
    long long x, y;
    int id;
}a[200010];
bool cmp(note x, note y)
{
    if(x.x == y.x) return x.y < y.y;
    return x.x < y.x;
}
int main(){
    scanf("%d %d", &n, &m);
    long long lx, ly;
    scanf("%lld %lld", &lx, &ly);

    for(int i = 1; i < n; i++){
        long long x, y;
        scanf("%lld %lld", &x, &y);
        a[i].x = x - ly;
        a[i].y = y - lx;
        a[i].id = i;
        ly = y;
        lx = x;
    }
    sort(a+1, a+n, cmp);
    for(int i = 1; i <= m; i++){
        scanf("%lld", &b[i].first);
        b[i].second = i;
    }
    sort(b+1, b+1+m);
    int j = m;
    for(int i = n - 1; i >= 1; i--){
        while(j > 0 && a[i].x <= b[j].first){
            s.insert(b[j]);
            j--;
        }
        set<pair<long long, int> >::iterator it = s.upper_bound(make_pair(a[i].y + 1, 0));
        if(it == s.begin()){
            printf("No\n");
            return 0;
        }
        it--;
        ans[a[i].id] = it -> second;
        s.erase(it);
    }
    printf("Yes\n");
    for(int i = 1; i < n; i++){
        printf("%d ", ans[i]);
    }
    return 0;
}