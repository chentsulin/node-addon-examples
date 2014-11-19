#include <node.h>
#include <v8.h>

using namespace v8;

struct person {
    char name[30];
    int  age;
    bool isMale;
};

typedef struct person Person;

Person john = { "John", 24, true  };
Person amy  = { "Amy" , 18, false };
Person tim  = { "Tim" , 25, true  };

Handle<Value> GetArray(const Arguments& args) {
    HandleScope scope;

    Handle<Array> result = Array::New(3);
    Handle<Object> person1 = Object::New();
    person1->Set(String::New("name"), String::New(john.name));
    person1->Set(String::New("age"), Number::New(john.age));
    person1->Set(String::New("isMale"), Boolean::New(john.isMale));

    Handle<Object> person2 = Object::New();
    person2->Set(String::New("name"), String::New(amy.name));
    person2->Set(String::New("age"), Number::New(amy.age));
    person2->Set(String::New("isMale"), Boolean::New(amy.isMale));

    Handle<Object> person3 = Object::New();
    person3->Set(String::New("name"), String::New(tim.name));
    person3->Set(String::New("age"), Number::New(tim.age));
    person3->Set(String::New("isMale"), Boolean::New(tim.isMale));

    result->Set(0, person1);
    result->Set(1, person2);
    result->Set(2, person3);

    return scope.Close(result);
}

void Init(Handle<Object> exports) {
    exports->Set(String::NewSymbol("getArray"), FunctionTemplate::New(GetArray)->GetFunction());
}

NODE_MODULE(array, Init);