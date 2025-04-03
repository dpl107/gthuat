ll fibo(ll n){
   ll f[100];
   f[0] = 0; f[1] = 1;
   for(ll i = 2; i <= 92; i++){
      f[i] = f[i - 1] + f[i - 2];
   }
   for(ll i = 0; i <= 92; i++){
      if(n == f[i]){
         return 1;
      }
   }
   return 0;
}
