class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1;
        stack<char>t1;
        string a;
        string b;
        for(int i=0;i<s.size();i++){   // insertion in stack
            if(s[i]=='#'){
                if(!s1.empty())
                  s1.pop();
            }
            else{
                s1.push(s[i]);
            }
        }
        for(int i=0;i<t.size();i++){    //insertion in stack
            if(t[i]=='#'){
                if(!t1.empty())
                  t1.pop();
            }
            else{
                t1.push(t[i]);
            }
        }
        while(!s1.empty()){       // add element from s1 stack to string a
            a.push_back(s1.top());
            s1.pop();
        }
        while(!t1.empty()){       // add element from t1 stack to string b
            b.push_back(t1.top());
            t1.pop();
        }
        return a == b;
    }
};