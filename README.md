# CCP_plazza_2018

Kitchens are represented by processes, cooks by threads themselves sheduled by a thread pool.
The threads are handled with the help of conditional variables and mutex.
Receptions and kitchens communicate through an IPC shared memory to serialize and send informations to child processes and threads. When kitchens are full, the program allocate a new kitchen by forking a process. if all cooks are busy, the thread pool trigger/allocate a new thread.
When an order is ready, the reception displays the informations to the user and keep a record.
The user send his commmands with the help of an interactive shell.

USING :

      Make
      
      ./plazza [COOK_TIME : 0 - 1] [NB_COOKS][REPLACE_STOCK_TIME].
      
      S := TYPE SIZE NUMBER [; TYPE SIZE NUMBER]*.
      TYPE := [a..zA..Z]+.      
      SIZE := S|M|L|XL|XXL.
      NUMBER := x[1..9][0..9]*.
   
EXEMPLE :
      
      > ./plazza 2 5 2000
      
      > regina XXL x2; fantasia M x3; margarita S x1.
      > status.
      
At the very beggining, no **kitchens** are open. A **kitchen** opens when an order has been received and no other **kitchens** are available (it can mean there are 0 **kitchens** open or that all the **kitchens** are busy with other orders).  
If a **kitchen** stays open for 5 seconds without having anything to do, it closes, leaving no zombie process or thread behind.

There are several sizes for pizzas : S = 1, M = 2, L = 4, XL = 8, XXL = 16.  

There are 4 types of pizzas :  
  - regina (baked in `1 * COOK_TIME * pizza_size` seconds) made with `doe, tomato, gruyere`
  - margarita (baked in `2 * COOK_TIME * pizza_size` seconds) made with `doe, tomato, gruyere, ham, mushrooms`
  - americana (baked in `2 * COOK_TIME * pizza_size` seconds) made with `doe, tomato, gruyere, steak`
  - fantasia (baked in `4 * COOK_TIME * pizza_size` seconds) made with `doe, tomato, eggplant, goat cheese, chief love`

Each **kitchen** has a maximum of 5 for each ingredient, which are shared between **cooks**.
