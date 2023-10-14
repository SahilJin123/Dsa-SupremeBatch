 #include<iostream>
 using namespace std ;

 void printarr(int arr[],int n,int i)
 {
    if(i>=n)
    return ;

    // ek case solve karliya
    cout<<arr[i]<<" ";
    // Baaki recursion sambhal lega 
    printarr(arr,n,i+1); 
 }
 int main()
 {

   int arr[] = {5,3,4,9,10};
   int size = sizeof(arr)/sizeof(arr[0]);
   int i=0;
   printarr(arr,size,i);

//    cout<<"Ans is:"<<ans;
 }