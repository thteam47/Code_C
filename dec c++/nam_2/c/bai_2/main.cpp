#include <iostream>
using namespace std;

template <typename type>
class sort_list
{
public:
    void input(type *arr,int &n)
    {
        cout <<"Nhap so phan tu cua mang: ";
        cin >> n;
        cout <<"Nhap cac phan tu cua mang: ";
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

    }
    void swap1(type &a, type &b)
    {
        type temp = a;
        a=b;
        b=temp;
    }

    void sort(type *arr,int n)
    {
        for (int i=0; i<n-1; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                if (arr[i]>arr[j])
                {
                    swap1(arr[i],arr[j]);
                }
            }
        }
    }
    void output(type *arr,int n)
    {
        cout <<endl;
        for (int i=0; i<n; i++)
        {
            cout<<arr[i] << "\t";
        }
    }
    void ok()
    {
        int n;
        type arr[100];
        input(arr,n);
        sort(arr,n);
        output(arr,n);
    }
};
int main(int argc, char** argv)
{
    sort_list<int> it;   //test kieu
    //sort_list<float> it;
    //sort_list<double> it;
    //sort_list<string> it;
    //sort_list<char> it;
    it.ok();
    return 0;
}

