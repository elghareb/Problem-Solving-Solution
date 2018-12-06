#include<stdio.h>
#include<string.h>
int main(){
    int i,works,c = 1,n,a,b;
    char s[1000001];
    while(gets(s) && strlen(s)!=0){
        scanf("%d", &n);
        printf("Case %d:\n", c++);
        while(n--){
            works = 1;
            scanf("%d%d",&a,&b);
            if(a==b){
                printf("Yes\n");
                continue;
            }
            if(a>b){
                for(i=b; i<=a; ++i){
                    if(s[i]!=s[a]){
                        works = 0;
                        printf("No\n");
                        break;
                    }
                }
            }else{
                for(i=a; i<=b; ++i){
                    if(s[i]!=s[a]){
                        works = 0;
                        printf("No\n");
                        break;
                    }
                }
            }
            if(works){
                printf("Yes\n");
            }
        }
        getchar();
    }
    return 0;
}
