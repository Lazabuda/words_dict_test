#include"functions.h"
/*:
struct dict
{
	char word[50];
	char meaning[150];
	int knowledge_level;
}
*/

int add_word_func() // Fuction to add words (1)
{

	while (1)
	{
		char word[50];
		char meaning[150];
		getchar(); // used for swallow \n
		char answer;
		printf("Enter new word, lowercase\n");
		fgets(word, 48, stdin); // read the string with word from input
		FILE *dict;
		dict = fopen("dict.txt", "a"); // open file (or create if file does't exest)
		fprintf(dict, "%s", word); // write word in file
		printf("Enter meaning of new word\n");
		fgets(meaning, 120, stdin); // read the string with meaning of the word
		fprintf(dict, "%s", meaning); // write the meaning of the word to file
		fprintf(dict, "%d\n", 0); // write variable, which shows how good we knoe this word
		fclose(dict); // close the file
		printf("You have just added:\n");
		int t = strcspn(word, "\n"); // return the number of last character before "\n"
                for (int a = 0; a < t; a++) // print word without "\n"
                	printf("%c", word[a]);
                printf(" - %s", meaning);
		printf("\n");
		printf("Do you want to enter another word? y/n\n");
		scanf("%c", &answer);
		if (answer == 'n') break;
	}
}


int test_func()
{
	int value;
	int i = 0;
	printf("Let's see how smart are you\n");
        printf("How many words do you want to train today?\n");
	scanf("%d", &value);
	getchar();
	FILE *dict;
	dict = fopen("dict.txt", "r");
	for (i; i<=value; i++)
	{
		if (i == value) break;
		char buffer_word[50];
        	char buffer_mean[150];
		int knowledge_level;
        	char answer[50];
		fgets(buffer_word, 50, dict);
        	fgets(buffer_mean, 150, dict);
		fscanf(dict, "%d\n", &knowledge_level);
		//printf("buffer_word - %s", buffer_word);
		//printf("buffer_mean - %s", buffer_mean);
        	//printf("knowledge_level - %d\n", knowledge_level);
		//printf("i = %d\n", i);
		printf("%s", buffer_mean);
        	printf("Enter the word: ");
        	fgets(answer, 49, stdin);
        	if (strcmp (buffer_word, answer) == 0)
        	{
                	printf("RIGHT!\n");
			int t = strcspn(buffer_word, "\n");
			for (int a = 0; a < t; a++)
				printf("%c", buffer_word[a]);
			printf(" - %s", answer);
        	}
        	else
        	{
                	printf("WRONG!\n");
			printf("The right word - %s", buffer_word);
			printf("You have input - %s", answer);
        	}
		printf("--------------------------------------------------------\n");
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
	while (!feof(dict))
	{
		printf("=====================================================================\n");
		fgets(buffer_word, 49, dict);
		fgets(buffer_mean, 149, dict);
		fscanf(dict, "%d\n", &knowledge_level);
		printf("%s", buffer_word);
		printf("%s", buffer_mean);
		printf("%d\n", knowledge_level); 
	}
	printf("The end of the dictionary. Thanks for your attention. You are smart and good!\n");
}

