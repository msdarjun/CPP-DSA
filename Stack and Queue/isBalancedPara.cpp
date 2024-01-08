#include <bits/stdc++.h>
using namespace std;

bool isPar (string s) {
    stack<char>st;
    for (int i=0; i<s.size(); i++) {
        if (st.empty()) {
            st.push(s[i]);
        } else if ((st.top() == '(' ) && (s[i] == ')')  || (st.top() == '[' ) && (s[i] == ']') || (st.top() == '{' ) && (s[i] == '}') ) {
            st.pop();
        }
        else {
            st.push(s[i]);
        }
    }
    if (st.empty ()) {
        return true;
    } else return false;
}

int main() {

    string s = "([]){";
    if (isPar(s))
    cout << "true " << endl;
    else 
    cout << "false " << endl;

    return 0;
}