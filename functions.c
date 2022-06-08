#include"functions.h"
// Define struct for working with records
typedef struct
{
	char *word;
	char *meaning;
	int recognition_value;
} dictionary;
// Arrays for replacing weak words in the first queue
int *word_level_value_0;
int *word_level_value_1;
int *word_level_value_2;
int *word_level_value_3;
int *word_level_value_4;
int *word_level_value_5;
int *word_level_value_6;
int *test_words_array;

int record_index = 0;
const char* const dictFile = "dict.txt"; // File to write data
const char* const tempFile = "temp.txt"; // File to save temporary data
static dictionary record[500]; // Max records
int words_num;

int memory_init() // Function to initialize memory and fill it by zero's
{
	printf("===================================\n");
	word_level_value_0 = (int*)calloc(50, sizeof(int));
	if (word_level_value_0 == NULL)
	{	printf("Memory not allocated \n"); return 1;}
	else
		printf("Memory array 0 allocated succesfully \n");
	word_level_value_1 = (int*)calloc(50, sizeof(int));
	if (word_level_value_1 == NULL)
	{	printf("Memory not allocated \n"); return 1;}
	else
                printf("Memory array 1 allocated succesfully \n");
	word_level_value_2 = (int*)calloc(50, sizeof(int));
	if (word_level_value_2 == NULL)
	{	printf("Memory not allocated \n"); return 1;}
	else
                printf("Memory array 2 allocated succesfully \n");
	word_level_value_3 = (int*)calloc(50, sizeof(int));
	if (word_level_value_3 == NULL)
	{	printf("Memory not allocated \n"); return 1;}
	else
                printf("Memory array 3 allocated succesfully \n");
	word_level_value_4 = (int*)calloc(50, sizeof(int));
	if (word_level_value_4 == NULL)
	{	printf("Memory not allocated \n"); return 1;}
	else
                printf("Memory array 4 allocated succesfully \n");
	word_level_value_5 = (int*)calloc(50, sizeof(int));
	if (word_level_value_5 == NULL)
	{	printf("Memory not allocated \n"); return 1;}
	else
                printf("Memory array 5 allocated succesfully \n");
	word_level_value_6 = (int*)calloc(50, sizeof(int));
	if (word_level_value_6 == NULL)
	{	printf("Memory not allocated \n"); return 1;}
	else
                printf("Memory array 6 allocated succesfully \n");
	test_words_array = (int*)calloc(50, sizeof(int));
        if (test_words_array == NULL)
	{	printf("Memory not allocated \n"); return 1;}
        else
                printf("Memory test words array allocated succesfully \n");
	printf("===================================\n");
	printf("\n");
	return 0;
}

int add_word_func() // Fuction to add words
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
		if (answer == 'y') continue;
		else ("unknown symbol, end cycle\n");
		
	}
}


int test_func()
{
	int value = 0;
	int i = 0;
	int counter = 0;

	download_data_from_file(); // This function dounloaded data from file to memory for working with data
	printf("SERVICE MESSAGE: download_data_from_file() - PASSED \n");
	printf("\n");
	printf("Let's see how smart are you\n");
        printf("How many words do you want to train today?\n");
	scanf("%d", &value);
	getchar();
	memory_init(); // Initialyze memory, added memory for all created arrays
	printf("SERVICE MESSAGE: memory_init() - PASSED \n");
	sort_weak_words(); // Sortning words by knowledge_level
	printf("SERVICE MESSAGE: sort_weak_words() - PASSED \n");
	find_weak_words(); // Put words for learning to queue
	printf("SERVICE MESSAGE: find_weak_words() - PASSED \n");
	memory_test(); // Show arrays to control
	printf("SERVICE MESSAGE: memory_test() - PASSED \n");
	for (counter; counter<=value; counter++)
	{
		if (counter == value) break;
 		char answer[50];
		i = test_words_array[counter];
		printf("SERVICE MESSAGE. iteration = %d\n", i);
		printf("\n");
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
			if (record[i].recognition_value < 7)
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
	upload_data_from_file(); // Upload data from memory to FILE
	replace_temp_file(); // Delete dict.txt and rename temp.txt to dict.txt
	free(word_level_value_0);
	free(word_level_value_1);
	free(word_level_value_2);
	free(word_level_value_3);
	free(word_level_value_4);
	free(word_level_value_5);
	free(word_level_value_6);
	free(test_words_array);
	record_index = 0;
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
			word_level_value_0[pos_0] = record_index;
			record_index++;
			pos_0++;
		}
		if (record[i].recognition_value == 2)
                {
                        word_level_value_1[pos_1] = record_index;
                        record_index++;
			pos_1++;
                }
		if (record[i].recognition_value == 3)
                {
                        word_level_value_2[pos_2] = record_index;
                        record_index++;
			pos_2++;
                }
		if (record[i].recognition_value == 4)
                {
                        word_level_value_3[pos_3] = record_index;
                        record_index++;
			pos_3++;
                }
		if (record[i].recognition_value == 5)
                {
                        word_level_value_4[pos_4] = record_index;
                        record_index++;
			pos_4++;
                }
		if (record[i].recognition_value == 6)
                {
                        word_level_value_5[pos_5] = record_index;
                        record_index++;
			pos_5++;
                }
		if (record[i].recognition_value == 7)
                {
                        word_level_value_6[pos_6] = record_index;
                        record_index++;
			pos_6++;
                }
		i++;
	}
	return 0;
}

int find_weak_words()
{
	int i_test_array = 0;
	int i = 0;
	while (word_level_value_0[i] != 0)
	{
		test_words_array[i_test_array] = word_level_value_0[i];
		i++;
		i_test_array++;
	}
	i = 0;
	while (word_level_value_1[i] != 0)
        {
                test_words_array[i_test_array] = word_level_value_1[i];
                i++;
                i_test_array++;
        }
        i = 0;
	while (word_level_value_2[i] != 0)
        {
                test_words_array[i_test_array] = word_level_value_2[i];
                i++;
                i_test_array++;
        }
        i = 0;
	while (word_level_value_3[i] != 0)
        {
                test_words_array[i_test_array] = word_level_value_3[i];
                i++;
                i_test_array++;
        }
        i = 0;
	while (word_level_value_4[i] != 0)
        {
                test_words_array[i_test_array] = word_level_value_4[i];
                i++;
                i_test_array++;
        }
        i = 0;
	while (word_level_value_5[i] != 0)
        {
                test_words_array[i_test_array] = word_level_value_5[i];
                i++;
                i_test_array++;
        }
        i = 0;
	while (word_level_value_6[i] != 0)
        {
                test_words_array[i_test_array] = word_level_value_6[i];
                i++;
                i_test_array++;
        }
        i = 0;
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

int memory_test()
{
	printf("===================================\n");
	printf("word_level_value_0 array:");
	for (int i = 0; i < 50; i++)
	{
		printf("%d", word_level_value_0[i]);
	}
	printf("\n");
	printf("word_level_value_1 array:");
	for (int i = 0; i < 50; i++)
        {
                printf("%d", word_level_value_1[i]);
        }
        printf("\n");
        printf("word_level_value_2 array:");
	for (int i = 0; i < 50; i++)
        {
                printf("%d", word_level_value_2[i]);
        }
        printf("\n");
        printf("word_level_value_3 array:");
	for (int i = 0; i < 50; i++)
        {
                printf("%d", word_level_value_3[i]);
        }
        printf("\n");
        printf("word_level_value_4 array:");
	for (int i = 0; i < 50; i++)
        {
                printf("%d", word_level_value_4[i]);
        }
        printf("\n");
        printf("word_level_value_5 array:");
	for (int i = 0; i < 50; i++)
        {
                printf("%d", word_level_value_5[i]);
        }
        printf("\n");
        printf("word_level_value_6 array:");
	for (int i = 0; i < 50; i++)
        {
                printf("%d", word_level_value_6[i]);
        }
        printf("\n");
	printf("test_words_array   array:");
        for (int i = 0; i < 50; i++)
        {
                printf("%d", test_words_array[i]);
        }
        printf("\n");
        printf("===================================\n");
	return 0;
}
