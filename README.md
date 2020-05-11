# Food court management system

## Introduction
This food court management system basically has the framework of CRUD. And this program manage food court’s food. User can create, read, update and delete food menu. In addition, the convenience of using the program was enhanced by making a set menu or by calculating the income of the day. Of course, it also includes sorting menus according to criteria or compressing the space of deleted data. 



## Key functionalities
#### 1. Create
+ Create a new data record from a .txt file 
+ Create a new record from the standard input (keyboard) 
 #### 2. Read
+ According to user specified conditions, print a record, multiple or all records to the standard output (monitor)
+ Export the entire data in a report format as a .txt file  
#### 3. Update
+ Update a specific field of a record, multiple or all records (according to user specified conditions) 
#### 4. Delete
+ Delete a record, multiple or all records (according to user specified conditions) 



## Additional functionalities
+ Arrange (sort) the order of data records based on user specified conditions 
+ Tells how much sales are today



## Function descriptions
#### 1. add_txt_record()
>  When you enter this program, add data stored in txt file to memory. Previous memory is preserved
#### 2. add_a_record()
> When you enter this program, prints the message “Enter a food’s name> ”. And you can enter the menu’s name as you want to add. Then the program print message “How much is it> ”. You can enter the price you want to add. And the program print another message “What type is it? >” You can enter the food’s type. Then the entered data is stored in memory. Previous memory is preserved 
#### 3. show_menu()
> When you enter this program, displays menus stored in memory on the screen 
#### 4. read_txt_menu()
> When you enter this program, import and store the data previously recorded in the txt file into memory. All previous contents disappear and are replaced with new contents. (Different from Create)
#### 5. export_menu() 
> When you enter this program, export the menus currently recorded in memory to a .txt file 
#### 6. update_a_menu() 
> When you enter this program, it shows all menu and prints the message “Enter a menu’s number you want to change the price> ”. And you can enter the menu’s number as you want to update. Then the program print another message “Enter the price you want to change> ”. You can enter the price you want to change. Then the program update the price of menu you want
#### 7. update_all_menu()
> When you enter this program, it prints the message “How much do you adjust the price of all menu> ”. And you can enter the adjusted price as you want to update. Then the program add the adjusted price of all menu you want
#### 8. delete_a_menu() 
> When you enter this program, it shows all menu and prints the message “Enter a menu’s number you want to delete> ”. And you can enter the menu’s number as you want to delete. Then the program change the record’s name to “none”, record’s price to “-1”, and record’s type to “0(default)”. It can defrag to implement the defrag_menu()
#### 9. delete_some_menu()
> When you enter this program, it shows all menu and prints the message “Enter a menu’s type you want to delete> ”. And you can enter the type number as you want to delete. Then the program delete all information of the type entered. The program change the record’s name to “none”, record’s price to “-1”, and record’s type to “0(default)”. It can defrag to implement the defrag_menu()
#### 10. defrag_menu()
>  When you enter this program, fill in the existing complete information in the place of information where the record’s price is “-1”.  Then the information with the record’s price of “1” is rolled back, and these information reset to default
#### 11. sort_menu()
>  When you enter this program, it shows all menu and prints the message “Enter a number you want to sort by> ”. And you can enter the number as you want to sort by. Then the program sort all information in ascending order by the number entered
#### 12. make_setmenu()
> When you enter this program, it shows all menu and prints the message “Choose two menu’s numbers to make set-menu> ”. And you can enter two numbers as you want to make set-menu. Then the program concatenate information of menu. The price of this menu is a 20% discount
#### 13. today_sales() 
> When you enter this program, it shows all menu and prints the message “How much did you sell> ”. And you can record how many sold each menu. Then the will show you how much you earn today
 
