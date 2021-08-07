class Solution {
public:
    string multiply(string num1, string num2) {
        string result = "";
        int m = num1.size();
        int n = num2.size();
       
        vector <int> res(m + n);
         
         for ( int i = m- 1 ; i >= 0 ;  i--) 
         {
             for ( int j = n- 1 ; j >= 0 ; j--)
             {
                 int mul = (num1[i]-'0')*(num2[j]-'0');   
                 int sum = mul + res[i+j+1];
                 res[i+j] += sum / 10;   
                 res[i+j+1] = sum % 10;   
             }
        }
        for (int num& : res) 
             if(!result.empty() || num!=0)
                 result += num +'0';     
        return result.empty()? "0" : result;
    }
};
