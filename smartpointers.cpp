#include <iostream>
#include <memory>

using namespace std;

class Entity {
public:
    Entity()
    {
        cout << "Creaated Entity" << endl;
    }
    ~Entity()
    {
        cout << "Destroyed Entity" << endl;
    }

};

auto f(std::unique_ptr<Entity> entity){
    
}


int main(){

    //std::unique_ptr<Entity> entity(new Entity());
    //will destroyed automatically when scope ends
    //copy constructor of unique is deleted, you cannot assign another 
    //pointer in to entity std::unique_ptr<Entity> e0 = entity;
    std::unique_ptr<Entity> entity = std::make_unique<Entity>();
    
    //will destroyed automatically when scope ends
    //you can assign another pointer in to entity
    // std::shared_ptr<Entity> e0 = sharedEntity;
    std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();


    //weak pointer 
    //it wont keep alive, it gets the reference of the shared pointer if it is alive
    //It must be converted to std::shared_ptr in order to access
    // the referenced object.

    //std::weak_ptr models temporary ownership: when an object 
    //needs to be accessed only if it exists, 
    //and it may be deleted at any time by someone else, std::weak_ptr is used to track the object, and it is converted to std::shared_ptr to assume temporary ownership.
    
    std::weak_ptr<Entity> weakEntity = sharedEntity;



    return 0;
}