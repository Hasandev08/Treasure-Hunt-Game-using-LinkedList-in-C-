#include<iostream>
#include<windows.h>		//Header files
#include<stdlib.h>
using namespace std;

struct Node		//declaring struct to create nodes in the link list
{
	int data;	//1st part of linked list storing data														
	Node* next;	//2nd part of lined list that points to the next node
};

Node* insertAtStart(Node* head, int data)		//function for inserting data at the start of linked list
{
	Node* ptr = new Node();		//creating a new node that is to be inserted at the start
	ptr->data = data;	//passing the data entered the user
	ptr->next = NULL;	//passing the value NULL to the pointer pointing at next node

	ptr->next = head;
	head = ptr;

	return head;
}

void insertAtPos(Node* head, int data, int x)  //function for inserting data at any position in the linked list
{
	Node* ptr = head;		//creating a pointer pointing at the head of the linked list
	Node* ptr1 = new Node();	//creating a node that is to be inserted in the lined list
	ptr1->data = data;		//passing the data entered by the user
	ptr1->next = NULL;		//passing NULL to the pointer that points to the next node	

	x--;	//decrementing the position entered by the user

	while (x != 1)	//while loop
	{
		if (ptr)	//removing extensions
		{
			ptr = ptr->next;
		}
		x--;
	}

	if (ptr && ptr1)
	{
		ptr1->next = ptr->next;	//inserting the node in the list
		ptr->next = ptr1; //linking the nodes
	}
}

void insertAtEnd(Node* head, int data)		//function for inserting data at the end of the list
{
	Node* ptr;		//creating a pointer
	Node* temp = new Node();	//creating a new node

	ptr = head;		//pointer pointing at the head of the list

	temp->data = data;		//passing the data entered by the user into the node
	temp->next = NULL;		//passing NULL to the node's pointer that is pointing to next node

	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}

	ptr->next = temp;	//linking the node to linked list
}

void deleteNode(Node* head, int pos)	//function for deleting the node
{
	//creating 3 pointers pointing to head node
	Node* prevptr = head;
	Node* currentptr = head;
	Node* ptr = head;

	if (head == NULL)   //condition if the linked list is empty
	{
		cout << "List is empty " << endl;
	}

	else if (pos == 1)	//condition to delete the head node
	{
		head = head->next;
		free(prevptr);
		prevptr = NULL;
	}

	else     //condition for deleting any node in the linked list
	{
		while (pos != 1)	//when the position will become 1 the loop will be ended
		{
			prevptr = currentptr;
			currentptr = currentptr->next;
			pos--;
		}
		prevptr->next = currentptr->next;
		free(currentptr);
		currentptr = NULL;
	}
}

void updateNode(Node* head, int data, int pos)	//function for updating any data in the list
{
	Node* temp4 = new Node();	//creating a new node
	temp4->data = data;		//passing the data entered by the user to the new node created

	if (head == NULL)	//condition if there is no data in the list
	{
		cout << "List is empty " << endl;
	}

	else if (pos == 1)	//condition if the user wants to update the data present the 1st position of the list
	{
		head->data = temp4->data;
	}

	else   //condition if user wants to update data present at any position in the list
	{
		Node* ptr = head;  //creating a pointer that is pointing to the head pointer

		while (pos != 1 && ptr != NULL)
		{
			ptr = ptr->next;
			pos--;
		}

		if (ptr)
		{
			ptr->data = temp4->data;
		}
	}
}

void print(Node* head)		//function to print the linked list
{
	Node* ptr = head;		//creating a pointer pointing at the head

	if (head == NULL)	//condition if there is no data in the list
		cout << "The list is empty " << endl;

	while (ptr != NULL)
	{
		if (ptr)
		{
			cout << ptr->data << "->";	//printing the data of the list and then moving the pointer to next node
			ptr = ptr->next;
		}
	}

	cout << "\b\b  ";
	cout << endl;
	cout << endl;
}

int main()		//main function
{
	char a;
	int pos;		//declaration

	Node* head = new Node();
	Node* temp = new Node();
	Node* temp1 = new Node();		//creating different nodes
	Node* temp2 = new Node();
	Node* temp3 = new Node();
	Node* temp4 = new Node();
	Node* ptr = head;		//creating a pointer pointing at the head

	//passing data to the nodes
	head->data = 23;
	head->next = NULL;

	temp->data = 20;
	temp->next = NULL;
	head->next = temp;

	temp1->data = 28;
	temp1->next = NULL;
	temp->next = temp1;

	temp2->data = 36;
	temp2->next = NULL;
	temp1->next = temp2;

	temp3->data = 23;
	temp3->next = NULL;
	temp2->next = temp3;

	cout << "                              ****************************************************** " << endl;
	cout << "               ************************************************************************************ " << endl;
	cout << "               ***************                  Treasure Hunt game                  *************** " << endl;
	cout << "               ************************************************************************************ " << endl;
	cout << "                              ****************************************************** " << endl;
	system("Color 0C");
	cout << endl;
	cout << endl;

	cout << "Enter 'A' if you are an admin " << endl;	//asking the user if he/she is admin or player
	cout << "Enter 'P' if you are a player " << endl;
	cin >> a;

	if (a == 'A' || a == 'a')	//if user enters A he will get access to the admin part of the game
	{
		char operation;
		cout << "Hello Admin! The original list of clues is :  ";
		while (ptr != 0)
		{
			cout << ptr->data << "->";		//printing the original list for the admin so he can perform functions easily
			ptr = ptr->next;
		}
		cout << "\b\b  ";
		cout << endl;
		cout << endl;

		do
		{
			cout << "1. Insert a clue " << endl;
			cout << "2. Delete a clue " << endl;
			cout << "3. Update a clue " << endl;		//asking the admin which function he/she wants to perform
			cout << "4. Print " << endl;
			cout << "0. To End the program " << endl;
			cin >> operation;

			switch (operation)	//switch/case
			{
			case '1':	//case 1 if user wants to insert data
				char x;
				int data;

				cout << "Enter the clue that you want to store in the list " << endl;
				cin >> data;

				cout << "Select the options from following " << endl;
				cout << "1. If you want to insert the clue at the beginning " << endl;
				cout << "2. If you want to insert the clue at the any position " << endl;	//asking the user to where he/she wants to insert the data
				cout << "3. If you want to insert the clue at the end " << endl;
				cin >> x;

				switch (x)	//nested switch/case 
				{
				case '1':	//case 1 if user wants to insert data at start
					head = insertAtStart(head, data);	//calling the function to insert data at start
					temp4 = head;
					system("cls");
					cout << "                              ****************************************************** " << endl;
					cout << "               ************************************************************************************ " << endl;
					cout << "               ***************                  Treasure Hunt game                  *************** " << endl;
					cout << "               ************************************************************************************ " << endl;
					cout << "                              ****************************************************** " << endl;
					cout << endl;
					cout << endl;
					break;

				case '2':	//case 2 if user wants to insert data at any position
					cout << "Enter the position at which you want to insert the clue " << endl;
					cin >> pos;
					insertAtPos(head, data, pos);	//calling the function for inserting data at any position
					system("cls");
					cout << "                              ****************************************************** " << endl;
					cout << "               ************************************************************************************ " << endl;
					cout << "               ***************                  Treasure Hunt game                  *************** " << endl;
					cout << "               ************************************************************************************ " << endl;
					cout << "                              ****************************************************** " << endl;
					cout << endl;
					cout << endl;
					break;

				case '3':	//case 3 if user wants to input data at the end of the list
					insertAtEnd(head, data);	//calling the function for inserting the data at the end of the list
					system("cls");
					cout << "                              ****************************************************** " << endl;
					cout << "               ************************************************************************************ " << endl;
					cout << "               ***************                  Treasure Hunt game                  *************** " << endl;
					cout << "               ************************************************************************************ " << endl;
					cout << "                              ****************************************************** " << endl;
					cout << endl;
					cout << endl;
					break;
				}
				break;

			case '2':	//case 2 if user wants to delete any data from the list
				cout << "Enter the position at which you want to delete the data " << endl;	//asking the user to enter the position
				cin >> pos;																	//to delete data from
				deleteNode(head, pos);		//calling the delete function 
				system("cls");				//clearing the screen
				cout << "                              ****************************************************** " << endl;
				cout << "               ************************************************************************************ " << endl;
				cout << "               ***************                  Treasure Hunt game                  *************** " << endl;
				cout << "               ************************************************************************************ " << endl;
				cout << "                              ****************************************************** " << endl;
				cout << endl;
				cout << endl;
				break;

			case '3':	//case 3 if user wants to update any data from the list
				cout << "Enter the clue that you want to update with " << endl;		//asking the user to enter the data that he
				cin >> data;														//wants in the list
				cout << "Enter the position of the number that you want to update " << endl;		//asking the user to enter the poistion
				cin >> pos;																			//on which he wants the data to be updated
				updateNode(head, data, pos);		//calling the update function
				system("cls");						//clearing the screen
				cout << "                              ****************************************************** " << endl;
				cout << "               ************************************************************************************ " << endl;
				cout << "               ***************                  Treasure Hunt game                  *************** " << endl;
				cout << "               ************************************************************************************ " << endl;
				cout << "                              ****************************************************** " << endl;
				cout << endl;
				cout << endl;
				break;

			case '4':	//case 4 for printing the list
				print(head);	//calling the print function
				break;
			}
		} while (operation != '0');	//if user enters 0 the program will be ended
	}

	else if (a == 'P' || a == 'p')	//if user enter 'P' he will get access to the player part
	{
		int ans;
		int m = 5;
		int p = 5;
		int q = 5;		//declaring and intializing data
		int r = 5;
		int s = 5;
		char y;

		cout << "Let's begin the game " << endl;
		cout << endl;

	z:
		cout << "Question 1 : 2+3=?                 Clue = 1+1=11 " << endl;	//printing the q1 for the user
		cin >> ans;

		if (ans == head->data)	//checking if the answer is equal to the data in the 1st node
		{
			cout << "Congratulations! Level 1 completed " << endl;		//if the ans is correct 
			Beep(3000, 500);											//user will be asked to enter 'E'
			cout << endl;												//to move to the next question
			cout << "Press E to move to the next question " << endl;
			cin >> y;
			if (y == 'E' || y == 'e')
				system("cls");		//clearing the screen

			else
			{
				cout << "Invalid input " << endl;
				return 0;
			}
		b:
			cout << "                              ****************************************************** " << endl;
			cout << "               ************************************************************************************ " << endl;
			cout << "               ***************                  Treasure Hunt game                  *************** " << endl;
			cout << "               ************************************************************************************ " << endl;
			cout << "                              ****************************************************** " << endl;
			cout << endl;
			cout << endl;

			cout << "Question 2 : 4+5=?                  Clue = 2*2=4" << endl;   //asking q2
			cin >> ans;
			if (ans == temp->data)	//if the answer is equal to the data in the 2nd node this block will be accessed
			{
				cout << "Congratulations! Level 2 completed " << endl;
				Beep(3000, 500);
				cout << endl;
				cout << "Press E to move to the next question " << endl;
				cin >> y;
				if (y == 'E' || y == 'e')
					system("cls");	//clearing the screen

				else
				{
					cout << "Invalid input " << endl;
					return 0;
				}
			c:
				cout << "                              ****************************************************** " << endl;
				cout << "               ************************************************************************************ " << endl;
				cout << "               ***************                  Treasure Hunt game                  *************** " << endl;
				cout << "               ************************************************************************************ " << endl;
				cout << "                              ****************************************************** " << endl;
				cout << endl;
				cout << endl;

				cout << "Question 3 : 8+6=?                    Clue=2+2=8 " << endl;		//asking q3
				cin >> ans;
				if (ans == temp1->data)	//if the ans is equal to the data in the 3rd node this block will be accessed
				{
					cout << "Congratulations Level 3 completed " << endl;
					Beep(3000, 500);
					cout << endl;
					cout << "Press E to move to the next question " << endl;
					cin >> y;
					if (y == 'E' || y == 'e')
						system("cls");	//clearing the screen

					else
					{
						cout << "Invalid input " << endl;
						return 0;
					}
				d:
					cout << "                              ****************************************************** " << endl;
					cout << "               ************************************************************************************ " << endl;
					cout << "               ***************                  Treasure Hunt game                  *************** " << endl;
					cout << "               ************************************************************************************ " << endl;
					cout << "                              ****************************************************** " << endl;
					cout << endl;
					cout << endl;

					cout << "Question 4 : 2+6+3                            Clue = 2+3+4=24 " << endl;    //asking the q4
					cin >> ans;
					if (ans == temp2->data)		//if ans is equal to the 4th node this block is accessed
					{
						cout << "Congratulations! Level 4 completed " << endl;
						Beep(3000, 500);
						cout << endl;
						cout << "Press E to move to the next question " << endl;
						cin >> y;
						if (y == 'E' || y == 'e')
							system("cls");		//clearing the screen

						else
						{
							cout << "Invalid input " << endl;
							return 0;
						}
					e:
						cout << "                              ****************************************************** " << endl;
						cout << "               ************************************************************************************ " << endl;
						cout << "               ***************                  Treasure Hunt game                  *************** " << endl;
						cout << "               ************************************************************************************ " << endl;
						cout << "                              ****************************************************** " << endl;
						cout << endl;
						cout << endl;

						cout << "Question 5 : 3+7+2               Clue: 1+2+3=5" << endl;		//asking q5
						cin >> ans;

						if (ans == temp3->data)		//if ans is equal to the data present in the node 5 this block is accessed
						{
							cout << "Woo Hoo! You have won the game. Congratulations! " << endl;	//when the player will win this line printed
							Beep(3000, 1500);
							return 0;
						}
						else
						{
							for (int i = 0; i < m; i++)		//for loop to give user 5 tries for solving the problem
							{
								m--;

								if (m == 0)
								{
									cout << "Oops! Wrong answer. You have 0 tries remaining " << endl;	//when 0 tries are remaining this lock is accessed
									Beep(2000, 1500);	//a beep sound is produced on wrong answer
									cout << "Good Luck for next time " << endl;
									return 0;	//the program is ended
								}
								else
								{
									cout << "Oops! Wrong answer. (" << m << " tries remaining)" << endl;	//player is given 5 tries to solve the game
									Beep(2000, 700);	//on wrong answer a beep sound is produced
									cout << "Press 'Y' if you want to continue " << endl;		//asking the user if he wants to continue
									cout << "Press 'N' if you want to end the game " << endl;
									cin >> y;

									if (y == 'Y' || y == 'y')
									{
										system("cls");

										goto e;		//if user continues he will be asked the question again 
									}
									else if (y == 'N' || y == 'n')
									{
										cout << "Good Luck for next time " << endl;	//if user enter N the program will be ended
										return 0;
									}

									else
									{
										cout << "Invalid input " << endl;
										return 0;
									}
								}
							}
						}
					}
					else			//else part for other questions with same logic
					{
						for (int i = 0; i < p; i++)
						{
							p--;

							if (p == 0)
							{
								cout << "Oops! Wrong answer. You have 0 tries remaining " << endl;
								Beep(2000, 1500);
								cout << "Good Luck for next time " << endl;
								return 0;
							}
							else
							{
								cout << "Oops! Wrong answer. (" << p << " tries remaining)" << endl;
								Beep(2000, 700);
								cout << "Press 'Y' if you want to continue " << endl;
								cout << "Press 'N' if you want to end the game " << endl;
								cin >> y;

								if (y == 'Y' || y == 'y')
								{
									system("cls");
									goto d;
								}
								else if (y == 'N' || y == 'n')
								{
									cout << "Good Luck for next time " << endl;
									return 0;
								}

								else
								{
									cout << "Invalid input " << endl;
									return 0;
								}
							}
						}
					}
				}
				else         //else part for other questions with same logic
				{
					for (int i = 0; i < q; i++)
					{
						q--;

						if (q == 0)
						{
							cout << "Oops! Wrong answer. You have 0 tries remaining " << endl;
							Beep(2000, 1500);
							cout << "Good Luck for next time " << endl;
							return 0;
						}
						else
						{
							cout << "Oops! Wrong answer. (" << q << " tries remaining)" << endl;
							Beep(2000, 700);
							cout << "Press 'Y' if you want to continue " << endl;
							cout << "Press 'N' if you want to end the game " << endl;
							cin >> y;

							if (y == 'Y' || y == 'y')
							{
								system("cls");
								goto c;
							}
							else if (y == 'N' || y == 'n')
							{
								cout << "Good Luck for next time " << endl;
								return 0;
							}

							else
							{
								cout << "Invalid input " << endl;
								return 0;
							}
						}
					}
				}
			}
			else             //else part for other questions with same logic
			{
				for (int i = 0; i < r; i++)
				{
					r--;

					if (r == 0)
					{
						cout << "Oops! Wrong answer. You have 0 tries remaining " << endl;
						Beep(2000, 1500);
						cout << "Good Luck for next time " << endl;
						return 0;
					}
					else
					{
						cout << "Oops! Wrong answer. (" << r << " tries remaining)" << endl;
						Beep(2000, 700);
						cout << "Press 'Y' if you want to continue " << endl;
						cout << "Press 'N' if you want to end the game " << endl;
						cin >> y;

						if (y == 'Y' || y == 'y')
						{
							system("cls");
							goto b;
						}
						else if (y == 'N' || y == 'n')
						{
							cout << "Good Luck for next time " << endl;
							return 0;
						}

						else
						{
							cout << "Invalid input " << endl;
							return 0;
						}
					}
				}
			}
		}
		else                 //else part for other questions with same logic
		{
			for (int i = 0; i < s; i++)
			{
				s--;

				if (s == 0)
				{
					cout << "Oops! Wrong answer. You have 0 tries remaining " << endl;
					Beep(2000, 1500);
					cout << "Good Luck for next time " << endl;
					return 0;
				}
				else
				{
					cout << "Oops! Wrong answer. (" << s << " tries remaining)" << endl;
					Beep(2000, 700);
					cout << "Press 'Y' if you want to continue " << endl;
					cout << "Press 'N' if you want to end the game " << endl;
					cin >> y;

					if (y == 'Y' || y == 'y')
					{
						system("cls");

						cout << "                              ****************************************************** " << endl;
						cout << "               ************************************************************************************ " << endl;
						cout << "               ***************                  Treasure Hunt game                  *************** " << endl;
						cout << "               ************************************************************************************ " << endl;
						cout << "                              ****************************************************** " << endl;
						cout << endl;
						cout << endl;

						goto z;
					}
					else if (y == 'N' || y == 'n')
					{
						cout << "Good Luck for next time " << endl;
						return 0;
					}

					else
					{
						cout << "Invalid input " << endl;
						return 0;
					}
				}
			}
		}
	}

	return 0;
}