# CS210A3

My submission for the third assignment in the course COMPSCI 210: Computer Organisation at the University of Auckland.

Two basic C++ programs with the aim of understanding the way data is represented in computer systems.

The first takes an arbitrary number of hexadecimal inputs from the command line, interprets them as "uintvars", variable-length, unsigned integers (more comprehensively defined in "A3.part.htm", and converts them into decimal integers before outputting the result to stdout.

An example run:
    ./part1.exe 8a5c 8102
which should return:
    8a5c:   1372
    8102:   130

The second takes an arbitrary number of files of type WBMP, "Wireless BitMaP", and extracts information from the header of the files to determine the width and height of the images they represent, then outputs this information to stdout. Some examples of wireless bitmaps are available.

An example run:
    ./part2.exe wbmp/X.wbmp wbmp/Box12x12.wbmp
Which should return:
    wbmp/X.wbmp:
        width: 8
        height: 8

Further details are available in the "A3.part.htm" file.
