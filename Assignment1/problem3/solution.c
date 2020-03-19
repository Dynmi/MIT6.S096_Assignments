#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 300

typedef struct Matrix_s {
    size_t R,C;
    int *index;
} Matrix;


Matrix* allocate_matrix(size_t R, size_t C) {
    Matrix *matrix = malloc( sizeof(Matrix) );
    matrix->R = R;
    matrix->C = C;
    matrix->index = malloc( R * C * sizeof(int) );
    return matrix;
}

void destroy_matrix (Matrix *matrix) {
    free(matrix->index);
    free(matrix);
}

Matrix* io_matrix(FILE *file, bool io ,Matrix *matrix)
{
    int R,C;
    if(io==0)
    {
        Matrix *matrix = malloc(sizeof(Matrix));
        fscanf(file,"%zu %zu", &R, &C);
        matrix->index = malloc( R * C * sizeof(int) ); 
    }
    else
    {
        fprintf(file,"%zu %zu",&R,&C);
    }
    matrix->R = R;
    matrix->C = C;
    for(size_t r =0; r<matrix->R;r++)
    {
        for(size_t c=0;c<matrix->C;c++)
        {
            if(io==0)
            {
                fscanf(file,"%ls",&matrix->index[c + r * matrix->C]);
            }
            else
            {
                fprintf(file,"%ls",&matrix->index[c + r * matrix->C]);
            }
            
        }
    }

    return matrix;
}

Matrix* product_matrix(Matrix *a,Matrix *b)
{
    Matrix *prod = allocate_matrix(a->R,b->R);
    for(size_t r=0;r<prod->R;r++)
    {
        for(size_t c=0;c<prod->C;c++)
        {
            prod->index[c + r * prod->C]=0;
            for(size_t i=0;i<a->C;i++)
            {
                prod->index[c + r * prod->C] += a->index[c + i * a->C] * b->index[i + c * b->C];
            }
        }
    }
    return prod;
}

int main() {
    FILE *input = fopen( "matrix2.in","r");

    Matrix *a = io_matrix(input,0, NULL);
    Matrix *b = io_matrix(input,0, NULL);
    
    fclose(input);

    Matrix *c = product_matrix(a,b);
    FILE *output = fopen("matrix2.out","w");
    io_matrix(output,1,c);
    fclose(output);

    destroy_matrix(a);
    destroy_matrix(b);
    destroy_matrix(c);

    return 0;
}