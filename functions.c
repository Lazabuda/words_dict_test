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

#define WORD_LENGTH 50
#define MEANING_LENGTH 150
// Max words in queue - 100 If you need more, just change values and hide test_memory function. It is for testing.
#define WORDS_IN_0_ARRAY 50
#define WORDS_IN_1_ARRAY 50
#define WORDS_IN_2_ARRAY 50
#define WORDS_IN_3_ARRAY 50
#define WORDS_IN_4_ARRAY 50
#define WORDS_IN_5_ARRAY 50
#define WORDS_IN_6_ARRAY 50
#define TEST_WORDS_QUEUE_ARRAY 100

int record_index = 0;
const char* const dictFile = "dict.txt"; // File to write data
const char* const tempFile = "temp.txt"; // File to save temporary data
static dictionary record[500]; // Max records
int words_num; // quantity of words

int memory_init() // Function to initialize memory and fill it by zero's
{
	printf("===================================\n");
	word_level_value_0 = (int*)calloc(WORDS_IN_0_ARRAY, sizeof(int));
	if (word_level_value_0 == NULL)
	{	printf("Memory not allocated \n"); return 1;}
	else
		printf("Memory array 0 allocated succesfully \n");
	word_level_value_1 = (int*)calloc(WORDS_IN_1_ARRAY, sizeof(int));
	if (word_level_value_1 == NULL)
	{	printf("Memory not allocated \n"); return 1;}
	else
                printf("Memory array 1 allocated succesfully \n");
	word_level_value_2 = (int*)calloc(WORDS_IN_2_ARRAY, sizeof(int));
	if (word_level_value_2 == NULL)
	{	printf("Memory not allocated \n"); return 1;}
	else
                printf("Memory array 2 allocated succesfully \n");
	word_level_value_3 = (int*)calloc(WORDS_IN_3_ARRAY, sizeof(int));
	if (word_level_value_3 == NULL)
	{	printf("Memory not allocated \n"); return 1;}
	else
                printf("Memory array 3 allocated succesfully \n");
	word_level_value_4 = (int*)calloc(WORDS_IN_4_ARRAY, sizeof(int));
	if (word_level_value_4 == NULL)
	{	printf("Memory not allocated \n"); return 1;}
	else
                printf("Memory array 4 allocated succesfully \n");
	word_level_value_5 = (int*)calloc(WORDS_IN_5_ARRAY, sizeof(int));
	if (word_level_value_5 == NULL)
	{	printf("Memory not allocated \n"); return 1;}
	else
                printf("Memory array 5 allocated succesfully \n");
	word_level_value_6 = (int*)calloc(WORDS_IN_6_ARRAY, sizeof(int));
	if (word_level_value_6 == NULL)
	{	printf("Memory not allocated \n"); return 1;}
	else
                printf("Memory array 6 allocated succesfully \n");
	test_words_array = (int*)calloc(TEST_WORDS_QUEUE_ARRAY, sizeof(int));
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
		char word[WORD_LENGTH];
		char meaning[MEANING_LENGTH];
		char answer;
		int size;

		getchar(); // used for swallow \n

		FILE *dict;
		dict = fopen(dictFile, "a"); //open file (or create if file does't exest)
		
		printf("Enter new word, lowercase\n");
		fgets(word, sizeof(word), stdin); // read the string with word from input
		if (strpbrk(word, "0123456789")) // check if we have digits in our input string
		{
			printf("There is a digit in your word!\n");
			break;
		}
		if (strpbrk(word, "ABCDEFGHIJKLMNOPQRSTUVWXYZ")) 
		{
			printf("All letters must be lowercase!\n");
			break;
		}
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
		else 
		{
			printf("unknown symbol, end cycle\n");
		       	break;
		}
		
	}
}


int test_func()
{
	int value = 0;
	int i = 0;
	int counter = 0;

	download_data_from_file(); // This function dounloaded data from file to memory for working with data
	//printf("SERVICE MESSAGE: download_data_from_file() - PASSED \n");
	printf("\n");
	printf("Let's see how smart are you\n");
        printf("How many words do you want to train today?\n");
	scanf("%d", &value);
	getchar();
	memory_init(); // Initialyze memory, added memory for all created arrays
	//printf("SERVICE MESSAGE: memory_init() - PASSED \n");
	sort_weak_words(); // Sortning words by knowledge_level
	//printf("SERVICE MESSAGE: sort_weak_words() - PASSED \n");
	find_weak_words(); // Put words for learning to queue
	//printf("SERVICE MESSAGE: find_weak_words() - PASSED \n");
	//memory_test(); // Show arrays to control
	//printf("SERVICE MESSAGE: memory_test() - PASSED \n");
	if (value > words_num)
	{
		printf("Quantity of words in the dictionary is less, than you want to train, sorry. In your dictionary now there are: %d words\n", words_num);
		value = words_num;
	}
	for (counter; counter<=value; counter++)
	{
		if (counter == value) break;
 		char answer[WORD_LENGTH];
		i = test_words_array[counter];
		//printf("SERVICE MESSAGE. iteration = %d\n", i);
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
	upload_data_to_file(); // Upload data from memory to FILE
	replace_temp_file(); // Delete dict.txt and rename temp.txt to dict.txt
	free(word_level_value_0); // Free memory of temporary arrays
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

int sort_weak_words() // This function analyze every value of knowledge_level and put records in queue by values (from weak words to famous)
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
		if (record[i].recognition_value == 1) // This value is less. Unknown word.
			word_level_value_0[pos_0++] = record_index;
		if (record[i].recognition_value == 2)
                        word_level_value_1[pos_1++] = record_index;
		if (record[i].recognition_value == 3)
                        word_level_value_2[pos_2++] = record_index;
		if (record[i].recognition_value == 4)
                        word_level_value_3[pos_3++] = record_index;
		if (record[i].recognition_value == 5)
                        word_level_value_4[pos_4++] = record_index;
		if (record[i].recognition_value == 6)
                        word_level_value_5[pos_5++] = record_index;
		if (record[i].recognition_value == 7) // This value is high. Famous word.
                        word_level_value_6[pos_6++] = record_index;
		i++;
		record_index++;
	}
	return 0;
}

int find_weak_words() // This function put words from weak to famous in one array - test_words_array in queue
{
	int i_test_array = 0;
	int i = 0;
	while (word_level_value_0[i] != 0){ // weak words first
		test_words_array[i_test_array++] = word_level_value_0[i++];}
	i = 0;
	while (word_level_value_1[i] != 0){
                test_words_array[i_test_array++] = word_level_value_1[i++];}
        i = 0;
	while (word_level_value_2[i] != 0){
                test_words_array[i_test_array++] = word_level_value_2[i++];}
        i = 0;
	while (word_level_value_3[i] != 0){
                test_words_array[i_test_array++] = word_level_value_3[i++];}
        i = 0;
	while (word_level_value_4[i] != 0){
                test_words_array[i_test_array++] = word_level_value_4[i++];}
        i = 0;
	while (word_level_value_5[i] != 0){
                test_words_array[i_test_array++] = word_level_value_5[i++];}
        i = 0;
	while (word_level_value_6[i] != 0){ // famous words last
                test_words_array[i_test_array++] = word_level_value_6[i++];}
	return 0;
}



int look_dict() // This function shows all data from dict.txt More simply - print dict.txt
{
	printf("Let's see, what we have in dictionary\n");
	FILE *dict;
	dict = fopen(dictFile, "r");
	char buffer_word[WORD_LENGTH];
	char buffer_mean[MEANING_LENGTH];
	int knowledge_level;
	while (!feof(dict))
	{
		printf("=====================================================================\n");
		fgets(buffer_word, WORD_LENGTH, dict);
		fgets(buffer_mean, MEANING_LENGTH, dict);
		fscanf(dict, "%d\n", &knowledge_level);
		printf("%s", buffer_word);
		printf("%s", buffer_mean);
		printf("%d\n", knowledge_level); 
	}
	printf("The end of the dictionary. Thanks for your attention. You are smart and good!\n");
	fclose(dict);
	return 0;
}

int download_data_from_file() // This function downloads data from file to the internal memory (buffer) to make our work with data more easy
{
	int i = 0;
	char buffer_word[WORD_LENGTH];
	char buffer_meaning[MEANING_LENGTH];
	int knowledge_level;
	FILE *dict;
	dict = fopen(dictFile, "r");
	while (!feof(dict))
	{
		fgets(buffer_word, WORD_LENGTH, dict);
		fgets(buffer_meaning, MEANING_LENGTH, dict);
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

int upload_data_to_file() // This function downloads data from memory (buffer) to temporary file temp.txt
{
	int i = 0;
        char buffer_word[WORD_LENGTH];
        char buffer_meaning[MEANING_LENGTH];
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

int replace_temp_file() // Replace old data in dict.txt by new data from temporary file temp.txt
{
	remove ("dict.txt");
	rename ("temp.txt", "dict.txt");
	return 0;
}



int memory_test() // Test of memory for data arrays
{
	printf("===================================\n");
	printf("word_level_value_0 array:");
	for (int i = 0; i < WORDS_IN_0_ARRAY; i++)
	{
		printf("%d", word_level_value_0[i]);
	}
	printf("\n");
	printf("word_level_value_1 array:");
	for (int i = 0; i < WORDS_IN_1_ARRAY; i++)
        {
                printf("%d", word_level_value_1[i]);
        }
        printf("\n");
        printf("word_level_value_2 array:");
	for (int i = 0; i < WORDS_IN_2_ARRAY; i++)
        {
                printf("%d", word_level_value_2[i]);
        }
        printf("\n");
        printf("word_level_value_3 array:");
	for (int i = 0; i < WORDS_IN_3_ARRAY; i++)
        {
                printf("%d", word_level_value_3[i]);
        }
        printf("\n");
        printf("word_level_value_4 array:");
	for (int i = 0; i < WORDS_IN_4_ARRAY; i++)
        {
                printf("%d", word_level_value_4[i]);
        }
        printf("\n");
        printf("word_level_value_5 array:");
	for (int i = 0; i < WORDS_IN_5_ARRAY; i++)
        {
                printf("%d", word_level_value_5[i]);
        }
        printf("\n");
        printf("word_level_value_6 array:");
	for (int i = 0; i < WORDS_IN_6_ARRAY; i++)
        {
                printf("%d", word_level_value_6[i]);
        }
        printf("\n");
	printf("test_words_array   array:");
        for (int i = 0; i < TEST_WORDS_QUEUE_ARRAY; i++)
        {
                printf("%d", test_words_array[i]);
        }
        printf("\n");
        printf("===================================\n");
	return 0;
}
