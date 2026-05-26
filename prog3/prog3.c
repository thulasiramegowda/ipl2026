#include<stdio.h>
 void printBits(int n);
 int countSetBits(int n);

 int main(){
    int n;
    printf("enter number:");
    scanf("%d",&n);

    printf("Bits:");
    printBits(n);
    int num = countSetBits(n);
    printf("Number of 1 bits :%d\n",num);
    return 0;
}

void printBits(int n){
    int i;
    for(i=31;i<n;i--){
        int bit = (n >> i) & 1;
        printf("%d",bit);
    }
    printf("\n");
}

int countSetBits(int n){
    int count =0;
    for(int i=31;i<n;i--){
        int bit = (n>>1) & 1;
        if(bit == 1){
            count++;
        }
    }
    return count;
}