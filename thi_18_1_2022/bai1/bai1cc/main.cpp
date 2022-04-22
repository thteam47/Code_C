#include <iostream>

using namespace std;

void nhap(int a[], int &n) {
    do {
        cout<<("Nhap n: ");
        cin>>n;
    } while(n<2||n>99);
    for(int i=0; i<n; i++) {
        cout<<"a["<<i<<"]: ";
        cin>>a[i];
    }
}

void xuat(int a[], int n) {
    for(int i=0; i<n; i++) {
        cout<<"  "<<a[i];
    }
}

void xuatBo3(int a[], int n) {
    for(int i=0; i<n-2; i++) {
        for(int j=i+1; j<n-1; j++) {
            for(int k=j+1; k<n; k++) {
                cout<<"  "<<a[i]<<"  "<<a[j]<<"  "<<a[k];
                cout<<"\n";
            }
        }
    }
}
int main() {
    int a[100];
    int n;
    nhap(a,n);
    cout<<"\nMang vua nhap: "<<endl;
    xuat(a,n);
    cout<<"\n";
    xuatBo3(a,n);
    return 0;
}
