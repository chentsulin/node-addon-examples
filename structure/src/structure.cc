#include <node.h>
#include <v8.h>

using namespace v8;

struct person {
    char name[30];
    int  age;
    bool isMale;
};

typedef struct person Person;

Person john = { "John", 24, true };

Handle<Value> GetStructure(const Arguments& args) {
    HandleScope scope;
    Handle<Object> Result = Object::New();
    Result->Set(String::New("name"), String::New(john.name));
    Result->Set(String::New("age"), Number::New(john.age));
    Result->Set(String::New("isMale"), Boolean::New(john.isMale));
    return scope.Close(Result);
}

void Init(Handle<Object> target) {
    target->Set(String::NewSymbol("getStructure"), FunctionTemplate::New(GetStructure)->GetFunction());
}

NODE_MODULE(structure, Init);