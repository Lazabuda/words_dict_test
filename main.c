#include"functions.h"

int main()
{
	int main_menu;
	while (1)
	{
		printf("###_____WORDS_TEST_ver1_____###\n");
        	printf("1 - Enter new word\n");
		printf("2 - Start testing\n");
		printf("3 - Look at the dictionary\n");
		printf("0 - exit\n");
		printf(">");
		scanf("%d", &main_menu);
		if (main_menu == 1)
			add_word_func();
		if (main_menu == 2)
			test_func();
		if (main_menu == 3)
			look_dict();
		if (main_menu == 0)
			break;
	}
	return 0;

}
