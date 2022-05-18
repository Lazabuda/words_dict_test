#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char c;
	char word[50];
	char meaning[150];
	char answ;

	printf("###_____WORDS_TEST_ver1_____###\n");
	printf("1 - Enter new word\n");
	printf("2 - Start testing\n");
	printf("3 - Look at the dictionary\n");
	if ((c=getchar()) == '1');
	{
		while (1)
		{
			getchar();
			printf("Enter new word, lowercase\n");
			fgets(word, 48, stdin);
			FILE *dict;
			dict = fopen("dict.txt", "a");
			fprintf(dict, "%s", word);
			fclose(dict);
			dict = fopen("dict.txt", "a");
			printf("Enter meaning of new word\n");
			fgets(meaning, 120, stdin);
			fprintf(dict, "%s", meaning);
			fclose(dict);
			printf("You have just added:\n");
			printf("%s -  %s", word, meaning);
			printf("\n");
			printf("Do you want to enter another word? y/n\n");
			scanf("%c", &answ);
			if (answ == 'n') break;
		}
		
	}
	if ((c = getchar()) == '2')
	{
		printf("Let's see how smart are you\n");
		FILE *dict;
		dict = fopen("dict.txt", "r");
		char buffer1[50];
		char buffer2[150];
		char answer[50];
		fgets(buffer1, 50, dict);
		fgets(buffer2, 150, dict);
		printf("%s", buffer2);
		printf("Enter the word: ");
		scanf("%s", answer);
		if (answer == buffer1)
		{
			printf("RIGHT!");
		}
		else
		{
			printf("WRONG!");
		}

	}
	if ((c = getchar()) == '3')
	{
		printf("Current dictionary:\n");
	}
	return 0;
}
/*
int write_to_file(char *s)
{
	FILE *dict;
	dict = fopen("dict.txt", "w");
	fprintf(dict, "%s", *s);
	fclose(dict);
	return 0;
}
*/
