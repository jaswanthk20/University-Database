# Introduction

The goal is to create a database capable of managing the academic records and personal information of university students and professors. The project will involve the implementation of C++ as the programming language for coding. To construct the database, successfully and fulfil all the project requirements, the team will utilize various algorithms such as composition, inheritance, linked list, searching, and sorting. The UML is as follows: 

![image](https://user-images.githubusercontent.com/114720268/236543510-a4860970-966b-4a56-bfbb-a80fb50f9f67.png)

The team opted to utilize four classes (as illustrated in figure 1) to construct the database. Two of these classes, namely the student and professor classes, were utilized to input unique data about each party. Meanwhile, the User class was utilized to store basic information for each party, thereby serving as the base class, while the student and professor classes were the derived classes. Additionally, the Course class was employed as a composition for the student class within the database.

# External Functions
## Function **uppercase()**
In the header file, there is a function called ‘uppercaser()’ with an input parameter and return type as string. The purpose of this function is to convert the name entered by user into uppercase letters. This is done to ensure that regardless of how the name is entered, all letters are in uppercase, making it easier to sort data alphabetically. The team utilized strings and a FOR loop to iterate through each letter. Within the FOR loop, the ‘toupper()’ string operation was used to convert each letter to uppercase, achieving the desired result.

## Function **len_check()**
The header file contains a function called ‘len_check()’ with an input parameter of integer (int) and return type of boolean (bool). The purpose of this function is to verify if the number of digits for ‘id’ given by the user is 4-digits. If it is 4-digit, then it returns true.
*(Note: classes are written in bold italics, ‘functions()’ are written in bold with single quotation marks and ‘class_members’ are written in single quotation marks.)*
(1) or else it returns false (0). To implement this function a simple return statement is required that sets the limit to greater than 999 and less than 10000. 


# Detailed Implementation
## Implementation User Class
This part of code defines a ‘user’ class has private and public members and the members are follows:

Private members: string ‘name’, int ‘id’, string ‘address’ and string ‘phone_number’
Public members:
### user() constructor: 
It is the constructor method that takes four parameters: the name, ‘id’, address, and phone number of a user object. It initializes the member variables where the integer ‘id’ has default value of 0, and the strings name, address and phone number have default empty double-quotations, and the ‘user()’ ‘id’ accepts 4-digit unique entries, if not it prompts error message.

### read() function: 
This method takes an input stream object (istream&) as its parameter and prompts the user to enter the user’s details. It reads the input stream, validates it, and stores it in the member variables of the class. It also calls a function named ‘uppercaser()’ to convert the user’s name to uppercase characters. Since the ‘read()’ functions do not need to return any values, they are declared with a return type of void. The ‘read()’ function reads in user data from the input stream and sets the private member variables of the ‘user’ object.

### write() function: 
This function takes an (ostream&) parameter and outputs the user’s data to the stream, including their name, ID, address, and phone number. It does not need to return any values, therefore, has a return type of void. The ‘write()’ function writes out the user data to the output stream.

### get_name() function:
This is a getter method that returns the name of the user as a string. It is declared as a ‘constant (const)’, which means that it cannot modify the member variables of the class. This function is used to return the user’s name.

### get_id() function: 
This function returns the ‘id’ data member of the user object. This is useful for accessing the private ‘id’ member in friend classes. The return type of the function is ‘integer’ (int), returns the ‘id’ of the user object.  


## Implementation Course Class
The ‘course’ class has the following data members:

Private members: string ‘course_name’, string ‘course_code’ and int ‘credit_hours’
Public members:
### course() constructor:
The class has a constructor that takes three arguments, one for each of the data members, and initializes them. The constructor has default parameter values of an empty string for the ‘name’ parameter, and 0 for the ‘course_code’ and ‘credit_hours’ parameters.

### read() function: 
The ‘read()’ function takes an (istream&) parameter and prompts the user to enter the course’s data, including the ‘course_name’, ‘code’, and ‘credit_hours’. The function reads the user’s input from the (istream&) and assigns the values to the appropriate data members. The return type of the ‘read()’ function is ‘void’, indicating that the function does not return any value.

### write() function: 
The ‘write’ function takes an (ostream&) parameter and outputs the course’s data to the stream, including ‘course_name’, ‘course_code’, and ‘credit_hours’. The return type of the ‘write()’ function is ‘void’, indicating that the function does not return any value, rather performs an action.

## Implementation Student Class
The code defines a ‘student’ class that is derived from the ‘user’ class. 
The data members of this class are as following:

Private members: double ‘gpa’, string ‘major’, double ‘fee_amount’, bool ‘fee_status’ and vector ‘courses’

Public members:
### student() constructor:
The ‘student’ class has a public constructor that initializes the ‘gpa’, ‘major’, ‘fee_amount’, ‘fee_status’, and ‘courses’ data members. 

*(Note: classes are written in bold italics, ‘functions()’ are written in bold with single quotation marks and ‘class_members’ are written in single quotation marks.)*

### read() function: 
It also has a ‘read()’ function that reads in values from the input stream. The ‘read’ function in this class uses the ‘user::read()’ function from the ‘user’ class to read in values for the base class data members. It also uses ‘course::read()’ to read values of course members and create a course object, which is then added to the ‘courses’ vector.

### friend ‘operator<<’ function:
The ‘student’ class also has a public ‘operator<<’ function that overloads the ‘<<’ operator to output the values of the data members to the output stream. The ‘operator<<’ function uses the ‘user::write()’ function from the ‘user’ class to output the base class data members. It then outputs the courses taken by the student, followed by the student’s ‘gpa’, ‘major’, ‘fee amount’ and ‘fee status’.

## Implementing Professor Class

The code defines a ‘professor’ class which is derived from the ‘user’ class.
private member: double ‘salary’, integer ‘num_courses’, string ‘department’ and string ‘start_date’.
Public members:
###	professor() constructor: 
The ‘professor’ class has a constructor that initializes its private member variables using the ‘user’ constructor and the passed parameters. The private member variable ‘salary’ and ‘num_courses’ have a default value of 0, and ‘department’ and ‘start_date’ have empty string as their default value. In the constructor of the ‘professor’ class, these member variables are initialized using the passed parameters. If no parameters are passed, the default values will be used.

###	read() function:
The member function named ‘read()’ that reads input from the user and sets the private member variables accordingly. This function first calls the ‘user::read()’ function to read the user data, then prompts the user to enter the data for the private variables, which are read using the input stream in.

###	write() function:
There is an overloaded insertion operator ‘<<’ that outputs the professor object to an output stream out. The function first calls the ‘user::write()’ function to output the user data, then outputs the private member variables of the ‘professor’ class.

## Implementing Template for the functionalities

The storing and manipulating of the student and professor data objects is done using linked lists. To make the code efficient and not have two different definitions of linked lists of each class type, a template class called ‘node’ and ‘manipulation’ is implemented. 

###	Node:
The members within the node class and their function are as follows:
  •	Template member ‘data’ - holds the student/professor object.
  •	Pointer member ‘next’ - holds the address of the next node within that linked list.
The methods of the ‘node’ class are as follows:
  •	A ‘node()’ constructor that takes the data to be stored as an argument and creates a node with NULL as next. 
  •	A ‘get_id()’ function that returns the id stored within the data member and takes no arguments. The method achieves this by using the ‘get_id()’ method that was  defined within the user class.
  
### Manipulation:
The members within the ‘manipulation’ class and their function are as follows:
  •	Pointer member ‘start’- holds the address of the first node of the linked list
  •	Integer member ‘count’- keeps track of the number of entries within the linked list
The methods of the ‘manipulation’ class are as follows:
  1) A constructor of an empty stack
  2) A ‘push()’ method that takes an argument of template class type and pushes a node that holds that passed argument as data into the linked list into the right position. The program is designed to maintain a database sorted by name and achieves this by using insertion sort. The method does the following to achieve its functionality:
    a) Create a new node using the data item passed to it. 
    b) Checks if the ‘ID’ of the new node is 4 digits and unique. This is done using the ‘searcher()’ method described within the methods of this class and the external function ‘len_check()’ described within external functions section.
    c) If confirms that the ID’s unacceptable, then it displays the appropriate error message, deletes the node and returns the control back to the function call. However, if the ID is found acceptable the sorting algorithm searches for the position of the new node based on ‘name’.
    d) Once the position has been found the new node is pushed there and the count is updated.
  3) A ‘get_count()’ method that takes no arguments and returns the count integer.
  4) A ‘ifempty()’ method that checks for an empty list and returns a boolean value of true if it is empty. It achieves this by checking if count=0.
  5) A ‘print_list()’ method that takes the argument of ostream and returns the ostream once it's done. The main functionality of this method is to parse through the linked list and print the data stored within to the ostream. This method uses the overloaded operators within student and professor class to achieve this.
  6) A ‘delete_item()’ method that takes no arguments and deletes an item within the linked list. This method first requests the user to input the ID of the entry they want to delete within the list. It then uses a linear searching algorithm to search for the node that holds the ID. If found the linked list is updated to remove the node from the list, the node is deleted, and the method ends. If the ID is not found the appropriate message is displayed and the method ends.
  7) A ‘clear()’ method that takes no arguments and deletes each node of the linked list by parsing through it.
  8) A ‘search()’ method that takes no arguments but returns a boolean value. This method is used to take an input ID from the user and pass it to the ‘searcher()’ method. The returned boolean value from this method is used to display the appropriate message and is passed as the return value of the method. A return value of 1 is passed if found and 0 if not found.
  9) A ‘searcher()’ method that takes an argument of an integer and returns a boolean value. The searcher method has a boolean variable ‘found’ that is 0 by default. This method uses the ‘get_id()’ method to linearly search through the linked list for the node that contains the integer passed as an ID. If found it prints the data within node and then updates ‘found’ to 1. If the element is not found the boolean variable ‘found’ remains 0. Finally, the boolean variable found is returned.

# Limitations
While creating this database and running different test cases the team realized and identified a few limitations in this project. 
The identified limitations are:
1.	Utilizing a linked list to manage data input and perform other functionalities may present certain drawbacks. Specifically, locating the address of the stored data can become a complex task, impeding users' ability to access relevant information. Additionally, linked list requires additional memory to store the pointers that link each element in the list. 
2.	When the data is entered the list inside the database gets sorted as it goes. Therefore, this limits the user from knowing the actual order that the data was entered. Nevertheless, the team contends that this approach enhances code concision and overall efficiency.
3.	This database exhibits a considerable level of memory usage due to the utilization of a linked list by the team. Nevertheless, there is no occurrence of memory leakage as no memory is released, given that when the dynamic elements used in the code were deleted the memory allocated to them was also released.
4.	This database does not allow the users to edit the information on the saved data. 

# System Failure
The system only fails if any invalid data type is added example, for ‘int’ number of courses if we add an entry of data type ‘string’ the system goes into an infinite loop of asking for selections.

# Recomendation
For any future designing of data structure that handles similar functionalities, some of the recommendations would be:
  1.	Working with vectors to perform the functionalities since in vectors entries are added contiguously, which also makes sorting them in any desired order easier.
  2.	Modifying or updating information of the saved data. 
  3.	Having a better way of handling incorrect data type added.


 














