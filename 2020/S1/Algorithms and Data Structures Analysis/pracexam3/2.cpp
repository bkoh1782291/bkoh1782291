#include <iostream>
using namespace std;
 
//预处理
template <class T>
int Getlength(T &a){
    return (sizeof(a)/sizeof(a[0]));
}
 
void Siftdown(int a[],int length ,int i){
 
    if (2*i > length)return;
    int j=2*i;
    while(j+1 <= length ){

        if (a[i-1]<a[j-1]&&a[i-1]>=a[j])
        {
            int temp=a[j-1];
            a[j-1]=a[i-1];
            a[i-1]=temp;
            i=j;
            j=2*i;
        }
        else if (a[i-1]>=a[j-1]&&a[i-1]<a[j])
        {
            int temp=a[j];
            a[j]=a[i-1];
            a[i-1]=temp;
            i=j+1;
            j=2*i;
        }
        else if (a[i-1]<a[j-1]&&a[i-1]<a[j])
        {
            if (a[j-1]<a[j])
            {
                int temp=a[j];
                a[j]=a[i-1];
                a[i-1]=temp;
                i=j+1;
                j=2*i;
            }
            else{
                int temp=a[j-1];
                a[j-1]=a[i-1];
                a[i-1]=temp;
                i=j;
                j=2*i;
            }
        }else {
            return;
        }
    }
    if (j==length&&a[i-1]<a[j-1])
    {
        int temp=a[j-1];
        a[j-1]=a[i-1];
        a[i-1]=temp;
    }
}
 
 
//改进方法
void Siftdown2(int a[],int length,int i){
    if (2*i > length)return;
    bool done=false;
    int j=2*i;
    do{
        if (j+1<=length && a[j-1]<a[j])j++;
        if (a[j-1] > a[i-1])
        {
            int temp=a[j-1];
            a[j-1]=a[i-1];
            a[i-1]=temp;
            i=j;
            j=2*i;
        }else done=true;
    }while(j <= length && !done);
}
 
int main(int argc, char const *argv[])
{
    int a[]={20,5,3,12,2,5,6,7,23,5};
    int length=Getlength(a);
    Siftdown2(a,length,2);
    for (int i = 0; i < length; ++i)
    {
        cout<<a[i]<<" ";
    }
 
    cout << endl;
 
 
    //system("pause");
    return 0;
}