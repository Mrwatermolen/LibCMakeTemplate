#include "my_add/my_add.h"
#include "my_sub/my_sub.h"

#include <my_math/my_math.h>

int MyMath::add(int a, int b) { return MyAdd::add(a, b); }

int MyMath::sub(int a, int b) { return MySub::sub(a, b); }
