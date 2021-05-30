#include <sstream>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

bool some_function(){
  return false;
}

bool throw_error(){
  throw std::invalid_argument("HoHoHo");
}

void raise(std::string file, int line, std::string msg = ""){
  std::ostringstream ss;
  ss << file << ":" << line << " " << msg;
  throw std::invalid_argument(ss.str());
}

void my_assert(bool cond, std::string file, int line){
  if(!cond){
    raise(file, line);
  }
}

#ifdef NDEBUG
#define MY_ASSERT( expr ) ((void)0)
#else
#define MY_ASSERT( expr ) \
  ( (expr) ? (void)0 : raise(__FILE__, __LINE__, #expr) )
#endif

#ifdef NDEBUG
#define MY_RAISES( expr ) ((void)0)
#else
#define MY_RAISES( expr )                   \
  {                                         \
    bool res = false;                       \
    try{                                    \
      expr;                                 \
    }catch(const std::invalid_argument&){   \
      res = true;                           \
    }                                       \
    MY_ASSERT(res);                         \
  }
#endif

int main(){

  // assert(some_function());

  // raise(__FILE__, __LINE__, "This failed");

  // my_assert(some_function(), __FILE__, __LINE__);
    
  // MY_ASSERT(some_function());

  try{
    MY_ASSERT(some_function());
  }
  catch (const std::invalid_argument&){
    cout << "exception" << endl;
  }

  MY_RAISES(throw_error());

  cout << "END" << endl;

}

