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

    Handle<Array> Result = Array::New(3);
    Handle<Object> Persion1 = Object::New();
    Persion1->Set(String::New("name"), String::New(john.name));
    Persion1->Set(String::New("age"), Number::New(john.age));
    Persion1->Set(String::New("isMale"), Boolean::New(john.isMale));

    Handle<Object> Persion2 = Object::New();
    Persion2->Set(String::New("name"), String::New(amy.name));
    Persion2->Set(String::New("age"), Number::New(amy.age));
    Persion2->Set(String::New("isMale"), Boolean::New(amy.isMale));

    Handle<Object> Persion3 = Object::New();
    Persion3->Set(String::New("name"), String::New(tim.name));
    Persion3->Set(String::New("age"), Number::New(tim.age));
    Persion3->Set(String::New("isMale"), Boolean::New(tim.isMale));

    Result->Set(0, Persion1);
    Result->Set(1, Persion2);
    Result->Set(2, Persion3);

    return scope.Close(Result);
}

void Init(Handle<Object> target) {
    target->Set(String::NewSymbol("getArray"), FunctionTemplate::New(GetArray)->GetFunction());
}

NODE_MODULE(array, Init);