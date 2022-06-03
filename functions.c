#include"functions.h"

typedef struct
{
	char *word;
	char *meaning;
	int recognition_value;
} dictionary;

const char* const dictFile = "dict.txt";
const char* const tempFile = "temp.txt";
static dictionary record[100];
int words_num;

int add_word_func() // Fuction to add words (1)
{

	while (1)
	{
		char word[50];
		char meaning[150];
		char answer;
		int size;

		getchar(); // used for swallow \n

		FILE *dict;
		dict = fopen(dictFile, "a"); //open file (or create if file does't exest)
		
		printf("Enter new word, lowercase\n");
		fgets(word, sizeof(word), stdin); // read the string with word from input
		fprintf(dict, "%s", word); // write word in file

		printf("Enter meaning of new word\n");
		fgets(meaning, sizeof(meaning), stdin); // read the string with meaning of the word
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
	download_data_from_file();
	printf("Let's see how smart are you\n");
        printf("How many words do you want to train today?\n");
	scanf("%d", &value);
	getchar();
	for (i; i<=value; i++)
	{
		if (i == value) break;
 		char answer[50];
                //printf("buffer_word - %s", record[i].word);
		//printf("buffer_mean - %s", record[i].meaning);
        	//printf("knowledge_level - %d\n", record[i].recognition_value);
		//printf("i = %d\n", i);
		printf("%s", record[i].meaning);
        	printf("Enter the word: ");
        	fgets(answer, 49, stdin);
        	if (strcmp (record[i].word, answer) == 0)
        	{
                	printf("RIGHT!\n");
			int t = strcspn(record[i].word, "\n");
			for (int a = 0; a < t; a++)
				printf("%c", record[i].word[a]);
			printf(" - %s", answer);
			record[i].recognition_value++;
        	}
        	else
        	{
                	printf("WRONG!\n");
			printf("The right word - %s", record[i].word);
			printf("You have input - %s", answer);
			if (record[i].recognition_value != 0) record[i].recognition_value--;
        	}
		printf("--------------------------------------------------------\n");
	}
	upload_data_from_file();
	return 0;
}

int look_dict()
{
	char check[10];
	printf("Let's see, what we have in dictionary\n");
	FILE *dict;
	dict = fopen(dictFile, "r");
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
	fclose(dict);
	return 0;
}

int download_data_from_file()
{
	int i = 0;
	char buffer_word[50];
	char buffer_meaning[150];
	int knowledge_level;
	FILE *dict;
	dict = fopen(dictFile, "r");
	while (!feof(dict))
	{
		fgets(buffer_word, 49, dict);
		fgets(buffer_meaning, 149, dict);
		fscanf(dict, "%d\n", &knowledge_level);
		record[i].word = (char*) malloc(strlen(buffer_word) + 1);
		strcpy(record[i].word, buffer_word);
		record[i].meaning = (char*) malloc(strlen(buffer_meaning) + 1);
		strcpy(record[i].meaning, buffer_meaning);
		record[i].recognition_value = knowledge_level;
		i++;
	}
	words_num = i;
	fclose(dict);
	return 0;
}

int upload_data_from_file()
{
	int i = 0;
        char buffer_word[50];
        char buffer_meaning[150];
        int knowledge_level;
        FILE *temp;
        temp = fopen(tempFile, "a");
        while (i < words_num)
        {
                fprintf(temp, "%s", record[i].word);
		fprintf(temp, "%s", record[i].meaning);
                fprintf(temp, "%d\n", record[i].recognition_value);
                i++;
        }
        fclose(temp);
        return 0;
}

int print_all_data()
{
	for (int i = 0; i < 3; i++)
	{
		printf("%s", record[i].word);
		printf("%s", record[i].meaning);
		printf("%d\n", record[i].recognition_value);
	}
	return 0;
}
/*
int read_word()
{
	printf("Enter new word, lowercase\n");
	return readstring(input_word, 50, &wordlen)
*/

//int read_meaning()

//int read_knowledge_level()
