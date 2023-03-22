/*Written By: Evan Owre, CSCE240, May 17th 2020
 *I have upheld the honor code and pledge all code in this assignment was written by me
 */
#include <fstream>
#include <iostream>
#include <cstddef>
#include <cmath>
using std::cout;
using std::endl;
using std::cin;

int main(int argc, char* argv[]){
	int input;
	int check=0;//if check equals 1 value is negative
	cin >> input;
	if(input <=0){
		++check;
		input = input *-1;//makes value positive to allow later code to work
	}
	int size = (1+log10(input));//figures number of digits in value
	if(check == 1)//if statement to place neg sign and parethesis
		cout << "-(";
	for(int i = size; i > 0; --i){//loop to sequentially print out correct numbers
		int exp = pow(10,i-1);// calculates power of 10
		int base = (input/exp)%10;// calculstes base
		int out = base*exp;//calculates value of place holder digit
		cout << out;// prints out number
		if(i>1)//adds plus sign for proper format
			cout << " + ";//note this loop dose not add a plus sign the last time it runs
	}
	if(check == 1)
		cout << ")";
	cout << endl;//adds final parathesis is the given number was negative
	//cout << endl;//note this line ensures if the program is called directly that the output is note on 
	//the same line as the command prompt. had to be removed as it caused answers to be incorrect when using
	//python3 test_decomposer.py
}
