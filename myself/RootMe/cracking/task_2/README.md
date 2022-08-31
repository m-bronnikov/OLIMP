## ELF x86 - Basic

### Task

Extract password from provided executable in linux gcc x86 format.

### Solution

#### Easy worst solution

Dump all segment rodata from exe using:

```
objdump -s -j .rodata ch2.bin > rodata
```

Take correct login, password and even result.

```asm
ch2.bin:     формат файла elf32-i386

Содержимое раздела .rodata:
 80a6ae0 03000000 01000200 2573203a 20222573  ........%s : "%s
 80a6af0 220a0041 6c6c6f63 6174696e 67206d65  "..Allocating me
 80a6b00 6d6f7279 00526561 6c6c6f63 6174696e  mory.Reallocatin
 80a6b10 67206d65 6d6f7279 006a6f68 6e007468  g memory.john.th
 80a6b20 65207269 70706572 00000000 23232323  e ripper....####
 80a6b30 23232323 23232323 23232323 23232323  ################
 80a6b40 23232323 23232323 23232323 23232323  ################
 80a6b50 23232323 23232323 23232323 23232323  ################
 80a6b60 23232323 23232323 00000000 23232020  ########....##  
 80a6b70 20202020 20204269 656e7665 6e6e7565        Bienvennue
 80a6b80 2064616e 73206365 20636861 6c6c656e   dans ce challen
 80a6b90 67652064 65206372 61636b69 6e672020  ge de cracking  
 80a6ba0 20202020 20202323 00000000 23232323        ##....####
 80a6bb0 23232323 23232323 23232323 23232323  ################
 80a6bc0 23232323 23232323 23232323 23232323  ################
 80a6bd0 23232323 23232323 23232323 23232323  ################
 80a6be0 23232323 23232323 0a007573 65726e61  ########..userna
 80a6bf0 6d653a20 00706173 73776f72 643a2000  me: .password: .
 80a6c00 39383736 35343332 31000000 4269656e  987654321...Bien
 80a6c10 206a6f75 652c2076 6f757320 706f7576   joue, vous pouv
 80a6c20 657a2076 616c6964 6572206c 27657072  ez valider l'epr
 80a6c30 65757665 20617665 63206c65 206d6f74  euve avec le mot
 80a6c40 20646520 70617373 65203a20 25732021   de passe : %s !
 80a6c50 0a004261 64207061 7373776f 72640042  ..Bad password.B
 80a6c60 61642075 7365726e 616d6500 46415441  ad username.FATA
 ...
```

### Nice solution

1. Launch [gdb](gdb).
2. Disassamble function main.
3. Find calls of `strcmp` and set breakpoints right after them (to `test` isa which checks result).
4. Set result register (`eax`) to zero to avoid execution break
5. Obtain result message with password.


```cpp
$ gdb ch2.bin
(gdb) set disassembly-flavor intel
(gdb) disas main
...
   0x08048373 <+106>:	call   0x80502f0 <strcmp>
   0x08048378 <+111>:	test   eax,eax
   0x0804837a <+113>:	jne    0x80483d0 <main+199>
   0x0804837c <+115>:	mov    DWORD PTR [esp],0x80a6bf5
   0x08048383 <+122>:	call   0x8048db0 <printf>
   0x08048388 <+127>:	mov    eax,DWORD PTR [ebp-0x8]
   0x0804838b <+130>:	mov    DWORD PTR [esp],eax
   0x0804838e <+133>:	call   0x804826a <getString>
   0x08048393 <+138>:	mov    DWORD PTR [ebp-0x8],eax
   0x08048396 <+141>:	mov    eax,DWORD PTR [ebp-0x10]
   0x08048399 <+144>:	mov    DWORD PTR [esp+0x4],eax
   0x0804839d <+148>:	mov    eax,DWORD PTR [ebp-0x8]
   0x080483a0 <+151>:	mov    DWORD PTR [esp],eax
   0x080483a3 <+154>:	call   0x80502f0 <strcmp>
   0x080483a8 <+159>:	test   eax,eax
...
(gdb) break *0x08048378
Breakpoint 1 at 0x8048378
(gdb) break *0x080483a8
Breakpoint 2 at 0x80483a8
(gdb) start
Temporary breakpoint 3 at 0x8048317
Starting program: /home/mbronnikov/Study/OLIMP/myself/RootMe/cracking/task_2/ch2.bin 

Temporary breakpoint 3, 0x08048317 in main ()
(gdb) continue
Continuing.
############################################################
##        Bienvennue dans ce challenge de cracking        ##
############################################################

username: name

Breakpoint 1, 0x08048378 in main ()
(gdb) set $eax=0
(gdb) continue
Continuing.
password: pass

Breakpoint 2, 0x080483a8 in main ()
(gdb) set $eax=0
(gdb) continue
Continuing.
Bien joue, vous pouvez valider l'epreuve avec le mot de passe : 987654321 !
[Inferior 1 (process 11642) exited normally]
(gdb) q
```


### Answer 

Password is `987654321`.