## ELF x86 - 0 protection

### Task

Extract password from provided executable in linux gcc x86 format.

### Solution

Just dump all string literals using `strings ch1.bin`:

```
/lib/ld-linux.so.2
__gmon_start__
libc.so.6
_IO_stdin_used
puts
realloc
getchar
__errno_location
malloc
stderr
fprintf
strcmp
strerror
__libc_start_main
GLIBC_2.0
PTRh@
[^_]
%s : "%s"
Allocating memory
Reallocating memory
123456789
############################################################
##        Bienvennue dans ce challenge de cracking        ##
############################################################
Veuillez entrer le mot de passe : 
Bien joue, vous pouvez valider l'epreuve avec le pass : %s!
Dommage, essaye encore une fois.
GCC: (GNU) 4.1.2 (Gentoo 4.1.2 p1.0.2)
GCC: (GNU) 4.1.2 (Gentoo 4.1.2 p1.0.2)
GCC: (Gentoo 4.3.4 p1.0, pie-10.1.5) 4.3.4
GCC: (Gentoo 4.3.4 p1.0, pie-10.1.5) 4.3.4
GCC: (GNU) 4.1.2 (Gentoo 4.1.2 p1.0.2)
GCC: (Gentoo 4.3.4 p1.0, pie-10.1.5) 4.3.4
GCC: (GNU) 4.1.2 (Gentoo 4.1.2 p1.0.2)
.symtab
.strtab
.shstrtab
.interp
.note.ABI-tag
.gnu.hash
.dynsym
.dynstr
.gnu.version
.gnu.version_r
.rel.dyn
.rel.plt
.init
.text
.fini
.rodata
.eh_frame
.ctors
.dtors
.jcr
.dynamic
.got
.got.plt
.data
.bss
.comment
ch1.c
_GLOBAL_OFFSET_TABLE_
__init_array_end
__init_array_start
_DYNAMIC
data_start
__errno_location@@GLIBC_2.0
strerror@@GLIBC_2.0
__libc_csu_fini
_start
getchar@@GLIBC_2.0
__gmon_start__
_Jv_RegisterClasses
_fp_hw
realloc@@GLIBC_2.0
_fini
__libc_start_main@@GLIBC_2.0
_IO_stdin_used
__data_start
getString
stderr@@GLIBC_2.0
__dso_handle
__DTOR_END__
__libc_csu_init
printf@@GLIBC_2.0
fprintf@@GLIBC_2.0
__bss_start
malloc@@GLIBC_2.0
_end
puts@@GLIBC_2.0
_edata
strcmp@@GLIBC_2.0
__i686.get_pc_thunk.bx
main
_init
printError
```

There is only `123456789` looks like a password, let's try it:

```
$ ./ch1.bin 
############################################################
##        Bienvennue dans ce challenge de cracking        ##
############################################################

Veuillez entrer le mot de passe : 123456789
Bien joue, vous pouvez valider l'epreuve avec le pass : 123456789!
```


### Answer 

Password is `123456789`.