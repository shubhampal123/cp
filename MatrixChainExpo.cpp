///Matrix Multiplication-->If we have a set of variables
///and at each step all variables are recalculating from
///each other using linear function, we can use
///binary matrix exponentiation.
/// ans=(base)^n
/// X(n)=ans*X(0)

ll ans[2][2] ;
ans[0][0]=1 ;
ans[0][1]=0 ;
ans[1][0]=0 ;
ans[1][1]=1 ;
ll base[2][2] ;
void multiply(ll a[2][2],ll b[2][2])
{
    ll temp[2][2] ;
    for(ll i=0;i<2;i++)
    {
        for(ll j=0;j<2;j++)
        {
            temp[i][j]=0 ;
            for(ll k=0;k<2;k++)
            {
                temp[i][j]+=(a[i][k]*b[k][j])%mod ;
                temp[i][j]%=mod ;
            }
        }
    }
    for(ll i=0;i<2;i++)
    {
        for(ll j=0;j<2;j++)
        {
            ans[i][j]=temp[i][j]%mod ; ;
        }
    }
}
void power(ll j)
{
    if(j==0)
        return ;

    power(j/2) ;

    multiply(ans,ans) ;

    if(j%2==1)
    multiply(ans,base) ;
}
