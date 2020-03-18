
/*
PROG: floating
LANG: C
AUTH: dynmiWang
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MANTISSA_WIDTH 23
#define MAX_EXPONENT   127
bool res[100];
float f;
int   p;
int exp_;
int transform(float f)
{
    memset(res,0,sizeof(res));
    int e = MAX_EXPONENT;
    p=0;
    float cmp = pow(2,e);
    while(f<cmp)
    {
        e--;
        cmp = cmp / 2.0;
    }
    exp_ = e;
    
    while(f>0)
    {
        if(f>=cmp)
        {
            f = f - cmp;
            res[p++]=1;
        }
        else
        {
            res[p++]=0;
        }
        e--;
        cmp = cmp / 2.0;
    }
    return e;

}

int main()
{
    FILE *input  = fopen("floating.in","r"),
         *output = fopen("floating.out","w"); 
    int n;
    n=2;
    fscanf(input,"%d",&n);
    float f;
    for(int i=0;i<n;i++)
    {
        fscanf(input,"%f",&f);
        clock_t start =clock();
        if(f<0){
        fprintf(output,"-");
        f=0-f;
        }
        transform(f);
        fprintf(output,"%d.",res[0]);
        for(int i=1;i<MANTISSA_WIDTH+1;i++)
        {
            fprintf(output,"%d",res[i]);
        }
        fprintf(output," * 2^%d\n",exp_);
        clock_t end =clock();
        printf("%d     %d\n",i,end-start);
    }
    fclose(input);
    fclose(output);
    return 0;
}