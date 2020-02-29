#include "stdio.h"
#include "string.h"
#include "stdlib.h"

/* int lengthOfLongestSubstring(char * s){
    int i;
    int ret = 0;
    int tmp = 0;
    int table[128] = {0}; //char

    for(i = 0; i < strlen(s); i++){
        int index = (int)s[i];
        if(table[index] == 0){
            ++tmp;
        } else {
            ret = (ret >= tmp) ? ret : tmp;
            tmp = (tmp >= i + 1 - table[index]) ? i + 1 - table[index] : ++tmp;
        }
        table[index] = i + 1;
    }
    ret = (ret >= tmp) ? ret : tmp;
    return ret;
} */


int lengthOfLongestSubstring(char * s) {
    if(s == NULL) {
        return 0;
    }

    int i, j, k;
    int length = strlen(s);
    int length1 = 0, length2 = 0;
    int same_flag;

    if (length <= 1) {
        return length;
    }

    for(i = 0, j = 1; (i < length) && (j < length); i++) {
        for(j = 1; j < length; ) {
            same_flag = 0;
            // 判断第j个字母，是否与i到j-1个字符重复
            for (k = i; k < j; k++)
            {
                if(s[j] == s[k]) {
                    same_flag = 1;
                    break;
                }
            }

            //如果重复，使j回退一格，跳出循环，开始移动i
            if(same_flag == 1) {                
                j--;
                break;
            } else {
                length1 = k - i + 1;
                j++;
            } 
        }

        if(length1 > length2) {
            length2 = length1;
        }
    }

    return length2;
}

int main()
{


	printf("hello world\n");

	char s[1024] = {0};

	scanf("%s", s);
	
	int result = 0;
	result = lengthOfLongestSubstring(s);

	printf("The result is %d.\r\n", result);

	return 0;
}