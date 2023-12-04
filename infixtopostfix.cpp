#include <iostream>
#include <stack>
#include <string>
#include <cctype> // To use isdigit function
using namespace std;

// Function to check if a character is an operand
bool isOperand(char c) {
  return isdigit(c); 							// Check if the character is a digit
}

// Function to convert postfix expression to infix expression
string postfixToInfix(string postfix) {
  stack<string> s; 							   	// Stack to store sub-expressions
  for (int i = 0, n= postfix.length(); i < n ; i++) {
    char c = postfix[i];						 // Current character
   
    if (isOperand(c)) { 						// If the character is an operand
      string op; 								// Temporary string to store the operand
      while (isOperand(c)) { 					// Append the digits to the operand string
        op = c;
        s.push(op); 							// Push the operand string to the stack change string to integer
        i++;
        c = postfix[i];
      }
      i--; 									// Decrement i to avoid skipping a character
   
    }
    else { 									// If the character is an operator
      string op1 = s.top(); s.pop(); 		// Pop two sub-expressions from the stack
      string op2 = s.top(); s.pop();
      s.push("(" + op2 + c + op1 + ")");	 // Concatenate them with the operator and parentheses, and push back to the stack
	  	
    }
   
  }
  
  return s.top(); 							// Return the final infix expression
}

// Main function
int main() {
  string postfix; 										// String to store the postfix expression
  cout << "Enter a postfix expression: ";
  cin >> postfix; 										// Read the postfix expression from the user
  string infix = postfixToInfix(postfix);				 // Convert the postfix expression to infix expression
  cout << "The infix expression is: " << infix << endl; // Print the infix expression
  return 0;
}
