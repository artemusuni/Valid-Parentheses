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
	Stack Index;	//WILL HOLD THE INDEXES FOR MISMATCHED!!!!
	bool result = true; // This will return the result of the operation
			    
	
	char ARROWS[256]; //THIS WILL HOLD THE ARROWS ^
	
	
	int error_count = 0;  // This will be counting the number of the mistake


	while(input[x] != '\0') {
		if(input[x] == '(' || input[x] == '[' || input[x] == '{') {
			Artem.push(input[x]);
			Index.push(static_cast<char>(x + '0'));	
		}
		if(input[x] == ')' || input[x] == ']' || input[x] == '}') {
			if(Artem.empty()) { 
				result = false;
				cout << ++error_count << ": Unmatched " << input[x] << " at position " << x << endl;
				ARROWS[x] = '^';	//HERE WE WILL ADD THE ARROW	
				
			}
			else {
				char index = Index.pop();	
				char brac = Artem.pop();
				if((brac == '(' && input[x] != ')') || (brac == '[' && input[x] != ']') || (brac == '{' && input[x] != '}') ) { 
					cout << ++error_count << " Mismatched " << brac << " at char " << index << " and " << input[x] << " at char " << x << endl;
					result = false;
					ARROWS[x] = '^'; //ADDS ARROW HERE
					//ARROWS[(int)index] = '^';
					

					ARROWS[index - '0'] = '^'; //STACK ARROW ADDED	I HAVE TO SOMEHOW ADD THIS ARROW, PROBLEM WITH TYPE_CAST
				
				}
			}
		
		}//else-if	
		x++;
	}//while-loop

	if(Artem.empty() == false) {
		result = false;
		
		int size = Index.size();

		for(int x = 0; x < size; x++) {
			error_count++;
			cout << error_count << ": Unmatched " << Artem.pop() << " at position " << Index.pop() << endl;
			ARROWS[x] = '^'; //ADDS ARROW HERE
		
		
		}
	 
	}
	cout << "\n" << input << endl;	//THIS SHOULD PRINT THE INPUT
					
	int arrows = x;
	//cout << "ARROWS: " << arrows << endl;	
	for(int x = 0; x < arrows; x++) {
		if(ARROWS[x] == '^') {
			cout << "^";
		
		}
		else {
			cout << " ";
		
		}
	
	}//HERE WILL BE THE ARROW PRINTING
	cout << endl;

	cout << "\nThere were " << error_count << " errors" << endl;


	return result;
}
//MAYBE IT IS MY FUNCTION?
int main() {
	char input[256];
	cout << "Enter expression: ";
	cin.getline(input, 256);
	//cin >> input;

	cout << match(input) << endl;

		
	
	



}
