# README #

This repository, maintained by SiFive, Inc, makes it easy to get started developing software for the Freedom E RISC-V platform. 

### Contents ###

* RISC-V Software Toolchain 
* RISC-V Debugging Toolchain
* Board Support Packages for FE310 and Development Kits
* A Few Example Programs

### Setting up the SDK ###

First, clone this repository:

```
git clone --recursive http://github.com/sifive/freedom-e-sdk.git
```

Ubuntu packages needed:

	$ sudo apt-get install autoconf automake libmpc-dev libmpfr-dev libgmp-dev gawk bison flex texinfo libtool libusb-1.0-0-dev make g++ pkg-config libexpat1-dev zlib1g-dev  

Next, build the tools:

```
cd freedom-e-sdk
make tools
```

To compile a bare-metal RISC-V program:

```
cd freedom-e-sdk
make software [PROGRAM=demo_gpio]
```

To see additional options:

```
cd freedom-e-sdk
make help
```

### For More Information ###

Documentation, Forums, and much more available at

[dev.sifive.com](http://dev.sifive.com)
