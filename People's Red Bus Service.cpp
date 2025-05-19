#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <iterator>
#include <fstream>
#include <time.h>
#include <windows.h>
using namespace std;
#define INF 0x3f3f3f3f
const int per_stop=4;
const float Time=0.9999;
bool flag=true;
class Node
{
public:
    string d;
    int seat_no;
    Node *next;
    Node *prev;

public:
    Node()
    {
        this->d = ' ';
        this->seat_no = 0;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(string d)
    {
        this->d = d;
        this->seat_no = seat_no;
        this->next = NULL;
        this->prev = NULL;
    }
};
static int st = 0;
class Reservation
{
public:
    Node *head = NULL;
    Reservation()
    {
        head = NULL;
    }
    void customer_enter(Node *&head, string d,int s)
    {
        Node *new_customer = new Node(d);
        if (head == NULL)
        {
            new_customer->prev = head;
            head = new_customer;
            new_customer->seat_no = st;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        st++;
        temp->next = new_customer;
        new_customer->prev = temp;
        new_customer->next = NULL;
        new_customer->seat_no = st;
        temp = new_customer;
    }
    void remove_customer(Node *&head, int s)
    {
        Node *temp = head;
        Node *temp2 = NULL;
        int c = 1;
        while (c != (s))
        {
            temp = temp->next;
            c++;
        }

        temp->seat_no = s;
        temp->d = "EmptySeat";
    }
    Node *remove_customer1(Node *&head)
    {
        if (head == NULL)
            return NULL;
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    void display_customerlist(Node *&head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << "[" << temp->d << "- " << temp->seat_no << "]->>";
            temp = temp->next;
        }
    }
    Node *sort_seatorder(Node *&head)
    {
        Node *temp = head;
        Node *temp2 = NULL;
        Node *newnode = new Node();
        Node *temp3 = newnode;
        int storage = 0;
        string st_storage; 
        while (temp->next != NULL)
        {
            temp2 = temp->next;
            while (temp2 != NULL)
            {
                if (temp->seat_no > temp2->seat_no)
                {
                    storage = temp->seat_no;
                    st_storage = temp->d;
                    temp->seat_no = temp2->seat_no;
                    temp->d = temp2->d;
                    temp2->seat_no = storage;
                    temp2->d = st_storage;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        return head;
    }
    void storedata(Node *&head)
    {
        ofstream obj;
        obj.open("PassengerList.txt");
        Node *temp = head;
        while (temp != NULL)
        {
            obj << endl
                << "Passenger Name: " << temp->d << endl
                << "Seat No: "
                << " " << temp->seat_no;
            temp = temp->next;
        }
    }
    void clearpassengerlist(Node *&head)
    {
        Node *temp = head;
        while (temp != NULL)
        {

            temp->d = "EmptySeat";
            temp = temp->next;
        }
    }
    void welcome()
    {
        cout << "\n\n";
        cout << "\t\t\t\t _______________________________________________\n";
        cout << "\t\t\t\t|                Reservation System            |\n";
        cout << "\t\t\t\t|                                              |\n";
        cout << "\t\t\t\t|       1. Book Ticket                         |\n";
        cout << "\t\t\t\t|       2. Cancel Ticket                       |\n";
        cout << "\t\t\t\t|       3. Sort List of Passengers             |\n";
        cout << "\t\t\t\t|       4. Display Passenger List              |\n";
        cout << "\t\t\t\t|       5. Clear Passenger Data                |\n";
        cout << "\t\t\t\t|       6. Exit From Reservation               |\n";
        cout << "\t\t\t\t|______________________________________________|\n";
    }

    int choices_enter(Reservation r1)
    {
        int choice, seat_no;
        string p_name;
    block:
        r1.welcome();
        cout << endl
             << "\t\t\t\tChoose your choice :  ";
        cin >> choice;
        if (choice == 1)
        {
            cout << endl
                 << "\t\t\t\tEnter Passenger Name: ";
            cin >> p_name;
            r1.customer_enter(head, p_name, 0);
            r1.storedata(head);
            cout << endl
                 << "\t\t\t\t||--------Passenger Successfully Entered------||" << endl
                 << endl;
            system("pause");
            system("cls");
            goto block;
        }
        if (choice == 2)
        {
            cout << endl
                 << "\t\t\t\tEnter Seat Number: ";
            cin >> seat_no;
            if (seat_no == 1)
            {
                r1.remove_customer1(head);
            }
            else
            {
                r1.remove_customer(head, seat_no);
            }
            r1.storedata(head);
            cout << endl
                 << "\t\t\t\t||--------Passenger Successfully Removed------||" << endl
                 << endl;
            system("pause");
            system("cls");
            goto block;
        }
        if (choice == 3)
        {
            cout << endl;
            r1.sort_seatorder(head);
            cout << endl
                 << "\t\t\t\t||--------List Successfully Sorted------||" << endl
                 << endl;
            system("pause");
            system("cls");
            goto block;
        }
        if (choice == 4)
        {
            cout << endl;
            r1.display_customerlist(head);
            cout << endl
                 << endl
                 << endl;
            system("pause");
            system("cls");
            goto block;
        }
        if (choice == 5)
        {
            cout << endl;
            r1.clearpassengerlist(head);
            r1.storedata(head);
            cout << endl
                 << "\t\t\t\t||--------List Successfully Cleared------||" << endl
                 << endl;
            system("pause");
            system("cls");
            goto block;
        }
        if (choice == 6)
        {
            return 0;
        }
        else
        {
            cout << endl
                 << "\t\t\t\t||-------Incorrect Choice-------||";
            system("cls");
            system("pause");
            goto block;
        }
    }
};

typedef pair<int, int> iPair;
class Graph
{
    int V;
    list<pair<int, int>> *adj;

public:
    Graph();
    Graph(int V);
    void addEdge(int u, int v, int w);
    vector<int> shortestPath(int s);
    void mainfun(Graph g);
    void printroutes();
    void welcome_main();
    void calprice(int d);
    void caltime(int d);
};
Graph::Graph()
{
}
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

vector<int> Graph::shortestPath(int src)
{
		priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    vector<int> dist(V, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

//        list<pair<int, int>>::iterator i;
//        for (i = adj[u].begin(); i != adj[u].end(); ++i)
//        {
//
//            int v = (*i).first;
//            int weight = (*i).second;
//
//            if (dist[v] > dist[u] + weight)
//            {
//                dist[v] = dist[u] + weight;
//                pq.push(make_pair(dist[v], v));
//            }
//        }
		for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
        {

            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
		
    }
    system("pause");
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
        system("pause");
    return dist;
}
void Graph::calprice(int d)
{
	
	
	if(flag==false){
		cout<<endl<<"Fare for the given Route: "<<d*per_stop<<" PKR";
	}else{
		cout<<endl<<"[Since path doesnot exist we can not calculate Fare]";
	}
	
	
}
void read(){
	ifstream file2;
        file2.open("dataset.txt");
        
        string tap;
        
        file2>>tap;
        file2>>tap;
        file2>>tap;
        file2>>tap;
        file2>>tap;
        file2>>tap;
        cout<<tap;
        
}
void Graph::caltime(int d)
{
	
	if(flag==false){
		cout<<endl<<"Estimated time to cover the Route: "<<d*Time<<" Min";
	}else{
		cout<<endl<<"[Since path doesnot exist we can not calculate Time]";
	}
	
}
void Graph::welcome_main()
{
    cout << "\n\n";
    cout << "\t\t\t\t____________________________________________________________\n";
    cout << "\t\t\t\t|                   PEOPLE'S RED BUS SERVICE                 |\n";
    cout << "\t\t\t\t|                                                            |\n";
    cout << "\t\t\t\t|      1. Reservation of Tickets                             |\n";
    cout << "\t\t\t\t|      2. Show Operational Routes in Service                 |\n";
    cout << "\t\t\t\t|      3. Shortest Route Between two Specified Locations     |\n";
    cout << "\t\t\t\t|      4. Exit                                               |\n";
    cout << "\t\t\t\t|____________________________________________________________|\n";
}
void printroutes()
{
    fstream my_file;
    my_file.open("stops.txt", ios::in);
    if (!my_file)
    {
        cout <<endl<< "No such file exists";
    }
    else
    {
        string ch1;
        string ch2;
        while (1)
        {
            my_file >> ch1;
            my_file>>ch2;
            if (my_file.eof())
                break;
            cout << endl
                 << ch1<<" "<<ch2;
        }
    }
    my_file.close();
    cout<<endl;
}
int main()
{
    system("color 40");
    Node *head = NULL;
    Reservation r1;
    int c;
    Graph g1;
    vector<string> v;
block:
    system("cls");
    g1.welcome_main();
    cout << "\n\t\t\t\tEnter your Choice: ";
    cin >> c;
    switch (c)
    {
    case 1:
        system("cls");
        r1.choices_enter(r1);
        goto block;
        break;
    case 2:
        printroutes();
        system("pause");
        goto block;
        break;
    case 3:
        goto dijikstra;
        goto block;
        break;
    case 4:
    	read();
        return 0;
    default:
        cout << "Invalid Choice!";
        return 0;
    }
dijikstra:
	
    ifstream file;
    file.open("dataset.txt");

    string tp;

    int count = 0;
    bool check = true;

    while (!file.eof())
    {
        file >> tp;
        for (int j = 0; j < v.size(); j++)
        {
            if (tp == v[j])
            {
                check = false;
                break;
            }
        }
        if (check == true)
        {
            count++;
            v.push_back(tp);
        }
        file >> tp;
        file >> tp;
        check = true;
    }
    file.close();
    Graph g(count);

    file.open("dataset.txt");
    int linecount = 0;
    while (getline(file, tp))
    {
        linecount++;
    }
    file.close();
    //	cout<<endl<<linecount<<endl;
    cout << endl
         << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << i << " " << v[i] << endl;
    }
    int size = linecount;
    struct read
    {
        string src;
        string dis;
        int distance;
    };
    int i = 0;
    file.open("dataset.txt");
    struct read r[size];
    while (!file.eof())
    {
        file >> r[i].src;
        file >> tp;
        file >> tp;
        file >> r[i].dis;
        file >> tp;
        file >> r[i].distance;
        i++;
    }
    i = 0;
    int k = 0, l = 0, m = 0;
    cout << endl
         << endl;
    file.close();
    for (int i = 0; i < size - 1; i++)
    {
        for (k = 0; k < v.size(); k++)
        {
            if (r[i].src == v[k])
                break;
        }
        for (l = 0; l < v.size(); l++)
        {
            if (r[i].dis == v[l])
                break;
        }
        if (m < size - 1)
        {
            g.addEdge(k, l, r[m].distance);
            m++;
            k = 0;
            l = 0;
        }
    }
    string sour, destination;
    cout << "\nEnter Source : ";
    cin >> sour;
    cout << "\nEnter Destination: " << destination;
    cin >> destination;
    for (i = 0; i < v.size(); i++)
    {
        if (sour == v[i])
        {
            break;
        }
    }
    int di = 0;
    for (di = 0; di < v.size(); di++)
    {
        if (destination == v[di])
        {
            break;
        }
    }

    vector<int> dist = g.shortestPath(i);
    system("cls");
    cout << endl
         << endl;
    system("pause");
    if (dist[di] > 1000)
    {
        cout << "\nPath Between " << sour << " and " << destination << " does not exist\n";
    }
    else
    {
    	flag=false;
        cout << "\nDistance Between " << sour << " and " << destination << ": " << dist[di] << " Km";
    }
    g.calprice(dist[di]);
    g.caltime(dist[di]);
    file.close();
    cout << endl
         << endl;
         
//        ifstream file2;
//        file2.open("dataset");
//        
//        string tap;
//        
//        file2>>tap;
//        file2>>tap;
//        file2>>tap;
//        file2>>tap;
//        file2>>tap;
//        file2>>tap;
//        cout<<tap;
//        
        read();
         return 0;
}
