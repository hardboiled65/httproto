httproto
===========
HTTP protocol library.

Dependencies
------------

- [http-parser](https://github.com/nodejs/http-parser)

### Intall dependencies

#### Arch Linux
```sh
$ sudo pacman -S http-parser
```

#### Ubuntu 20.04 / 20.10 / 21.04
```sh
$ sudo apt install libhttp-parser2.9
```

Build
-----

```sh
$ make
```

Install
-------

For install the library to under `/usr/lib` then

```sh
$ sudo make install PREFIX=/usr
```

