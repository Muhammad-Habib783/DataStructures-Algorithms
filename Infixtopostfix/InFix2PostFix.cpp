#include <iostream>
#include "CharStack.h"
#include <string>
using namespace std;
// This function determines if the character is one of the five operators (+, -, *, /, ^)
bool isOperator(char character) 
{
    if (character == '+' || character == '-' || character == '*' || character == '/' || character == '^') 
	{
        return true;
    }
    return false;
}	
// This function determines if character is one among the delimeters.
bool isDelimeter(char character) 
{
	if(character == ' ' || character == ',' || character == '\t'|| character == '.' ||
	   character == ',' || character == ';' || character == ':' || character == '?' ||
	   character == '>' || character == '<' || character == '?' || character == '&' || 
	   character == '%' || character == '$' || character == '@' || character == '!') 
	{
		return true;
	}
	return false;
}
// If the character is not an operator or a parenthesis then it is assumed to be an operand.
bool isOperand(char character) 
{
    if (!isOperator(character) && character != '(' && character != ')') 
	{
        return true;
    }
    return false;
}	
// Compare operator precedence of main operators (+, -, *, /, ^).
// Return 0 if op1 and op2 have equal precedence,
// -1 if op2 is less than op1, and 
// 1 if op2 is greater than op1.
int compareOperators(char op1, char op2) 
{
    if ( (op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-') ) 
	{ 
		return -1;	// op1 is higher than op2
	}
	else if ( (op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/') ) 
	{
		return 1;	// op2 is higher than op1
	}
	else if ( (op1 == '^') && (op2 == '*' || op2 == '/' || op2 == '+' || op2 == '-') ) 
	{ 
		return -1;	// op1 is higher than op2
	}
	else if ( (op1 == '*' || op1 == '/' || op1 == '+' || op1 == '-') && (op2 == '^')  ) 
	{ 
		return 1;	// op2 is higher than op1
	}
    
    return 0;		// op1 and op2 are of equal precedence
}
//===================================================================================
int main()
{
    // Empty character stack and blank postfix string.
    
    
    //----------------------------------------
    // 1. initialize an empty stack
    //----------------------------------------

    CharStack *opStack = new CharStack(100);
    string postFixString = "";
	
    char input[100];    //string input

 
    cout << " \n\n\tEnter an Infix expression: ";	   // Collect input
    cin.get(input, 100);	// input with white spaces

    //cin  >> input;		// input without white spaces
    
	  
    char *cPtr = input;  	// Get a pointer to our character array's base address.

    // Loop through the array (one character at a time) until we reach the end of the string.
    
    //----------------------------------------
    // 2. scan input string left to right
    //----------------------------------------
    
    while (*cPtr) 
	{
        
        // If it is an operator, pop operators off our stack until it is empty, 
		
        if (isDelimeter(*cPtr))			// if the token is a delimeter
		{ 
			cPtr++; 		// increment the pointer to the next token
			continue; 		// continue WHILE loop
		}
		
		//----------------------------------------
		// a. isOperand
		//----------------------------------------
		// If operand, add it to our postfix string.
		else if (isOperand(*cPtr)) 
		{ 
			postFixString += *cPtr; 
		}
		
		// Simply push all open parenthesis in to the stack
        // When we reach a closing one, start popping off operators 
		// until we encounter an opening parenthesis.
		
		//----------------------------------------
		// b. left parenthesis
		//----------------------------------------
        // If the token is left (open) parenthesis, push it on the stack.
		else if (*cPtr == '(') 
		{ 
			opStack->Push(*cPtr); 
		}
		
		//----------------------------------------
		// c. right parenthesis	 
		//----------------------------------------
		// If the token is right (close) parenthesis, 
        else if (*cPtr == ')') 
		{
            while (!opStack->isEmpty()) 
			{
                // if stack TOP is equal to left (open) paranthesis
				if (opStack->Top() == '(') 
				{ 
					// ignore left (open) parenthesis
					opStack->Pop(); 
					break; 
				}
                // append each operator to the output string
				postFixString += opStack->Top();
				// ignore right (close) parenthesis
                opStack->Pop();
            }
        }
        
		//----------------------------------------
        // d. isOperator
        //----------------------------------------
        else if (isOperator(*cPtr)) 
		{
            // store whatever is at the TOP of stack
			char t = opStack->Top();
			// if t is not equal to left (open) parenthesis and
			// precedence of t is greater than the token (cPtr)
			while (!opStack->isEmpty() && t != '(' && compareOperators(t,*cPtr) <= 0) 
			{
                postFixString += t;		// append operator of higher precedence to the output string
                opStack->Pop();
            }
            opStack->Push(*cPtr);		// now push the token (cPtr) on the stack
        }

        // Advance our pointer to next character in string.
        cPtr++;
    }

    // After the input expression has been ran through, 
	// if there is any remaining operators left on the stack
    // pop them off and put them onto the postfix string.
	//----------------------------------------
	// 3. input completely processed
	//----------------------------------------
    while (!opStack->isEmpty()) 
	{
        postFixString += opStack->Top();
        opStack->Pop();
    }
    // Show the postfix string at the end.
    cout << " \n\tThe Postfix expression is: " << postFixString << endl;
	opStack->~CharStack();   
	return 0;
}


