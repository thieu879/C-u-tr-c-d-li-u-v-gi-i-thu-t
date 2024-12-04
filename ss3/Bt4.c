#include <stdio.h>
#include <string.h>
void reverseString(char str[],int start, int end){
    if(start>=end){
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseString(str,start+1,end -1);
}
int main(){
    char str[100];
    printf("Nh?p chu?i:");
    scanf("%[^\n]", str);
    reverseString(str,0 ,strlen(str) - 1);
    printf("chu?i d?o ngu?c: %s\n", str);
    return 0;
}
