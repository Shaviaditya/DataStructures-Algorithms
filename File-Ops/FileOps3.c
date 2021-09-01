#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SZ  10000
typedef long long int lli;
void revstr(char *str1)
{
    static int i, len, temp;
    len = strlen(str1);

    if (i < len / 2)
    {
        temp = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = temp;
        i++;
        revstr(str1); 
    }
}
void add(char *n1,char *n2){
    //printf("%s",n1);
    //printf("%s", n2);
    char c1[strlen(n1) + strlen(n2)+2];
    if(strlen(n1)==strlen(n2)){
        int carry = 0,g=0;
        for (int i = strlen(n1)-1;i>=0;i--,g++){
            int val = ((int)(n1[i]) + (int)(n2[i]) - 96) + carry;
            if(val>=10){
                char ch = (char)((val%10)+48);
                strcat(c1,&ch);
                carry = 1;
            }
            else {
                char ch = (char)((val % 10) + 48);
                strcat(c1, &ch);
                carry = 0;
            }
        }
        char ch1 = carry+'0';
        strcat(c1,&ch1);
        revstr(c1);
        strcpy(&c1[strlen(c1)-1], &c1[strlen(c1)]);
        printf("%s\n", c1);
    }

}
int main(){
    char *at[2];
    FILE *fp = fopen("data.txt","r");
    if(!fp){
        printf("No such file exists!");
    } else {
        int i=0;
        char *a;
        char buffer[MAX_SZ];
        while(fgets(buffer,MAX_SZ,fp)){
            if(buffer==NULL){
                continue;
            }
            char *value = buffer;
            a = value;
            at[i] = (char *)malloc(MAX_SZ + 1);
            strcpy(at[i], a);
            i++;
        }
    }
    char ch = '0';
    int l1 = strlen(at[0]),l2 = strlen(at[1]); 
    if (l1 < l2){
        while (l1 < l2)
        {
            at[0] = at[0] + ch;
            l1++;
        }
        //revstr(at[0]);
    }
    strcat(at[1], &ch,5);
    /*
    if (l2 < l1){
        while (l2<l1)
        {
            //at[1] = at[1] + ch;
            strcat(at[1], &ch);
            l2++;
            printf("%s",at[1]);
        }
        //revstr(at[1]);
    }
    //printf("%s",at[0]);
    //printf("%s",at[1]);
    //add(at[0],at[1]);
    */
    return 0;
}