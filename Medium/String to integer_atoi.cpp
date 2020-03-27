class Solution {
public:
    int myAtoi(string str) {
        int k = -1;
        //remove initial white spaces
        for(int i = 0; i < str.size(); i++){
            if(str[i] == ' ') k++;
            else break;
        }
        if(k+1 == str.size()) return 0;
        else str = str.substr(k+1);
        
        //if initially non digit, return 0
        bool neg = false;
        k = 1;
        if(str[0] == '-') neg = true;
        else if(str[0] != '+') k = 0;
        for(int i = k; i < str.size() ; i++){
            int temp = (int)(str[i]-'0');
            if(0 <= temp && temp <= 9) break;
            else return 0;
        }
        
        //actual conversion of the digit part
        long long int ans = 0;
        for(int i = k; i < str.size(); i++){
            int temp = (int)(str[i]-'0');
            if(!(0 <= temp && temp <= 9)){
                if(ans > INT_MAX){
                    if(neg) return INT_MIN;
                    else return INT_MAX;
                }
                else{
                    if(neg) return -1 * (int) ans;
                    else return (int) ans;
                }
            }
            else{
                ans = (long long int )(ans*10ll + (long long int)temp); 
            }
            if(ans > INT_MAX){
                if(neg) return INT_MIN;
                else return INT_MAX;
            }
        }
        if(ans > INT_MAX){
            if(neg) return INT_MIN;
            else return INT_MAX;
        }
        else{
            if(neg) return -1 * (int) ans;
            else return (int) ans;
        }
    }
};