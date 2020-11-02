class Solution {
public:
    void moveZeroes(vector<int>& A) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> zeroes;
        for(int i = 0 ; i  <A.size(); i++){
            if(A[i] == 0) zeroes.push_back(i);
        }
        int point = 0;
        for(int i = 0 ; i < A.size(); i++){
            if(A[i] == 0) continue;
            while(point < zeroes.size() && zeroes[point] < i) point++;
            if(point > zeroes.size()) return;
            A[i-point] = A[i];
        }
        int k = A.size()-1;
        for(int i = 0 ; i < zeroes.size(); i++) A[k--] = 0;
    }
};