// void merge(int arr[],int array[],int l,int mid, int r){
//     int a[an];
//     int b[bn];

//     for(int i=0; i<n; i++){
//         a[i]=arr[l+i];
//     }
//     for(int j=0; j<n; j++){
//         b[i]=array[mid+1+j];
//     }

//     int i=0; , int j=0 , int k=l;
//      while(i<an && j<bn){

//         if(a[i]<b[j]){
//             arr[k++]=a[i++];
//         }
//         else{
//             array[k++]=b[j++];
//         }
//     }
//     while(i<an){
//         arr[k++]=a[i++];
//     }
//     while(j<bn){
//         array[k++]=b[j++];
//     }

    

// }



// void mergesort(int arr[],int array[],int l , int r){
//     if(l>=r){
//         return;
//     }
//     int mid=(l+r)/2;
//     mergesort(arr,l,mid);
//     mergesort(array,mid+1,r);
//     merge(arr,array,l,mid,r);
// }