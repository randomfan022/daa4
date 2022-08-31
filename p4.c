#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include<time.h> 
int binary_search(int a[],int low,int high,int key) 
{ 
 int mid; 
 while(low<=high) 
 { 
 mid=(low+high)/2; 
 if(a[mid]==key) 
 return mid+1; 
 else if(a[mid]<key) 
 low=mid+1; 
 else 
 high=mid-1;
 } 
 return -1;
} 
void bubble_sort(int a[],int n) 
{ 
 int i,j,temp; 
 for(i=0;i<n;i++) 
 { 
 for(j=0;j<n-i-1;j++) 
 { 
 if(a[j]>a[j+1]) 
 { 
 temp=a[j]; 
 a[j]=a[j+1]; 
 a[j+1]=temp; 
 } 
 } 
 } 
} 
int main(){ 
 int n,a[1000],i,key,pos; 
 clock_t start,end; 
 double clk; 
 printf("ENTER THE NO. OF PRODUCT TYPES\n"); 
 scanf("%d",&n); 
 
 for(i=0;i<n;i++) 
 a[i]=rand()%1000; 
 
 bubble_sort(a,n); 
 
 printf("THE SORTED PRODUCT IDs ARE:\n"); 
 for(i=0;i<n;i++) 
 printf("%d\t",a[i]); 
 printf("\n"); 
 
 
 printf("ENTER ID TO SEARCH\n"); 
 scanf("%d",&key); 
 
 start=clock(); 
 pos=binary_search(a,0,n,key); 
 end=clock(); 
 clk=(double)(end-start)/CLOCKS_PER_SEC; 
 
 if(pos==-1)
 printf("SEARCH KEY NOT FOUND\n"); 
 else 
 printf("SEARCH KEY FOUND AT %d\n",pos); 
 
 printf("TIME TAKEN FOR EXECUTION: %f\n",clk); 
}
