#include"functions.h"

typedef struct
{
	char *word;
	char *meaning;
	int recognition_value;
} dictionary;

typedef struct
{
	int *word_level_value_0;
	int *word_level_value_1;
	int *word_level_value_2;
	int *word_level_value_3;
	int *word_level_value_4;
	int *word_level_value_5;
	int *word_level_value_6;
	int *test_words_array;

} test_array;
int record_index;
const char* const dictFile = "dict.txt";
const char* const tempFile = "temp.txt";
static dictionary record[500];
static test_array level[100];
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
		
		fprintf(dict, "%d\n", 1); // write variable, which shows how good we knoe this word
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
	int counter = 0;

	download_data_from_file();

	printf("Let's see how smart are you\n");
        printf("How many words do you want to train today?\n");
	scanf("%d", &value);
	getchar();
	sort_weak_words();
	find_weak_words();
	for (counter; counter<=value; counter++)
	{
		if (counter == value) break;
 		char answer[50];
		i = level[counter].test_words_array;
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
	replace_temp_file();
	return 0;
}

int sort_weak_words()
{
	int i = 0;
	int pos_0 = 0;
	int pos_1 = 0;
	int pos_2 = 0;
	int pos_3 = 0;
	int pos_4 = 0;
	int pos_5 = 0;
	int pos_6 = 0;

	
	while (i < words_num)
	{
		if (record[i].recognition_value == 1) 
		{
			level[pos_0].word_level_value_0 = record_index;
			record_index++;
		}
		if (record[i].recognition_value == 2)
                {
                        level[pos_1].word_level_value_1 = record_index;
                        record_index++;
                }
		if (record[i].recognition_value == 3)
                {
                        level[pos_2].word_level_value_2 = record_index;
                        record_index++;
                }
		if (record[i].recognition_value == 4)
                {
                        level[pos_3].word_level_value_3 = record_index;
                        record_index++;
                }
		if (record[i].recognition_value == 5)
                {
                        level[pos_4].word_level_value_4 = record_index;
                        record_index++;
                }
		if (record[i].recognition_value == 6)
                {
                        level[pos_5].word_level_value_5 = record_index;
                        record_index++;
                }
		if (record[i].recognition_value == 7)
                {
                        level[pos_6].word_level_value_6 = record_index;
                        record_index++;
                }
	}
	return 0;
}

int find_weak_words()
{
	int i_test_array = 0;
	int i = 0;
	while (level[i].word_level_value_0 != 0)
	{
		level[i_test_array].test_words_array = level[i].word_level_value_0;
		i++;
		i_test_array++;
	}
	i = 0;
	while (level[i].word_level_value_1 != 0)
        {
                level[i_test_array].test_words_array = level[i].word_level_value_1;
                i++;
		i_test_array++;
        }
	i = 0;
	while (level[i].word_level_value_2 != 0)
        {
                level[i_test_array].test_words_array = level[i].word_level_value_2;
                i++;
        }
	i = 0;
	while (level[i].word_level_value_3 != 0)
        {
                level[i_test_array].test_words_array = level[i].word_level_value_3;
                i++;
        }
	i = 0;
	while (level[i].word_level_value_4 != 0)
        {
                level[i_test_array].test_words_array = level[i].word_level_value_4;
                i++;
        }
	i = 0;
	while (level[i].word_level_value_5 != 0)
        {
                level[i_test_array].test_words_array = level[i].word_level_value_5;
                i++;
        }
	i = 0;
	while (level[i].word_level_value_6 != 0)
        {
                level[i_test_array].test_words_array = level[i].word_level_value_6;
                i++;
        }
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

int replace_temp_file()
{
	remove ("dict.txt");
	rename ("temp.txt", "dict.txt");
	return 0;
}

//int find_low_recognize_word();

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
