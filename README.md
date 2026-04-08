# filetool


# Index
- [Description](#description)
- [Getting started](#getting-started)
  - [Directory structure](#directory-structure)
  - [Requirements](#requirements)
  - [Installation](#installation)
- [Usage](#usage)
  - [Expected input](#expected-input)
  - [Possible error messages](#possible-error-messages)
  - [Standard output](#standard-output)
- [Uninstalling](#uninstalling)
- [About](#about)
  - [Support](#support)
  - [Author and acknowledgment](#authors-and-acknowledgment)
  - [License](#license)


## Description
filetool provides several utilities to examine and modify files. Getting info, appending, searching, search and replace, and deleting files are options in this program.


## Getting started


### Directory structure
```
.
├── makefile
├── README.md
├── .clangformat
├── .gitignore
└── src
    ├── file_operations.c
    ├── filetool.c
    ├── getargs.c
    └── include
        ├── common.h
        ├── file_operations.h
        └── getargs.h
    

```


### Requirements
This program requires C99 or greater, and is designed to run on Ubuntu 22.04.5 LTS or greater.


### Installation
Clone this repository using git. In a terminal with git installed, run the following command:
```
git clone <repo-url>
```

In a terminal, navigate to the program directory and run make to compile the program using the included makefile.
```
cd path/to/dir
make
```


## Usage
[back to top](#index)

In a terminal, navigate to the program directory and execute the program along with the desired flags.

```
cd path/to/dir
./filetool -h
Usage: ./filetool [options]
        -f, --filename <path/to/file>
                file to use tool on
        -a, --append <string>
                string to append to file, requires use of --filename option
        -s, --search <string>
                string to search for, requires use of --filename option
        -r, --replace <string>
                string to replace in file, requires use of --filename and --search options
        -d, --delete
                delete file, requires use of --filename option
        -i, --info
                get info on file, requires use of --filename option
        -h, --help
```


### Flag options

#### Expected flags
The program expects either ```-h``` or ```-f```, or the associated long-flag. The program will not accept both, only one at a time may be used.

When the ```-f``` flag is used, the program expects ```-a```, ```-s```, ```-d```, or ```-i```. The program will only accept one at a time.

If the user chooses the ```-s``` flag to search a file, they optionally can also use the ```-r``` flag in order to replace the string.


#### -h and --help
The ```-h``` and ```--help``` options will display the usage as shown in [Usage section](#usage).


#### -f and --filename
The ```-f``` and ```--filename``` options are necessary to use the ```-a```, ```-s```, ```-d```, and ```-i``` flags.

```
./filetool -f path/to/file
```

```
./filetool --filename path/to/file
```

#### -a and --append
The ```-a``` and ```--append``` options are used to append the file with a provided string.

```
./filetool -f path/to/file -a "Append this string to the file."
```

```
./filetool --filename path/to/file --append one_word_string
```


#### -s and --search
The ```-s``` and ```--search``` options are used to search the file for a provided string.

```
./filetool -f path/to/file -s "Search for this string"
```

```
./filetool --filename path/to/file --search string_to_find

```


#### -r and --replace
The ```-r``` and ```--replace``` options are used to replace the first occurance of a string in the file with a provided string. This can only be used if the ```-s``` or ```--search``` options were used.

```
./filetool -f path/to/file -s "Search for this string" -r "Replace with this string"
```

```
./filetool --filename path/to/file --search string_to_find --replace replace_with_this

```


#### -d and --delete
The ```-d``` and ```--delete``` options are used to delete a file.

```
./filetool -f path/to/file -d
```

```
./filetool --filename path/to/file --delete

```


#### -i and --info
The ```-i``` and ```--info``` options are used to get info on the file (file type, size, owner, and group)

```
./filetool -f path/to/file -i
```

```
./filetool --filename path/to/file --info

```


## Uninstalling

The executable and build files can be removed by using the included make command ```make clean```.

For complete removal of all project files, delete the entire project directory from within your terminal.
```
rm -rf path/to/dir
```


## About

[back to top](#index)

### Support
For support, contact Chase Carter.


### Authors and acknowledgment
Thhis project was created as part of the US Army Cyber School - 170D WOBC Course.


### License

![open source initiative](https://i0.wp.com/opensource.org/wp-content/uploads/2023/03/cropped-OSI-horizontal-large.png?fit=200%2C229&quality=80&ssl=1)

The MIT License (MIT)

Copyright (c) 2026 Chase Carter

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE