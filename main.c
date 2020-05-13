#include <stdio.h>
#include <string.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 100

// function prototypes
void input_handler(char[], Record[]);
void display_menu();

// main function
int main(){

    Record records[MAX_RECORDS] = {0,};
    char user_input[64] = "";
    while(strcmp(user_input, "99") != 0){
	display_menu();
	printf("\nSelect a menu> ");
	fgets(user_input, 64, stdin);
	user_input[strlen(user_input)-1] = '\0';
	input_handler(user_input, records);
    }

    return 0;
}


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(char input[], Record records[]){

    // TODO: Modify this function as you need

    if(!strcmp(input, "1"))
	add_txt_record(records);
    else if(!strcmp(input, "2"))
	add_a_record(records);	
    else if(!strcmp(input, "3"))
	show_menu(records);
    else if(!strcmp(input, "4"))
	read_txt_menu(records);
    else if(!strcmp(input, "5"))
	export_menu(records);
    else if(!strcmp(input, "6"))
	update_a_menu(records);
    else if(!strcmp(input, "7"))
	update_all_menu(records);
    else if(!strcmp(input, "8"))
	delete_a_menu(records);
    else if(!strcmp(input, "9"))
	delete_some_menu(records);
    else if(!strcmp(input, "10"))
	defrag_menu(records);
    else if(!strcmp(input, "11"))
	sort_menu(records);
    else if(!strcmp(input, "12"))
	make_setmenu(records);
    else if(!strcmp(input, "13"))
	today_sales(records);
    else if(!strcmp(input, "14"))
	delete_all_but(records);
    else if(!strcmp(input, "99"))
	printf("Terminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)
    else
	printf("Unknown menu: %s \n\n", input);
}



// Function: display_menu()
// Input: none
// Output: none
// - Leave a brief information about the function
void display_menu(){

    // TODO: Modify this function as you need

    printf("******************************\n");
    printf(" Food court management system \n");
    printf("******************************\n");
    printf(" 1. Add a new food from .txt\n");
    printf(" 2. Add a new food from keyboard\n");
    printf(" 3. Print food's records\n");
    printf(" 4. Read entire data from .txt\n");
    printf(" 5. Export entire data to .txt\n");
    printf(" 6. Update a food price\n");
    printf(" 7. Update all food price\n");
    printf(" 8. Delete a food\n");
    printf(" 9. Delete multiple foods (conditional)\n");
    printf(" 10. Optimize (defrag) the records\n");
    printf(" 11. Sort menu (name/price/type)\n");
    printf(" 12. Make set-menu\n");
    printf(" 13. Today's sales\n");
    printf(" 14. Delete all but\n");
    printf(" 99. Quit\n");
}
