#include<stdio.h>
#include<string.h>

int minPartitions(char* n) {
    int maxdigit=0;
    int len=strlen(n);
    for(int i=0; i<len; i++)
    {
        int digit= n[i] - '0';
        if (digit> maxdigit)
        {
            maxdigit=digit;
        }
        if(maxdigit ==9)
        {
            break;
        }
    }
    return maxdigit;
    
}
