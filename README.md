<img src="img/Banner.png">

# XALL
Xall is a markup languages which was created to create pre-rendered websites with a lot of ease and flexiblity. XALL Was also designed to be begginer friendly. This repository Contains the XALL and it's compiler/transpiler XTrans's source code.

## Features Of XALL
- Modular Design
- Simple To Read & Write
- Takes Less Time Than Writting Raw HTML
- Very Fast In Compilation
- Pre-Rendered And fast Web-Development
- Fully OpenSource
- Cross-Platform Compatiblity
- No 3rd Party API Or Dependency Required
- Written From Scratch with only C++ and STL (XTrans Feature)

## Cons Of XALL
 - A Completly New Language
 - Has A Learning Curve
 - Relatively New With Small Community

## Installing XALL
For Installing XALL You have 2 ways:-
1. Installing via CLI:
   Installing via CLI is super easy just copy the following commands:-
   ```bash
   git clone https://github.com/darkyboys/XALL.git
   cd XALL
   # configure nautix runtime first
   chmod +x configure-nautix-rt
   ./configure-nautix-rt
   # build
   ./build .
   echo "XALL was successfully installed in the bin directory"
   echo ""
   ```
2. Installing via GUI
   - Download this repository
   - Extract It
   - Open Terminal/CMD/Powershell
   - Fire The following commands
   ```bash
   chmod +x configure-nautix-rt
   ./configure-nautix-rt
   # build
   ./build .
   echo "XALL was successfully installed in the bin directory"
   echo ""
   ```
*Now You can move the XALL file from the bin directory anywhere you want, Tip:- Move the binary to your environment path variable for better accessiblity.*

## Writting Programs In XALL
Writting Programs in XALL is very Simple.
<img src="img/demo program.png">

### Syntax
HTML tags in XALL are blocks which are similar to functions of other languages since they are created like this `myblock("argument which will be always string");`for example:-
```xall
b("This is bold tag!!")
```
You can also create custom blocks which will be turned into html tags after compilation.
```xall
yourblock ("value");
```
You can inject html tags inside arguments and the argument must be always the xstring (Xall String)
```xall
yourblock ("<input>");
```
String chain: You can create a single string consist of multiple strings which will become a string chain in XALL like this:-
```xall
h1 ("My String" "My String 2");
```
Here Mystring and mystring2 will become single string of a chain
<br>
You can use any HTML Feature in XALL like this:-
```xall
h1("<script>alert('hy from js written with XALL');</script>");
```
You can write your XALL code in any way you want
```xall
script
(
" var a = 1;"
" alert(a);"
);
````
In XALL You have full freedom to do anything you want.
Also Note that XALL is a Compiled language and only generates HTML once means that the features which are planned to be added in future like loops, reusable blocks will be compiled during runtime resulting in the pre-rendered html pages so the loop will not run during runtime but will be already pre-compiled.

## Compiling XALL Programs
Compiling the programs Written in XALL is super easy just use your xtrans installation from the above code and follow this guide.

**Compiling Single XALL Program**
```bash
xtrans yourfile.xall
```
The Result will be a.html 
You can also use `-o` flag in the last for giving the output file name eg `index.html`

**Compiling Multiple XALL Programs For a single file**
```bash
xtrans -c header.xall main.xall footer.xall
```
`-c` refers to `combine` you can use full word like `--combine` for compiling multiple files.

**Compiling multiple files into a single output file**
```bash
xtrans -c header.xall main.xall footer.xall -o index.html
```
`-o` for output file which will be the index.html

**Check Version of XALL and XTrans**
```bash
xtrans -v or xtrans --version
```
This will output the version of both XTrans and XALL.

## Contributing
Contributions are Open Just make a fork, Create a custom branch, Contribute in your branch, Define your contribution in README.md file of your branch and the part of code you modified and no file deletion is allowed only modification and new files are allowed also using any 3rd party library/API/framework/tool is not requested and acceptable, Once done submit a pull request and wait for results.

## Thanks Have a nice day
