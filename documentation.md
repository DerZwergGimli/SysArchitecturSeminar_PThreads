# POSIX 7

**Portable Operating System Interface**

[IEEE Std 1003.1-2008](http://pubs.opengroup.org/onlinepubs/9699919799/)



- Report about POSIX Standard with focus on
  - Shell and Utilities
  - System Interfaces
- Implement an Example of multi-threading in C

---

## Whats is POSIX?

POSIX is nowadays common standard for many Unix based operating systems. It was defined due to the fact that every computer manufacturers has there own standards how to interact with the system. With the POSIX Standard they became more cross-compatible and programs for one system don't needed to be rewritten to work on a other system of another manufacturer and vice versa. 

### Specification 

The specification of the User- and Software-Interfaces of the Operating System is in four parts separated, combined this is the IEEE 1003.1-2008 standard.

- Basic-definition: A List of the standard and its used conventions. definitions and concepts.
- System-interfaces: The system calls and the appropriate Header-Files.
- Command-line-interpreter and help-programs:  A list of help-programs and the command-line-interpreter.

---

### POSIX Definitions:

#### Base Definitions

1. [Introduction](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap01.html) 
2. [Conformance](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap02.html) 
3. [Definitions](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap03.html) 
4. [General Concepts](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap04.html) 
5. [File Format Notation](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap05.html) 
6. [Character Set](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap06.html) 
7. [Locale](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap07.html) 
8. [Environment Variables](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap08.html) 
9. [Regular Expressions](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap09.html) 
10. [Directory Structure and Devices](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap10.html) 
11. [General Terminal Interface](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap11.html) 
12. [Utility Conventions](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap12.html) 
13. [Headers](http://pubs.opengroup.org/onlinepubs/9699919799/idx/head.html) 

#### System Interfaces

1. [Introduction](http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap01.html)
2. [General Information](http://pubs.opengroup.org/onlinepubs/9699919799/idx/xsh_chap02.html)
3. [System Interfaces](http://pubs.opengroup.org/onlinepubs/9699919799/idx/functions.html) 

#### Shell & Utilities

1. [Introduction](http://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap01.html) 
2. [Shell Command Language](http://pubs.opengroup.org/onlinepubs/9699919799/idx/shell.html) 
3. [Batch Environment Services](http://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap03.html) 
4. [Utilities](http://pubs.opengroup.org/onlinepubs/9699919799/idx/utilities.html) 

---

**Most important things POSIX 7 defines**

1. [C API](http://pubs.opengroup.org/onlinepubs/9699919799/functions/contents.html)

   Greatly [extends ANSI C](https://stackoverflow.com/questions/9376837/difference-bewteen-c-standard-library-and-c-posix-library/37969420#37969420) with things like:

   - more file operations: `mkdir`, `dirname`, `symlink`, `readlink`, `link` (hardlinks), [`poll()`](https://stackoverflow.com/questions/12444679/how-does-the-poll-c-linux-function-work/44127590#44127590), `stat`, `sync`, [`nftw()`](https://stackoverflow.com/questions/8436841/how-to-recursively-list-directories-in-c-on-linux/29402705)
   - process and threads: `fork`, `execl`, `pipe`, semaphors [`sem_*`](https://stackoverflow.com/questions/16400820/how-to-use-posix-semaphores-on-forked-processes-in-c/52042490#52042490), shared memory (`shm_*`), `kill`, scheduling parameters (`nice`, `sched_*`), `sleep`, `mkfifo`, [`setpgid()`](https://stackoverflow.com/questions/6108953/how-does-ctrl-c-terminate-a-child-process/52042970#52042970)
   - networking: [`socket()`](https://stackoverflow.com/questions/11208299/how-to-make-an-http-get-request-in-c-without-libcurl/35680609#35680609)
   - memory management: `mmap`, `mlock`, `mprotect`, `madvise`, [`brk()`](https://stackoverflow.com/questions/6988487/what-does-the-brk-system-call-do/31082353#31082353)
   - utilities: regular expressions (`reg*`)

   Those APIs also determine underlying system concepts on which they depend, e.g. `fork` requires a concept of a process.

   Many [Linux system calls](https://unix.stackexchange.com/questions/421750/where-do-you-find-the-syscall-table-for-linux) exist to implement a specific POSIX C API function and make Linux compliant, e.g. `sys_write`, `sys_read`, ... Many of those syscalls also have Linux-specific extensions however.

   Major Linux desktop implementation: glibc, which in many cases just provides a shallow wrapper to system calls.

2. [CLI utilities](http://pubs.opengroup.org/onlinepubs/9699919799/utilities/contents.html)

   E.g.: `cd`, `ls`, `echo`, ...

   Many utilities are direct shell front ends for a corresponding C API function, e.g. `mkdir`.

   Major Linux desktop implementation: GNU Coreutils for the small ones, separate GNU projects for the big ones: `sed`, `grep`, `awk`, ... Some CLI utilities are implemented by Bash [as built-ins](https://unix.stackexchange.com/questions/11454/what-is-the-difference-between-a-builtin-command-and-one-that-is-not).

3. [Shell language](http://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18)

   E.g., `a=b; echo "$a"`

   Major Linux desktop implementation: [GNU Bash](https://en.wikipedia.org/wiki/Bash_(Unix_shell)).

4. [Environment variables](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap08.html#tag_08)

   E.g.: `HOME`, `PATH`.

   `PATH` [search semantics are specified](http://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_09_01_01), including [how slashes prevent `PATH` search](https://stackoverflow.com/questions/6331075/why-do-you-need-dot-slash-before-executable-or-script-name-to-run-it-in-bas/6331085#6331085). 

5. [Program exit status](http://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_08)

   ANSI C says `0` or `EXIT_SUCCESS` for success, `EXIT_FAILURE` for failure, and leaves the rest implementation defined.

   POSIX adds:

   - `126`: command found but not executable.

   - `127`: command not found.

   - `> 128`: terminated by a signal.

     But POSIX does not seem to specify the `128 + SIGNAL_ID` rule used by Bash: <https://unix.stackexchange.com/questions/99112/default-exit-code-when-process-is-terminated>

6. [Regular expression](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap09.html#tag_09)

   There are two types: BRE (Basic) and ERE (Extended). Basic is deprecated and only kept to not break APIs.

   Those are implemented by C API functions, and used throughout CLI utilities, e.g. `grep` accepts BREs by default, and EREs with `-E`.

   E.g.: `echo 'a.1' | grep -E 'a.[[:digit:]]'`

   Major Linux implementation: glibc implements the functions under [regex.h](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/regex.h.html) which programs like `grep` can use as backend.

7. [Directory struture](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap10.html#tag_10)

   E.g.: `/dev/null`, `/tmp`

   The Linux [FHS](https://en.wikipedia.org/wiki/Filesystem_Hierarchy_Standard) greatly extends POSIX.

8. [Filenames](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap03.html#tag_03_267)

   - `/` is the path separator
   - `NUL` cannot be used
   - `.` is `cwd`, `..` parent
   - portable filenames  
     - use at most max 14 chars and 256 for the full path
     - can only contain: `a-zA-Z0-9._-`

   See also: [what is posix compliance for filesystem?](https://stackoverflow.com/questions/18550253/what-is-posix-compliance-for-filesystem)

9. [Command line utility API conventions](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap12.html)

   Not mandatory, used by POSIX, but almost nowhere else, notably not in  GNU. But true, it is too restrictive, e.g. single letter flags only  (e.g. `-a`), no double hyphen long versions (e.g. `--all`).

   A few widely used conventions:

   - `-` means stdin where a file is expected
   - `--` terminates flags, e.g. `ls -- -l` to list a directory named `-l` 

   See also: [Are there standards for Linux command line switches and arguments?](https://stackoverflow.com/questions/8957222/are-there-standards-for-linux-command-line-switches-and-arguments)

10. "POSIX ACLs" (Access Control Lists), e.g. as used as backend for [`setfacl`](https://askubuntu.com/questions/487527/give-specific-user-permission-to-write-to-a-folder-using-w-notation/809562#809562).

    This [was withdrawn](https://unix.stackexchange.com/questions/489820/why-was-posix-1e-withdrawn) but it was implemented in several OSes, including [in Linux with `setxattr`](https://www.linuxquestions.org/questions/linux-kernel-70/system-call-to-set-file-acls-in-linux-537615/#post5988355).

**Who conforms to POSIX?**

Many systems follow POSIX closely, but few are actually certified by  the Open Group which maintains the standard. Notable certified ones  include:

- OS X (Apple) X stands for both 10 and UNIX. Was the first Apple POSIX system, released circa 2001. See also: [Is OSX a POSIX OS?](https://stackoverflow.com/questions/5785516/is-osx-a-posix-os)
- AIX (IBM)
- HP-UX (HP)
- Solaris (Oracle)

Most Linux distros are very compliant, but not certified because they don't want to pay the compliance check. [Inspur's K-UX](https://en.wikipedia.org/wiki/Inspur_K-UX) and [Huawei's EulerOS](https://www.huawei.com/en/press-events/news/2016/9/huawei-kunlun-euleros-unix-certification) are two certified examples.

The official list of certified systems be found at: <https://www.opengroup.org/openbrand/register/> and also at the [wiki page](https://en.wikipedia.org/wiki/POSIX#POSIX-oriented_operating_systems).

**Windows**

Windows implemented POSIX on some of its professional distributions. 

Since it was an optional feature, programmers could not rely on it for most end user applications. 

Support was deprecated in Windows 8:

- [Where does Microsoft Windows' 7 POSIX implementation currently stand?](https://stackoverflow.com/questions/4746043/where-does-microsoft-windows-7-posix-implementation-currently-stand)
- <https://superuser.com/questions/495360/does-windows-8-still-implement-posix>
- Feature request: <https://windows.uservoice.com/forums/265757-windows-feature-suggestions/suggestions/6573649-full-posix-support>

In 2016 a new official Linux-like API called "Windows Subsystem for  Linux" was announced. It includes Linux system calls, ELF running, parts  of the `/proc` filesystem, Bash, GCC, (TODO likely glibc?), `apt-get` and more: <https://channel9.msdn.com/Events/Build/2016/P488>  so I believe that it will allow Windows to run much, if not all, of  POSIX. However, it is focused on developers / deployment instead of end  users. In particular, there were no plans to allow access to the Windows  GUI. 

Historical overview of the official Microsoft POSIX compatibility: <http://brianreiter.org/2010/08/24/the-sad-history-of-the-microsoft-posix-subsystem/>

[Cygwin](http://www.cygwin.com/)  is a well known GPL third-party project for that "provides substantial  POSIX API functionality" for Windows, but requires that you "rebuild  your application from source if you want it to run on Windows". [MSYS2](https://sourceforge.net/projects/msys2/) is a related project that seems to add more functionality on top of Cygwin.

**Android**

Android has its own C library (Bionic) which does not fully support POSIX as of Android O: [Is Android POSIX-compatible?](https://stackoverflow.com/questions/27604455/is-android-posix-compatible)

**Bonus level**

The [Linux Standard Base](https://en.wikipedia.org/wiki/Linux_Standard_Base) further extends POSIX.

Use the non-frames indexes, they are much more readable and searchable: <http://pubs.opengroup.org/onlinepubs/9699919799/nfindex.html>

Get a full zipped version of the HTML pages for grepping:  [Where is the list of the POSIX C API functions?](https://stackoverflow.com/questions/453993/is-there-a-listing-of-the-posix-api-functions/45832939#45832939)

---



## a) System Interfaces

### a1) Introduction

The System Interfaces volume of POSIX.1-2017 describes the interfaces offered to application programs by POSIX-conformant systems.

#### Format of Entries

The entries in [*System Interfaces*](http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap03.html#tag_16) are based on a common format as follows. The only sections relating to conformance are the SYNOPSIS, DESCRIPTION, RETURN VALUE, and ERRORS sections.

- **NAME**

   This section gives the name or names of the entry and briefly states its purpose.

- **SYNOPSIS**

   This section summarizes the use of the entry being described. If it is necessary to include a header to use this function, the names of such headers are shown, for example:    `#include <stdio.h>  `  

- **DESCRIPTION**

   This section describes the functionality of the function or header.

- **RETURN VALUE**

   This section indicates the possible return values, if any.   If the implementation can detect errors, "successful completion" means that no error has been detected during execution of the function. If the implementation does detect an error, the error is indicated.  For functions where no errors are defined, "successful completion"  means that if the implementation checks for errors, no error has been detected. If the implementation can detect errors, and an  error is detected, the indicated return value is returned and *errno* may be set. 

- **ERRORS**

   This section gives the symbolic names of the error values returned by a function or stored into a variable accessed through the symbol *errno* if an error occurs.   ``No errors are defined" means that error values returned by a function or stored into a variable accessed through the symbol *errno*, if any, depend on the implementation. 

- **EXAMPLES**

   This section is informative.   This section gives examples of usage, where appropriate. In the event of conflict between an example and a normative part of this volume of POSIX.1-2017, the normative material is to be taken as correct. 

- **APPLICATION USAGE**

   This section is informative.   This section gives warnings and advice to application developers about the entry. In the event of conflict between warnings and advice and a normative part of this volume of POSIX.1-2017, the normative material is to be taken as correct. 

- **RATIONALE**

   This section is informative.   This section contains historical information concerning the contents of this volume of POSIX.1-2017 and why features were included or discarded by the standard developers. 

- **FUTURE DIRECTIONS**

   This section is informative.   This section provides comments which should be used as a guide to current thinking; there is not necessarily a commitment to adopt these future directions. 

- **SEE ALSO**

   This section is informative.   This section gives references to related information. 

- **CHANGE HISTORY**

   This section is informative.   This section shows the derivation of the entry and any significant changes that have been made to it. 



### a2) General Information

1. [Use and Implementation of Interfaces](http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_01)
2. [The Compilation Environment](http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_02) 
3. [Error Numbers](http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_03) 
4. [Signal Concepts](http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_04) 
5. [Standard I/O Streams](http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_05) 
6. [STREAMS](http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_06) 
7. [XSI Interprocess Communication](http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_07) 
8. [Realtime](http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_08) 
9. [Threads](http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_09) 
10. [Sockets](http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_10) 
11. [Tracing](http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_11) 
12. [Data Types](http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_12)
13. [Status Information](http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_13)
14. [File Descriptor Allocation](http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_14)



### a3) System Interfaces

[List of Interfaces](http://pubs.opengroup.org/onlinepubs/9699919799/idx/functions.html)

----



## b) Shell and Utilities

### b1) Introduction

The Shell and Utilities volume of POSIX.1-2017 describes the commands and utilities offered to application programs by POSIX-conformant systems.

### b2) Shell Command Language

The shell is a command language interpreter. This chapter describes the syntax of that command language as it is used by the [*sh*](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/utilities/sh.html) utility and the [*system*()](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/functions/system.html) and [*popen*()](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/functions/popen.html) functions defined in the System Interfaces volume of POSIX.1-2017.

The shell operates according to the following general overview of operations. The specific details are included in the cited sections of this chapter.

1. The shell reads its input from a file (see [*sh*](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/utilities/sh.html)), from the **-c** option or from the [*system*()](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/functions/system.html) and [*popen*()](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/functions/popen.html) functions defined in the System Interfaces volume of POSIX.1-2017. If the first line of a file of shell commands starts with the characters `"#!"`, the results are unspecified.
2. The shell breaks the input into tokens: words and operators; see [Token Recognition](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/utilities/V3_chap02.html#tag_18_03).
3. The shell parses the input into simple commands (see [Simple Commands](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/utilities/V3_chap02.html#tag_18_09_01)) and compound commands (see [Compound Commands](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/utilities/V3_chap02.html#tag_18_09_04)).
4. The shell performs various expansions (separately) on different parts of each command, resulting in a list of pathnames and fields to be treated as a command and arguments; see [*wordexp*](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/functions/wordexp.html#).
5. The shell performs redirection (see [Redirection](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/utilities/V3_chap02.html#tag_18_07)) and removes redirection operators and their operands from the parameter list.
6. The shell executes a function (see [Function Definition Command](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/utilities/V3_chap02.html#tag_18_09_05)), built-in (see [Special Built-In Utilities](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/utilities/V3_chap02.html#tag_18_14)), executable file, or script, giving the names of the arguments as positional parameters numbered 1 to *n*, and the name of the command (or in the case of a function within a script, the name of the script) as the positional parameter numbered 0 (see [Command Search and Execution](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/utilities/V3_chap02.html#tag_18_09_01_01)).
7. The shell optionally waits for the command to complete and collects the exit status (see [Exit Status for Commands](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/utilities/V3_chap02.html#tag_18_08_02)).



#### Shell Types

Most common:

- Bourne shell ( sh)
- Korn shell ( ksh)
- Bourne Again shell ( bash)
- POSIX shell ( sh)

The different C-type shells follow:

- C shell ( csh)
- TENEX/TOPS C shell ( tcsh)

Additional Information can be found [here](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/idx/shell.html). 



### b3) Batch Environment Services

This simply means that every command is processed after each other and not all commands will be executed at the same time.

There are things like:

- Batch Job Creation
- Batch Job Tracking
- Batch Job Routing
- Batch Job Execution
- Batch Job Exit
- Batch Job Abort
- Batch Administration
- Batch Notification
- Batch Services
- Batch Job States

=> If i understand this correctly this is the same as Windows (.bat) accordingly DOS (Disk Operating System).

This is then just a simple Script file that uses the POSIX defined shell commands to some work.?



### b4) Utilities

A List of all Shell Utilities can be found [here](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/idx/utilities.html).



## c) Topics of Examples 

What we will need here:

1. Thread Creation
2. Thread Destroy
3. Thread Communication
4. Thread Synchronization

---

You will need to include this file to work with `pThreads` in your Project: 

```c
#include <pthread.h>
```

Additional information  about pThreads can always be found in the [doc](https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/).

### 1. pThread - create()

This will launch a new thread to do some work on another CPU.

```c
 #include <pthread.h>

 int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                    void *(*start_routine) (void *), void *arg);
```



#### 1.1. Simple pThread_create() - Single Thread

```c
#include <pthread.h>

void* thread_function(void* arg)
{
    //Do some thread work here...
    pthread_exit(0);
}

int main(int argc, char **argsv)
{
    //Define a Single pThread ID
    pthread_t thread_id;
    
    // Create Attributes for Thread (this is not necessary! you can also use NULL)
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    pthread_create(&thread_id, &attr, thread_function, NULL);
    //pthread_create(&tid, NULL, thread_function, &i);
    
    // Wait until thread is done
    pthread_join(thread_id, NULL);
    
    
    return 0;   
}
```



#### 1.2. Advanced pThread_create() - Multiple Threads

```c
#include <pthread.h>

void* thread_function(void* arg)
{
    //Do some thread work here...
    pthread_exit(0);
}

int main(int argc, char **argsv)
{
    int numberOfThreads = 100;
    
    //Define a Single pThread ID
    pthread_t thread_ids[numberOfThreads];
    
    // Create Attributes for Thread
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    for(int i = 0; i < 100; i++)
    {
        //We will share the value i to the thread_function
        pthread_create(&thread_ids[i], &attr, thread_function, &i);
    }
    
	
    // Wait until ALL thread are done
    for (int i = 0; i < 100; i++)
    {
    	pthread_join(thread_ids[i], NULL);    
    }
    
    
    return 0;   
}
```

### 2. pThread - destroy()

You may want to stop a Thread form executing for whatever reason.

```c
#include <signal.h>

int pthread_kill(pthread_t thread, int sig);
```

#### 2.1 pThread_kill()

```c
#include <pthread.h>
#include <signal.h>

void* thread_function(void* arg)
{
    //Do some thread work here...
    pthread_exit(0);
}

int main(int argc, char **argsv)
{
    //Define a Single pThread ID
    pthread_t thread_id;
    
    // Create Attributes for Thread (this is not necessary! you can also use NULL)
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
	pthread_create(&thread_id, &attr, thread_function, NULL);
	
    //Now kill the thread again
    pthread_kill(thread_id, 0);
    
    return 0;   
}
```



### 3. pThread - Communication

You may want to send Data from your main()-loop to a thread and vice versa.

To accomplish communication a nice way to do it are pointers to a `struct`

#### 3.1 pThread communication via struct

```c
#include <pthread.h>
#include <stdio.h>

struct myStructTemplate
{
    int number;
    long longNumber;
};

void* thread_function1(void* arg)
{
   struct myStructTemplate *my_struct = (struct myStructTemplate*) arg;
   my_struct->number = 11;
   my_struct->longNumber = 111111111;
    
   pthread_exit(0);
}

void* thread_function2(void* arg)
{
   struct myStructTemplate *my_struct = (struct myStructTemplate*) arg;
   my_struct->number = 22;
   my_struct->longNumber = 222222222;
    
   pthread_exit(0);
}

int main(int argc, char **argsv)
{
    struct myStructTemplate myStruct[2]; 
    
    //Define pThreads 
    pthread_t thread_1, thread_2;
    
    //Create threads and share pointer
	pthread_create(&thread_1, NULL, thread_function1, &myStruct[0]);
    pthread_create(&thread_2, NULL, thread_function2, &myStruct[1]);
	
    // Join/Wait on threads
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    
    printf("Number_1: %d, %ld \n", myStruct[0].number, myStruct[0].longNumber);
    printf("Number_2: %d, %ld \n", myStruct[1].number, myStruct[1].longNumber);
    
    pthread_exit(NULL);  
}
```



### 4. pThread -  Synchronization

If you run multiple thread and they share a common value there will be some inexplicable behavior.
May be known as `race conditions`.
To bypass this issue you can use `mutexes`.

#### 4.1. pThread synchronization via Mutexs

```c
#include <pthread.h>

int global_var = 0;
pthread_mutex_t mutex;

void* thread_function(void* arg)
{
   pthread_mutex_lock(&mutex);
   global_var++;
   pthread_mutex_unlock(%mutex);
   pthread_extit(0);
}

int main(int argc, char **argsv)
{
    //Define pThreads 
    pthread_t thread_1 thread_2;
    
    //Init mutex
    pthread_mutex_init(&mutex, NULL);
    
    //Create threads
	pthread_create(&thread_1, NULL, thread_function, NULL);
    pthread_create(&thread_2, NULL, thread_function, NULL);
	
    // Join/Wait on threads
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    
    return 0;   
}
```





### 5. pThread additional stuff

#### 5.1 pThread_setname() - Naming pThreads

```c
#include <pthread.h>

void* thread_function(void* arg)
{
    //Do some thread work here...
    pthread_extit(0);
}

int main(int argc, char **argsv)
{
    //Define a Single pThread ID
    pthread_t thread_id;
    
    // Create Attributes for Thread (this is not necessary! you can also use NULL)
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
	pthread_create(&thread_id, &attr, thread_function, &i);
    
    //Here we will Create a name for our Thread
    char buffer[20];
    snprintf(buffer, sizeof(buffer), "%C%i", "Thread-", 1);
    pthread_setname_np(thread_id,  buffer);

    
    // Wait until thread is done
    pthread_join(thread_id, NULL);
    
    
    return 0;   
}
```

## Additional Information

[Multithreaded Programming (POSIX pthreads Tutorial)](https://randu.org/tutorials/threads/ )

[pThreads - Condition Variables](https://computing.llnl.gov/tutorials/pthreads/#ConditionVariables)

