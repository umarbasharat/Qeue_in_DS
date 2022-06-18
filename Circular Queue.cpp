///part2 
//CIRCULAR QUEUE BY USING ONLY REAR POiNTER


#include<iostream>
using namespace std;

template<typename T>
struct Node
{
	T data;
	Node *next;
};


template<typename T>
class Queue
 {
  private:
   	Node<T> *rear;
  public:
  Queue()
  {
	rear=NULL;
  }

  void enque(T v)
  {
	Node<T> *temp;
	temp=new Node<T>;
	temp->data=v;
//	temp->next=NULL;
	
	if(rear==NULL) //IF QUEUE IS EMPTY
	{
		rear=temp;
		rear->next=rear;
	}
	
	else
	{
		temp->next=rear->next;    //here address of previous node is assigned to temp
		rear->next=temp;       //address of temp (that is new node) is assigned to qrear next
		rear=temp;
	
	}
	
  }  


  T deque()
  {
	T v;
	Node<T> *temp;
	temp=rear->next; 
	v=temp->data;  
	rear->next=temp->next;
// rear->next=temp;
	delete temp;
	return v;

  }


  bool isEmpty()
 {
	return (rear==NULL); 
     
 }


  bool isfull()
   {
   	Node<T> *temp;
	temp=rear;
	if(temp==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
   }


  void makeEmpty()
  {
   while(!isEmpty())
  {
	deque();
  } 
  }


  ~Queue()
  {
	makeEmpty();
  }

};


int main()
{
	Queue<int> Q;
	Q.enque(22);
	Q.enque(21);
	Q.enque(31);
	Q.enque(40);
	Q.enque(67);
	Q.enque(89);
	Q.enque(95);
	
	cout<<"   deque values are  :"<<endl;

    cout<<"\t\t\t"<<Q.deque()<<endl;
    cout<<"\t\t\t"<<Q.deque()<<endl;
	cout<<"\t\t\t"<<Q.deque()<<endl;
	cout<<"\t\t\t"<<Q.deque()<<endl;
	cout<<"\t\t\t"<<Q.deque()<<endl;
	cout<<"\t\t\t"<<Q.deque()<<endl;
	cout<<"\t\t\t"<<Q.deque()<<endl;
	system("pause");
	
}
