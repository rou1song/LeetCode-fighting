class Solution {
public:
    int atoi(const char *str) {
        bool flag = false;
        int result = 0;
        
        while(*str == ' ')                //处理开头的空格
            str++;
            
        if(*str == '-'){                  //处理第一个有效字符为符号的时候，若没有符号位，则默认flag = false，
            flag = true;
            str++;
        } 
        else if(*str == '+'){
            flag = false;
            str++;
        }
        while(isdigit(*str)){               //依次读入数字，直到非法字符为止； 先预判result * 10 之后会不会溢出
            if( result > INT_MAX/10 || (result == INT_MAX/10 && (*str - '0') > INT_MAX%10) ) {
                if (flag == true) 
                    return INT_MIN;
                else 
                    return INT_MAX;
            }
            result = result * 10 + (*str - '0');
            str++;
        }
        if(flag == false)
            return result;
        else
            return -result;
//      return (flag == false) ? result : -result;
    }
};
