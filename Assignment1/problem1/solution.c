/*
PROG: floating
LANG: C
AUTH: dynmiWang
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define MANTISSA_WIDTH 23
#define MAX_EXPONENT   127
#define BITS_LEN       32

bool   res[BITS_LEN];
float  f;
short  EXPO_,p,n;

void transform(float f)
{
    memset(res,0,sizeof(res));
    int e = BITS_LEN;
    p=0;
    float cmp = pow(2,BITS_LEN);
    while(f<cmp)
    {
        e--;
        cmp = cmp / 2.0;
    }
    EXPO_ = e;
    
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
        cmp = cmp / 2.0;
    }

}

int main()
{
    FILE *input  = fopen("floating.in","r"),
         *output = fopen("floating.out","w"); 
    fscanf(input,"%hd",&n);
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
        fprintf(output," * 2^%d\n",EXPO_);
        clock_t end =clock();
        printf("%d     %ld\n",i,end-start);
    }
    fclose(input);
    fclose(output);
    return 0;
}