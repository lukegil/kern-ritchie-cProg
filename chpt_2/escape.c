#include <stdio.h>

void escape(char s[], char t[], int len);

int main() 
{
	char t[] = "Hello	!";
	char s[sizeof(t)];

	escape(s, t, sizeof(t));
	printf("line : %s\n",s);	
	return 0;
}

void escape(char s[], char t[], int len) 
{
	int j = 0;

	for (int i = 0; i < len; ++i) {
		switch(t[i]) {
		case '\n':
			s[j] = '\\';
			s[j+=1] = 'n';
			break;
		case '\t':
			s[j] = '\\';
			s[j+=1] = 't';
			break;
		default:
			s[j] = t[i];
			break;
		}
		j += 1;
			}	
}
