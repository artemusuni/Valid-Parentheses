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
	
	
	int error_count = 0;  // This will be counting the number of the mistake


	while(input[x] != '\0') {
		if(input[x] == '(' || input[x] == '[' || input[x] == '{') {
			Artem.push(input[x]);
			Index.push(static_cast<char>(x + '0'));// WILL PUSH X TO INDEX NOT FINISHED!!!!	
		}
		if(input[x] == ')' || input[x] == ']' || input[x] == '}') {
			if(Artem.empty()) { 
				result = false;
				cout << ++error_count << ": Unmatched " << input[x] << " at position " << x << endl;		//IMPLEMENTING MISMATCH NOT DONE!!!!!
				//return false; //WILL HAVE TO REMOVE THIS SO THE LOOP CONTINUES
			}
			else {
				char index = Index.pop();// WILL BE POPING FROM INDEX TO GET IT FOR PRINTING POSITION NOT FINISHED!!!	
				char brac = Artem.pop();	//ADD AND ELSE branch, that will only execute if it is not empty!!!!
				if((brac == '(' && input[x] != ')') || (brac == '[' && input[x] != ']') || (brac == '{' && input[x] != '}') ) { 
					cout << ++error_count << " Mismatched " << brac << " at char " << index << " and " << input[x] << " at char " << x << endl;           //HAVE TO ADD INDEX AND INPUT AND X 
					result = false;		//HERE ALSO		
				
				}
			}
		
		}//else-if	
		x++;
	}//while-loop
	//cout << "Size of Artem is: " << Artem.size() << endl;
	//cout << "Size of Index is: " << Index.size() << endl;

	if(Artem.empty() == false) {	// NEED A FOR LOOP : for(int x = 0; x < Artem.size(); x++);  IT WILL ONLY BE A UNMATCH
		result = false;
		
		int size = Index.size();

		for(int x =0; x < size; x++) {	//loop for the brackets that are left!!  NOT DONE
			error_count++;
			cout << error_count << ": Unmatched " << Artem.pop() << " at position " << Index.pop() << endl;
				
		
		
		}
	 
	}
	cout << "There were " << error_count << " errors" << endl;	//THIS WILL THE TOTAL COUNT OF MISTAKES


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
