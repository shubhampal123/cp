 ll z[N] ;
   z[0]=0 ;
   ll l=0,r=0 ;
   for(ll i=1;i<N;i++)
   {
       if(i>r)
       {
           l=i ;
           r=i ;
           while(r<N&&a[r]==a[r-l])
            r++ ;

           z[i]=r-l ;
           r-- ;
       }
       else
       {
           ll k=i-l ;
           if(z[k]<r-i+1)
            z[i]=z[k] ;
           else
           {
               l=i ;
               while(r<N&&a[r]==a[r-l])
                r++ ;

               z[i]=r-l ;
               r-- ;
           }
       }
   }
