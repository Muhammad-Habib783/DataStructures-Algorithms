#include<iostream>
#include"CharStack2.h"
#include<string>
#include<algorithm>
using namespace std;
bool isOperator(char character)
 {
    if(character=='+'||character=='-'||character=='*'||character=='/'||character=='^')
     {
        return true;
    }
    return false;
}
bool isDelimeter(char character)
 {
    if(character==' '||character==','||character=='\t'||character=='.'||
       character==','||character==';'||character==':'||character=='?'||
       character=='>'||character=='<'||character=='?'||character=='&'|| 
       character=='%'||character=='$'||character=='@'||character=='!') 
       {
        return true;
    }
    return false;
}
bool isOperand(char character) 
{
    if (!isOperator(character)&&character!='('&&character!=')')
     {
        return true;
    }
    return false;
}
int compareOperators(char op1,char op2) 
{
    if((op1=='*'||op1=='/')&&(op2=='+'||op2=='-')) 
    {
        return -1;
    }
    else if((op1=='+'||op1=='-')&&(op2=='*'||op2=='/'))
     {
        return 1;
    }
    else if((op1=='^')&&(op2=='*'||op2=='/'||op2=='+'||op2=='-')) 
    {
        return -1;
    }
    else if((op1=='*'||op1=='/'||op1=='+'||op1=='-')&&(op2=='^')) 
    {
        return 1;
    }
    return 0;
}
int main()
 {
    CharStack *opStack=new CharStack(100);
    string prefixString="";
    char input[100];

    cout<<" \n    Enter an Infix expression:   ";
    cin.get(input,100);

    string infix=input;

    // here we  reverse the infix string
    reverse(infix.begin(),infix.end());

    // here we  swap brackets
    for(int i=0;i<infix.length();i++) 
    {
        if(infix[i]=='(')
         infix[i]=')';
        else if(infix[i]==')') 
        infix[i]='(';
    }

    char *cPtr=&infix[0];

    while(*cPtr) 
    {
        if(isDelimeter(*cPtr)) 
        {
            cPtr++;
            continue;
        }
        else if(isOperand(*cPtr))
         {
            prefixString=prefixString+*cPtr;
        }
        else if(*cPtr=='(') 
        {
            opStack->Push(*cPtr);
        }
        else if(*cPtr==')') 
        {
            while(!opStack->isEmpty())
             {
                if(opStack->Top()=='(') 
                {
                    opStack->Pop();
                    break;
                }
                prefixString=prefixString+opStack->Top();
                opStack->Pop();
            }
        }
        else if(isOperator(*cPtr)) 
        {
            char t=opStack->Top();
            while(!opStack->isEmpty()&&t!='('&&compareOperators(t,*cPtr)<=0)
             {
                prefixString=prefixString+t;
                opStack->Pop();
            }
            opStack->Push(*cPtr);
        }
        cPtr++;
    }

    while (!opStack->isEmpty())
     {
        prefixString=prefixString+opStack->Top();
        opStack->Pop();
    }

    // here we reverse the result to get final prefix
    reverse(prefixString.begin(),prefixString.end());

    cout<<" \n    The Prefix expression is: "<<prefixString;

    opStack->~CharStack();

    return 0;
}