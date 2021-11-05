#include <iostream>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

template <class type>
void vector1(){
	vector<type> arr;
	type x;
	char isCheck;
	while (true){
		cout << "Nhap phan tu: ";
        fflush(stdin);
        cin >> x;
        arr.push_back(x);
        fflush(stdin);
        cout << "Ban co nhap nua khong (Y/N): ";
        cin >> isCheck;
        if (isCheck == 'n' || isCheck == 'N')
            break;
	}
	
	for (int i=0;i<arr.size();i++){
		cout <<arr.at(i)<<"\t";   
		}
}


int main(int argc, char** argv) {
	vector1<float>(); //test kieu
	//vector1<double>();
	//vector1<int>();
	return 0;
}
