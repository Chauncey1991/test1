#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int is_include_same_char(char * str) {
	if (str == NULL) {
		return -1;
	}

	int length;
	length = strlen(str);

	if (length == 0) {
		return 0;
	}

	int i , j;
	for(i =0; i < length; i++) {
		for(j = i + 1; j < length; j++) {
			if (str[j] == str[i]) {
				return 1;
			}
		}
	}

	return 0;
}

int lengthOfLongestSubstring(char * s) {
	if (s == NULL) {
		return 0;
	}

	int length;
	length = strlen(s);
	if(length == 0) {
		return 0;
	}

	int length1;
	length1 = length;
	char * s1 = NULL;

	s1 = (char *)malloc(length + 1);
	if(s1 == NULL) {
		return 0;
	}

	int flag = 0;

	while (length1 > 1) {
	
		int i;
		for(i = 0; i <= (length - length1); i++) {
			(void)memset(s1, 0, length + 1);
			(void)strncpy(s1, &(s[i]), length1);

			flag = is_include_same_char(s1);
			if(flag == 0) {
				return length1;
			}
		}

		length1--;
	}

	return length1;
}


int lengthOfLongestSubstring1(char * s){
	if (s == NULL) {
		printf("input error.\r\n");
		return -1;
	}

	int i, j, k;
	int length, result = 0, result1 = 0, result2 = 0;
	int flag = 0;
	length = strlen(s);

	for(i = 0; i < length; i++) {
		for(j = i; j < length; j++) {
			for (k = j + 1; k < length; k++) {
				if(s[k] == s[j]) {
					flag = 1;
					result = k - j;	
					if (result > result1) {
						result1 =result;
					}
					break;							
				}
			}
		}

		if(result1 > result2) {
			result2 = result1;
		}
	}

	if(flag == 0) {
		result2 = length;
	}
	
	return result2;
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