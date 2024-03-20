// https://thehacktivists.medium.com/null-pointer-dereference-cwe-476-the-hacktivists-d3ceb2a7ade1
// NULL Pointer Dereference [CWE-476] vulnerable code example
    // (c) HTB Research
    #include <stdio.h>
    int *ptr = NULL;
    int _tmain(int argc, _TINT* argv[])
    {
            *ptr = 17;
            return 0;
    }
