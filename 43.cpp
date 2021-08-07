class Solution {
public:
    string multiply(string num1, string num2) {
       string finalstring = "" ;
         int m = num1.size();
        int n = num2.size();
       
        vector <int> res(m + n);
         
         for ( int i = m- 1 ; i >= 0 ;  i--) {
             for ( int j = n- 1 ; j >= 0 ; j--) {
                 
                 int mul = (num1[i]- '0' ) * (num2[j]-  '0' );
                
                 int sum = mul + res[i+j+1];
                 
                 res[i+j] += sum/10;   
                 res[i+j+1] = sum% 10;   
            }
        }
         
        for (int num: res) {
            cout<<num<<" ";
             if(!finalstring.empty() || num!=0){
                 finalstring+=char(num +'0');   
             }
            
        }
        cout<<endl;
        return finalstring.empty()? "0" : finalstring;
    }
};
