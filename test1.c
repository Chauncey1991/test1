#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int lengthOfLongestSubstring(char * s){
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
}

int main()
{


	printf("hello world\n");

	char s[1024] = {0};

	scanf("%s", s);
	
	int result = 0;
	result = lengthOfLongestSubstring(s);

//	result = is_include_same_char(s);

	printf("The result is %d.\r\n", result);

	return 0;
}