 #include<iostream>
 #include<limits.h>
 using namespace std ;

 void findMax(int arr[],int n,int i,int& maxi)
 {
    if(i>=n)
    return ;

    // ek case solve karliya
    if(arr[i]>maxi)
    {
        maxi = arr[i];
    }
    // Baaki recursion sambhal lega 
    findMax(arr,n,i+1,maxi); 
 }

 void findMin(int arr[],int n,int i,int& mini)
 {
      if(i>=n)
      return;

      // ek case Solve karna padega
      if(arr[i]<mini)
      {
        mini = arr[i];
      }

      // Baaki recursion sambhal lega
      findMin(arr,n,i+1,mini);

 }
 int main()
 {

   int arr[] = {5,3,4,9,10};
   int size = sizeof(arr)/sizeof(arr[0]);
   int i=0;
   int maxi = INT_MIN;
   int mini = INT_MAX;
   findMax(arr,size,i,maxi);
   findMin(arr,size,i,mini);

   cout<<"Maximum is:"<<maxi<<endl;
   cout<<"Minimum is:"<<mini<<endl;
 }