
#include <iostream>

struct A
{
   char* data;

   A(const char* msg = 0)
      : data(msg ? new char[strlen(msg)] : 0)
   {
      if (msg)
      {
         memcpy(data, msg, strlen(msg));
      }
   }

   void say()
   {
      std::cout << data << std::endl;
   }

   ~A()
   {
      delete[] data;
   }
};

struct B : public A
{
   int *data;

   B() 
      : A()
      , data(new int(0))
   {}

   void say()
   {
      std::cout << *data << std::endl;
   }

   ~B()
   {
      delete data;
   }
};

int main(int, char**)
{
   A* a = new A("hello");
   B* b = new B();

   b->say();
   a->say();

   a = b;

   a->say();

   return 0;
}
