class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string x:tokens)
        {
            if(isdigit(x[0]) || (x[0] == '-' && x.size() > 1) ) st.push(stoi(x));

            else
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();

                if(x=="+") st.push(b+a);
                else if(x=="-") st.push(b-a);
                else if(x=="/") st.push(b/a);
                else if(x=="*") st.push(b*a);
            }
        }
        return st.top();
    }
};
