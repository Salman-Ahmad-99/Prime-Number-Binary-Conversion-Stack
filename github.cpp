#include<iostream>
#include<string>
using namespace std;

class Node
{
	private:
	Node* nextnode;
	int object;
	
	public:
		
		void set_object(int object)
		{
		this->object=object;	
	    } 
		
		int get_object()
		{
			return object;
		}
        
		void set_nextnode(Node* nextnode)
	   {
	   	this->nextnode=nextnode;
	    }	
	    
	    Node* get_nextnode()
	    {
	    	return nextnode;
	    }
       
};

class NumberStack
{
	private:
	Node* top;
	public:
		NumberStack()
		{
			top=NULL;
		}
    
    void push(int object)
    {
    	Node* newnode=new Node;
    	newnode->set_object(object);
    	newnode->set_nextnode(top);
    	top=newnode;
	}
   
   
   int pop()
   {
   	if(top==NULL)
   	{
   		cout<<"Stack is empty";
   		return -1;
	   }
	else
	{
	Node* temp=top;
	int object = temp->get_object();
	top=top->get_nextnode();
	
	delete temp;
	
	return object;	
	}   
	
	}
   
   bool isprime(int num)
   {
   	if(num<=1)
   	{
   		return false;
	   }
   for(int i=2;i<num;i++)
   {
   	if(num%i==0)
   	{
   		return false;
	   }
   	
   }
   return true;
   }
   
   int countprime()
   {
   	int count=0;
   	Node* current=top;
   	while(current!=NULL)
   	{
	if(isprime(current->get_object()))
	{
	count++;
	}
	current=current->get_nextnode();
	}
    return count;
	}
	
	int sumprime()
	{
		int sum=0;
		Node* current=top;
		while(current!=0)
		{
			if(isprime(current->get_object()))
			{
				sum = sum + current->get_object();
			}
		current=current->get_nextnode();
		}
		return sum;
	}
	
	void toBinary(int number)
	{
		NumberStack binaryStack;
		long long n=number;
		if(n<0)
		{
			cout<<"-";
			n=-n;
		}
		if(n==0)
		{
			binaryStack.push(0);
		}
		
		while(n>0)
		{
			int remainder= n%2;
			binaryStack.push(remainder);
			n=n/2;
		}
		
		while(binaryStack.top!=NULL)
		{
			cout<<binaryStack.pop();
			
		}
		cout<<endl;
		
	}
	
	~NumberStack()
	{
		while(top!=0)
		{
			pop();
		}
	}
	void display()
{
    if(top == NULL)
    {
        cout << "Stack is empty";
        return;
    }

    Node* current = top;

    cout << "Stack elements (Top to Bottom): ";

    while(current != NULL)
    {
        cout << current->get_object() << " ";
        current = current->get_nextnode();
    }
cout<<endl;    

}	 
  };
   
   
  int main()
  {
  	cout<<"************************************************************"<<endl;
  	string vuid="BC00000009";
  	cout<<"VU STUDENT ID: "<<vuid<<endl;
  	cout<<"************************************************************"<<endl;
  	NumberStack stack;
  	int lastdig=vuid[vuid.length()-1]-'0';
   stack.push(lastdig);
   stack.push(18);
   stack.push(23);
   stack.push(29);
   stack.push(55);
   stack.push(47);
   
   stack.display();
   cout<<endl;
   
   cout<<"Total Prime Numbers:"
   <<stack.countprime();
   cout<<endl;
   
   cout<<"Sum of Prime Number:"
   <<stack.sumprime();
   cout<<endl;
   
   cout<<"************************************************************"<<endl;
   
   int poppedNumber=stack.pop();
   cout<<"Popped Number:"
   <<poppedNumber;
   cout<<endl;
   
    cout<<"Binary of "<<poppedNumber<<":";
   stack.toBinary(poppedNumber);
   cout<<"************************************************************"<<endl;
   return 0;
   } 





