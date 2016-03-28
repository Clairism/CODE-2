#include <iostream>
using namespace std;

//comments here

/*
 multiple lines
 of comments
 */

//custom functions
void greet(string name){
	cout << "Hi there " << name << "." << endl;	
}

int main() {

	//std::cout << "Exercising here!" << std::endl;
/*
	greet("Claire");
	return 0;
*/
	
/*
	int answer = 3;

	int answer;
	answer = 3;

	
	cout << "My friend is " << 20 << " years old." << endl;
	cout << "The answer to the life the universe and everything is " << answer << "."
<< endl;
	cout << "That number plus 1 is " << (answer+1) << "." << endl;
	return 0;
*/

	int counter = 0;
	cout << counter; 
	
	counter = counter ++;
	cout << counter; 
	
	cout << ++counter; //add 1 before printing out
	
	counter = 10; 
	cout << counter; 
	//counter = 2; 
	counter = counter + 2;
	cout << counter; 
	//counter = 8;
	counter = counter * 2;
	cout << counter;
	counter = counter + 1 * 2;
	cout << counter;
	return 0;
}
