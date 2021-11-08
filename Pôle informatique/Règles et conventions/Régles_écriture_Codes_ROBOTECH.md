# règle écriture des codes du projet ROBOTECH en langage C++ (CPP)
# Auteur : Jean Luc Noizette
# Date   : 1er novembre 2021


### A - Syntax : 

**Class name      :** begin with uppercase, no underscores (ex : ClasseName)

**Function name   :** no uppercase, with underscores (ex: function_name())

**Variable name   :** Camel case only (ex: variableName)

**Constant :** all in uppercase with underscores (ex: CONSTANT_NAME)

### B - Function return values : 

Function return an integer 0 if it goes well
return an integer -1 if there was an error

### C - Tips : 

**- Beautify files :** 

Create your .clang-format file **in every folders** with the command : 

`$ clang-format -style=webkit -dump-config > .clang-format`

Modify the line : 

- `BreakBeforeBraces: webkit` in `BreakBeforeBraces: Allman`

- `AccessModifierOffset: -4` in `AccessModifierOffset: 0`


Add an alias to .bashrc to beautify files : 

`$ alias beautify++='clang-format -i -style=file'` 

Beautify you file file_name.cpp with the command : 
`$ beautify++ file_name.cpp` 

**IMPORTANT** : Always check in VScode at the bottom right of the editor window : 
- if you are in LF or CRLF and always put it in LF
- if you're using tab or spaces for indentation and always put it in tab 
                                                    