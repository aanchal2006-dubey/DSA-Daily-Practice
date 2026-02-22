/* This file checks if the parenthesis in a string are balanced or not

Input: s = "[{()}]"
Output: true

Input: s = "[()()]{}"
Output: true

Input: s = "([]"
Output: false*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isBalanced(string& s){
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else{
            if(!st.empty() && 
               ((st.top() == '(' && ch == ')') || 
                (st.top() == '{' && ch == '}') || 
                (st.top() == '[' && ch == ']'))){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
}

int main(){
    string s1 = "[{()}]";
    string s2 = "[()()]{}";
    string s3 = "([]";

    cout << isBalanced(s1) << endl; // Output: true
    cout << isBalanced(s2) << endl; // Output: true
    cout << isBalanced(s3) << endl; // Output: false

    return 0;
}