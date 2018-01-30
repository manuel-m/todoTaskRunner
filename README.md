# CPP with node.js toolchain

cli task runner and editor

### Features

* fast rebuild on code change (debug / release binaries)
* tests integration

### Usage

* configuration
```
make configure
```

* build 
```
make build
```

* build on change
```
make watch
```

* unit tests
```
make tests
```

### Pre-requisites

* [cmake](https://cmake.org)
* [gyp](https://gyp.gsrc.io)
* [ninja build system](https://ninja-build.org)