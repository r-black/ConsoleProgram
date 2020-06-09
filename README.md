# ConsoleProgram

## Build Setup

> bash (linux)
``` bash (linux)
$ sudo apt-get install libboost-all-dev
$ cd ConsoleProgram/
$ mkdir build
$ cd build/
$ cmake ..
$ make
```
> run app (current directory 'build')
``` run app
$ cd src

$ ./app -f ../../Test.tst -m words -v mother
# печатает количество слов «mother» в файле «Test.tst»

$ ./app -f ../../Test.tst -m checksum
# печатает 32-битную чексумму, рассчитанную по алгоритму checksum = word1 + word2 + … + wordN (word1..wordN – 32-хбитные слова, представляющие содержимое файла)

$ ./app -h
# печатает информацию о программе и описание параметров.
```

> run tests
``` run tests (current directory 'build')
$ cd test

$ ./tests
```
