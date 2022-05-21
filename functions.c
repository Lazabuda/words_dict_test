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
		fprintf(dict, "%d\n", 0);
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
	int value;
	printf("Let's see how smart are you\n");
        printf("How many words do you want to train today?\n");
	scanf("%d\n", &value);
	for (int i; i<value; i++)
	{
		FILE *dict;
        	dict = fopen("dict.txt", "r");
        	char buffer_word[50];
        	char buffer_mean[150];
        	char answer[50];
        	fgets(buffer_word, 50, dict);
        	fgets(buffer_mean, 150, dict);
        	printf("%s", buffer_mean);
        	printf("Enter the word: ");
        	scanf("%s", answer);
        	if (strcmp (buffer_word, answer) == 0)
        	{
                	printf("RIGHT!");
        	}
        	else
        	{
                	printf("WRONG!");
        	}
	}
}

int look_dict()
{
	char check[10];
	printf("Let's see, what we have in dictionary\n");
	FILE *dict;
	dict = fopen("dict.txt", "r");
	char buffer_word[50];
	char buffer_mean[150];
	int knowledge_level;
	char buffer_check[49];
	//for (int i = 0; i < 30; i++)
	while (1)
	{
		printf("=====================================================================\n");
		fgets(buffer_word, 49, dict);
		if (strcmp (buffer_word, buffer_check) == 0)
                {
                        printf("The end of the dictionary. Thanks for your attention. You are smart and good!");
                        break;
                }
		fgets(buffer_mean, 149, dict);
		fscanf(dict, "%d", &knowledge_level);
		printf("%s", buffer_word);
		printf("%s", buffer_mean);
		strcpy(buffer_check, buffer_word);
		printf("====================================================================="); 
	}
}

