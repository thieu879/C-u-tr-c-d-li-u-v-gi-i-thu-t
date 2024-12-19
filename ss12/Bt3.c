#include<stdio.h>
void findSymmetry(int arr[], int size)
{
    int i;
    for (i = 0; i < size/2; i++)
    {
        if (arr[i] == arr[size - i - 1])
        {
            printf("c?p d?i x?ng: (%d, %d) \n", arr[i], arr[size - i - 1]);
        }else{
        	printf("Không có ph?n t? d?i x?ng trong m?ng.");
        	break;
		}
    }
}
int main()
{
    int n, i;
    printf("Nh?p n:");
    scanf("%d", &n);
    int arr[n];
    printf("Nh?p các ph?n t? vào m?ng: \n");
    for (i = 0; i < n; i++)
    {
    	printf("arr[%d]= ", i);
        scanf("%d", &arr[i]);
    }
    findSymmetry(arr, n);
    return 0;
}
