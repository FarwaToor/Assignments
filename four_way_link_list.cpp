// C++ program to construct a 4_way linked list
// 
#include <iostream>
#include<string>
using namespace std;
void veli_insan ()
{
    cout << "/////////////////////////////////////////////////////////////////////////////////////////////" << endl<<endl;

    cout << "///////////////////////  |   | ||  | | /    |    |  ---/  ----   ///////////////////////////" << endl;
    cout << "///////////////////////  |   | | | | |/     |    |  ||     |     ///////////////////////////" << endl;
    cout << "///////////////////////  |__ | |  || |'|    |___ | /---    |     //////////////////////////" << endl<<endl;

    cout << "//////////////////////////////////////////////////////////////////////////////////////////" << endl;
}

class four_way
{
    private:


    struct node    // node of linked list having 3 data and 4 pointers
    {
    int data; string name; string address;    // data
    node* right,* down,* up,* left;           // pointers
    };
    int row, col;   // specified rows and cols


    public:


    node* mainhead = NULL;          // main head of four-way linked list
    node* temp = new node();
    // parametric constructor
    four_way(int r, int c)
    {
        row = r; col = c;
    }

    // making a node having all of it's components 
    node* newNode(int d,string n,string a)
    {

    node* temp = new node;
    temp->data = d; temp->name = n; temp->address = a;
    temp->right = temp->down = temp->left = temp->left = NULL;
    return temp;

    }


// function making r 2-way linked lists 
// and connect then with up and down pointers

    node* linked_list()
    {
        // dynamic array is having issues
    node* head[2];                  // indiviual heads of each 2 way linked list
    node* righttemp ,* newptr;
    int d;             // phone num
    string n, a;       // name and address

    // creating r linked lists
    // by setting all the right and left nodes of every row

    for (int i = 0; i < row; i++) {

        // initially set the head of ith row as NULL    

        head[i] = NULL;
        righttemp = head[i];

        for (int j = 0; j < col; j++) {

            cout << " enter the data : ";
            cin >> d;
            cout << " enter the name : ";
            cin.ignore();
            getline(cin, n);
            cout << " enter the address : ";
            getline(cin , a);
            cout << endl;
            newptr = newNode(d,n,a);
            // stores the data in the mainhead of the linked list
            // if it is null
            if (mainhead == NULL)
                mainhead = newptr;
            // checking head of each linked list; 
            if (head[i] == NULL)
            {
                head[i] = newptr;
            }
            // making left and right connections
            else
            {
                righttemp->right = newptr;   // temp->next-mew_ptr
                newptr->left = righttemp;
            }

            //  temp will move to new added ptr
            righttemp = newptr;    // temp = temp->next
        }
    }


    // Then, for every ith and (i+1)th list, we set the down pointers of every node of ith list  with its corresponding node of (i+1)th list

    for (int i = 0; i < row - 1; i++)
    {
        node* temp1 = head[i],* temp2 = head[i + 1];
        while (temp1 && temp2)
        {
            temp1->down = temp2;
            temp2->up = temp1;

            temp1 = temp1->right;
            temp2 = temp2->right;
        }
    }
    // return the mainhead pointer of the linked list
    return mainhead;
}



    void display()
    {
        
        node* right_ptr;
        node* head =mainhead ;
        node*down_ptr = head;
        while (down_ptr)            // loop until the down pointer is not NULL
        {
            right_ptr = down_ptr;   // initially, down and right pointer will be pointing to main head
            while (right_ptr)       // loop until the right pointer is not NULL
            {

            cout << right_ptr->name  <<" , "<< right_ptr->data <<" , " << right_ptr->address << "    ";

            right_ptr = right_ptr->right;

            }
            cout << endl<<endl;
            down_ptr = down_ptr->down;
        }
    }

    void search(string key)
    {
        
        node* right_ptr;
        node* head = mainhead;
        node* down_ptr = head;
        while (down_ptr)            // loop until the down pointer is not NULL
        {
            right_ptr = down_ptr;   // initially, down and right pointer will be pointing to main head
            while (right_ptr)       // loop until the right pointer is not NULL
            {
                if(right_ptr->name==key)
                cout << right_ptr->name << " , " << right_ptr->data << " , " << right_ptr->address << "    ";

                right_ptr = right_ptr->right;

            }
            cout << endl << endl;
            down_ptr = down_ptr->down;
        }
    }

    void swap(int num)
    {
        node* delt = new node(); 
        
        node* head = mainhead;

        node* down_ptr = head;

        node* right_ptr = down_ptr;
        while (down_ptr)            
        {
            right_ptr = down_ptr;   
            while (right_ptr)       
            {
                if (right_ptr->data == num)
                {
                    delt = right_ptr;
                }
                temp = right_ptr;
                right_ptr = right_ptr->right;

            }
            cout << endl << endl;
            
            down_ptr = down_ptr->down;
        }
        // swapping the node to delete and last node
        int temp1 = delt->data;
        delt->data = temp->data;
        temp->data = temp1;

        string temp2= delt->name;
        delt->name = temp->name;
        temp->name = temp2;

        string temp3 = delt->address;
        delt->address = temp->address;
        temp->address = temp2;
    }

    void del()
    {
        node* head = mainhead;
        int count = 0;
        node* down_ptr = head;

        node* right_ptr = down_ptr;
        while (down_ptr)
        {
            right_ptr = down_ptr;
            while (right_ptr)
            {
                count++;
                if (count==(row*col)-1)
                {
                    right_ptr->right=NULL;
                    delete right_ptr->right;
                }
                
                    right_ptr = right_ptr->right;
               

            }
                down_ptr = down_ptr->down;

        }

        display();
    }


    };


int main()
{
    veli_insan();
    int r, c;    // r = rows and c = columns
    r = 2, c = 2;
    string key;
    four_way f(r, c);
    f.linked_list();     // link list creation
    f.display();         // printing link list
    cout << endl;
    cout << " enter the name you want to find : ";
   // cin.ignore();
    getline(cin , key);
    f.search(key);       // searching node through name
    int num;
    cout << " enter the number you want to delete : ";      // linked list deletion
    cin >> num;
    f.swap(num);         // first we will swap
    f.del();             // then delete the node 
    

    return 0;
}