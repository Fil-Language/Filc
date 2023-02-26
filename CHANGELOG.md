# Changelog

## v0.3.0

- Add `--debug` option to compile with debug information
- Add `-o,--out` option to specify executable name
- Change base grammar to be more functional : remove `return` and `functionCall` + transform `()` to be an operator
- Override `BaseErrorListener` of Antlr to use my `ErrorsRegister`
- Specify type is mandatory, so no more type inference
- Add a script to easily change the version

## v0.2.0

*2023-01-03*

- Implement part B
- Create Environment and SymbolTable
- Create ErrorsRegister
- Implement `dump` function for option `-a`
- Change license to MIT

## v0.1.0

*2022-12-17*

- Create Parser and Lexer with Antlr
- Create Abstract Syntax Tree
- Implement `decompile` function for option `-d`
