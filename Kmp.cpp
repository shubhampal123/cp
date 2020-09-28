ll lps[N] ;
ll i=1 ;
ll len=0 ;
lps[len]=0 ;
while(i<N)
{
   if(a[len]==a[i])
   {
       len++ ;
       lps[i]=len ;
       i++ ;
   }
   else
   {
       if(len!=0)
       {
           len=lps[len-1] ;
       }
       else
       {
           lps[i]=0 ;
           i++ ;
       }
   }
}
