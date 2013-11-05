#include <iostream>
#include <string>
struct node
{
        int data;
        node*previous;
};
class Q
{
public:
        Q(){};
        Q(const Q& rhs);
        Q(int s):size(s),numMembers(0){
                node n;
                n.data = 0;
                headnode = &n;
        };
        void enqueue(int n);
        int dequeue();
        void setHN(node* hn){ headnode=hn;};
        void setNM(int nm){numMembers=nm;};
        int getNM(){return numMembers;};
        node* getHN(){return headnode;};
		void print();
private:
        node* headnode;
		node* tailnode;
        int size;
        int numMembers;
};
Q::Q(const Q& rhs)
{
        this->headnode = rhs.headnode;
        this->size = rhs.size;
        this->numMembers = rhs.numMembers;
}
int Q::dequeue()
{
        if(numMembers == 0)
        {
                std::cout << "ERROR: DEQUEUE OF EMPTY QUEUE" << std::endl;
                return -50454;
        }
        int r = headnode->data;
		std::cout <<"r = "<< r <<std::endl;
        headnode = headnode->previous;
        numMembers--;
        return r;
 
}
void Q::print()	
{
	node* currNode = headnode;
	std::cout << "Current queue (" << numMembers << " members)" << std::endl;
	for(int i = 0; i<numMembers; i++)
	{
		if(i != numMembers-1)
			 std::cout << " | ";
		std::cout << currNode->data;
		currNode = currNode->previous;
	}
	std::cout << std::endl;

}
void Q::enqueue(int n)
{
        if(numMembers==size)
        {
                std::cout<< "ERROR: QUEUE FULL" << std::endl;
                return;
        }
        if(numMembers==0)
                {      
						std::cout <<"nm = 0"<<std::endl;
                        headnode->data = n;
						numMembers++;
                }
        else if(numMembers==1)
                {
                        std::cout <<"nm = 1"<<std::endl;
                        system("PAUSE");
                        node newNode;
                        newNode.data =n;
                        headnode->previous = &newNode;
						tailnode = &newNode;
                        numMembers++;
                }
        else
                {
                        std::cout <<"nm > 0 && nm < size"<<std::endl;
                        system("PAUSE");
                        node newNode;
                        newNode.data = n;
						tailnode->previous = &newNode;
						tailnode = &newNode;
                        numMembers++;
                }
}
 
int main()
{
        std::string input = "";
		Q q;
        while(input != "stop")
        {
                input = "";
                std::cout << "Command: ";
                std::cin.clear();
                std::cin >> input;
                
                int n = 0;
                if(input == "cq")
                {
                        std::cout<<"Enter the size of the queue: ";
                        std::cin>>n;
                        std::cout << "n = " << n << std::endl;
                        if(!std::cin)
                        {
                                std::cout << "ERROR: Queue size non-integer" << std::endl;
                        }
                        else
                        {
                                q = Q(n);
                        }
 
                }
                if(input == "eq")
                {
                        std::cout << "Enter the number to be queued: ";
                        std::cin>>n;
                        if(!std::cin)
                                std::cout << "ERROR: Enqueue input non-integer" << std::endl;
                        else
                                q.enqueue(n);
 
 
                }
                if(input == "dq")
                {
                        std::cout << "Dequeue: " << q.dequeue() << std::endl;
                }
				if(input == "print")
				{
				
					q.print();
				}
       
        }
return 0;
}