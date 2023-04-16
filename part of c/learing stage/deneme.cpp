#include<iostream>


using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 
    class Box{
        private:
            int l;
            int b;
            int h;
            
        public:
            Box(int,int,int);
            Box();
            Box(Box &t);
            
            int getLength(); 
            int getBreadth (); 
            int getHeight ();  
            unsigned long long CalculateVolume(){
                unsigned long long sum = 1;
                sum *= this->l;
                sum *= this->b;
                sum *= this->h;
                return sum;
            }
            
            bool operator<(Box& B);
            friend ostream &operator<<(ostream& out, Box& B){
                out << B.l << " " << B.b << " " << B.h ;
                return out;
            }
    };
    
    Box::Box(int x,int y, int z): l(x), b(y), h(z){}
    Box::Box(): l(0), b(0), h(0){}
    Box::Box(Box &t){
        l = t.l;
        b = t.b;
        h = t.h;
    }
    


 int Box::getLength(){return l;} 
 int Box::getBreadth(){return b;}
 int Box::getHeight(){return h;}  
 


//Overload operator < as specified
 bool Box::operator<(Box& B){
    if (l < B.l){
        return true;
    }else if (l == B.l && b < B.b) {
        return true;
    }else if(l == B.l && b == B.b && h < B.h){
        return true;
    }
    
    return false;
 }

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}