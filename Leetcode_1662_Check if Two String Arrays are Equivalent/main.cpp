/*

1662. Check If Two String Arrays are Equivalent

Descriptioin:
	Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

	A string is represented by an array if the array elements concatenated in order forms the string.

	给你两个字符串数组 word1 和 word2 。如果两个数组表示的字符串相同，返回 true ；否则，返回 false 。

	数组表示的字符串 是由数组中的所有元素 按顺序 连接形成的字符串。


Example 1:

	Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
	Output: true
	Explanation:
	word1 represents string "ab" + "c" -> "abc"
	word2 represents string "a" + "bc" -> "abc"
	The strings are the same, so return true.

Example 2:

	Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
	Output: false

Example 3:

	Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
	Output: true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-two-string-arrays-are-equivalent
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include<stdio.h>

bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size)
{
	int m = 0;
	int n = 0;
	int i = 0;
	int j = 0;

	/* 遍历两个字符串数组 */
	while (i < word1Size && j < word2Size)
	{
		/* 遍历单个字符串 */
		while (word1[i][m] != '\0' && word2[j][n] != '\0')
		{
			if (word1[i][m] == word2[j][n])
			{
				m++;
				n++;
			}
			else
			{
				return false;
			}
		}
		
		if (word1[i][m] == '\0')	/* 字符串word1中一个字符串遍历结束，开始遍历下一个字符串 */
		{
			i++;
			m = 0;
		}
		
		if (word2[j][n] == '\0')	/* 字符串word2中一个字符串遍历结束，开始遍历下一个字符串 */
		{
			j++;
			n = 0;
		}
	}

	/* 判断两个字符串数组都遍历结束 */
	if (i == word1Size && j == word2Size)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

int main()
{
	char* word1[] = { "abc", "d","defg" };
	char* word2[] = { "abcddefg"};

	if (arrayStringsAreEqual(word1, 3, word2, 1))
	{
		printf_s("true\n");
	}
	else
	{
		printf_s("false\n");
	}

	return 0;
}