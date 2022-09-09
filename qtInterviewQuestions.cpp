What is Qt?
-> Qt is a cross platform aapplication framework, widely used for developing 
   application software that can be run on various software and hardware platforms

What is a framework?
-> Essential supporting structure of an object
-> Special case of software libraries that they are reusable of code wrapped in
   a well defined API which is overridden by user.

Whaat is qmake?
-> qmake is a utility that automates the generation of makefiles.
Makefiles are used by the program make to build executable programs from 
source code. There for qmake is make-makefile

qmake does not call g++/gcc directly. Instead creates native make files 
according to your system. Linux->GNU make file, Windows->Visual Studio Makefile

What is QML?
-> Stands for Qt Meta Language or Qt Modelling Language. It is a language like C++

What is Qts Meta Object System?
-> provides signals and slots mechanism for inter object communication,
run time type information, dynamic property system
    -> QObject class provides a base class for objects that can take 
       advantage of the meta-object system
    -> Q_OBJECT macro inside the private section of the class declaration
       is used to enable meta-object features, such as signals and slots
    -> The Meta-Object Compiler (moc) supplies each QObject subclass with the 
       necessary code to implement  meta-object features.
       moc reads a c++ source file, if it finds one or more class declaration
       that contaion Q_OBJECT macro, it produces another c++ source file which
       contains the metaobject code for each of those classes
    
What are limitations if Moc?
-> moc does not handle all of c++
-> the main problem is that class templates cannot have signals or slots
-> signal/slot return types cannot be references
-> nested classes cannot have signals or slots

What is QVariant?
-> QVariant is a container of variables. It can store variables of different types.
   similar in someway to void* but it provides you information about the stored type
   it can be used to return different types of values from a function

What is QtWidgets?
-> basic building blocks for GUI. Each widget is provided by a subclass of QWidget which
it self is a subclass of QObject 

How to call a c++ function from a QML?
-> Through setContext property. 

What are 4 ways of Integrating C++ with QML?
-> 

