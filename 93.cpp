class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> r;
        string t;
        int dot=0;
        helper(s,0,dot,t,r);
        return r;
    }
    
    void helper(string& s, int start, int& dot, string& t, vector<string>& r)
    {
        int remaining=s.length()-start;
        int expected=(3-dot+1)*3;
        if(remaining>expected)
            return;
        
        int n=s.length();
        if(start==n&&dot-1==3)
        {
            r.push_back(t);
            return;
        }
        if(s[start]=='0')
        {
            t.push_back('0');
            if(dot<3)
                t.push_back('.');
            dot++;
            helper(s, start+1, dot, t, r);
            dot--;
            if(dot<3) 
                t.pop_back();
            t.pop_back();
        }
        else if(s[start]=='1')
        {
            t.push_back('1');
            if(dot<3)
                t.push_back('.');
            dot++;
            helper(s, start+1, dot, t, r);
            dot--;
            if(dot<3) 
                t.pop_back();
            t.pop_back();
            
            if(start+1<n)
            {
                t.push_back('1');
                t.push_back(s[start+1]);
                if(dot<3)
                    t.push_back('.');
                dot++;
                helper(s, start+2, dot, t, r);
                dot--;
                if(dot<3) 
                    t.pop_back();
                t.pop_back();
                t.pop_back();
            }
            if(start+2<n)
            {
                t.push_back('1');
                t.push_back(s[start+1]);
                t.push_back(s[start+2]);
                if(dot<3)
                    t.push_back('.');
                dot++;
                helper(s, start+3, dot, t, r);
                dot--;
                if(dot<3) 
                    t.pop_back();
                t.pop_back();
                t.pop_back();
                t.pop_back();
            }
        }
        else if(s[start]=='2')
        {
            t.push_back('2');
            if(dot<3)
                t.push_back('.');
            dot++;
            helper(s, start+1, dot, t, r);
            dot--;
            if(dot<3) 
                t.pop_back();
            t.pop_back();
            
            if(start+1<n)
            {
                t.push_back('2');
                t.push_back(s[start+1]);
                if(dot<3)
                    t.push_back('.');
                dot++;
                helper(s, start+2, dot, t, r);
                dot--;
                if(dot<3) 
                    t.pop_back();
                t.pop_back();
                t.pop_back();
            }
            if(start+2<n&&(s[start+1]<'5'||s[start+1]=='5'&&s[start+2]<='5'))
            {
                t.push_back('2');
                t.push_back(s[start+1]);
                t.push_back(s[start+2]);
                if(dot<3)
                    t.push_back('.');
                dot++;
                helper(s, start+3, dot, t, r);
                dot--;
                if(dot<3) 
                    t.pop_back();
                t.pop_back();
                t.pop_back();
                t.pop_back();
            }            
        }
        else // '3'~'9'
        {
            t.push_back(s[start]);
            if(dot<3)
                t.push_back('.');
            dot++;
            helper(s, start+1, dot, t, r);
            dot--;
            if(dot<3) 
                t.pop_back();
            t.pop_back();
            
            if(start+1<n)
            {
                t.push_back(s[start]);
                t.push_back(s[start+1]);
                if(dot<3)
                    t.push_back('.');
                dot++;
                helper(s, start+2, dot, t, r);
                dot--;
                if(dot<3) 
                    t.pop_back();
                t.pop_back();
                t.pop_back();
            }            
        }
        
    }
};
