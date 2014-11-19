node-addon-examples
=========


## Dependencies

- nodejs
- node-gyp

## node-gyp

### Install

    npm install -g node-gyp

### Environment

You will also need to install:

  * On Unix:
    * `python` (`v2.7` recommended, `v3.x.x` is __*not*__ supported)
    * `make`
    * A proper C/C++ compiler toolchain, like GCC
  * On Windows:
    * [Python][windows-python] ([`v2.7.3`][windows-python-v2.7.3] recommended, `v3.x.x` is __*not*__ supported)
    * Windows XP/Vista/7:
      * Microsoft Visual Studio C++ 2010 ([Express][msvc2010] version works well)
      * For 64-bit builds of node and native modules you will _**also**_ need the [Windows 7 64-bit SDK][win7sdk]
        * If the install fails, try uninstalling any C++ 2010 x64&x86 Redistributable that you have installed first.
      * If you get errors that the 64-bit compilers are not installed you may also need the [compiler update for the Windows SDK 7.1]
    * Windows 7/8:
      * Microsoft Visual Studio C++ 2012/13 for Windows Desktop ([Express][msvc2012] version works well)
