#ft_ls<br>
<br>
make #command to build the project<br>
./ft_ls -5 to see the usage<br>
<br>
usage: ./ft_ls [-alRruftGgS] [file ...]<br>
<br>
this is a defaulf flag<br>
```
-1 (The numeric digit 'one'.)  Force output to be one entry per line.
              This is the default when output is not to a terminal.
#those flags are required to test

-a hidden files
-l List in long format. Ownership, Date/Time etc (See below)
             For terminal output, a total sum of all the file sizes is 
             output on a line before the long listing.
             If the file is a symbolic link the pathname of the linked-to file is
             preceded by ->
-R Recursively list subdirectories encountered.
-r Reverse the order of the sort to get reverse lexicographical
             order or the oldest entries first.
             (or largest files last, if combined with sort by size, or time)
-u Use time of last access, instead of last modification of the file
             for sorting (-t) or printing (-l).
-f      Output is not sorted (list the files as their order in the machine)
-t      Sort by time modified (most recently modified first) before
             sorting the operands by lexicographical order.
-G      Enable colour output.
             This option is equivalent to defining CLICOLOR in the environment.(See below.)
-g      This option is deprecated. This option is only available for compatibility
             with POSIX; it is used to display the group name in the long (-l) format output
             (the owner name is suppressed).
-S      Sort files by size

#also we add option to manage files exist in /dev they have minor and major ->
```