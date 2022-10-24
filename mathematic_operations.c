#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 20

int menu();
int out_of_square_function();
int repaired_function();
void print_array_function(int function_title, int *array, int the_array_size, int *first_digit_array, int *last_digit_array);
void system_clear_function();
void system_pause_function();

int main(){

	menu();

	return 0;
}

int menu(){
	int option;

	do {
		system_clear_function();
		printf("Select an option:\n");
		printf("(1) Out Of Square Number\n");
		printf("(2) Repaired Number\n");
		printf("(9) Exit\n");
		printf("Option: ");
		scanf("%i", &option);

		switch(option) {
			case 1:
				out_of_square_function();
				system_pause_function();
				break;
			case 2:
				repaired_function();
				system_pause_function();
				break;
			case 9:
				break;
		}
	} while (option != 9);
}

int out_of_square_function(){
	int function_title = 0;
	int array[MAX_ARRAY_SIZE];
	int first_digit_array[MAX_ARRAY_SIZE];
	int last_digit_array[MAX_ARRAY_SIZE];
	int counter = 0;
	int i;

	for(i = 0; counter < MAX_ARRAY_SIZE; i+=113){
		int number = i;
		int aux = number;
    int first_digit = 0;
		int last_digit = number % 10;

		while(number > 100){
			first_digit = number /= 10;
			if(last_digit == 1 && first_digit == last_digit*last_digit){
				continue;
			} else if(number == last_digit*last_digit) {
				array[counter] = aux;
				first_digit_array[counter] = first_digit;
				last_digit_array[counter] = last_digit;
				counter++;
			}
		}
	}
	print_array_function(function_title, array, MAX_ARRAY_SIZE, first_digit_array, last_digit_array);
}

int repaired_function(){
	int function_title = 1;
	int array[MAX_ARRAY_SIZE];
	int first_digit_array[MAX_ARRAY_SIZE];
	int last_digit_array[MAX_ARRAY_SIZE];
	int counter = 0;
	int i;

	for(i = 0; counter < MAX_ARRAY_SIZE; i+=111){
		int number = i;
		int aux = number;
    int first_digit = 0;
		int last_digit = number % 10;

		while(number > 100){
			first_digit = number /= 10;
		}
		if(first_digit % 2 == 1 && last_digit % 2 == 0){
			array[counter] = aux;
			first_digit_array[counter] = first_digit;
			last_digit_array[counter] = last_digit;
			counter++;
		}
	}
	print_array_function(function_title, array, MAX_ARRAY_SIZE, first_digit_array, last_digit_array);
}

void print_array_function(int function_title, int *array, int the_array_size, int *first_digit_array, int *last_digit_array){
	system_clear_function();
	int i;

	if(function_title == 0){
    printf("->Out of Square Function\n\n");
		printf("Number\tSquare  Base\n");
		for(i = 0; i < the_array_size; i++){
			printf("%i\t%i\t  %i\n", array[i], first_digit_array[i], last_digit_array[i]);
		}
	} else {
		printf("->Repaired Function\n\n");
		printf("Number\tOdd\tEven\n");
		for(i = 0; i < the_array_size; i++){
			printf("%i\t%i\t%i\n", array[i], first_digit_array[i], last_digit_array[i]);
		}
	}
}

void system_clear_function() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void system_pause_function() {
	printf("\n\n--------------------------------\n");
	printf("Press any key to continue . . .\n");
	getchar();
	getchar();
}


