class Solution {
public:
    bool isNumber(string s) {
        int current=0;
        
        for(auto&c:s)
        {
            if(c=='+'||c=='-')
            {
                switch(current)
                {
                    case 0:
                        current=1;
                        break;
                    case 5:
                        current=6;
                        break;
                    default:
                        return false;
                }
            }
            else if(c=='.')
            {
                switch(current)
                {
                    case 0:
                    case 1:
                        current=4;
                        break;
                    case 2:
                        current=3;
                        break;
                    default:
                        return false;
                }
            }
            else if(c=='E'||c=='e')
            {
                switch(current)
                {
                    case 2:
                    case 3:
                    case 8:
                        current=5;
                        break;
                    default:
                        return false;
                }
            }
            else if(c>='0'&&c<='9')
            {
                switch(current)
                {
                    case 0:
                    case 1:
                        current=2;
                        break;
                    case 2:
                        current=2;
                        break;
                    case 3:
                        current=3;
                        break;
                    case 4:
                        current=8;
                        break;
                    case 5:
                    case 6:
                    case 7:
                        current=7;
                        break;
                    case 8:
                        current=8;
                        break;
                    default:
                        return false;
                }
            }
            else
                return false;
        }
        if(current==4||current==5||current==6)
            return false;
        return true;
    }
};
