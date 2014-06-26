#include <string.h>
#include <stdio.h>


/*
 * KMP 模式匹配算法 O(m+n),查找str2 在 str1中第pos位之后首次出现的位置
 */
int strstr_kmp(const char *str1,const char * str2, int pos)
{
	int i = pos;
	int j = 0;
	int ilen = strlen(str1);
	int jlen = strlen(str2);
	int next[jlen];

	printf("%d\n",ilen);
	printf("%d\n",jlen);

	int ni = 1;
	next[ni] = 0;
	int nj = 0;
	while(ni <= jlen){
		if(nj == 0 || *(str2+ni) == *(str2+nj)){
			ni++; nj++;
			if(*(str2+ni) != *(str2+nj))
				next[ni] = nj;
			else
				next[ni] = next[nj];
		}else
			nj = next[nj];
	};

	int tmp= 0;
	for(tmp=1;tmp<=jlen;tmp++){
		printf("%d,",next[tmp]);
	}

	while(i<= ilen && j<=jlen){
		if(j ==0 || *(str1+i) == *(str2+j)){
			i ++; j++;
		}else
			j = next[j];
	};
	if(j > jlen)
		return  i-jlen;
	else 
		return 0;
}

int main()
{
	char *s1 = "asdfgsdfhasjasdkasd\0";
	printf("%s\n",s1);
	char *s2 = "asdkasd\0";
	printf("%s\n",s2);
	printf("%d\n",strstr_kmp(s1,s2,0));
	return 0;
}

