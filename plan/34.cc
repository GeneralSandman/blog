class Solution {
public:
    /**
     * 获得两个整形二进制表达位数不同的数量
     * 
     * @param m 整数m
     * @param n 整数n
     * @return 整型
     */
    int countBitDiff(int m, int n) {
        int res=0;
        int dif=m^n;
        while(dif){
            if(dif&1)
                res++;
            dif>>=1;
        }
        return res;
    }
};