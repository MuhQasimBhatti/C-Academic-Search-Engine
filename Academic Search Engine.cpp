#include<fstream>
#include<string>
#include<iostream>
using namespace std;


ofstream f;
ifstream fr;

struct guide
{
	char title[20];
	char passage[2000];
	char newdet[1000];
};

struct book {
	guide g;
public:
	void write()
	{
		cout << "Title: ";
		cin.ignore();
		cin.getline(g.title, 20);
		cout << "Details: ";
		cin.getline(g.passage, 2000);
	//	cout << "new  details" << endl;
	//	cin.getline(g.newdet, 1000);
		write_to_file();
	}
	
	void display()
	{
		cout << g.title << endl;
		cout << "\t" << g.passage << endl;
		cout << "\n\n_____________________________________________________________________________________________" << endl;
	}

	void write_to_file()
	{
		f.open("Project File.txt", ios::in | ios::out | ios::app);
		f.write((char*)&g, sizeof(g));
		f.close();
	}

	void read_from_file()
	{
		fr.open("Project File.txt", ios::in | ios::out | ios::app);
		
		fr.read((char*)&g, sizeof(g));
		while (!fr.eof())
		{
			display();
			fr.read((char*)&g, sizeof(g));
		}
		fr.close();
	}

	void search_from_file(char kw[])
	{
		fr.open("Project File.txt", ios::in | ios::out | ios::app);

		fr.read((char*)&g, sizeof(g));
		while (!fr.eof())
		{
			search_title(kw);
			fr.read((char*)&g, sizeof(g));
		}
		fr.close();
	}

	void search_title(char kw[])
	{
		string A = g.title;


		//SEARCHING IN TITLE
		int i = 0;
		int j = 0;
		int k = 0;

		while ((A[i]) != 0)
			i++;
		i--;

		while (i >= j)
		{
			if (A[j] == (kw[k]))
			{
				k++;

			}
			else
				if (kw[k] == '\0')
					break;

				else
				{
					k = 0;

				}

			j++;
		}


		if (kw[k] == '\0')
			display();
		else
			search_passage(kw);
	}

	void search_passage(char kw[])
	{
		string B = g.passage;

		int i = 0;
		int j = 0;
		int k = 0;

		while (B[i] != 0)
			i++;
		i--;

		while (i >= j)
		{
			if (B[j] == kw[k])
			{
				k++;

			}
			else
				if (kw[k] == '\0')
					break;

				else
				{
					k = 0;

				}

			j++;
		}


		if (kw[k] == '\0')
			display();
	}
};

struct node
{
	book b;
	node* next = NULL;
	node* prev = NULL;
	node* head = NULL;
public:

	void create_node()
	{
		node* newnode = new node();
		newnode->b.write();
		if (head == NULL)
		{
			head = newnode;
		}
		else
		{
			node* temp = new node();
			temp = head;
			while (temp->next != NULL)
				temp = temp->next;
			newnode->prev = temp;
			temp->next = newnode;
		}
	}

	void display_nodes()
	{
		b.read_from_file();
		/*node* temp = new node();
		temp = head;
		if (temp == NULL)
			cout << "No data to show" << endl;
		else
		{
			while (temp != NULL)
			{
				temp->b.read_from_file();
				temp = temp->next;
			}
		}*/
	}

	void search_nodes(char kw[])
	{
		b.search_from_file(kw);
		/*node* temp = new node();
		temp = head;
		if (temp == NULL)
			cout << "No data to show" << endl;
		else
		{
			while (temp != NULL)
			{
				temp->b.search_from_file(kw);
				temp = temp->next;
			}
		}*/
	}
};

int main()
{
	char keyword[200];
	int menu, menu1, password;
	node obj;
	node disobj;
	//Welcome screen
	cout << "\t\t\t\t\tWELCOME TO C++ DICTIONARY" << endl << endl;

	do {
		cout << "\t\t\t\tSELECT MODE:" << endl;
		cout << "\t\t\t\t\t1. SERVER" << endl
			<< "\t\t\t\t\t2. CLIENT" << endl;
		cin >> menu1;

		//SERVER MODE
		if (menu1 == 1)
		{
			system("CLS");
			cout << "ENTER PASSWORD " << endl;
			cin >> password;
			if (password == 3339)
			{
				cout << "\t\tACCESS GRANTED" << endl;
				system("CLS");
				do
				{
					cout << "		1 Writing\n		2 Display\n	     0 Back to Menu" << endl;
					cin >> menu;
					switch (menu)
					{
					case 1:
					{
						obj.create_node();

						cout << "--------------------------------------------------" << endl;
					}

					break;

					case 2:
					{
						obj.display_nodes();
					}

					}
				} while (menu != 0);
			}
			else
				cout << "Access Denied" << endl;
		}

		//CLIENT MODE
		else if (menu1 == 2)
		{
			system("CLS");
			cout << "Hi, What are you looking for?" << endl;
			cin.ignore();
			cin.getline(keyword, 200);

			disobj.search_nodes(keyword);


		}

		else if (menu1 != 0)
			cout << "Damn! Please select the right mode....." << endl;

	} while (menu1 != 0);
	system("CLS");
	cout << "\n\n\n\t\t\t\t\tTHANKYOU!!!   TAKE CARE!!!" << endl;
	return 0;
}
