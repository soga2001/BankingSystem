# Final Project For CSCI2275
I am working Alone on this project.<br>
This is a Banking System made using **C++** with **Hashing Data Structure** for better and easier access to user information. Instead of 2 classes, I used only one but my program is using two data structure, **Hashing Data Structure** and **Singly Linked List**.<br> 
When the program is ran, a menu will appear with 3 options:<br>
  1) **Login:** When pressed, the user has to input their username and password after which, the program will try to find the username and if it is invalid, then it will either ask the user to create a new account or ask the user to make sure the username or password is correct.<br>
          -> After logging in, the user will have the choices to **deposit, withdraw, check balance,** and **close their account.**
  2) **Create New Account**: When pressed, the user will have to input a username and password. After entering the username and password, the program will check to see if there is another user with the same username, if there is not then it will add the new user into the system. It will then redirect the user to the main menu where they can login with their newly created account.<br>
  3) **Quit:** When pressed, the program will stop. The program will also utilize deposit, withdraw, and check balance.<br><br>
**Collisin Resolution**<br>
-> Since it is a banking system, there will undoubtedly be collision between 2 username where their ASCII is the same. For that reason, I used chaining in my program where every index was initilized as NULL. When 2 account with same ASCII is created, they are inserted in the same index but their properties are different. In this case, each user in the same chain would have their own unqiue userID, username, password and balance.<br><br>
To download my program, click the green "Code" button on my finalproject Github page. Then press the "Download.ZIP" which is the very last button on the dropdown menu. After downloading, extract everything from the .ZIP folder and open the folder with the text editor of your choice.<br>
->To run the program, simply open the terminal of the editor. Complie it using "g++ -std=c++11 finalMain.cpp final.cpp -o final( or any name of your choice)". Afterwards enter "./final" to run the program. Then create an account using "Option 2" or just enter "2" into the terminal. After that you can login using the account you just created.<br><br>
Also there is a function commented out called "printTable()" from all of the files. If you uncomment that, when you press "1" in the **Login Menu**, it prints the hash table. If you want to see how my program runs with collision, create 2 account one with username "GoCatGo." and another with "GoDog,Go".

No additional system requirements.

I worked on this project by myself.
