#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<char> s;
    char str[]="{a+[b*c]+(d+e)+f}";
    for (int i=0;str[i]!='\0';i++){
        char ch=str[i];
        switch(ch){
            case '(':
            case '{':
            case '[':s.push(ch);break;
            case ')':if (!s.empty()&&s.top()=='('){
                        s.pop();
                        break;
                    } else {
                        cout<<"Not balanced";
                        return 0;
                    }
            case '}':if (!s.empty()&&s.top()=='{'){
                        s.pop();
                        break;
                    } else {
                        cout<<"Not balanced";
                        return 0;
                    }
            case ']':if (!s.empty()&&s.top()=='['){
                        s.pop();
                        break;
                    } else {
                        cout<<"Not balanced";
                        return 0;
                    }
            default: break;
        }
    }
    if (s.empty()) cout<<"Balanced";
        else cout<<"Not Balanced";
}
