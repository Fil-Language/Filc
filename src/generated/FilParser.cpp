
// Generated from /home/kevin/DATA/Programmation/FIL/Filc/src/antlr/FilParser.g4 by ANTLR 4.11.1


#include "FilParserVisitor.h"

#include "FilParser.h"


using namespace antlrcpp;
using namespace antlrcppfil;

using namespace antlr4;

namespace {

struct FilParserStaticData final {
  FilParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  FilParserStaticData(const FilParserStaticData&) = delete;
  FilParserStaticData(FilParserStaticData&&) = delete;
  FilParserStaticData& operator=(const FilParserStaticData&) = delete;
  FilParserStaticData& operator=(FilParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag filparserParserOnceFlag;
FilParserStaticData *filparserParserStaticData = nullptr;

void filparserParserInitialize() {
  assert(filparserParserStaticData == nullptr);
  auto staticData = std::make_unique<FilParserStaticData>(
    std::vector<std::string>{
      "program", "module", "import_", "expr", "function", "fun_params", 
      "fun_param_list", "fun_param", "fun_body", "function_decl", "lambda", 
      "interface", "interface_body", "class_", "class_modifier", "class_params", 
      "class_param_list", "class_param", "class_extends", "class_extend_list", 
      "class_extend", "class_body", "class_function", "class_variable", 
      "class_atr_modifier", "class_constructor", "enum_", "enum_body", "condition", 
      "if_", "if_condition", "if_body", "else_if", "else_", "switch_", "switch_condition", 
      "switch_body", "switch_case", "loop", "fori", "fori_condition", "foriter", 
      "foriter_condition", "while_", "exception", "catch_body", "binary_operator", 
      "unary_calcul", "unary_operator", "assignation", "assignation_operator", 
      "cast", "function_call", "function_call_params", "function_call_param_list", 
      "variable_decl", "type", "litteral", "temp", "expr_parenthesis", "expr_block"
    },
    std::vector<std::string>{
      "", "'export'", "'module'", "'fun'", "'interface'", "'class'", "'abstract'", 
      "'open'", "'private'", "'public'", "'internal'", "'protected'", "'constructor'", 
      "'enum'", "'if'", "'else'", "'switch'", "'default'", "'for'", "'val'", 
      "'var'", "'while'", "'try'", "'catch'", "'true'", "'false'", "'null'", 
      "", "'.'", "'->'", "'{'", "'}'", "'('", "')'", "'['", "']'", "':'", 
      "','", "';'", "'='", "'+'", "'-'", "'/'", "'*'", "'%'", "'<<'", "'>>'", 
      "'&&'", "'||'", "'<'", "'>'", "'=='", "'<='", "'>='", "'!='", "'!'", 
      "'&'", "'|'", "'^'"
    },
    std::vector<std::string>{
      "", "EXPORT", "MODULE", "FUN", "INTERFACE", "CLASS", "ABSTRACT", "OPEN", 
      "PRIVATE", "PUBLIC", "INTERNAL", "PROTECTED", "CONSTRUCTOR", "ENUM", 
      "IF", "ELSE", "SWITCH", "DEFAULT", "FOR", "VAL", "VAR", "WHILE", "TRY", 
      "CATCH", "TRUE", "FALSE", "NULL_", "IDENTIFIER", "DOT", "ARROW", "LBRACE", 
      "RBRACE", "LPAREN", "RPAREN", "LBRAK", "RBRAK", "COLON", "COMMA", 
      "SEMICOLON", "EQ", "PLUS", "MINUS", "DIVIDE", "TIMES", "MOD", "FLEFT", 
      "FRIGHT", "AND", "OR", "LE", "GE", "EQEQ", "LEQ", "GEQ", "NEQ", "NOT", 
      "BAND", "BOR", "BXOR", "INT", "FLOAT", "STRING", "CHAR", "COMMENT", 
      "COMMENT_BLOCK", "SEPARATOR", "MODULE_NAME", "IMPORT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,67,539,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,7,
  	56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,1,0,1,0,5,0,125,8,0,10,0,12,
  	0,128,9,0,1,0,5,0,131,8,0,10,0,12,0,134,9,0,1,1,1,1,1,1,1,2,1,2,1,2,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,
  	159,8,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,5,3,173,8,3,10,
  	3,12,3,176,9,3,1,4,1,4,1,4,1,4,1,4,3,4,183,8,4,1,4,1,4,1,5,1,5,3,5,189,
  	8,5,1,5,1,5,1,6,1,6,1,6,5,6,196,8,6,10,6,12,6,199,9,6,1,7,1,7,1,7,1,7,
  	1,8,1,8,1,8,3,8,208,8,8,1,9,1,9,1,9,1,9,1,9,3,9,215,8,9,1,10,1,10,1,10,
  	1,10,3,10,221,8,10,1,11,1,11,1,11,3,11,226,8,11,1,11,3,11,229,8,11,1,
  	12,1,12,5,12,233,8,12,10,12,12,12,236,9,12,1,12,1,12,1,13,1,13,1,13,1,
  	13,3,13,244,8,13,1,13,3,13,247,8,13,1,13,3,13,250,8,13,1,14,1,14,1,15,
  	1,15,3,15,256,8,15,1,15,1,15,1,16,1,16,1,16,5,16,263,8,16,10,16,12,16,
  	266,9,16,1,17,1,17,1,17,1,17,1,17,1,17,3,17,274,8,17,3,17,276,8,17,1,
  	18,1,18,1,18,1,19,1,19,1,19,5,19,284,8,19,10,19,12,19,287,9,19,1,20,1,
  	20,1,20,1,21,1,21,1,21,1,21,5,21,296,8,21,10,21,12,21,299,9,21,1,21,1,
  	21,1,22,3,22,304,8,22,1,22,1,22,1,22,1,23,1,23,1,23,1,24,1,24,1,25,1,
  	25,1,25,1,26,1,26,1,26,3,26,320,8,26,1,27,1,27,1,27,1,27,5,27,326,8,27,
  	10,27,12,27,329,9,27,3,27,331,8,27,1,27,1,27,1,28,1,28,3,28,337,8,28,
  	1,29,1,29,1,29,1,29,5,29,343,8,29,10,29,12,29,346,9,29,1,29,3,29,349,
  	8,29,1,30,1,30,1,31,1,31,1,31,3,31,356,8,31,1,32,1,32,1,32,1,32,1,32,
  	1,33,1,33,1,33,1,34,1,34,1,34,1,34,1,35,1,35,1,36,1,36,5,36,374,8,36,
  	10,36,12,36,377,9,36,1,36,1,36,1,37,1,37,3,37,383,8,37,1,37,1,37,1,37,
  	1,37,3,37,389,8,37,1,38,1,38,1,38,3,38,394,8,38,1,39,1,39,1,39,1,39,3,
  	39,400,8,39,1,40,1,40,3,40,404,8,40,1,40,1,40,3,40,408,8,40,1,40,1,40,
  	3,40,412,8,40,1,40,1,40,1,41,1,41,1,41,1,41,3,41,420,8,41,1,42,1,42,1,
  	42,1,42,1,42,1,42,1,42,1,43,1,43,1,43,1,43,1,44,1,44,1,44,1,44,3,44,437,
  	8,44,1,44,4,44,440,8,44,11,44,12,44,441,1,45,1,45,1,45,1,45,1,45,1,45,
  	1,45,3,45,451,8,45,1,46,1,46,1,47,1,47,1,47,1,48,1,48,1,48,1,48,1,48,
  	1,48,1,48,1,48,1,48,1,48,1,48,1,48,3,48,470,8,48,1,49,1,49,1,49,1,50,
  	3,50,476,8,50,1,50,1,50,1,51,1,51,1,51,1,51,1,51,1,52,1,52,1,52,1,53,
  	1,53,3,53,490,8,53,1,53,1,53,1,54,1,54,1,54,5,54,497,8,54,10,54,12,54,
  	500,9,54,1,55,1,55,1,55,1,55,1,55,1,55,3,55,508,8,55,1,55,3,55,511,8,
  	55,1,56,1,56,1,56,1,56,3,56,517,8,56,1,56,3,56,520,8,56,1,57,1,57,1,58,
  	1,58,1,59,1,59,1,59,1,59,1,60,1,60,5,60,532,8,60,10,60,12,60,535,9,60,
  	1,60,1,60,1,60,0,1,6,61,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,
  	34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,
  	80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,
  	120,0,5,1,0,6,7,1,0,8,11,1,0,19,20,2,0,40,54,56,58,2,0,24,26,59,62,561,
  	0,122,1,0,0,0,2,135,1,0,0,0,4,138,1,0,0,0,6,158,1,0,0,0,8,177,1,0,0,0,
  	10,186,1,0,0,0,12,192,1,0,0,0,14,200,1,0,0,0,16,207,1,0,0,0,18,209,1,
  	0,0,0,20,216,1,0,0,0,22,222,1,0,0,0,24,230,1,0,0,0,26,239,1,0,0,0,28,
  	251,1,0,0,0,30,253,1,0,0,0,32,259,1,0,0,0,34,275,1,0,0,0,36,277,1,0,0,
  	0,38,280,1,0,0,0,40,288,1,0,0,0,42,291,1,0,0,0,44,303,1,0,0,0,46,308,
  	1,0,0,0,48,311,1,0,0,0,50,313,1,0,0,0,52,316,1,0,0,0,54,321,1,0,0,0,56,
  	336,1,0,0,0,58,338,1,0,0,0,60,350,1,0,0,0,62,355,1,0,0,0,64,357,1,0,0,
  	0,66,362,1,0,0,0,68,365,1,0,0,0,70,369,1,0,0,0,72,371,1,0,0,0,74,382,
  	1,0,0,0,76,393,1,0,0,0,78,395,1,0,0,0,80,401,1,0,0,0,82,415,1,0,0,0,84,
  	421,1,0,0,0,86,428,1,0,0,0,88,432,1,0,0,0,90,443,1,0,0,0,92,452,1,0,0,
  	0,94,454,1,0,0,0,96,469,1,0,0,0,98,471,1,0,0,0,100,475,1,0,0,0,102,479,
  	1,0,0,0,104,484,1,0,0,0,106,487,1,0,0,0,108,493,1,0,0,0,110,501,1,0,0,
  	0,112,512,1,0,0,0,114,521,1,0,0,0,116,523,1,0,0,0,118,525,1,0,0,0,120,
  	529,1,0,0,0,122,126,3,2,1,0,123,125,3,4,2,0,124,123,1,0,0,0,125,128,1,
  	0,0,0,126,124,1,0,0,0,126,127,1,0,0,0,127,132,1,0,0,0,128,126,1,0,0,0,
  	129,131,3,6,3,0,130,129,1,0,0,0,131,134,1,0,0,0,132,130,1,0,0,0,132,133,
  	1,0,0,0,133,1,1,0,0,0,134,132,1,0,0,0,135,136,5,2,0,0,136,137,5,66,0,
  	0,137,3,1,0,0,0,138,139,5,67,0,0,139,140,5,66,0,0,140,5,1,0,0,0,141,142,
  	6,3,-1,0,142,159,3,8,4,0,143,159,3,20,10,0,144,159,3,22,11,0,145,159,
  	3,26,13,0,146,159,3,52,26,0,147,159,3,56,28,0,148,159,3,76,38,0,149,159,
  	3,88,44,0,150,159,3,94,47,0,151,159,3,102,51,0,152,159,5,27,0,0,153,159,
  	3,104,52,0,154,159,3,114,57,0,155,159,3,110,55,0,156,159,3,118,59,0,157,
  	159,3,120,60,0,158,141,1,0,0,0,158,143,1,0,0,0,158,144,1,0,0,0,158,145,
  	1,0,0,0,158,146,1,0,0,0,158,147,1,0,0,0,158,148,1,0,0,0,158,149,1,0,0,
  	0,158,150,1,0,0,0,158,151,1,0,0,0,158,152,1,0,0,0,158,153,1,0,0,0,158,
  	154,1,0,0,0,158,155,1,0,0,0,158,156,1,0,0,0,158,157,1,0,0,0,159,174,1,
  	0,0,0,160,161,10,11,0,0,161,162,3,92,46,0,162,163,3,6,3,12,163,173,1,
  	0,0,0,164,165,10,9,0,0,165,166,5,28,0,0,166,173,3,6,3,10,167,168,10,8,
  	0,0,168,169,5,29,0,0,169,173,3,6,3,9,170,171,10,10,0,0,171,173,3,98,49,
  	0,172,160,1,0,0,0,172,164,1,0,0,0,172,167,1,0,0,0,172,170,1,0,0,0,173,
  	176,1,0,0,0,174,172,1,0,0,0,174,175,1,0,0,0,175,7,1,0,0,0,176,174,1,0,
  	0,0,177,178,5,3,0,0,178,179,5,27,0,0,179,182,3,10,5,0,180,181,5,36,0,
  	0,181,183,3,112,56,0,182,180,1,0,0,0,182,183,1,0,0,0,183,184,1,0,0,0,
  	184,185,3,16,8,0,185,9,1,0,0,0,186,188,5,32,0,0,187,189,3,12,6,0,188,
  	187,1,0,0,0,188,189,1,0,0,0,189,190,1,0,0,0,190,191,5,33,0,0,191,11,1,
  	0,0,0,192,197,3,14,7,0,193,194,5,37,0,0,194,196,3,14,7,0,195,193,1,0,
  	0,0,196,199,1,0,0,0,197,195,1,0,0,0,197,198,1,0,0,0,198,13,1,0,0,0,199,
  	197,1,0,0,0,200,201,5,27,0,0,201,202,5,36,0,0,202,203,3,112,56,0,203,
  	15,1,0,0,0,204,208,3,98,49,0,205,208,3,118,59,0,206,208,3,120,60,0,207,
  	204,1,0,0,0,207,205,1,0,0,0,207,206,1,0,0,0,208,17,1,0,0,0,209,210,5,
  	3,0,0,210,211,5,27,0,0,211,214,3,10,5,0,212,213,5,36,0,0,213,215,3,112,
  	56,0,214,212,1,0,0,0,214,215,1,0,0,0,215,19,1,0,0,0,216,217,3,10,5,0,
  	217,220,5,29,0,0,218,221,3,120,60,0,219,221,3,118,59,0,220,218,1,0,0,
  	0,220,219,1,0,0,0,221,21,1,0,0,0,222,223,5,4,0,0,223,225,5,27,0,0,224,
  	226,3,30,15,0,225,224,1,0,0,0,225,226,1,0,0,0,226,228,1,0,0,0,227,229,
  	3,24,12,0,228,227,1,0,0,0,228,229,1,0,0,0,229,23,1,0,0,0,230,234,5,30,
  	0,0,231,233,3,18,9,0,232,231,1,0,0,0,233,236,1,0,0,0,234,232,1,0,0,0,
  	234,235,1,0,0,0,235,237,1,0,0,0,236,234,1,0,0,0,237,238,5,31,0,0,238,
  	25,1,0,0,0,239,240,3,28,14,0,240,241,5,5,0,0,241,243,5,27,0,0,242,244,
  	3,30,15,0,243,242,1,0,0,0,243,244,1,0,0,0,244,246,1,0,0,0,245,247,3,36,
  	18,0,246,245,1,0,0,0,246,247,1,0,0,0,247,249,1,0,0,0,248,250,3,42,21,
  	0,249,248,1,0,0,0,249,250,1,0,0,0,250,27,1,0,0,0,251,252,7,0,0,0,252,
  	29,1,0,0,0,253,255,5,32,0,0,254,256,3,32,16,0,255,254,1,0,0,0,255,256,
  	1,0,0,0,256,257,1,0,0,0,257,258,5,33,0,0,258,31,1,0,0,0,259,264,3,34,
  	17,0,260,261,5,37,0,0,261,263,3,34,17,0,262,260,1,0,0,0,263,266,1,0,0,
  	0,264,262,1,0,0,0,264,265,1,0,0,0,265,33,1,0,0,0,266,264,1,0,0,0,267,
  	276,3,110,55,0,268,269,5,27,0,0,269,270,5,36,0,0,270,273,3,112,56,0,271,
  	272,5,39,0,0,272,274,3,114,57,0,273,271,1,0,0,0,273,274,1,0,0,0,274,276,
  	1,0,0,0,275,267,1,0,0,0,275,268,1,0,0,0,276,35,1,0,0,0,277,278,5,36,0,
  	0,278,279,3,38,19,0,279,37,1,0,0,0,280,285,3,40,20,0,281,282,5,37,0,0,
  	282,284,3,40,20,0,283,281,1,0,0,0,284,287,1,0,0,0,285,283,1,0,0,0,285,
  	286,1,0,0,0,286,39,1,0,0,0,287,285,1,0,0,0,288,289,5,27,0,0,289,290,3,
  	106,53,0,290,41,1,0,0,0,291,292,5,30,0,0,292,297,3,50,25,0,293,296,3,
  	46,23,0,294,296,3,44,22,0,295,293,1,0,0,0,295,294,1,0,0,0,296,299,1,0,
  	0,0,297,295,1,0,0,0,297,298,1,0,0,0,298,300,1,0,0,0,299,297,1,0,0,0,300,
  	301,5,31,0,0,301,43,1,0,0,0,302,304,5,6,0,0,303,302,1,0,0,0,303,304,1,
  	0,0,0,304,305,1,0,0,0,305,306,3,48,24,0,306,307,3,8,4,0,307,45,1,0,0,
  	0,308,309,3,48,24,0,309,310,3,110,55,0,310,47,1,0,0,0,311,312,7,1,0,0,
  	312,49,1,0,0,0,313,314,5,12,0,0,314,315,3,120,60,0,315,51,1,0,0,0,316,
  	317,5,13,0,0,317,319,5,27,0,0,318,320,3,54,27,0,319,318,1,0,0,0,319,320,
  	1,0,0,0,320,53,1,0,0,0,321,330,5,30,0,0,322,327,5,27,0,0,323,324,5,37,
  	0,0,324,326,5,27,0,0,325,323,1,0,0,0,326,329,1,0,0,0,327,325,1,0,0,0,
  	327,328,1,0,0,0,328,331,1,0,0,0,329,327,1,0,0,0,330,322,1,0,0,0,330,331,
  	1,0,0,0,331,332,1,0,0,0,332,333,5,31,0,0,333,55,1,0,0,0,334,337,3,58,
  	29,0,335,337,3,68,34,0,336,334,1,0,0,0,336,335,1,0,0,0,337,57,1,0,0,0,
  	338,339,5,14,0,0,339,340,3,60,30,0,340,344,3,62,31,0,341,343,3,64,32,
  	0,342,341,1,0,0,0,343,346,1,0,0,0,344,342,1,0,0,0,344,345,1,0,0,0,345,
  	348,1,0,0,0,346,344,1,0,0,0,347,349,3,66,33,0,348,347,1,0,0,0,348,349,
  	1,0,0,0,349,59,1,0,0,0,350,351,3,118,59,0,351,61,1,0,0,0,352,356,3,6,
  	3,0,353,356,3,120,60,0,354,356,3,118,59,0,355,352,1,0,0,0,355,353,1,0,
  	0,0,355,354,1,0,0,0,356,63,1,0,0,0,357,358,5,15,0,0,358,359,5,14,0,0,
  	359,360,3,60,30,0,360,361,3,62,31,0,361,65,1,0,0,0,362,363,5,15,0,0,363,
  	364,3,62,31,0,364,67,1,0,0,0,365,366,5,16,0,0,366,367,3,70,35,0,367,368,
  	3,72,36,0,368,69,1,0,0,0,369,370,3,118,59,0,370,71,1,0,0,0,371,375,5,
  	30,0,0,372,374,3,74,37,0,373,372,1,0,0,0,374,377,1,0,0,0,375,373,1,0,
  	0,0,375,376,1,0,0,0,376,378,1,0,0,0,377,375,1,0,0,0,378,379,5,31,0,0,
  	379,73,1,0,0,0,380,383,3,114,57,0,381,383,5,17,0,0,382,380,1,0,0,0,382,
  	381,1,0,0,0,383,384,1,0,0,0,384,388,5,29,0,0,385,389,3,6,3,0,386,389,
  	3,120,60,0,387,389,3,118,59,0,388,385,1,0,0,0,388,386,1,0,0,0,388,387,
  	1,0,0,0,389,75,1,0,0,0,390,394,3,78,39,0,391,394,3,82,41,0,392,394,3,
  	86,43,0,393,390,1,0,0,0,393,391,1,0,0,0,393,392,1,0,0,0,394,77,1,0,0,
  	0,395,396,5,18,0,0,396,399,3,80,40,0,397,400,3,6,3,0,398,400,3,120,60,
  	0,399,397,1,0,0,0,399,398,1,0,0,0,400,79,1,0,0,0,401,403,5,32,0,0,402,
  	404,3,110,55,0,403,402,1,0,0,0,403,404,1,0,0,0,404,405,1,0,0,0,405,407,
  	5,38,0,0,406,408,3,6,3,0,407,406,1,0,0,0,407,408,1,0,0,0,408,409,1,0,
  	0,0,409,411,5,38,0,0,410,412,3,6,3,0,411,410,1,0,0,0,411,412,1,0,0,0,
  	412,413,1,0,0,0,413,414,5,33,0,0,414,81,1,0,0,0,415,416,5,18,0,0,416,
  	419,3,84,42,0,417,420,3,6,3,0,418,420,3,120,60,0,419,417,1,0,0,0,419,
  	418,1,0,0,0,420,83,1,0,0,0,421,422,5,32,0,0,422,423,7,2,0,0,423,424,5,
  	27,0,0,424,425,5,36,0,0,425,426,5,27,0,0,426,427,5,33,0,0,427,85,1,0,
  	0,0,428,429,5,21,0,0,429,430,3,60,30,0,430,431,3,62,31,0,431,87,1,0,0,
  	0,432,436,5,22,0,0,433,437,3,6,3,0,434,437,3,120,60,0,435,437,3,118,59,
  	0,436,433,1,0,0,0,436,434,1,0,0,0,436,435,1,0,0,0,437,439,1,0,0,0,438,
  	440,3,90,45,0,439,438,1,0,0,0,440,441,1,0,0,0,441,439,1,0,0,0,441,442,
  	1,0,0,0,442,89,1,0,0,0,443,444,5,23,0,0,444,445,5,32,0,0,445,446,3,14,
  	7,0,446,450,5,33,0,0,447,451,3,6,3,0,448,451,3,120,60,0,449,451,3,118,
  	59,0,450,447,1,0,0,0,450,448,1,0,0,0,450,449,1,0,0,0,451,91,1,0,0,0,452,
  	453,7,3,0,0,453,93,1,0,0,0,454,455,3,96,48,0,455,456,3,6,3,0,456,95,1,
  	0,0,0,457,470,5,40,0,0,458,470,5,41,0,0,459,470,5,42,0,0,460,470,5,43,
  	0,0,461,470,5,44,0,0,462,470,5,55,0,0,463,470,5,56,0,0,464,470,5,58,0,
  	0,465,470,5,57,0,0,466,467,5,34,0,0,467,468,5,59,0,0,468,470,5,35,0,0,
  	469,457,1,0,0,0,469,458,1,0,0,0,469,459,1,0,0,0,469,460,1,0,0,0,469,461,
  	1,0,0,0,469,462,1,0,0,0,469,463,1,0,0,0,469,464,1,0,0,0,469,465,1,0,0,
  	0,469,466,1,0,0,0,470,97,1,0,0,0,471,472,3,100,50,0,472,473,3,6,3,0,473,
  	99,1,0,0,0,474,476,3,96,48,0,475,474,1,0,0,0,475,476,1,0,0,0,476,477,
  	1,0,0,0,477,478,5,39,0,0,478,101,1,0,0,0,479,480,5,32,0,0,480,481,3,112,
  	56,0,481,482,5,33,0,0,482,483,3,6,3,0,483,103,1,0,0,0,484,485,5,27,0,
  	0,485,486,3,106,53,0,486,105,1,0,0,0,487,489,5,32,0,0,488,490,3,108,54,
  	0,489,488,1,0,0,0,489,490,1,0,0,0,490,491,1,0,0,0,491,492,5,33,0,0,492,
  	107,1,0,0,0,493,498,3,6,3,0,494,495,5,37,0,0,495,497,3,6,3,0,496,494,
  	1,0,0,0,497,500,1,0,0,0,498,496,1,0,0,0,498,499,1,0,0,0,499,109,1,0,0,
  	0,500,498,1,0,0,0,501,502,7,2,0,0,502,510,5,27,0,0,503,504,5,36,0,0,504,
  	511,3,112,56,0,505,506,5,36,0,0,506,508,3,112,56,0,507,505,1,0,0,0,507,
  	508,1,0,0,0,508,509,1,0,0,0,509,511,3,98,49,0,510,503,1,0,0,0,510,507,
  	1,0,0,0,511,111,1,0,0,0,512,519,5,27,0,0,513,520,5,43,0,0,514,516,5,34,
  	0,0,515,517,5,59,0,0,516,515,1,0,0,0,516,517,1,0,0,0,517,518,1,0,0,0,
  	518,520,5,35,0,0,519,513,1,0,0,0,519,514,1,0,0,0,519,520,1,0,0,0,520,
  	113,1,0,0,0,521,522,7,4,0,0,522,115,1,0,0,0,523,524,5,28,0,0,524,117,
  	1,0,0,0,525,526,5,32,0,0,526,527,3,6,3,0,527,528,5,33,0,0,528,119,1,0,
  	0,0,529,533,5,34,0,0,530,532,3,6,3,0,531,530,1,0,0,0,532,535,1,0,0,0,
  	533,531,1,0,0,0,533,534,1,0,0,0,534,536,1,0,0,0,535,533,1,0,0,0,536,537,
  	5,35,0,0,537,121,1,0,0,0,53,126,132,158,172,174,182,188,197,207,214,220,
  	225,228,234,243,246,249,255,264,273,275,285,295,297,303,319,327,330,336,
  	344,348,355,375,382,388,393,399,403,407,411,419,436,441,450,469,475,489,
  	498,507,510,516,519,533
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  filparserParserStaticData = staticData.release();
}

}

FilParser::FilParser(TokenStream *input) : FilParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

FilParser::FilParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  FilParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *filparserParserStaticData->atn, filparserParserStaticData->decisionToDFA, filparserParserStaticData->sharedContextCache, options);
}

FilParser::~FilParser() {
  delete _interpreter;
}

const atn::ATN& FilParser::getATN() const {
  return *filparserParserStaticData->atn;
}

std::string FilParser::getGrammarFileName() const {
  return "FilParser.g4";
}

const std::vector<std::string>& FilParser::getRuleNames() const {
  return filparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& FilParser::getVocabulary() const {
  return filparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView FilParser::getSerializedATN() const {
  return filparserParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

FilParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::ModuleContext* FilParser::ProgramContext::module() {
  return getRuleContext<FilParser::ModuleContext>(0);
}

std::vector<FilParser::Import_Context *> FilParser::ProgramContext::import_() {
  return getRuleContexts<FilParser::Import_Context>();
}

FilParser::Import_Context* FilParser::ProgramContext::import_(size_t i) {
  return getRuleContext<FilParser::Import_Context>(i);
}

std::vector<FilParser::ExprContext *> FilParser::ProgramContext::expr() {
  return getRuleContexts<FilParser::ExprContext>();
}

FilParser::ExprContext* FilParser::ProgramContext::expr(size_t i) {
  return getRuleContext<FilParser::ExprContext>(i);
}


size_t FilParser::ProgramContext::getRuleIndex() const {
  return FilParser::RuleProgram;
}


std::any FilParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

FilParser::ProgramContext* FilParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, FilParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    module();
    setState(126);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FilParser::IMPORT) {
      setState(123);
      import_();
      setState(128);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(132);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 9187377346430984408) != 0) {
      setState(129);
      expr(0);
      setState(134);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModuleContext ------------------------------------------------------------------

FilParser::ModuleContext::ModuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::ModuleContext::MODULE() {
  return getToken(FilParser::MODULE, 0);
}

tree::TerminalNode* FilParser::ModuleContext::MODULE_NAME() {
  return getToken(FilParser::MODULE_NAME, 0);
}


size_t FilParser::ModuleContext::getRuleIndex() const {
  return FilParser::RuleModule;
}


std::any FilParser::ModuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitModule(this);
  else
    return visitor->visitChildren(this);
}

FilParser::ModuleContext* FilParser::module() {
  ModuleContext *_localctx = _tracker.createInstance<ModuleContext>(_ctx, getState());
  enterRule(_localctx, 2, FilParser::RuleModule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    match(FilParser::MODULE);
    setState(136);
    match(FilParser::MODULE_NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Import_Context ------------------------------------------------------------------

FilParser::Import_Context::Import_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Import_Context::IMPORT() {
  return getToken(FilParser::IMPORT, 0);
}

tree::TerminalNode* FilParser::Import_Context::MODULE_NAME() {
  return getToken(FilParser::MODULE_NAME, 0);
}


size_t FilParser::Import_Context::getRuleIndex() const {
  return FilParser::RuleImport_;
}


std::any FilParser::Import_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitImport_(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Import_Context* FilParser::import_() {
  Import_Context *_localctx = _tracker.createInstance<Import_Context>(_ctx, getState());
  enterRule(_localctx, 4, FilParser::RuleImport_);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138);
    match(FilParser::IMPORT);
    setState(139);
    match(FilParser::MODULE_NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

FilParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::FunctionContext* FilParser::ExprContext::function() {
  return getRuleContext<FilParser::FunctionContext>(0);
}

FilParser::LambdaContext* FilParser::ExprContext::lambda() {
  return getRuleContext<FilParser::LambdaContext>(0);
}

FilParser::InterfaceContext* FilParser::ExprContext::interface() {
  return getRuleContext<FilParser::InterfaceContext>(0);
}

FilParser::Class_Context* FilParser::ExprContext::class_() {
  return getRuleContext<FilParser::Class_Context>(0);
}

FilParser::Enum_Context* FilParser::ExprContext::enum_() {
  return getRuleContext<FilParser::Enum_Context>(0);
}

FilParser::ConditionContext* FilParser::ExprContext::condition() {
  return getRuleContext<FilParser::ConditionContext>(0);
}

FilParser::LoopContext* FilParser::ExprContext::loop() {
  return getRuleContext<FilParser::LoopContext>(0);
}

FilParser::ExceptionContext* FilParser::ExprContext::exception() {
  return getRuleContext<FilParser::ExceptionContext>(0);
}

FilParser::Unary_calculContext* FilParser::ExprContext::unary_calcul() {
  return getRuleContext<FilParser::Unary_calculContext>(0);
}

FilParser::CastContext* FilParser::ExprContext::cast() {
  return getRuleContext<FilParser::CastContext>(0);
}

tree::TerminalNode* FilParser::ExprContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

FilParser::Function_callContext* FilParser::ExprContext::function_call() {
  return getRuleContext<FilParser::Function_callContext>(0);
}

FilParser::LitteralContext* FilParser::ExprContext::litteral() {
  return getRuleContext<FilParser::LitteralContext>(0);
}

FilParser::Variable_declContext* FilParser::ExprContext::variable_decl() {
  return getRuleContext<FilParser::Variable_declContext>(0);
}

FilParser::Expr_parenthesisContext* FilParser::ExprContext::expr_parenthesis() {
  return getRuleContext<FilParser::Expr_parenthesisContext>(0);
}

FilParser::Expr_blockContext* FilParser::ExprContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}

std::vector<FilParser::ExprContext *> FilParser::ExprContext::expr() {
  return getRuleContexts<FilParser::ExprContext>();
}

FilParser::ExprContext* FilParser::ExprContext::expr(size_t i) {
  return getRuleContext<FilParser::ExprContext>(i);
}

FilParser::Binary_operatorContext* FilParser::ExprContext::binary_operator() {
  return getRuleContext<FilParser::Binary_operatorContext>(0);
}

tree::TerminalNode* FilParser::ExprContext::DOT() {
  return getToken(FilParser::DOT, 0);
}

tree::TerminalNode* FilParser::ExprContext::ARROW() {
  return getToken(FilParser::ARROW, 0);
}

FilParser::AssignationContext* FilParser::ExprContext::assignation() {
  return getRuleContext<FilParser::AssignationContext>(0);
}


size_t FilParser::ExprContext::getRuleIndex() const {
  return FilParser::RuleExpr;
}


std::any FilParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


FilParser::ExprContext* FilParser::expr() {
   return expr(0);
}

FilParser::ExprContext* FilParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  FilParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  FilParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, FilParser::RuleExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(158);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(142);
      function();
      break;
    }

    case 2: {
      setState(143);
      lambda();
      break;
    }

    case 3: {
      setState(144);
      interface();
      break;
    }

    case 4: {
      setState(145);
      class_();
      break;
    }

    case 5: {
      setState(146);
      enum_();
      break;
    }

    case 6: {
      setState(147);
      condition();
      break;
    }

    case 7: {
      setState(148);
      loop();
      break;
    }

    case 8: {
      setState(149);
      exception();
      break;
    }

    case 9: {
      setState(150);
      unary_calcul();
      break;
    }

    case 10: {
      setState(151);
      cast();
      break;
    }

    case 11: {
      setState(152);
      match(FilParser::IDENTIFIER);
      break;
    }

    case 12: {
      setState(153);
      function_call();
      break;
    }

    case 13: {
      setState(154);
      litteral();
      break;
    }

    case 14: {
      setState(155);
      variable_decl();
      break;
    }

    case 15: {
      setState(156);
      expr_parenthesis();
      break;
    }

    case 16: {
      setState(157);
      expr_block();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(174);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(172);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(160);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(161);
          binary_operator();
          setState(162);
          expr(12);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(164);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(165);
          match(FilParser::DOT);
          setState(166);
          expr(10);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(167);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(168);
          match(FilParser::ARROW);
          setState(169);
          expr(9);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(170);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(171);
          assignation();
          break;
        }

        default:
          break;
        } 
      }
      setState(176);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

FilParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::FunctionContext::FUN() {
  return getToken(FilParser::FUN, 0);
}

tree::TerminalNode* FilParser::FunctionContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

FilParser::Fun_paramsContext* FilParser::FunctionContext::fun_params() {
  return getRuleContext<FilParser::Fun_paramsContext>(0);
}

FilParser::Fun_bodyContext* FilParser::FunctionContext::fun_body() {
  return getRuleContext<FilParser::Fun_bodyContext>(0);
}

tree::TerminalNode* FilParser::FunctionContext::COLON() {
  return getToken(FilParser::COLON, 0);
}

FilParser::TypeContext* FilParser::FunctionContext::type() {
  return getRuleContext<FilParser::TypeContext>(0);
}


size_t FilParser::FunctionContext::getRuleIndex() const {
  return FilParser::RuleFunction;
}


std::any FilParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

FilParser::FunctionContext* FilParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 8, FilParser::RuleFunction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(177);
    match(FilParser::FUN);
    setState(178);
    match(FilParser::IDENTIFIER);
    setState(179);
    fun_params();
    setState(182);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FilParser::COLON) {
      setState(180);
      match(FilParser::COLON);
      setState(181);
      type();
    }
    setState(184);
    fun_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fun_paramsContext ------------------------------------------------------------------

FilParser::Fun_paramsContext::Fun_paramsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Fun_paramsContext::LPAREN() {
  return getToken(FilParser::LPAREN, 0);
}

tree::TerminalNode* FilParser::Fun_paramsContext::RPAREN() {
  return getToken(FilParser::RPAREN, 0);
}

FilParser::Fun_param_listContext* FilParser::Fun_paramsContext::fun_param_list() {
  return getRuleContext<FilParser::Fun_param_listContext>(0);
}


size_t FilParser::Fun_paramsContext::getRuleIndex() const {
  return FilParser::RuleFun_params;
}


std::any FilParser::Fun_paramsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFun_params(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Fun_paramsContext* FilParser::fun_params() {
  Fun_paramsContext *_localctx = _tracker.createInstance<Fun_paramsContext>(_ctx, getState());
  enterRule(_localctx, 10, FilParser::RuleFun_params);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    match(FilParser::LPAREN);
    setState(188);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FilParser::IDENTIFIER) {
      setState(187);
      fun_param_list();
    }
    setState(190);
    match(FilParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fun_param_listContext ------------------------------------------------------------------

FilParser::Fun_param_listContext::Fun_param_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FilParser::Fun_paramContext *> FilParser::Fun_param_listContext::fun_param() {
  return getRuleContexts<FilParser::Fun_paramContext>();
}

FilParser::Fun_paramContext* FilParser::Fun_param_listContext::fun_param(size_t i) {
  return getRuleContext<FilParser::Fun_paramContext>(i);
}

std::vector<tree::TerminalNode *> FilParser::Fun_param_listContext::COMMA() {
  return getTokens(FilParser::COMMA);
}

tree::TerminalNode* FilParser::Fun_param_listContext::COMMA(size_t i) {
  return getToken(FilParser::COMMA, i);
}


size_t FilParser::Fun_param_listContext::getRuleIndex() const {
  return FilParser::RuleFun_param_list;
}


std::any FilParser::Fun_param_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFun_param_list(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Fun_param_listContext* FilParser::fun_param_list() {
  Fun_param_listContext *_localctx = _tracker.createInstance<Fun_param_listContext>(_ctx, getState());
  enterRule(_localctx, 12, FilParser::RuleFun_param_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    fun_param();
    setState(197);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FilParser::COMMA) {
      setState(193);
      match(FilParser::COMMA);
      setState(194);
      fun_param();
      setState(199);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fun_paramContext ------------------------------------------------------------------

FilParser::Fun_paramContext::Fun_paramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Fun_paramContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

tree::TerminalNode* FilParser::Fun_paramContext::COLON() {
  return getToken(FilParser::COLON, 0);
}

FilParser::TypeContext* FilParser::Fun_paramContext::type() {
  return getRuleContext<FilParser::TypeContext>(0);
}


size_t FilParser::Fun_paramContext::getRuleIndex() const {
  return FilParser::RuleFun_param;
}


std::any FilParser::Fun_paramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFun_param(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Fun_paramContext* FilParser::fun_param() {
  Fun_paramContext *_localctx = _tracker.createInstance<Fun_paramContext>(_ctx, getState());
  enterRule(_localctx, 14, FilParser::RuleFun_param);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(200);
    match(FilParser::IDENTIFIER);
    setState(201);
    match(FilParser::COLON);
    setState(202);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fun_bodyContext ------------------------------------------------------------------

FilParser::Fun_bodyContext::Fun_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::AssignationContext* FilParser::Fun_bodyContext::assignation() {
  return getRuleContext<FilParser::AssignationContext>(0);
}

FilParser::Expr_parenthesisContext* FilParser::Fun_bodyContext::expr_parenthesis() {
  return getRuleContext<FilParser::Expr_parenthesisContext>(0);
}

FilParser::Expr_blockContext* FilParser::Fun_bodyContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}


size_t FilParser::Fun_bodyContext::getRuleIndex() const {
  return FilParser::RuleFun_body;
}


std::any FilParser::Fun_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFun_body(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Fun_bodyContext* FilParser::fun_body() {
  Fun_bodyContext *_localctx = _tracker.createInstance<Fun_bodyContext>(_ctx, getState());
  enterRule(_localctx, 16, FilParser::RuleFun_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(207);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(204);
      assignation();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(205);
      expr_parenthesis();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(206);
      expr_block();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_declContext ------------------------------------------------------------------

FilParser::Function_declContext::Function_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Function_declContext::FUN() {
  return getToken(FilParser::FUN, 0);
}

tree::TerminalNode* FilParser::Function_declContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

FilParser::Fun_paramsContext* FilParser::Function_declContext::fun_params() {
  return getRuleContext<FilParser::Fun_paramsContext>(0);
}

tree::TerminalNode* FilParser::Function_declContext::COLON() {
  return getToken(FilParser::COLON, 0);
}

FilParser::TypeContext* FilParser::Function_declContext::type() {
  return getRuleContext<FilParser::TypeContext>(0);
}


size_t FilParser::Function_declContext::getRuleIndex() const {
  return FilParser::RuleFunction_decl;
}


std::any FilParser::Function_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFunction_decl(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Function_declContext* FilParser::function_decl() {
  Function_declContext *_localctx = _tracker.createInstance<Function_declContext>(_ctx, getState());
  enterRule(_localctx, 18, FilParser::RuleFunction_decl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    match(FilParser::FUN);
    setState(210);
    match(FilParser::IDENTIFIER);
    setState(211);
    fun_params();
    setState(214);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FilParser::COLON) {
      setState(212);
      match(FilParser::COLON);
      setState(213);
      type();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LambdaContext ------------------------------------------------------------------

FilParser::LambdaContext::LambdaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::Fun_paramsContext* FilParser::LambdaContext::fun_params() {
  return getRuleContext<FilParser::Fun_paramsContext>(0);
}

tree::TerminalNode* FilParser::LambdaContext::ARROW() {
  return getToken(FilParser::ARROW, 0);
}

FilParser::Expr_blockContext* FilParser::LambdaContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}

FilParser::Expr_parenthesisContext* FilParser::LambdaContext::expr_parenthesis() {
  return getRuleContext<FilParser::Expr_parenthesisContext>(0);
}


size_t FilParser::LambdaContext::getRuleIndex() const {
  return FilParser::RuleLambda;
}


std::any FilParser::LambdaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitLambda(this);
  else
    return visitor->visitChildren(this);
}

FilParser::LambdaContext* FilParser::lambda() {
  LambdaContext *_localctx = _tracker.createInstance<LambdaContext>(_ctx, getState());
  enterRule(_localctx, 20, FilParser::RuleLambda);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(216);
    fun_params();
    setState(217);
    match(FilParser::ARROW);
    setState(220);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FilParser::LBRAK: {
        setState(218);
        expr_block();
        break;
      }

      case FilParser::LPAREN: {
        setState(219);
        expr_parenthesis();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InterfaceContext ------------------------------------------------------------------

FilParser::InterfaceContext::InterfaceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::InterfaceContext::INTERFACE() {
  return getToken(FilParser::INTERFACE, 0);
}

tree::TerminalNode* FilParser::InterfaceContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

FilParser::Class_paramsContext* FilParser::InterfaceContext::class_params() {
  return getRuleContext<FilParser::Class_paramsContext>(0);
}

FilParser::Interface_bodyContext* FilParser::InterfaceContext::interface_body() {
  return getRuleContext<FilParser::Interface_bodyContext>(0);
}


size_t FilParser::InterfaceContext::getRuleIndex() const {
  return FilParser::RuleInterface;
}


std::any FilParser::InterfaceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitInterface(this);
  else
    return visitor->visitChildren(this);
}

FilParser::InterfaceContext* FilParser::interface() {
  InterfaceContext *_localctx = _tracker.createInstance<InterfaceContext>(_ctx, getState());
  enterRule(_localctx, 22, FilParser::RuleInterface);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(222);
    match(FilParser::INTERFACE);
    setState(223);
    match(FilParser::IDENTIFIER);
    setState(225);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(224);
      class_params();
      break;
    }

    default:
      break;
    }
    setState(228);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(227);
      interface_body();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interface_bodyContext ------------------------------------------------------------------

FilParser::Interface_bodyContext::Interface_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Interface_bodyContext::LBRACE() {
  return getToken(FilParser::LBRACE, 0);
}

tree::TerminalNode* FilParser::Interface_bodyContext::RBRACE() {
  return getToken(FilParser::RBRACE, 0);
}

std::vector<FilParser::Function_declContext *> FilParser::Interface_bodyContext::function_decl() {
  return getRuleContexts<FilParser::Function_declContext>();
}

FilParser::Function_declContext* FilParser::Interface_bodyContext::function_decl(size_t i) {
  return getRuleContext<FilParser::Function_declContext>(i);
}


size_t FilParser::Interface_bodyContext::getRuleIndex() const {
  return FilParser::RuleInterface_body;
}


std::any FilParser::Interface_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitInterface_body(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Interface_bodyContext* FilParser::interface_body() {
  Interface_bodyContext *_localctx = _tracker.createInstance<Interface_bodyContext>(_ctx, getState());
  enterRule(_localctx, 24, FilParser::RuleInterface_body);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
    match(FilParser::LBRACE);
    setState(234);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FilParser::FUN) {
      setState(231);
      function_decl();
      setState(236);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(237);
    match(FilParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_Context ------------------------------------------------------------------

FilParser::Class_Context::Class_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::Class_modifierContext* FilParser::Class_Context::class_modifier() {
  return getRuleContext<FilParser::Class_modifierContext>(0);
}

tree::TerminalNode* FilParser::Class_Context::CLASS() {
  return getToken(FilParser::CLASS, 0);
}

tree::TerminalNode* FilParser::Class_Context::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

FilParser::Class_paramsContext* FilParser::Class_Context::class_params() {
  return getRuleContext<FilParser::Class_paramsContext>(0);
}

FilParser::Class_extendsContext* FilParser::Class_Context::class_extends() {
  return getRuleContext<FilParser::Class_extendsContext>(0);
}

FilParser::Class_bodyContext* FilParser::Class_Context::class_body() {
  return getRuleContext<FilParser::Class_bodyContext>(0);
}


size_t FilParser::Class_Context::getRuleIndex() const {
  return FilParser::RuleClass_;
}


std::any FilParser::Class_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_Context* FilParser::class_() {
  Class_Context *_localctx = _tracker.createInstance<Class_Context>(_ctx, getState());
  enterRule(_localctx, 26, FilParser::RuleClass_);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(239);
    class_modifier();
    setState(240);
    match(FilParser::CLASS);
    setState(241);
    match(FilParser::IDENTIFIER);
    setState(243);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(242);
      class_params();
      break;
    }

    default:
      break;
    }
    setState(246);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(245);
      class_extends();
      break;
    }

    default:
      break;
    }
    setState(249);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(248);
      class_body();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_modifierContext ------------------------------------------------------------------

FilParser::Class_modifierContext::Class_modifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Class_modifierContext::ABSTRACT() {
  return getToken(FilParser::ABSTRACT, 0);
}

tree::TerminalNode* FilParser::Class_modifierContext::OPEN() {
  return getToken(FilParser::OPEN, 0);
}


size_t FilParser::Class_modifierContext::getRuleIndex() const {
  return FilParser::RuleClass_modifier;
}


std::any FilParser::Class_modifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_modifier(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_modifierContext* FilParser::class_modifier() {
  Class_modifierContext *_localctx = _tracker.createInstance<Class_modifierContext>(_ctx, getState());
  enterRule(_localctx, 28, FilParser::RuleClass_modifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(251);
    _la = _input->LA(1);
    if (!(_la == FilParser::ABSTRACT

    || _la == FilParser::OPEN)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_paramsContext ------------------------------------------------------------------

FilParser::Class_paramsContext::Class_paramsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Class_paramsContext::LPAREN() {
  return getToken(FilParser::LPAREN, 0);
}

tree::TerminalNode* FilParser::Class_paramsContext::RPAREN() {
  return getToken(FilParser::RPAREN, 0);
}

FilParser::Class_param_listContext* FilParser::Class_paramsContext::class_param_list() {
  return getRuleContext<FilParser::Class_param_listContext>(0);
}


size_t FilParser::Class_paramsContext::getRuleIndex() const {
  return FilParser::RuleClass_params;
}


std::any FilParser::Class_paramsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_params(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_paramsContext* FilParser::class_params() {
  Class_paramsContext *_localctx = _tracker.createInstance<Class_paramsContext>(_ctx, getState());
  enterRule(_localctx, 30, FilParser::RuleClass_params);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    match(FilParser::LPAREN);
    setState(255);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 135790592) != 0) {
      setState(254);
      class_param_list();
    }
    setState(257);
    match(FilParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_param_listContext ------------------------------------------------------------------

FilParser::Class_param_listContext::Class_param_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FilParser::Class_paramContext *> FilParser::Class_param_listContext::class_param() {
  return getRuleContexts<FilParser::Class_paramContext>();
}

FilParser::Class_paramContext* FilParser::Class_param_listContext::class_param(size_t i) {
  return getRuleContext<FilParser::Class_paramContext>(i);
}

std::vector<tree::TerminalNode *> FilParser::Class_param_listContext::COMMA() {
  return getTokens(FilParser::COMMA);
}

tree::TerminalNode* FilParser::Class_param_listContext::COMMA(size_t i) {
  return getToken(FilParser::COMMA, i);
}


size_t FilParser::Class_param_listContext::getRuleIndex() const {
  return FilParser::RuleClass_param_list;
}


std::any FilParser::Class_param_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_param_list(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_param_listContext* FilParser::class_param_list() {
  Class_param_listContext *_localctx = _tracker.createInstance<Class_param_listContext>(_ctx, getState());
  enterRule(_localctx, 32, FilParser::RuleClass_param_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
    class_param();
    setState(264);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FilParser::COMMA) {
      setState(260);
      match(FilParser::COMMA);
      setState(261);
      class_param();
      setState(266);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_paramContext ------------------------------------------------------------------

FilParser::Class_paramContext::Class_paramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::Variable_declContext* FilParser::Class_paramContext::variable_decl() {
  return getRuleContext<FilParser::Variable_declContext>(0);
}

tree::TerminalNode* FilParser::Class_paramContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

tree::TerminalNode* FilParser::Class_paramContext::COLON() {
  return getToken(FilParser::COLON, 0);
}

FilParser::TypeContext* FilParser::Class_paramContext::type() {
  return getRuleContext<FilParser::TypeContext>(0);
}

tree::TerminalNode* FilParser::Class_paramContext::EQ() {
  return getToken(FilParser::EQ, 0);
}

FilParser::LitteralContext* FilParser::Class_paramContext::litteral() {
  return getRuleContext<FilParser::LitteralContext>(0);
}


size_t FilParser::Class_paramContext::getRuleIndex() const {
  return FilParser::RuleClass_param;
}


std::any FilParser::Class_paramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_param(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_paramContext* FilParser::class_param() {
  Class_paramContext *_localctx = _tracker.createInstance<Class_paramContext>(_ctx, getState());
  enterRule(_localctx, 34, FilParser::RuleClass_param);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(275);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FilParser::VAL:
      case FilParser::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(267);
        variable_decl();
        break;
      }

      case FilParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(268);
        match(FilParser::IDENTIFIER);
        setState(269);
        match(FilParser::COLON);
        setState(270);
        type();
        setState(273);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FilParser::EQ) {
          setState(271);
          match(FilParser::EQ);
          setState(272);
          litteral();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_extendsContext ------------------------------------------------------------------

FilParser::Class_extendsContext::Class_extendsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Class_extendsContext::COLON() {
  return getToken(FilParser::COLON, 0);
}

FilParser::Class_extend_listContext* FilParser::Class_extendsContext::class_extend_list() {
  return getRuleContext<FilParser::Class_extend_listContext>(0);
}


size_t FilParser::Class_extendsContext::getRuleIndex() const {
  return FilParser::RuleClass_extends;
}


std::any FilParser::Class_extendsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_extends(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_extendsContext* FilParser::class_extends() {
  Class_extendsContext *_localctx = _tracker.createInstance<Class_extendsContext>(_ctx, getState());
  enterRule(_localctx, 36, FilParser::RuleClass_extends);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(277);
    match(FilParser::COLON);
    setState(278);
    class_extend_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_extend_listContext ------------------------------------------------------------------

FilParser::Class_extend_listContext::Class_extend_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FilParser::Class_extendContext *> FilParser::Class_extend_listContext::class_extend() {
  return getRuleContexts<FilParser::Class_extendContext>();
}

FilParser::Class_extendContext* FilParser::Class_extend_listContext::class_extend(size_t i) {
  return getRuleContext<FilParser::Class_extendContext>(i);
}

std::vector<tree::TerminalNode *> FilParser::Class_extend_listContext::COMMA() {
  return getTokens(FilParser::COMMA);
}

tree::TerminalNode* FilParser::Class_extend_listContext::COMMA(size_t i) {
  return getToken(FilParser::COMMA, i);
}


size_t FilParser::Class_extend_listContext::getRuleIndex() const {
  return FilParser::RuleClass_extend_list;
}


std::any FilParser::Class_extend_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_extend_list(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_extend_listContext* FilParser::class_extend_list() {
  Class_extend_listContext *_localctx = _tracker.createInstance<Class_extend_listContext>(_ctx, getState());
  enterRule(_localctx, 38, FilParser::RuleClass_extend_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(280);
    class_extend();
    setState(285);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(281);
        match(FilParser::COMMA);
        setState(282);
        class_extend(); 
      }
      setState(287);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_extendContext ------------------------------------------------------------------

FilParser::Class_extendContext::Class_extendContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Class_extendContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

FilParser::Function_call_paramsContext* FilParser::Class_extendContext::function_call_params() {
  return getRuleContext<FilParser::Function_call_paramsContext>(0);
}


size_t FilParser::Class_extendContext::getRuleIndex() const {
  return FilParser::RuleClass_extend;
}


std::any FilParser::Class_extendContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_extend(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_extendContext* FilParser::class_extend() {
  Class_extendContext *_localctx = _tracker.createInstance<Class_extendContext>(_ctx, getState());
  enterRule(_localctx, 40, FilParser::RuleClass_extend);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(288);
    match(FilParser::IDENTIFIER);
    setState(289);
    function_call_params();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_bodyContext ------------------------------------------------------------------

FilParser::Class_bodyContext::Class_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Class_bodyContext::LBRACE() {
  return getToken(FilParser::LBRACE, 0);
}

FilParser::Class_constructorContext* FilParser::Class_bodyContext::class_constructor() {
  return getRuleContext<FilParser::Class_constructorContext>(0);
}

tree::TerminalNode* FilParser::Class_bodyContext::RBRACE() {
  return getToken(FilParser::RBRACE, 0);
}

std::vector<FilParser::Class_variableContext *> FilParser::Class_bodyContext::class_variable() {
  return getRuleContexts<FilParser::Class_variableContext>();
}

FilParser::Class_variableContext* FilParser::Class_bodyContext::class_variable(size_t i) {
  return getRuleContext<FilParser::Class_variableContext>(i);
}

std::vector<FilParser::Class_functionContext *> FilParser::Class_bodyContext::class_function() {
  return getRuleContexts<FilParser::Class_functionContext>();
}

FilParser::Class_functionContext* FilParser::Class_bodyContext::class_function(size_t i) {
  return getRuleContext<FilParser::Class_functionContext>(i);
}


size_t FilParser::Class_bodyContext::getRuleIndex() const {
  return FilParser::RuleClass_body;
}


std::any FilParser::Class_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_body(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_bodyContext* FilParser::class_body() {
  Class_bodyContext *_localctx = _tracker.createInstance<Class_bodyContext>(_ctx, getState());
  enterRule(_localctx, 42, FilParser::RuleClass_body);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(291);
    match(FilParser::LBRACE);
    setState(292);
    class_constructor();
    setState(297);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3904) != 0) {
      setState(295);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
      case 1: {
        setState(293);
        class_variable();
        break;
      }

      case 2: {
        setState(294);
        class_function();
        break;
      }

      default:
        break;
      }
      setState(299);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(300);
    match(FilParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_functionContext ------------------------------------------------------------------

FilParser::Class_functionContext::Class_functionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::Class_atr_modifierContext* FilParser::Class_functionContext::class_atr_modifier() {
  return getRuleContext<FilParser::Class_atr_modifierContext>(0);
}

FilParser::FunctionContext* FilParser::Class_functionContext::function() {
  return getRuleContext<FilParser::FunctionContext>(0);
}

tree::TerminalNode* FilParser::Class_functionContext::ABSTRACT() {
  return getToken(FilParser::ABSTRACT, 0);
}


size_t FilParser::Class_functionContext::getRuleIndex() const {
  return FilParser::RuleClass_function;
}


std::any FilParser::Class_functionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_function(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_functionContext* FilParser::class_function() {
  Class_functionContext *_localctx = _tracker.createInstance<Class_functionContext>(_ctx, getState());
  enterRule(_localctx, 44, FilParser::RuleClass_function);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(303);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FilParser::ABSTRACT) {
      setState(302);
      match(FilParser::ABSTRACT);
    }
    setState(305);
    class_atr_modifier();
    setState(306);
    function();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_variableContext ------------------------------------------------------------------

FilParser::Class_variableContext::Class_variableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::Class_atr_modifierContext* FilParser::Class_variableContext::class_atr_modifier() {
  return getRuleContext<FilParser::Class_atr_modifierContext>(0);
}

FilParser::Variable_declContext* FilParser::Class_variableContext::variable_decl() {
  return getRuleContext<FilParser::Variable_declContext>(0);
}


size_t FilParser::Class_variableContext::getRuleIndex() const {
  return FilParser::RuleClass_variable;
}


std::any FilParser::Class_variableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_variable(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_variableContext* FilParser::class_variable() {
  Class_variableContext *_localctx = _tracker.createInstance<Class_variableContext>(_ctx, getState());
  enterRule(_localctx, 46, FilParser::RuleClass_variable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(308);
    class_atr_modifier();
    setState(309);
    variable_decl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_atr_modifierContext ------------------------------------------------------------------

FilParser::Class_atr_modifierContext::Class_atr_modifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Class_atr_modifierContext::PRIVATE() {
  return getToken(FilParser::PRIVATE, 0);
}

tree::TerminalNode* FilParser::Class_atr_modifierContext::PUBLIC() {
  return getToken(FilParser::PUBLIC, 0);
}

tree::TerminalNode* FilParser::Class_atr_modifierContext::INTERNAL() {
  return getToken(FilParser::INTERNAL, 0);
}

tree::TerminalNode* FilParser::Class_atr_modifierContext::PROTECTED() {
  return getToken(FilParser::PROTECTED, 0);
}


size_t FilParser::Class_atr_modifierContext::getRuleIndex() const {
  return FilParser::RuleClass_atr_modifier;
}


std::any FilParser::Class_atr_modifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_atr_modifier(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_atr_modifierContext* FilParser::class_atr_modifier() {
  Class_atr_modifierContext *_localctx = _tracker.createInstance<Class_atr_modifierContext>(_ctx, getState());
  enterRule(_localctx, 48, FilParser::RuleClass_atr_modifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(311);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3840) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_constructorContext ------------------------------------------------------------------

FilParser::Class_constructorContext::Class_constructorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Class_constructorContext::CONSTRUCTOR() {
  return getToken(FilParser::CONSTRUCTOR, 0);
}

FilParser::Expr_blockContext* FilParser::Class_constructorContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}


size_t FilParser::Class_constructorContext::getRuleIndex() const {
  return FilParser::RuleClass_constructor;
}


std::any FilParser::Class_constructorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_constructor(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_constructorContext* FilParser::class_constructor() {
  Class_constructorContext *_localctx = _tracker.createInstance<Class_constructorContext>(_ctx, getState());
  enterRule(_localctx, 50, FilParser::RuleClass_constructor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(313);
    match(FilParser::CONSTRUCTOR);
    setState(314);
    expr_block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_Context ------------------------------------------------------------------

FilParser::Enum_Context::Enum_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Enum_Context::ENUM() {
  return getToken(FilParser::ENUM, 0);
}

tree::TerminalNode* FilParser::Enum_Context::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

FilParser::Enum_bodyContext* FilParser::Enum_Context::enum_body() {
  return getRuleContext<FilParser::Enum_bodyContext>(0);
}


size_t FilParser::Enum_Context::getRuleIndex() const {
  return FilParser::RuleEnum_;
}


std::any FilParser::Enum_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitEnum_(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Enum_Context* FilParser::enum_() {
  Enum_Context *_localctx = _tracker.createInstance<Enum_Context>(_ctx, getState());
  enterRule(_localctx, 52, FilParser::RuleEnum_);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(316);
    match(FilParser::ENUM);
    setState(317);
    match(FilParser::IDENTIFIER);
    setState(319);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      setState(318);
      enum_body();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_bodyContext ------------------------------------------------------------------

FilParser::Enum_bodyContext::Enum_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Enum_bodyContext::LBRACE() {
  return getToken(FilParser::LBRACE, 0);
}

tree::TerminalNode* FilParser::Enum_bodyContext::RBRACE() {
  return getToken(FilParser::RBRACE, 0);
}

std::vector<tree::TerminalNode *> FilParser::Enum_bodyContext::IDENTIFIER() {
  return getTokens(FilParser::IDENTIFIER);
}

tree::TerminalNode* FilParser::Enum_bodyContext::IDENTIFIER(size_t i) {
  return getToken(FilParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> FilParser::Enum_bodyContext::COMMA() {
  return getTokens(FilParser::COMMA);
}

tree::TerminalNode* FilParser::Enum_bodyContext::COMMA(size_t i) {
  return getToken(FilParser::COMMA, i);
}


size_t FilParser::Enum_bodyContext::getRuleIndex() const {
  return FilParser::RuleEnum_body;
}


std::any FilParser::Enum_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitEnum_body(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Enum_bodyContext* FilParser::enum_body() {
  Enum_bodyContext *_localctx = _tracker.createInstance<Enum_bodyContext>(_ctx, getState());
  enterRule(_localctx, 54, FilParser::RuleEnum_body);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(321);
    match(FilParser::LBRACE);
    setState(330);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FilParser::IDENTIFIER) {
      setState(322);
      match(FilParser::IDENTIFIER);
      setState(327);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FilParser::COMMA) {
        setState(323);
        match(FilParser::COMMA);
        setState(324);
        match(FilParser::IDENTIFIER);
        setState(329);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(332);
    match(FilParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionContext ------------------------------------------------------------------

FilParser::ConditionContext::ConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::If_Context* FilParser::ConditionContext::if_() {
  return getRuleContext<FilParser::If_Context>(0);
}

FilParser::Switch_Context* FilParser::ConditionContext::switch_() {
  return getRuleContext<FilParser::Switch_Context>(0);
}


size_t FilParser::ConditionContext::getRuleIndex() const {
  return FilParser::RuleCondition;
}


std::any FilParser::ConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitCondition(this);
  else
    return visitor->visitChildren(this);
}

FilParser::ConditionContext* FilParser::condition() {
  ConditionContext *_localctx = _tracker.createInstance<ConditionContext>(_ctx, getState());
  enterRule(_localctx, 56, FilParser::RuleCondition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(336);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FilParser::IF: {
        enterOuterAlt(_localctx, 1);
        setState(334);
        if_();
        break;
      }

      case FilParser::SWITCH: {
        enterOuterAlt(_localctx, 2);
        setState(335);
        switch_();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_Context ------------------------------------------------------------------

FilParser::If_Context::If_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::If_Context::IF() {
  return getToken(FilParser::IF, 0);
}

FilParser::If_conditionContext* FilParser::If_Context::if_condition() {
  return getRuleContext<FilParser::If_conditionContext>(0);
}

FilParser::If_bodyContext* FilParser::If_Context::if_body() {
  return getRuleContext<FilParser::If_bodyContext>(0);
}

std::vector<FilParser::Else_ifContext *> FilParser::If_Context::else_if() {
  return getRuleContexts<FilParser::Else_ifContext>();
}

FilParser::Else_ifContext* FilParser::If_Context::else_if(size_t i) {
  return getRuleContext<FilParser::Else_ifContext>(i);
}

FilParser::Else_Context* FilParser::If_Context::else_() {
  return getRuleContext<FilParser::Else_Context>(0);
}


size_t FilParser::If_Context::getRuleIndex() const {
  return FilParser::RuleIf_;
}


std::any FilParser::If_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitIf_(this);
  else
    return visitor->visitChildren(this);
}

FilParser::If_Context* FilParser::if_() {
  If_Context *_localctx = _tracker.createInstance<If_Context>(_ctx, getState());
  enterRule(_localctx, 58, FilParser::RuleIf_);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(338);
    match(FilParser::IF);
    setState(339);
    if_condition();
    setState(340);
    if_body();
    setState(344);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(341);
        else_if(); 
      }
      setState(346);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
    setState(348);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      setState(347);
      else_();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_conditionContext ------------------------------------------------------------------

FilParser::If_conditionContext::If_conditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::Expr_parenthesisContext* FilParser::If_conditionContext::expr_parenthesis() {
  return getRuleContext<FilParser::Expr_parenthesisContext>(0);
}


size_t FilParser::If_conditionContext::getRuleIndex() const {
  return FilParser::RuleIf_condition;
}


std::any FilParser::If_conditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitIf_condition(this);
  else
    return visitor->visitChildren(this);
}

FilParser::If_conditionContext* FilParser::if_condition() {
  If_conditionContext *_localctx = _tracker.createInstance<If_conditionContext>(_ctx, getState());
  enterRule(_localctx, 60, FilParser::RuleIf_condition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(350);
    expr_parenthesis();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_bodyContext ------------------------------------------------------------------

FilParser::If_bodyContext::If_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::ExprContext* FilParser::If_bodyContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
}

FilParser::Expr_blockContext* FilParser::If_bodyContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}

FilParser::Expr_parenthesisContext* FilParser::If_bodyContext::expr_parenthesis() {
  return getRuleContext<FilParser::Expr_parenthesisContext>(0);
}


size_t FilParser::If_bodyContext::getRuleIndex() const {
  return FilParser::RuleIf_body;
}


std::any FilParser::If_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitIf_body(this);
  else
    return visitor->visitChildren(this);
}

FilParser::If_bodyContext* FilParser::if_body() {
  If_bodyContext *_localctx = _tracker.createInstance<If_bodyContext>(_ctx, getState());
  enterRule(_localctx, 62, FilParser::RuleIf_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(355);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(352);
      expr(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(353);
      expr_block();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(354);
      expr_parenthesis();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Else_ifContext ------------------------------------------------------------------

FilParser::Else_ifContext::Else_ifContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Else_ifContext::ELSE() {
  return getToken(FilParser::ELSE, 0);
}

tree::TerminalNode* FilParser::Else_ifContext::IF() {
  return getToken(FilParser::IF, 0);
}

FilParser::If_conditionContext* FilParser::Else_ifContext::if_condition() {
  return getRuleContext<FilParser::If_conditionContext>(0);
}

FilParser::If_bodyContext* FilParser::Else_ifContext::if_body() {
  return getRuleContext<FilParser::If_bodyContext>(0);
}


size_t FilParser::Else_ifContext::getRuleIndex() const {
  return FilParser::RuleElse_if;
}


std::any FilParser::Else_ifContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitElse_if(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Else_ifContext* FilParser::else_if() {
  Else_ifContext *_localctx = _tracker.createInstance<Else_ifContext>(_ctx, getState());
  enterRule(_localctx, 64, FilParser::RuleElse_if);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
    match(FilParser::ELSE);
    setState(358);
    match(FilParser::IF);
    setState(359);
    if_condition();
    setState(360);
    if_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Else_Context ------------------------------------------------------------------

FilParser::Else_Context::Else_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Else_Context::ELSE() {
  return getToken(FilParser::ELSE, 0);
}

FilParser::If_bodyContext* FilParser::Else_Context::if_body() {
  return getRuleContext<FilParser::If_bodyContext>(0);
}


size_t FilParser::Else_Context::getRuleIndex() const {
  return FilParser::RuleElse_;
}


std::any FilParser::Else_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitElse_(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Else_Context* FilParser::else_() {
  Else_Context *_localctx = _tracker.createInstance<Else_Context>(_ctx, getState());
  enterRule(_localctx, 66, FilParser::RuleElse_);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(362);
    match(FilParser::ELSE);
    setState(363);
    if_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Switch_Context ------------------------------------------------------------------

FilParser::Switch_Context::Switch_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Switch_Context::SWITCH() {
  return getToken(FilParser::SWITCH, 0);
}

FilParser::Switch_conditionContext* FilParser::Switch_Context::switch_condition() {
  return getRuleContext<FilParser::Switch_conditionContext>(0);
}

FilParser::Switch_bodyContext* FilParser::Switch_Context::switch_body() {
  return getRuleContext<FilParser::Switch_bodyContext>(0);
}


size_t FilParser::Switch_Context::getRuleIndex() const {
  return FilParser::RuleSwitch_;
}


std::any FilParser::Switch_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitSwitch_(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Switch_Context* FilParser::switch_() {
  Switch_Context *_localctx = _tracker.createInstance<Switch_Context>(_ctx, getState());
  enterRule(_localctx, 68, FilParser::RuleSwitch_);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(365);
    match(FilParser::SWITCH);
    setState(366);
    switch_condition();
    setState(367);
    switch_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Switch_conditionContext ------------------------------------------------------------------

FilParser::Switch_conditionContext::Switch_conditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::Expr_parenthesisContext* FilParser::Switch_conditionContext::expr_parenthesis() {
  return getRuleContext<FilParser::Expr_parenthesisContext>(0);
}


size_t FilParser::Switch_conditionContext::getRuleIndex() const {
  return FilParser::RuleSwitch_condition;
}


std::any FilParser::Switch_conditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitSwitch_condition(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Switch_conditionContext* FilParser::switch_condition() {
  Switch_conditionContext *_localctx = _tracker.createInstance<Switch_conditionContext>(_ctx, getState());
  enterRule(_localctx, 70, FilParser::RuleSwitch_condition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(369);
    expr_parenthesis();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Switch_bodyContext ------------------------------------------------------------------

FilParser::Switch_bodyContext::Switch_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Switch_bodyContext::LBRACE() {
  return getToken(FilParser::LBRACE, 0);
}

tree::TerminalNode* FilParser::Switch_bodyContext::RBRACE() {
  return getToken(FilParser::RBRACE, 0);
}

std::vector<FilParser::Switch_caseContext *> FilParser::Switch_bodyContext::switch_case() {
  return getRuleContexts<FilParser::Switch_caseContext>();
}

FilParser::Switch_caseContext* FilParser::Switch_bodyContext::switch_case(size_t i) {
  return getRuleContext<FilParser::Switch_caseContext>(i);
}


size_t FilParser::Switch_bodyContext::getRuleIndex() const {
  return FilParser::RuleSwitch_body;
}


std::any FilParser::Switch_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitSwitch_body(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Switch_bodyContext* FilParser::switch_body() {
  Switch_bodyContext *_localctx = _tracker.createInstance<Switch_bodyContext>(_ctx, getState());
  enterRule(_localctx, 72, FilParser::RuleSwitch_body);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(371);
    match(FilParser::LBRACE);
    setState(375);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8646911284668923904) != 0) {
      setState(372);
      switch_case();
      setState(377);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(378);
    match(FilParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Switch_caseContext ------------------------------------------------------------------

FilParser::Switch_caseContext::Switch_caseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Switch_caseContext::ARROW() {
  return getToken(FilParser::ARROW, 0);
}

FilParser::LitteralContext* FilParser::Switch_caseContext::litteral() {
  return getRuleContext<FilParser::LitteralContext>(0);
}

tree::TerminalNode* FilParser::Switch_caseContext::DEFAULT() {
  return getToken(FilParser::DEFAULT, 0);
}

FilParser::ExprContext* FilParser::Switch_caseContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
}

FilParser::Expr_blockContext* FilParser::Switch_caseContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}

FilParser::Expr_parenthesisContext* FilParser::Switch_caseContext::expr_parenthesis() {
  return getRuleContext<FilParser::Expr_parenthesisContext>(0);
}


size_t FilParser::Switch_caseContext::getRuleIndex() const {
  return FilParser::RuleSwitch_case;
}


std::any FilParser::Switch_caseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitSwitch_case(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Switch_caseContext* FilParser::switch_case() {
  Switch_caseContext *_localctx = _tracker.createInstance<Switch_caseContext>(_ctx, getState());
  enterRule(_localctx, 74, FilParser::RuleSwitch_case);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(382);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FilParser::TRUE:
      case FilParser::FALSE:
      case FilParser::NULL_:
      case FilParser::INT:
      case FilParser::FLOAT:
      case FilParser::STRING:
      case FilParser::CHAR: {
        setState(380);
        litteral();
        break;
      }

      case FilParser::DEFAULT: {
        setState(381);
        match(FilParser::DEFAULT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(384);
    match(FilParser::ARROW);
    setState(388);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      setState(385);
      expr(0);
      break;
    }

    case 2: {
      setState(386);
      expr_block();
      break;
    }

    case 3: {
      setState(387);
      expr_parenthesis();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopContext ------------------------------------------------------------------

FilParser::LoopContext::LoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::ForiContext* FilParser::LoopContext::fori() {
  return getRuleContext<FilParser::ForiContext>(0);
}

FilParser::ForiterContext* FilParser::LoopContext::foriter() {
  return getRuleContext<FilParser::ForiterContext>(0);
}

FilParser::While_Context* FilParser::LoopContext::while_() {
  return getRuleContext<FilParser::While_Context>(0);
}


size_t FilParser::LoopContext::getRuleIndex() const {
  return FilParser::RuleLoop;
}


std::any FilParser::LoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitLoop(this);
  else
    return visitor->visitChildren(this);
}

FilParser::LoopContext* FilParser::loop() {
  LoopContext *_localctx = _tracker.createInstance<LoopContext>(_ctx, getState());
  enterRule(_localctx, 76, FilParser::RuleLoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(393);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(390);
      fori();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(391);
      foriter();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(392);
      while_();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForiContext ------------------------------------------------------------------

FilParser::ForiContext::ForiContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::ForiContext::FOR() {
  return getToken(FilParser::FOR, 0);
}

FilParser::Fori_conditionContext* FilParser::ForiContext::fori_condition() {
  return getRuleContext<FilParser::Fori_conditionContext>(0);
}

FilParser::ExprContext* FilParser::ForiContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
}

FilParser::Expr_blockContext* FilParser::ForiContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}


size_t FilParser::ForiContext::getRuleIndex() const {
  return FilParser::RuleFori;
}


std::any FilParser::ForiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFori(this);
  else
    return visitor->visitChildren(this);
}

FilParser::ForiContext* FilParser::fori() {
  ForiContext *_localctx = _tracker.createInstance<ForiContext>(_ctx, getState());
  enterRule(_localctx, 78, FilParser::RuleFori);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    match(FilParser::FOR);
    setState(396);
    fori_condition();
    setState(399);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      setState(397);
      expr(0);
      break;
    }

    case 2: {
      setState(398);
      expr_block();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fori_conditionContext ------------------------------------------------------------------

FilParser::Fori_conditionContext::Fori_conditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Fori_conditionContext::LPAREN() {
  return getToken(FilParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> FilParser::Fori_conditionContext::SEMICOLON() {
  return getTokens(FilParser::SEMICOLON);
}

tree::TerminalNode* FilParser::Fori_conditionContext::SEMICOLON(size_t i) {
  return getToken(FilParser::SEMICOLON, i);
}

tree::TerminalNode* FilParser::Fori_conditionContext::RPAREN() {
  return getToken(FilParser::RPAREN, 0);
}

FilParser::Variable_declContext* FilParser::Fori_conditionContext::variable_decl() {
  return getRuleContext<FilParser::Variable_declContext>(0);
}

std::vector<FilParser::ExprContext *> FilParser::Fori_conditionContext::expr() {
  return getRuleContexts<FilParser::ExprContext>();
}

FilParser::ExprContext* FilParser::Fori_conditionContext::expr(size_t i) {
  return getRuleContext<FilParser::ExprContext>(i);
}


size_t FilParser::Fori_conditionContext::getRuleIndex() const {
  return FilParser::RuleFori_condition;
}


std::any FilParser::Fori_conditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFori_condition(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Fori_conditionContext* FilParser::fori_condition() {
  Fori_conditionContext *_localctx = _tracker.createInstance<Fori_conditionContext>(_ctx, getState());
  enterRule(_localctx, 80, FilParser::RuleFori_condition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(401);
    match(FilParser::LPAREN);
    setState(403);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FilParser::VAL

    || _la == FilParser::VAR) {
      setState(402);
      variable_decl();
    }
    setState(405);
    match(FilParser::SEMICOLON);
    setState(407);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 9187377346430984408) != 0) {
      setState(406);
      expr(0);
    }
    setState(409);
    match(FilParser::SEMICOLON);
    setState(411);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 9187377346430984408) != 0) {
      setState(410);
      expr(0);
    }
    setState(413);
    match(FilParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForiterContext ------------------------------------------------------------------

FilParser::ForiterContext::ForiterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::ForiterContext::FOR() {
  return getToken(FilParser::FOR, 0);
}

FilParser::Foriter_conditionContext* FilParser::ForiterContext::foriter_condition() {
  return getRuleContext<FilParser::Foriter_conditionContext>(0);
}

FilParser::ExprContext* FilParser::ForiterContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
}

FilParser::Expr_blockContext* FilParser::ForiterContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}


size_t FilParser::ForiterContext::getRuleIndex() const {
  return FilParser::RuleForiter;
}


std::any FilParser::ForiterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitForiter(this);
  else
    return visitor->visitChildren(this);
}

FilParser::ForiterContext* FilParser::foriter() {
  ForiterContext *_localctx = _tracker.createInstance<ForiterContext>(_ctx, getState());
  enterRule(_localctx, 82, FilParser::RuleForiter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(415);
    match(FilParser::FOR);
    setState(416);
    foriter_condition();
    setState(419);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      setState(417);
      expr(0);
      break;
    }

    case 2: {
      setState(418);
      expr_block();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Foriter_conditionContext ------------------------------------------------------------------

FilParser::Foriter_conditionContext::Foriter_conditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Foriter_conditionContext::LPAREN() {
  return getToken(FilParser::LPAREN, 0);
}

std::vector<tree::TerminalNode *> FilParser::Foriter_conditionContext::IDENTIFIER() {
  return getTokens(FilParser::IDENTIFIER);
}

tree::TerminalNode* FilParser::Foriter_conditionContext::IDENTIFIER(size_t i) {
  return getToken(FilParser::IDENTIFIER, i);
}

tree::TerminalNode* FilParser::Foriter_conditionContext::COLON() {
  return getToken(FilParser::COLON, 0);
}

tree::TerminalNode* FilParser::Foriter_conditionContext::RPAREN() {
  return getToken(FilParser::RPAREN, 0);
}

tree::TerminalNode* FilParser::Foriter_conditionContext::VAL() {
  return getToken(FilParser::VAL, 0);
}

tree::TerminalNode* FilParser::Foriter_conditionContext::VAR() {
  return getToken(FilParser::VAR, 0);
}


size_t FilParser::Foriter_conditionContext::getRuleIndex() const {
  return FilParser::RuleForiter_condition;
}


std::any FilParser::Foriter_conditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitForiter_condition(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Foriter_conditionContext* FilParser::foriter_condition() {
  Foriter_conditionContext *_localctx = _tracker.createInstance<Foriter_conditionContext>(_ctx, getState());
  enterRule(_localctx, 84, FilParser::RuleForiter_condition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(421);
    match(FilParser::LPAREN);
    setState(422);
    _la = _input->LA(1);
    if (!(_la == FilParser::VAL

    || _la == FilParser::VAR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(423);
    match(FilParser::IDENTIFIER);
    setState(424);
    match(FilParser::COLON);
    setState(425);
    match(FilParser::IDENTIFIER);
    setState(426);
    match(FilParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_Context ------------------------------------------------------------------

FilParser::While_Context::While_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::While_Context::WHILE() {
  return getToken(FilParser::WHILE, 0);
}

FilParser::If_conditionContext* FilParser::While_Context::if_condition() {
  return getRuleContext<FilParser::If_conditionContext>(0);
}

FilParser::If_bodyContext* FilParser::While_Context::if_body() {
  return getRuleContext<FilParser::If_bodyContext>(0);
}


size_t FilParser::While_Context::getRuleIndex() const {
  return FilParser::RuleWhile_;
}


std::any FilParser::While_Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitWhile_(this);
  else
    return visitor->visitChildren(this);
}

FilParser::While_Context* FilParser::while_() {
  While_Context *_localctx = _tracker.createInstance<While_Context>(_ctx, getState());
  enterRule(_localctx, 86, FilParser::RuleWhile_);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(428);
    match(FilParser::WHILE);
    setState(429);
    if_condition();
    setState(430);
    if_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExceptionContext ------------------------------------------------------------------

FilParser::ExceptionContext::ExceptionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::ExceptionContext::TRY() {
  return getToken(FilParser::TRY, 0);
}

FilParser::ExprContext* FilParser::ExceptionContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
}

FilParser::Expr_blockContext* FilParser::ExceptionContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}

FilParser::Expr_parenthesisContext* FilParser::ExceptionContext::expr_parenthesis() {
  return getRuleContext<FilParser::Expr_parenthesisContext>(0);
}

std::vector<FilParser::Catch_bodyContext *> FilParser::ExceptionContext::catch_body() {
  return getRuleContexts<FilParser::Catch_bodyContext>();
}

FilParser::Catch_bodyContext* FilParser::ExceptionContext::catch_body(size_t i) {
  return getRuleContext<FilParser::Catch_bodyContext>(i);
}


size_t FilParser::ExceptionContext::getRuleIndex() const {
  return FilParser::RuleException;
}


std::any FilParser::ExceptionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitException(this);
  else
    return visitor->visitChildren(this);
}

FilParser::ExceptionContext* FilParser::exception() {
  ExceptionContext *_localctx = _tracker.createInstance<ExceptionContext>(_ctx, getState());
  enterRule(_localctx, 88, FilParser::RuleException);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(432);
    match(FilParser::TRY);
    setState(436);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      setState(433);
      expr(0);
      break;
    }

    case 2: {
      setState(434);
      expr_block();
      break;
    }

    case 3: {
      setState(435);
      expr_parenthesis();
      break;
    }

    default:
      break;
    }
    setState(439); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(438);
              catch_body();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(441); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Catch_bodyContext ------------------------------------------------------------------

FilParser::Catch_bodyContext::Catch_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Catch_bodyContext::CATCH() {
  return getToken(FilParser::CATCH, 0);
}

tree::TerminalNode* FilParser::Catch_bodyContext::LPAREN() {
  return getToken(FilParser::LPAREN, 0);
}

FilParser::Fun_paramContext* FilParser::Catch_bodyContext::fun_param() {
  return getRuleContext<FilParser::Fun_paramContext>(0);
}

tree::TerminalNode* FilParser::Catch_bodyContext::RPAREN() {
  return getToken(FilParser::RPAREN, 0);
}

FilParser::ExprContext* FilParser::Catch_bodyContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
}

FilParser::Expr_blockContext* FilParser::Catch_bodyContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}

FilParser::Expr_parenthesisContext* FilParser::Catch_bodyContext::expr_parenthesis() {
  return getRuleContext<FilParser::Expr_parenthesisContext>(0);
}


size_t FilParser::Catch_bodyContext::getRuleIndex() const {
  return FilParser::RuleCatch_body;
}


std::any FilParser::Catch_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitCatch_body(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Catch_bodyContext* FilParser::catch_body() {
  Catch_bodyContext *_localctx = _tracker.createInstance<Catch_bodyContext>(_ctx, getState());
  enterRule(_localctx, 90, FilParser::RuleCatch_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(443);
    match(FilParser::CATCH);
    setState(444);
    match(FilParser::LPAREN);
    setState(445);
    fun_param();
    setState(446);
    match(FilParser::RPAREN);
    setState(450);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      setState(447);
      expr(0);
      break;
    }

    case 2: {
      setState(448);
      expr_block();
      break;
    }

    case 3: {
      setState(449);
      expr_parenthesis();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binary_operatorContext ------------------------------------------------------------------

FilParser::Binary_operatorContext::Binary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Binary_operatorContext::PLUS() {
  return getToken(FilParser::PLUS, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::MINUS() {
  return getToken(FilParser::MINUS, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::DIVIDE() {
  return getToken(FilParser::DIVIDE, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::TIMES() {
  return getToken(FilParser::TIMES, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::MOD() {
  return getToken(FilParser::MOD, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::FLEFT() {
  return getToken(FilParser::FLEFT, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::FRIGHT() {
  return getToken(FilParser::FRIGHT, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::AND() {
  return getToken(FilParser::AND, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::OR() {
  return getToken(FilParser::OR, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::LE() {
  return getToken(FilParser::LE, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::GE() {
  return getToken(FilParser::GE, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::EQEQ() {
  return getToken(FilParser::EQEQ, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::LEQ() {
  return getToken(FilParser::LEQ, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::GEQ() {
  return getToken(FilParser::GEQ, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::NEQ() {
  return getToken(FilParser::NEQ, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::BAND() {
  return getToken(FilParser::BAND, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::BOR() {
  return getToken(FilParser::BOR, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::BXOR() {
  return getToken(FilParser::BXOR, 0);
}


size_t FilParser::Binary_operatorContext::getRuleIndex() const {
  return FilParser::RuleBinary_operator;
}


std::any FilParser::Binary_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitBinary_operator(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Binary_operatorContext* FilParser::binary_operator() {
  Binary_operatorContext *_localctx = _tracker.createInstance<Binary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 92, FilParser::RuleBinary_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(452);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 540430855772831744) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_calculContext ------------------------------------------------------------------

FilParser::Unary_calculContext::Unary_calculContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::Unary_operatorContext* FilParser::Unary_calculContext::unary_operator() {
  return getRuleContext<FilParser::Unary_operatorContext>(0);
}

FilParser::ExprContext* FilParser::Unary_calculContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
}


size_t FilParser::Unary_calculContext::getRuleIndex() const {
  return FilParser::RuleUnary_calcul;
}


std::any FilParser::Unary_calculContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitUnary_calcul(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Unary_calculContext* FilParser::unary_calcul() {
  Unary_calculContext *_localctx = _tracker.createInstance<Unary_calculContext>(_ctx, getState());
  enterRule(_localctx, 94, FilParser::RuleUnary_calcul);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(454);
    unary_operator();
    setState(455);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_operatorContext ------------------------------------------------------------------

FilParser::Unary_operatorContext::Unary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Unary_operatorContext::PLUS() {
  return getToken(FilParser::PLUS, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::MINUS() {
  return getToken(FilParser::MINUS, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::DIVIDE() {
  return getToken(FilParser::DIVIDE, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::TIMES() {
  return getToken(FilParser::TIMES, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::MOD() {
  return getToken(FilParser::MOD, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::NOT() {
  return getToken(FilParser::NOT, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::BAND() {
  return getToken(FilParser::BAND, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::BXOR() {
  return getToken(FilParser::BXOR, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::BOR() {
  return getToken(FilParser::BOR, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::LBRAK() {
  return getToken(FilParser::LBRAK, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::INT() {
  return getToken(FilParser::INT, 0);
}

tree::TerminalNode* FilParser::Unary_operatorContext::RBRAK() {
  return getToken(FilParser::RBRAK, 0);
}


size_t FilParser::Unary_operatorContext::getRuleIndex() const {
  return FilParser::RuleUnary_operator;
}


std::any FilParser::Unary_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitUnary_operator(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Unary_operatorContext* FilParser::unary_operator() {
  Unary_operatorContext *_localctx = _tracker.createInstance<Unary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 96, FilParser::RuleUnary_operator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(469);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FilParser::PLUS: {
        enterOuterAlt(_localctx, 1);
        setState(457);
        match(FilParser::PLUS);
        break;
      }

      case FilParser::MINUS: {
        enterOuterAlt(_localctx, 2);
        setState(458);
        match(FilParser::MINUS);
        break;
      }

      case FilParser::DIVIDE: {
        enterOuterAlt(_localctx, 3);
        setState(459);
        match(FilParser::DIVIDE);
        break;
      }

      case FilParser::TIMES: {
        enterOuterAlt(_localctx, 4);
        setState(460);
        match(FilParser::TIMES);
        break;
      }

      case FilParser::MOD: {
        enterOuterAlt(_localctx, 5);
        setState(461);
        match(FilParser::MOD);
        break;
      }

      case FilParser::NOT: {
        enterOuterAlt(_localctx, 6);
        setState(462);
        match(FilParser::NOT);
        break;
      }

      case FilParser::BAND: {
        enterOuterAlt(_localctx, 7);
        setState(463);
        match(FilParser::BAND);
        break;
      }

      case FilParser::BXOR: {
        enterOuterAlt(_localctx, 8);
        setState(464);
        match(FilParser::BXOR);
        break;
      }

      case FilParser::BOR: {
        enterOuterAlt(_localctx, 9);
        setState(465);
        match(FilParser::BOR);
        break;
      }

      case FilParser::LBRAK: {
        enterOuterAlt(_localctx, 10);
        setState(466);
        match(FilParser::LBRAK);
        setState(467);
        match(FilParser::INT);
        setState(468);
        match(FilParser::RBRAK);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignationContext ------------------------------------------------------------------

FilParser::AssignationContext::AssignationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FilParser::Assignation_operatorContext* FilParser::AssignationContext::assignation_operator() {
  return getRuleContext<FilParser::Assignation_operatorContext>(0);
}

FilParser::ExprContext* FilParser::AssignationContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
}


size_t FilParser::AssignationContext::getRuleIndex() const {
  return FilParser::RuleAssignation;
}


std::any FilParser::AssignationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitAssignation(this);
  else
    return visitor->visitChildren(this);
}

FilParser::AssignationContext* FilParser::assignation() {
  AssignationContext *_localctx = _tracker.createInstance<AssignationContext>(_ctx, getState());
  enterRule(_localctx, 98, FilParser::RuleAssignation);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(471);
    assignation_operator();
    setState(472);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assignation_operatorContext ------------------------------------------------------------------

FilParser::Assignation_operatorContext::Assignation_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Assignation_operatorContext::EQ() {
  return getToken(FilParser::EQ, 0);
}

FilParser::Unary_operatorContext* FilParser::Assignation_operatorContext::unary_operator() {
  return getRuleContext<FilParser::Unary_operatorContext>(0);
}


size_t FilParser::Assignation_operatorContext::getRuleIndex() const {
  return FilParser::RuleAssignation_operator;
}


std::any FilParser::Assignation_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitAssignation_operator(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Assignation_operatorContext* FilParser::assignation_operator() {
  Assignation_operatorContext *_localctx = _tracker.createInstance<Assignation_operatorContext>(_ctx, getState());
  enterRule(_localctx, 100, FilParser::RuleAssignation_operator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(475);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 540466057324789760) != 0) {
      setState(474);
      unary_operator();
    }
    setState(477);
    match(FilParser::EQ);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CastContext ------------------------------------------------------------------

FilParser::CastContext::CastContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::CastContext::LPAREN() {
  return getToken(FilParser::LPAREN, 0);
}

FilParser::TypeContext* FilParser::CastContext::type() {
  return getRuleContext<FilParser::TypeContext>(0);
}

tree::TerminalNode* FilParser::CastContext::RPAREN() {
  return getToken(FilParser::RPAREN, 0);
}

FilParser::ExprContext* FilParser::CastContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
}


size_t FilParser::CastContext::getRuleIndex() const {
  return FilParser::RuleCast;
}


std::any FilParser::CastContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitCast(this);
  else
    return visitor->visitChildren(this);
}

FilParser::CastContext* FilParser::cast() {
  CastContext *_localctx = _tracker.createInstance<CastContext>(_ctx, getState());
  enterRule(_localctx, 102, FilParser::RuleCast);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(479);
    match(FilParser::LPAREN);
    setState(480);
    type();
    setState(481);
    match(FilParser::RPAREN);
    setState(482);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_callContext ------------------------------------------------------------------

FilParser::Function_callContext::Function_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Function_callContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

FilParser::Function_call_paramsContext* FilParser::Function_callContext::function_call_params() {
  return getRuleContext<FilParser::Function_call_paramsContext>(0);
}


size_t FilParser::Function_callContext::getRuleIndex() const {
  return FilParser::RuleFunction_call;
}


std::any FilParser::Function_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFunction_call(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Function_callContext* FilParser::function_call() {
  Function_callContext *_localctx = _tracker.createInstance<Function_callContext>(_ctx, getState());
  enterRule(_localctx, 104, FilParser::RuleFunction_call);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(484);
    match(FilParser::IDENTIFIER);
    setState(485);
    function_call_params();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_call_paramsContext ------------------------------------------------------------------

FilParser::Function_call_paramsContext::Function_call_paramsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Function_call_paramsContext::LPAREN() {
  return getToken(FilParser::LPAREN, 0);
}

tree::TerminalNode* FilParser::Function_call_paramsContext::RPAREN() {
  return getToken(FilParser::RPAREN, 0);
}

FilParser::Function_call_param_listContext* FilParser::Function_call_paramsContext::function_call_param_list() {
  return getRuleContext<FilParser::Function_call_param_listContext>(0);
}


size_t FilParser::Function_call_paramsContext::getRuleIndex() const {
  return FilParser::RuleFunction_call_params;
}


std::any FilParser::Function_call_paramsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFunction_call_params(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Function_call_paramsContext* FilParser::function_call_params() {
  Function_call_paramsContext *_localctx = _tracker.createInstance<Function_call_paramsContext>(_ctx, getState());
  enterRule(_localctx, 106, FilParser::RuleFunction_call_params);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(487);
    match(FilParser::LPAREN);
    setState(489);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 9187377346430984408) != 0) {
      setState(488);
      function_call_param_list();
    }
    setState(491);
    match(FilParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_call_param_listContext ------------------------------------------------------------------

FilParser::Function_call_param_listContext::Function_call_param_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<FilParser::ExprContext *> FilParser::Function_call_param_listContext::expr() {
  return getRuleContexts<FilParser::ExprContext>();
}

FilParser::ExprContext* FilParser::Function_call_param_listContext::expr(size_t i) {
  return getRuleContext<FilParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> FilParser::Function_call_param_listContext::COMMA() {
  return getTokens(FilParser::COMMA);
}

tree::TerminalNode* FilParser::Function_call_param_listContext::COMMA(size_t i) {
  return getToken(FilParser::COMMA, i);
}


size_t FilParser::Function_call_param_listContext::getRuleIndex() const {
  return FilParser::RuleFunction_call_param_list;
}


std::any FilParser::Function_call_param_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFunction_call_param_list(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Function_call_param_listContext* FilParser::function_call_param_list() {
  Function_call_param_listContext *_localctx = _tracker.createInstance<Function_call_param_listContext>(_ctx, getState());
  enterRule(_localctx, 108, FilParser::RuleFunction_call_param_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(493);
    expr(0);
    setState(498);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FilParser::COMMA) {
      setState(494);
      match(FilParser::COMMA);
      setState(495);
      expr(0);
      setState(500);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_declContext ------------------------------------------------------------------

FilParser::Variable_declContext::Variable_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Variable_declContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

tree::TerminalNode* FilParser::Variable_declContext::VAL() {
  return getToken(FilParser::VAL, 0);
}

tree::TerminalNode* FilParser::Variable_declContext::VAR() {
  return getToken(FilParser::VAR, 0);
}

tree::TerminalNode* FilParser::Variable_declContext::COLON() {
  return getToken(FilParser::COLON, 0);
}

FilParser::TypeContext* FilParser::Variable_declContext::type() {
  return getRuleContext<FilParser::TypeContext>(0);
}

FilParser::AssignationContext* FilParser::Variable_declContext::assignation() {
  return getRuleContext<FilParser::AssignationContext>(0);
}


size_t FilParser::Variable_declContext::getRuleIndex() const {
  return FilParser::RuleVariable_decl;
}


std::any FilParser::Variable_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitVariable_decl(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Variable_declContext* FilParser::variable_decl() {
  Variable_declContext *_localctx = _tracker.createInstance<Variable_declContext>(_ctx, getState());
  enterRule(_localctx, 110, FilParser::RuleVariable_decl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(501);
    _la = _input->LA(1);
    if (!(_la == FilParser::VAL

    || _la == FilParser::VAR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(502);
    match(FilParser::IDENTIFIER);
    setState(510);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      setState(503);
      match(FilParser::COLON);
      setState(504);
      type();
      break;
    }

    case 2: {
      setState(507);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FilParser::COLON) {
        setState(505);
        match(FilParser::COLON);
        setState(506);
        type();
      }
      setState(509);
      assignation();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

FilParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::TypeContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

tree::TerminalNode* FilParser::TypeContext::TIMES() {
  return getToken(FilParser::TIMES, 0);
}

tree::TerminalNode* FilParser::TypeContext::LBRAK() {
  return getToken(FilParser::LBRAK, 0);
}

tree::TerminalNode* FilParser::TypeContext::RBRAK() {
  return getToken(FilParser::RBRAK, 0);
}

tree::TerminalNode* FilParser::TypeContext::INT() {
  return getToken(FilParser::INT, 0);
}


size_t FilParser::TypeContext::getRuleIndex() const {
  return FilParser::RuleType;
}


std::any FilParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

FilParser::TypeContext* FilParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 112, FilParser::RuleType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(512);
    match(FilParser::IDENTIFIER);
    setState(519);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      setState(513);
      match(FilParser::TIMES);
      break;
    }

    case 2: {
      setState(514);
      match(FilParser::LBRAK);
      setState(516);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FilParser::INT) {
        setState(515);
        match(FilParser::INT);
      }
      setState(518);
      match(FilParser::RBRAK);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LitteralContext ------------------------------------------------------------------

FilParser::LitteralContext::LitteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::LitteralContext::INT() {
  return getToken(FilParser::INT, 0);
}

tree::TerminalNode* FilParser::LitteralContext::FLOAT() {
  return getToken(FilParser::FLOAT, 0);
}

tree::TerminalNode* FilParser::LitteralContext::STRING() {
  return getToken(FilParser::STRING, 0);
}

tree::TerminalNode* FilParser::LitteralContext::CHAR() {
  return getToken(FilParser::CHAR, 0);
}

tree::TerminalNode* FilParser::LitteralContext::TRUE() {
  return getToken(FilParser::TRUE, 0);
}

tree::TerminalNode* FilParser::LitteralContext::FALSE() {
  return getToken(FilParser::FALSE, 0);
}

tree::TerminalNode* FilParser::LitteralContext::NULL_() {
  return getToken(FilParser::NULL_, 0);
}


size_t FilParser::LitteralContext::getRuleIndex() const {
  return FilParser::RuleLitteral;
}


std::any FilParser::LitteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitLitteral(this);
  else
    return visitor->visitChildren(this);
}

FilParser::LitteralContext* FilParser::litteral() {
  LitteralContext *_localctx = _tracker.createInstance<LitteralContext>(_ctx, getState());
  enterRule(_localctx, 114, FilParser::RuleLitteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(521);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8646911284668792832) != 0)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TempContext ------------------------------------------------------------------

FilParser::TempContext::TempContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::TempContext::DOT() {
  return getToken(FilParser::DOT, 0);
}


size_t FilParser::TempContext::getRuleIndex() const {
  return FilParser::RuleTemp;
}


std::any FilParser::TempContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitTemp(this);
  else
    return visitor->visitChildren(this);
}

FilParser::TempContext* FilParser::temp() {
  TempContext *_localctx = _tracker.createInstance<TempContext>(_ctx, getState());
  enterRule(_localctx, 116, FilParser::RuleTemp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(523);
    match(FilParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr_parenthesisContext ------------------------------------------------------------------

FilParser::Expr_parenthesisContext::Expr_parenthesisContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Expr_parenthesisContext::LPAREN() {
  return getToken(FilParser::LPAREN, 0);
}

FilParser::ExprContext* FilParser::Expr_parenthesisContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
}

tree::TerminalNode* FilParser::Expr_parenthesisContext::RPAREN() {
  return getToken(FilParser::RPAREN, 0);
}


size_t FilParser::Expr_parenthesisContext::getRuleIndex() const {
  return FilParser::RuleExpr_parenthesis;
}


std::any FilParser::Expr_parenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitExpr_parenthesis(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Expr_parenthesisContext* FilParser::expr_parenthesis() {
  Expr_parenthesisContext *_localctx = _tracker.createInstance<Expr_parenthesisContext>(_ctx, getState());
  enterRule(_localctx, 118, FilParser::RuleExpr_parenthesis);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(525);
    match(FilParser::LPAREN);
    setState(526);
    expr(0);
    setState(527);
    match(FilParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr_blockContext ------------------------------------------------------------------

FilParser::Expr_blockContext::Expr_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Expr_blockContext::LBRAK() {
  return getToken(FilParser::LBRAK, 0);
}

tree::TerminalNode* FilParser::Expr_blockContext::RBRAK() {
  return getToken(FilParser::RBRAK, 0);
}

std::vector<FilParser::ExprContext *> FilParser::Expr_blockContext::expr() {
  return getRuleContexts<FilParser::ExprContext>();
}

FilParser::ExprContext* FilParser::Expr_blockContext::expr(size_t i) {
  return getRuleContext<FilParser::ExprContext>(i);
}


size_t FilParser::Expr_blockContext::getRuleIndex() const {
  return FilParser::RuleExpr_block;
}


std::any FilParser::Expr_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitExpr_block(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Expr_blockContext* FilParser::expr_block() {
  Expr_blockContext *_localctx = _tracker.createInstance<Expr_blockContext>(_ctx, getState());
  enterRule(_localctx, 120, FilParser::RuleExpr_block);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(529);
    match(FilParser::LBRAK);
    setState(533);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 9187377346430984408) != 0) {
      setState(530);
      expr(0);
      setState(535);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(536);
    match(FilParser::RBRAK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool FilParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 3: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool FilParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 11);
    case 1: return precpred(_ctx, 9);
    case 2: return precpred(_ctx, 8);
    case 3: return precpred(_ctx, 10);

  default:
    break;
  }
  return true;
}

void FilParser::initialize() {
  ::antlr4::internal::call_once(filparserParserOnceFlag, filparserParserInitialize);
}
