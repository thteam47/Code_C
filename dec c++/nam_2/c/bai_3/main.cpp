#include <iostream>
#include <string.h>
using namespace std;
const int max_size =100;
int size = -1;

bool isFull(){
	return (size == max_size);
}
bool isEmpty(){
	return (size == -1);
}
template <typename type>
class STACK{
	public:
	void push(type stack[], type data){
	 if(!isFull()){
	 	size++;
	 	stack[size] = data;
	 }
	 else cout << "Stack da day. Dung lai"<<endl;
}

void pop(type stack[], type &data){
		data = stack[size];
		size--;
}

void input_stack(type stack[]){
	type x;
	char isCheck;
	while (true){
		cout <<"Nhap phan tu: ";
		fflush(stdin);
		cin >> x;
		push(stack, x);
		cout << "Ban co nhap nua khong (Y/N): ";
		cin >> isCheck;
		if (isCheck == 'n' || isCheck == 'N')
		break;
	}	
}

void output_stack(type stack[]){
	type data;
	while(!isEmpty()){
		pop(stack, data);
		cout<<data<<"\t";
	}
}
void ok(){
	type stack[max_size];    //test hàm
	input_stack(stack);
	output_stack(stack);
}
};
int main(int argc, char** argv) {
	STACK <string> stack;   //test kieu
	//STACK <int> stack;
	//STACK <double> stack;
	//STACK <float> stack;
	//STACK <char> stack;
	stack.ok();		 
	return 0;
}
