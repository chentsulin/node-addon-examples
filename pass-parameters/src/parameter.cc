#include <node.h>
#include <v8.h>

using namespace v8;

Handle<Value> GetParameter(const Arguments& args) {
    HandleScope scope;
    Local<Value> arg;

    Handle<String> result = String::New("");

    if (args.Length() >= 2) {
        return ThrowException(
            Exception::TypeError(String::New("Too many arguments"))
        );
    } else if (args.Length() == 1) {

         arg = args[0];

    } else {
        return ThrowException(
            Exception::TypeError(String::New("No arguments"))
        );
    }

    if (arg->IsArray()) {
        Handle<Object> arr = arg->ToObject();

        int i, length = arr->Get(String::New("length"))->ToNumber()->Value();

        for (i = 0; i < length; i++) {
            result = String::Concat(result, arr->Get(i)->ToString());
        }

    } else if (arg->IsObject()) {
        Handle<Object> obj = arg->ToObject();

        Handle<Array> keys = obj->GetOwnPropertyNames();

        int i, length = keys->Get(String::New("length"))->ToNumber()->Value();

        for (i = 0; i < length; i++) {
            result = String::Concat(result, obj->Get(keys->Get(i))->ToString());
        }

    } else if (arg->IsBoolean()) {
        Handle<Boolean> b = arg->ToBoolean();

        if (b->Value()) {
            result = String::New("true");
        } else {
            result = String::New("false");
        }

    } else if (arg->IsNumber()) {
        Handle<Number> num = arg->ToNumber();

        double n = num->Value();

        char buffer[32];
        snprintf(buffer, sizeof(buffer), "%g", n);

        result = String::New(buffer);

    } else if (arg->IsString()) {
        Handle<String> s = arg->ToString();
        result = s;
    }


    return scope.Close(result);
}

void Init(Handle<Object> exports) {
    exports->Set(String::NewSymbol("getParameter"), FunctionTemplate::New(GetParameter)->GetFunction());
}

NODE_MODULE(parameter, Init);