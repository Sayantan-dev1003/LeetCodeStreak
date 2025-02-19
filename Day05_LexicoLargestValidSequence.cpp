class Solution {
    bool recFunc(int countIdx,vector<int>&res, vector<bool>&isNumUsed,int n){
        if(countIdx==res.size()){
               return true;
        }
        if(res[countIdx]!=0){
            return recFunc(countIdx+1, res, isNumUsed,n);
        }
        for(int num = n; num>0; num--){
            if(isNumUsed[num]==true)continue;
            isNumUsed[num] = true;
            if(num==1){
                res[countIdx]=num;
                if(recFunc(countIdx+1,res,isNumUsed,n)){
                    return true;
                }
            }
            else if(countIdx+num<res.size() && res[countIdx+num]==0){
                res[countIdx]= num;
                res[countIdx+num]=num;
                if(recFunc(countIdx+1,res,isNumUsed,n)){
                    return true;
                }
                res[countIdx+num]=0;
            }
            res[countIdx]=0;
            isNumUsed[num]=false;
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int>res(2*n-1,0);
        vector<bool>isNumUsed(n+1,false);
        recFunc(0,res,isNumUsed,n);
        return res;
    }
};
