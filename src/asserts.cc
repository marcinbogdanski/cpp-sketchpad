#include <sstream>
#include <string>
#include <cassert>

bool some_function(){
    return false;
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

int main(){

  // assert(some_function());

  // raise(__FILE__, __LINE__, "This failed");

  // my_assert(some_function(), __FILE__, __LINE__);
    
  MY_ASSERT(some_function());
}

