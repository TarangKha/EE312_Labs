#include <stdio.h>
void generateAllMatchedParens(int n);
void generateAllPalindromicDecompositions(char str[]);

int main() {
	generateAllMatchedParens(-1);
	generateAllMatchedParens(0);
	generateAllMatchedParens(1);
	generateAllMatchedParens(2);
	generateAllMatchedParens(3);
	generateAllMatchedParens(4);
	generateAllMatchedParens(5);
	generateAllPalindromicDecompositions("abcdef");
	generateAllPalindromicDecompositions("abadef");
	generateAllPalindromicDecompositions("abaded");
	generateAllPalindromicDecompositions("abaaba");
	generateAllPalindromicDecompositions("#@!!@#");
	generateAllPalindromicDecompositions("Toyota atoyoT");
	generateAllPalindromicDecompositions("Toyota atoyot");
	generateAllPalindromicDecompositions(" a a ");
	generateAllPalindromicDecompositions("");
	generateAllPalindromicDecompositions("a");
	generateAllPalindromicDecompositions("ab");
	generateAllPalindromicDecompositions("abc");
	generateAllPalindromicDecompositions("abbcd");
	generateAllPalindromicDecompositions("abcba");
	generateAllPalindromicDecompositions("abc");
	generateAllPalindromicDecompositions("abadefe");
}
