# Modern CPP
<p>This repository is aimed to cover Modern C++ topics in different versions such as C++11, 14, 17 and 20.</p>

### Configuration:
- Visual Studio IDE 2019 (*Optional*)
- C++ Language Standard: ISO C++20 Standard (/std:c++20)
- Assembly code Generation (Right Click on VS Solution > C/C++ > Output Files > Assembler Output --> Set Assembly with Source Code (/FAs)) (*Optional*)
- In VS IDE, set the solution config to "Debug" and solution platform to 'x64'

### Contents

#### Basic
1. [Naming conventions](./Basic/1_Prog_NamingConv.cpp)
2. [Calling conventions](./Basic/2_Prog_CallingConv.cpp)
3. [Default Class C'tor synthesization](./Basic/3_Prog_Default_Ctor.cpp)
4. [Virtual Functions](./Basic/4_Virtual_Functions.cpp)
5. [Multiple Inheritance](./Basic/5_VirtualFunc_MultipleInheritance.cpp)
6. [Class Object Destruction](./Basic/6_rValue_and_DtorScope.cpp)
7. [Exceptions and Vf table](./Basic/7_exception.cpp)
8. [Heap object creation](./Basic/8_new_operator_heap_obj_Creation.cpp)
9. [Order of initialization](./Basic/9_Order_of_initialization.cpp)

#### Intermediate
1. [Smart Pointers (with deep copy handling)](./Intermediate/1_smart_pointer.cpp)
2. [Callback Function (Template Method design pattern)](./Intermediate/2_callback.cpp)
3. [C++ Functors](./Intermediate/3_Functors.cpp)
4. [Template Specialization and Constexpr](./Intermediate/4_Template_Specialization.cpp)
5. [Move Constructor](./Intermediate/5_Move_Constructor.cpp)
6. [Variadic template function](./Intermediate/6_variadic_Function_TemplatePack.cpp)
7. [std::any datatype](./Intermediate/7_the_ANY_Datatype.cpp)

#### Advanced
1. [Type Inference](./Advanced/1_TypeInference.cpp)
2. [Tuple](./Advanced/2_tuple.cpp)
3. [std::Map](./Advanced/3_std_map.cpp)
4. [Designated Initializations](./Advanced/4_Designated_Initializations.cpp)
5. [Enum class](./Advanced/5_enum_class.cpp)
6. [std:: variant and std:: optional](./Advanced/6_std_variant_and_optional_type.cpp)

#### Assembly Ouput
Assembly output has been provided in 'asm/' folder (only for [Basic](#Basic)). This helps to know how the C++ code has been interpreted in the backend.

#### Tips
For searching a particular line in .asm file, type "; linenumber" in find window.
*Example: ; 20*