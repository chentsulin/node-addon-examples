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
    Handle<Object> result = Object::New();
    result->Set(String::New("name"), String::New(john.name));
    result->Set(String::New("age"), Number::New(john.age));
    result->Set(String::New("isMale"), Boolean::New(john.isMale));
    return scope.Close(result);
}

void Init(Handle<Object> exports, Handle<Object> module) {

    Local<FunctionTemplate> tpl = FunctionTemplate::New();
    // tpl->InstanceTemplate()->SetInternalFieldCount(1);
    // tpl->SetClassName(String::New("Test"));
    NODE_SET_PROTOTYPE_METHOD(tpl, "getStructure", GetStructure);

    module->Set(String::NewSymbol("exports"), tpl->GetFunction());

}

NODE_MODULE(prototype, Init);