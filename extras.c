#include <stdio.h>
#include <string.h>
#include "extras.h"

#define MAX_RECORDS 100

// Function: defrag_menu()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: 1 if successful, otherwise 0
// - Defrag menu to records
void defrag_menu(Record records[]){
    // TODO: Modify this function as you need
    int temp = 0;
    while(records[temp].price != 0){
	int copy;
	if(records[temp].price == -1){
	    for(copy = temp + 1; records[copy].price != 0; copy++){
		if(records[copy].price > 0) break;
	    }
	    if(records[copy].price == 0){
		for(int i = temp; i < copy; i++){
		    records[i].name[0] = '\0';
		    records[i].type = 0;
		    records[i].price = 0;
		}
		break;
	    }
	    strcpy(records[temp].name, records[copy].name);
	    records[temp].price = records[copy].price;
	    records[temp].type = records[copy].type;
	    records[copy].price = -1;
	}
	temp++;
    }
    printf("Optimize Complete! \n\n");
    return;	 
}

// Function: sort_menu()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Sort the menu to records
void sort_menu(Record records[]){
    // TODO: Modify this function as you need
    int sort_num;
    printf(" (1 - name, 2 - price, 3 - type) \n");
    printf("Enter a number you want to sort by> ");
    scanf("%d", &sort_num);

    if(sort_num == 1){  // Sort by name
	char copy_name[20];
	int copy_price;
	int copy_type;

	for(int i = 0; records[i].price != 0; i++){
	    int min = i;
	    for(int j = i+1; records[j].price != 0; j++){
		if(strcmp(records[i].name, records[j].name) > 0) min = j;
	    }
	    strcpy(copy_name, records[i].name);
	    copy_price = records[i].price;
	    copy_type = records[i].type;
	    strcpy(records[i].name, records[min].name);
	    records[i].price = records[min].price;
	    records[i].type = records[min].type;
	    strcpy(records[min].name, copy_name);
	    records[min].price = copy_price;
	    records[min].type = copy_type;
	}

    }else if(sort_num == 2){  // Sort by price
	char copy_name[20];
	int copy_price;
	int copy_type;

	for(int i = 0; records[i].price != 0; i++){
	    int min = i;
	    for(int j = i+1; records[j].price != 0; j++){
		if(records[i].price > records[j].price) min = j;
	    }
	    strcpy(copy_name, records[i].name);
	    copy_price = records[i].price;
	    copy_type = records[i].type;
	    strcpy(records[i].name, records[min].name);
	    records[i].price = records[min].price;
	    records[i].type = records[min].type;
	    strcpy(records[min].name, copy_name);
	    records[min].price = copy_price;
	    records[min].type = copy_type;
	}

    }else if(sort_num == 3){  // Sort by type
	char copy_name[20];
	int copy_price;
	int copy_type;

	for(int i = 0; records[i].price != 0; i++){
	    int min = i;
	    for(int j = i+1; records[j].price != 0; j++){
		if(records[i].type > records[j].type) min = j;
	    }
	    strcpy(copy_name, records[i].name);
	    copy_price = records[i].price;
	    copy_type = records[i].type;
	    strcpy(records[i].name, records[min].name);
	    records[i].price = records[min].price;
	    records[i].type = records[min].type;
	    strcpy(records[min].name, copy_name);
	    records[min].price = copy_price;
	    records[min].type = copy_type;
	}
    }else {
	printf("Wrong num!\n\n");
    }
    printf("\n");
    getchar();
}

// Function: make_setmenu()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Make set-menu to records
void make_setmenu(Record records[]){
    // TODO: Modify this function as you need
    int menu1, menu2;
    printf("Choose two menu's numbers to make set-menu >");
    scanf("%d %d", &menu1, &menu2);

    int discount_price = ((records[menu1-1].price + records[menu2-1].price) * 8 / 10);
    int temp = 0;
    while(records[temp].price != 0){
	temp++;
    }
    strcpy(records[temp].name, records[menu1-1].name);
    strcat(records[temp].name, " + ");
    strcat(records[temp].name, records[menu2-1].name);
    records[temp].price = discount_price;
    records[temp].type = 4;

    printf("Make a Set-menu Complete! \n\n");
    getchar();
    return;	 
}



// Function: today_sales()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Inform the today's earnings
void today_sales(Record records[]){
    int sum = 0;
    int count = 0;
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
	printf("How much did you sell> ");
	scanf("%d", &count);
	sum += count * records[temp].price;
	temp++;
    }
    printf("Today's earnings are %d Won! \n\n", sum);
    getchar(); // Delete buffer
}

void delete_all_but(Record records[]){

    int temp = 0;
    while(records[temp].price !=0){
	temp++;
    }

    printf("(1 - korean , 2 - chinese , 3 - Western )\n");
    printf("Enter a type's string you don't want to delete> ");
    int input;
    scanf("%d",&input);

    for(int i=0;i < temp; i++){
	if(records[i].type != input) {
	    strcpy(records[i].name,"none");	
	    records[i].price = -1;
	    records[temp].type = 0;
	}
    }


    printf("Delete Complete!\n\n");
    getchar();
}
