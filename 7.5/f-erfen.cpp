#include<bits/stdc++.h>
using namespace std;
int n, k;
float a[10002];
int main()
{
    float r = 0;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%f", &a[i]);
        if(a[i] > r) r = a[i];
    }
    float l = 0;
    while(r - l >= 0.0001){
        float mid = (l + r)/2;
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sum += a[i]/mid;
        }
     //   printf("%f %d\n", mid, sum);
        if(sum > k) l = mid + 1;
        else r = mid;
    }
    int ans = r * 1000;
    float ans2;
    if(ans % 1000 >= 5) ans2 = ans / 1000 + 0.01;
    else ans2 = ans / 1000;
    printf("%0.2f", ans2);
    return 0;
}