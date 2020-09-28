ll  power(ll  i,ll  j)
{
    if(j==0)
    return 1 ;
    ll t=power(i,j/2)%mod ;
    if(j%2==0)
    return (t%mod*t%mod)%mod ;
    else
    return ((t%mod*t%mod)%mod*(i%mod)%mod)%mod ;
}
