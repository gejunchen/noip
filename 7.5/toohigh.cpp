#include<bits/stdc++.h>
using namespace std;
int f[202][1000002], n;
char tmp[5];
int main()
{
	scanf("%d", &n);
    f[1][1] = 1;
    f[1][0] = 1;
    f[2][0] = 1;
    f[2][1] = 1;
    for(int j = 3; j <= n; j++){
         int i=0,x=0;
	while(i<f[j-1][0]||i<f[j-2][0])
	{
		i++;
        f[j][i]=f[j-1][i]+f[j-2][i]+x;
		x=f[j][i]/10;
		f[j][i]%=10;
	}
	if(x!=0) i++,f[j][i]=x;
    f[j][0] = i;
    }
    for(int j=f[n][0];j>=1;j--)
	  printf("%d",f[n][j]);
	return 0;
}