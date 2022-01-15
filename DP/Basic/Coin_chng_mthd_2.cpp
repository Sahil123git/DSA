class Solution {//https://leetcode.com/problems/coin-change/
public:
    
    int fnd_cn_chng(vector<int>& coins,int n,int amt,vector<vector<int>>& dp_arr)//Unbounded KnapSack Method
    {
        if(amt!=0 && n==0)//this is base when amt is not 0 but iterated full coins arr
        {
            return -1;
        }
        
        else if(amt==0)//if amt is 0 return directly 0 it will get inc in prev call
        {
            // cout<<"d";
            return 0;
        }
        else if(dp_arr[n][amt]!=-2)//if already computed this case
        {
            return dp_arr[n][amt];
        }
        else if(amt>=coins[n-1])//chk if any prev call is returng -1
        {
            int cnd1=fnd_cn_chng(coins,n,amt-coins[n-1],dp_arr),cnd2=fnd_cn_chng(coins,n-1,amt,dp_arr);
            //add 1 only in cnd1(1st case) becoz we subtracted 1 ele from this cnd1 only
            if(cnd1==-1 && cnd2==-1){return dp_arr[n][amt]=-1;}//if both condn are returning -1
            else if(cnd1!=-1 && cnd2!=-1){return dp_arr[n][amt]= min(1+cnd1,cnd2);}//take smallest one from these 2
            else if(cnd1!=-1){return dp_arr[n][amt]=1+cnd1;}
            else{return dp_arr[n][amt]=cnd2;}
        }
        else//chk if prev case is not returng -1
        {
            int cnd1=(fnd_cn_chng(coins,n-1,amt,dp_arr));//case when we didn't add any ele
            if(cnd1==-1){return dp_arr[n][amt]=-1;}
            else{return dp_arr[n][amt]=(fnd_cn_chng(coins,n-1,amt,dp_arr));}
        }
    }
    int coinChange(vector<int>& coins, int amt) {
        vector<vector<int>> dp_arr(coins.size()+1,vector<int>(amt+1,-2));//initially all ele of dp_arr initialized with -2
        return fnd_cn_chng(coins,coins.size(),amt,dp_arr);
    }
};