// encrypt()内还存在一个小问题没解决

#include <stdio.h>
#include <string.h>

void encrypt(char *string, size_t length)
{

    if(length<2){return;}
    char *left, *right;
    int p,k=length/2;
    char temp;
    for(p=0;p<k/2;p++)
    {
        temp=string[p];
        string[p]=string[k-p];
        string[k-p]=temp;
    }
    encrypt(string,k);
    size_t  b = length;
    for(p=k;p<(length-k)/2+k;p++)
    {
        b--;
        temp=string[p];
        string[p]=string[b];
        string[b]=temp;
    }
    encrypt(string+k,length-k);
}

size_t getstr(char *str, FILE *input ) {
    size_t length = 0;
    while( fread( str + length, 1, 1, input ) ) {
        length++;
    }
    return length;
}

int main()
{
    FILE *in = fopen("st.in","r"),
         *out= fopen("st.out","w");
    char *str;

    size_t len_ = getstr(str,in);
    fclose(in);
    encrypt(str,len_);
    fprintf(out,"%s",str);
    fclose(out);
    return 0;
}