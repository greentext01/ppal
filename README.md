# shmake
## Building:
``` 
$ cmake .
$ make
```
## Installing:
```
$ sudo mv shmake /usr/bin/
```

## Usage:
```
$ shmake <target>
```
Example:
```
$ shmake build
```

## Syntax:
### You need a file named Shmfile in the working directory.  

To make a target, add ":" to the start of the name  
Example:
```
:build
```
To echo something, add ";" to the start of the message you want to echo  
Example:
```
;Building...
```

To run a shell command, just write the command without anything at the start  
Example:
```
cd build/
```
Example Shmfile:
```
:build
  ;Building...
  g++ main.cpp -o main
  ;Done!

:clean
  rm main
```

## Tips:
Using bash instead of sh:
```
target:
  #!/bin/bash
  #Instructions go here
```
