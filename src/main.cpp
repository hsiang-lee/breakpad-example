#include <iostream>
#include <client/linux/handler/exception_handler.h>

bool DumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
                         void* context,
                         bool succeeded)
{
    std::cout << "Dump path:" << descriptor.path() << std::endl;
    return succeeded;
}

void Crash(){
    int* a = nullptr;
    *a = 1;
}

void Func() {
    Crash();
}

int main(int argc, char** argv) {
  google_breakpad::MinidumpDescriptor descriptor("/tmp");
  google_breakpad::ExceptionHandler eh(descriptor, nullptr, DumpCallback, nullptr, true, -1);

  Func();

  return 0;
}