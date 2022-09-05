## ELF C++ - 0 protection

### Task

Extract password from provided executable in x86 ELF C++ format.

### Solution

1. Dump asm code of `main` using randar2 due to better symbols highlighting especially for cpp:

```bash
$ r2 ch25.bin
[0x08048890]> aaa
[x] Analyze all flags starting with sym. and entry0 (aa)
[x] Analyze all functions arguments/locals
[x] Analyze function calls (aac)
[x] Analyze len bytes of instructions for references (aar)
[x] Finding and parsing C++ vtables (avrr)
[x] Type matching analysis for all functions (aaft)
[x] Propagate noreturn information (aanr)
[x] Use -AA or aaaa to perform additional experimental analysis.
[0x08048890]> s main
[0x08048a86]> pdf
```

2. We are interested in following part of asm:

```asm
0x08048b7b      e8b0fcffff     call fcn.08048830
0x08048b80      8b4304         mov eax, dword [ebx + 4]
0x08048b83      83c004         add eax, 4
0x08048b86      8b00           mov eax, dword [eax]
0x08048b88      89442404       mov dword [esp+0x4], eax   ; int32_t arg_ch
0x08048b8c      8d45ec         lea eax, [ebp-0x14]
0x08048b8f      890424         mov dword [esp], eax       ; int32_t arg_8h
0x08048b92      e860010000     call method bool std::operator==<char, std::char_traits<char>, std::allocator<char> >(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, char const*) ; method.bool_std::operator_char__std::char_traits_char___std.allocator_char____std::basic_string_char__std::char_traits_char___std::allocator_char____const__char_const_
0x08048b97      84c0           test al, al
0x08048b99      744a           je 0x8048be5
```

This part could be decoded as:

* Load some value obtained after func call to `[esp + 0x4]` - second arg of `operator==`.
* Load some value from `[ebp - 0x14]` to `[esp]` - first arg of `operator==`.
* Call strings comparison for args `std::string&` and `const char*`.
* Compare result.

3. Open gdb, add breakpoint to `operator==` and run binary with random pass (as cmd line arg):

```bash
$ gdb ch25.bin
(gdb) break *0x08048b92
Breakpoint 1 at 0x8048b92
(gdb) run pass
Starting program: /home/mbronnikov/Study/OLIMP/myself/RootMe/cracking/task_4/ch25.bin pass

Breakpoint 1, 0x08048b92 in main ()
```

4. Since `[esp]` points to first arg of method - `std::string&`, references in cpp is just a beauty wrapper over pointers and `std::string` internally looks like:

```cpp
struct string{
    const char* data;
    int length;
    int capacity;
}
```

we need to dereference value from `esp` as `const char***` - pointer to pointer (operator arg) to string (Value) which allows to interpret first bytes of the struct as pointer:

```cpp
(gdb) x/s **(const char***) $esp
0x8050c8c:	"Here_you_have_to_understand_a_little_C++_stuffs"
```

5. Interestring that we can ensure in our thory about asm interpretation and evaluate value which was provided as `argv`:

```cpp
(gdb) x/s *(const char**) ($esp + 4)
0xffffd18b:	"pass"
```

We need to dereference only twice since we provide second arg `const char *` by value when first arg `std::string&` we provide by reference. 


### Answer 

Password is `Here_you_have_to_understand_a_little_C++_stuffs`
