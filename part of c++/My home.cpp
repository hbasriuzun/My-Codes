#include <iostream>
using namespace std;
    
class Entity
{
private:
public:
    int X,Y,Z;
    //Entity(int Xvalue, int Yvalue,int Zvalue);
    std::string GetName() {return "Entity" ;}

    void Move(int xa,int ya,int za){
        X = xa;
        Y = ya;
        Z = za;

    }

};


class Firnuiture : public Entity // make subclass
{
    private:
    std::string m_Name;
    
    public:
  //  Firnuiture(int Xvalue, int Yvalue,int Zvalue);
    Firnuiture(const std::string& name) : m_Name(name){}

    std::string GetName() {return m_Name ;}
    
};


int main(int argc, char const *argv[])
{
    Entity* e = new Entity();

    cout << e->GetName() << endl;

    Firnuiture* f = new Firnuiture("Coffe_Table");
    cout << f->GetName() << endl;



    return 0;
}

//Firnuiture::Firnuiture(int Xvalue,int Yvalue, int Zvalue) : X(Xvalue), Y(Yvalue), Z(Zvalue) {}
//Entity::Entity(int Xvalue,int Yvalue, int Zvalue) : X(Xvalue), Y(Yvalue), Z(Zvalue) {}

