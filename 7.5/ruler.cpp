#include<bits/stdc++.h>
using namespace std;
int n, m, a[100002], ans = 9999999;
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
       scanf("%d", &a[i]);
    int i = 1, j = 0, sum = 0;
    bool flag = 0;
    while(1)
    {
        printf("%d %d\n", j, sum);
        while(sum < m){
            j++;
            sum+=a[j];
            
            if(j > n) {
                flag = 1;
                break;
            }
        }
        if(flag) break;
        do
        {
            printf("%d %d\n", i, sum);
            ans = min(ans, j - i + 1);
            sum-=a[i];          
            i++
        }while(sum >= m);
    }
    printf("%d", ans);
}
