#include <stdio.h>
#include <string.h>
#include "base.h"
#define _CRT_SECURE_NO_WARNINGS


// Function: add_txt_record()
// Input: record - array of Records; this may contain empty elements in the middle, .txt file – file of Records
// Output: none
// - Create new food record from .txt file
void add_txt_record(Record records[]){
	// TODO: Modify this function as you need

	FILE *rfp = fopen("menufile1.txt", "r");
  while(1)  {
  int enter_price, enter_type;
  char user_input[64] = "";

  fscanf(rfp, "%s %d %d", user_input, &enter_price, &enter_type);
  if(feof(rfp)) break;
  printf("name : %s, price : %d, type : %d \n", user_input, enter_price, enter_type);
  
	int temp = 0;
  while(records[temp].price != 0){
    temp++;
  }
  strcpy(records[temp].name, user_input);
  records[temp].price = enter_price;
  records[temp].type = enter_type;
  }
  fclose(rfp);
  printf("Complete!! \n\n");
}

// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Create new food record from the keyboard
void add_a_record(Record records[]){
	// TODO: Modify this function as you need
	int temp = 0;
  while(records[temp].price != 0){
    temp++;
  }

  char user_input[64] = "";
	printf("\nEnter a food's name> ");
	fgets(user_input, 64, stdin);
	user_input[strlen(user_input)-1] = '\0';
  strcpy(records[temp].name, user_input);

  int enter_price = 0;
  printf("How much is it? > ");
  scanf("%d", &enter_price);
  records[temp].price = enter_price;

  int enter_type = 0;
  printf("(Korean - 1, Chinese - 2, Western - 3, Set - 4)\n");
  printf("What type is it? > ");
  scanf("%d", &enter_type);
  records[temp].type = enter_type;

  printf("Complete!\n\n");
	getchar(); // delete buffer
}

// Function: show_menu()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: Print all menu on the screen
// - Show all menu on the screen
void show_menu(Record records[]){
	// TODO: Modify this function as you need
	int temp = 0;
  while(records[temp].price != 0){
    printf("<menu %d>\n" , temp+1);
    printf("Name : %s\n", records[temp].name);
    printf("Price : %d\n", records[temp].price);
    if(records[temp].type == 1) printf("Type : Korean\n");
    else if(records[temp].type == 2) printf("Type : Chinese\n");
    else if(records[temp].type == 3) printf("Type : Western\n");
    else if(records[temp].type == 4) printf("Type : Set\n");
    else printf("Type : none\n");
    temp++;
  }
  printf("\n");
}


// Function: read_txt_menu()
// Input: record - array of Records; this may contain empty elements in the middle, .txt file – file of Records
// Output: none
// - Read all menu from .txt file
void read_txt_menu(Record records[]){
	// TODO: Modify this function as you need
	FILE *rfp = fopen("menufile2.txt", "r");
  int temp = 0;

  while(1)  { // Read end of file
  int enter_price, enter_type;
  char user_input[64] = "";

  fscanf(rfp, "%s %d %d", user_input, &enter_price, &enter_type);
  if(feof(rfp)) break;
  printf("name : %s, price : %d, type : %d \n", user_input, enter_price, enter_type);
  
  strcpy(records[temp].name, user_input);
  records[temp].price = enter_price;
  records[temp].type = enter_type;
  temp++;
  }
  records[temp].price = 0;  // If the price is 0, it's not printed.
  fclose(rfp);
  printf("Complete!! \n\n");
}

// Function: export_menu()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: .txt file
// - Export all menu to .txt file 
void export_menu(Record records[]){
	// TODO: Modify this function as you need
  FILE *rfp = fopen("recordmenufile.txt", "w");
  int temp = 0;
  while(records[temp].price != 0){
    fprintf(rfp, "<menu %d>\n", temp+1);
    fprintf(rfp, "name : %s, price : %d, type : %d\n\n", records[temp].name, records[temp].price, records[temp].type);
    temp++;
  }
  fclose(rfp);
  printf("Export Complete!!\n\n");
}

// Function: update_a_menu()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Update a menu’s price to records
void update_a_menu(Record records[]){
	// TODO: Modify this function as you need
	show_menu(records);
  int temp_menu;
  int adjust_price;
  printf("Enter a menu's number you want to change the price> ");
  scanf("%d", &temp_menu);
  printf("Enter the price you want to change> ");
  scanf("%d", &adjust_price);
  
  records[temp_menu-1].price = adjust_price;
  printf("Menu %s's price change to %dWon\n\n", records[temp_menu-1].name, records[temp_menu-1].price);
	getchar(); // delete buffer
}

// Function: update_all_menu()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Update all menu’s price to records
void update_all_menu(Record records[]){
	// TODO: Modify this function as you need
	int adjusted_price;
  printf("How much do you adjust the price of all menu> ");
  scanf("%d", &adjusted_price);

  int temp = 0;
  while(records[temp].price != 0){
    records[temp].price += adjusted_price;
    temp++;
  }
  printf("Price adjusted!\n\n");
	getchar(); // delete buffer
}

// Function: delete_a_menu()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Delete a menu to records 
void delete_a_menu(Record records[]){
	// TODO: Modify this function as you need
  show_menu(records);
	int delete_num;
  printf("Enter a menu's number you want to delete> ");
  scanf("%d", &delete_num);

  strcpy(records[delete_num-1].name, "none");
  records[delete_num-1].price = -1;
  records[delete_num-1].type = 0;
  
  printf("Delete Complete!\n\n");
	getchar(); // delete buffer
}

// Function: delete_some_menu()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Delete some conditional menu to records
void delete_some_menu(Record records[]){
	// TODO: Modify this function as you need
  show_menu(records);
	int delete_type;
  printf("(Korean - 1, Chinese - 2, Western - 3, Set - 4)\n");
  printf("Enter a number of menu's type you want to delete> ");
  scanf("%d", &delete_type);

  int temp = 0;
  while(records[temp].price != 0){
    if(records[temp].type == delete_type){
      strcpy(records[temp].name, "none");
      records[temp].price = -1;
      records[temp].type = 0;
    }
    temp++;
  }

  printf("Delete Complete!\n\n");
	getchar(); // delete buffer
}
