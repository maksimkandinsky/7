#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int* f(int *p,int *q, int m,int n){
int j,k,t,l;
int* s;
s = (int*)malloc((m+n)*sizeof(int));
for(j = 0;j<m+n;j++){
    if (j<m){
            t = p[j];
        s[j]=t;
    }else{
    t=q[j-m];
    s[j]=t;
    }
}
for(j =m;j<m+n;j++){
        for(k = j-m;k<j;k++){
        if(s[j]<s[k]){
             t = s[j];
                for(l = j;l>k;l--){
                s[l]=s[l-1];
               }
                s[k]=t;
            }
        }
}
return s;
}
int main()
{
 setlocale(LC_ALL,"Rus");
   int m,n,i,k,x;
   int *p,*q,*s;
printf("¬ведите кол-во элементов в первом массиве,во 2,элементы первого,элементы второго\n");
   scanf("%d%d",&m,&n);
   p = (int*)malloc(m*sizeof(int));
   q = (int*)malloc(n*sizeof(int));
   for(i = 0;i<m;i++){
    scanf("%d",&p[i]);
   }
    for(i = 0;i<n;i++){
    scanf("%d",&q[i]);
   }
   s =f(p,q,m,n);
   for(i=0;i<m+n;i++){
   printf("%d ",s[i]);
   }
    return 0;
}
