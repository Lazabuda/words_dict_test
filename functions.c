#include"functions.h"

int add_word_func()
{

	while (1)
	{
		getchar();
		char answer;
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
		scanf("%c", &answer);
		if (answer == 'n') break;
	}
}


int test_func()
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

