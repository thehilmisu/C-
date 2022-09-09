#include <iostream>
#include <unordered_map>
#include <string> 
#include <memory>

using namespace std;

class Plane
{
    
    string _plane;
    string _body;
    string _engine;

    public:
        Plane(string planeType) : _plane{planeType}{}
        void setEngine(string type) {_engine = type ;}
        void setBody(string body) {_body = body ;}

        string getEngine() {return _engine;}
        string getBody() {return _body;}

        void show(){
            cout << "Plane Type :" << _plane << endl
                 << "Body Type  :" << _body << endl
                 << "Engine Type:" << _engine << endl;
        }
};

class PlaneBuilder{
protected:
    Plane *_plane;
public:
    virtual void getPartsDone() = 0;
    virtual void buildBody() = 0;
    virtual void buildEngine() = 0;

    Plane* getPlane(){return _plane;}

};

class PropellerBuilder : public PlaneBuilder
{
public:
    void getPartsDone() { _plane = new Plane("Propeller Plane");}
    void buildBody() {_plane->setBody("Propeller Body");}
    void buildEngine() {_plane->setEngine("Propeller Engine");}

};

class JetBuilder : public PlaneBuilder
{
public:
    void getPartsDone() { _plane = new Plane("Jet Plane");}
    void buildBody() {_plane->setBody("Jet Body");}
    void buildEngine() {_plane->setEngine("Jet Engine");}

};


class Director{
public:
    Plane* createPlane(PlaneBuilder* builder){
        builder->getPartsDone();
        builder->buildBody();
        builder->buildEngine();
        return builder->getPlane();
    }
};

// Driver code 
int main() 
{ 
    Director dir;
    JetBuilder  jb;
    PropellerBuilder pb;

    Plane *jet = dir.createPlane(&jb);
    Plane *pro = dir.createPlane(&pb);

    jet->show();
    pro->show();

    delete jet;
    delete pro;

    return 0; 
} 