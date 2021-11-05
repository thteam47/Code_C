#include <iostream>
using namespace std;

template <typename type>
class nhap
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
        output(arr,n);
    }

};
int main(int argc, char** argv)
{
    nhap<int> it;  //test kieu
    //nhap<float> it;
    //nhap<double> it;
    //nhap<char> it;
    //nhap<string> it;
    it.ok();
    return 0;
}

