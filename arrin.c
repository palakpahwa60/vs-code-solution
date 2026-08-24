
#include<stdio.h>
void display(int arr[],int n){
    int i ;
    printf("\narray elements are :\n");
    for (i=0 ;i<n;i++){
        printf("%d ",arr[i]);
    }
    }

int insertBeginning(int arr[] ,int n){
    int i ,element ;
    
    printf("Element to be inseted ");
    scanf("%d",&element);
    for (i = n ; i>0 ; i--){
        arr[i] = arr[i-1];
        arr[0] = element;
        return n+1;
        }
}

int insertpos(int arr[] , int n ){
    int i ,pos,element ;
    printf("Enter the position ");
    scanf("%d",&pos);
     if(pos <1 || pos >n+1) {
        printf("Invalid position:");}

     
    printf("Enter the element:");
    scanf("%d ",&element);

    arr[pos-1] = element ;
    for (i = n ; i>0 ; i--){
        arr[i] = arr[i-1];
        return n+1;

    }
}
int insertend(int arr[] , int n ){
    int i ,element ;
    printf("Enter the element:");
    scanf("%d",&element);

    arr[n] = element;
    return n+1;}




int main() {
    int arr[100],n,i,choice;
    printf("enter the number of elements: \n");
    scanf("%d",&n);
    printf("Enter elements :");


    for(i = 0; i<n ; i++){
        scanf("%d",&arr[i]);

    }

printf("\n1 insert element at the beginning");
printf("\n2 insert element at the pos");
printf("\n3 insert element at the end");
printf("\nEnter choice:");
scanf("%d",&choice);

switch(choice)
{
    case 1:
    n=insertBeginning(arr,n);
    break;
    case 2:
    n=insertpos(arr,n);
    break;
    case 3:
    n = insertend(arr,n);
    break;
    default:
    printf("invalid choice");
}

display(arr, n);
return 0;
}
