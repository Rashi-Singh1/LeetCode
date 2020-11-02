class Solution {
public:
    string intToRoman(int num) {
        int value[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int size = 13;
        string ans;
        if(num <= 0) return ans;
        for(int i = size - 1; i >= 0; i--){
            if(num/value[i]){
                for(int j = 0; j < num/value[i]; j++){
                    ans+=sym[i];
                }
                num%=value[i];
            }
        }
        return ans;
    }
};