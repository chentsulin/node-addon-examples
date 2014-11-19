#include <node.h>
#include <v8.h>

using namespace v8;

Handle<Value> SayHelloWorld(const Arguments& args) {
    HandleScope scope;
    return scope.Close(String::New("Hello world!"));
}

void Init_Hello_World(Handle<Object> target) {
    target->Set(String::NewSymbol("sayHelloWorld"), FunctionTemplate::New(SayHelloWorld)->GetFunction());
}

NODE_MODULE(hello, Init_Hello_World);