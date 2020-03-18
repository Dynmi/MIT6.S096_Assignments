/*
 
 AUTH: DynmiWang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 300

typedef struct Matrix_s {
    size_t R, C;
    int    index[MAXN][MAXN];
} Matrix;


int main()
{
    Matrix A,B,C;
    FILE   *input = fopen("matrix.in","r"),
           *output = fopen("matrix.out","w");
    short    i,j;
    memset(C.index,0,sizeof(C.index));
    
    // Read matrix A,B 
    fscanf(input,"%ld %ld",&A.R,&A.C);
    for(i = 0;i < A.R;i++)
    {
        for(j = 0;j<A.C;j++)
        {
            fscanf(input,"%d ",&A.index[i][j]);
        }
    }
    fscanf(input,"%ld %ld",&B.R,&B.C);
    for(i = 0;i < B.R;i++)
    {
        for(j = 0;j<B.C;j++)
        {
            fscanf(input,"%d ",&B.index[i][j]);
        }
    }

    // calculate matrix C, and write 
    fprintf(output,"%ld %ld\n",A.R,B.C);
    for(i=0;i<A.R;i++)
    {
        for(j=0;j<B.C;j++)
        {
            for(short p=0;p<A.C;p++)
            {
                C.index[i][j] += A.index[i][p] * B.index[p][j];
            }
            fprintf(output,"%d ",C.index[i][j]);
        }
        fprintf(output,"\n");
    }


    return 0;
}