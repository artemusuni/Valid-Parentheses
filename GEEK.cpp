#include <iostream>

using namespace std;

struct Stack {
	private:	
		char array[256];
		int top = 0;

	public:
		void push(char x) {
			array[top++] = x;
	
		}
	
		char pop() {
			return array[--top];
	
		}

		bool empty() {
			return (top == 0);
	
		}
	
		int size() {
			return top;	
	
		}
	
		char peek() {
			return array[top - 1];
	
		}
};


bool match(char input[]) {
	int x = 0;
	Stack Artem;
	bool result = true; // This will return the result of the operation
	
	while(input[x] != 0) {
		//cout << Artem.size() << endl;
		if(input[x] == '(' || input[x] == '[' || input[x] == '{') {
			Artem.push(input[x]);//
	                //cout << "pushed " << input[x] << endl;	
		}
		else if(input[x] == ')' || input[x] == ']' || input[x] == '}') {
			if(Artem.empty()) {
				//cout << "returning false at position " << x << endl;
				return false;
			}
			char brac = Artem.pop();
			//cout << "popped " << brac <<endl;
			if((brac == '(' && input[x] != ')') || (brac == '[' && input[x] != ']') || (brac == '{' && input[x] != '}') ) { // HERE IS THE PROBLEM!!
				result = false;		
				//cout << "set to false at  position " << x << endl;
				
			}
		
		}//else-if	
		x++;
	}//while-loopa
	 //cout << "stack len at end: " << Artem.size() << endl;
	if(Artem.empty() == false) {
		result = false;
	  
	
	
	}


	return result;
}
//MAYBE IT IS MY FUNCTION?
int main() {
	char input[256];
	cout << "Enter expression: ";
	cin >> input;

	cout << match(input) << endl;

		
	
	



}
