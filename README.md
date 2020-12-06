# Final Project For CSCI2275
This is a Banking System made using **C++** with **Hashing Data Structure** for better and easier access to user information.<br> 
When the program is ran, a menu will appear with 3 options:<br>
  1) **Login:** When pressed, the user has to input their username and password after which, the program will try to find the username and if it is invalid, then it will either ask the user to create a new account or ask the user to make sure the username or password is correct.<br>
          -> After logging in, the user will have the choices to **deposit, withdraw, check balance,** and **close their account.**
  2) **Create New Account**: When pressed, the user will have to input a username and password. After entering the username and password, the program will check to see if there is another user with the same username, if there is not then it will add the new user into the system. It will then redirect the user to the main menu where they can login with their newly created account.<br>
  3) **Quit:** When pressed, the program will stop. The program will also utilize deposit, withdraw, and check balance.<br><br>
**Collisin Resolution**<br>
-> Since it is a banking system, there will undoubtedly be collision between 2 username where their ASCII is the same. For that reason, I used chaining in my program where every index was initilized as NULL. When 2 account with same ASCII is created, they are inserted in the same index but their properties are different. In this case, each user in the same chain would have their own unqiue userID, username, password and balance.<br>
