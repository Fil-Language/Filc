
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
      "program", "expr", "function", "function_name", "fun_params", "fun_param_list", 
      "fun_param", "fun_body", "function_decl", "lambda", "interface", "interface_body", 
      "class_", "class_modifier", "class_identifier", "class_generic", "class_params", 
      "class_param_list", "class_param", "class_extends", "class_extend_list", 
      "class_extend", "class_body", "class_function", "class_variable", 
      "class_atr_modifier", "class_constructor", "enum_", "enum_body", "condition", 
      "if_", "if_condition", "if_body", "else_if", "else_", "switch_", "switch_condition", 
      "switch_body", "switch_case", "loop", "fori", "fori_condition", "foriter", 
      "foriter_condition", "while_", "exception", "catch_body", "binary_operator", 
      "unary_op_pre", "unary_op_post", "unary_operator", "assignation", 
      "assignation_operator", "cast", "function_call", "function_call_params", 
      "function_call_param_list", "variable_decl", "array_assign", "type", 
      "litteral", "expr_parenthesis", "expr_block"
    },
    std::vector<std::string>{
      "", "'export'", "'fun'", "'interface'", "'class'", "'abstract'", "'override'", 
      "'open'", "'private'", "'public'", "'internal'", "'protected'", "'constructor'", 
      "'enum'", "'if'", "'else'", "'switch'", "'default'", "'for'", "'val'", 
      "'var'", "'while'", "'try'", "'catch'", "'true'", "'false'", "'null'", 
      "'new'", "'operator'", "", "'.'", "'->'", "'{'", "'}'", "'('", "')'", 
      "'['", "']'", "':'", "','", "';'", "'='", "'+'", "'-'", "'/'", "'*'", 
      "'%'", "'<<'", "'>>'", "'&&'", "'||'", "'<'", "'>'", "'=='", "'<='", 
      "'>='", "'!='", "'!'", "'&'", "'|'", "'^'"
    },
    std::vector<std::string>{
      "", "EXPORT", "FUN", "INTERFACE", "CLASS", "ABSTRACT", "OVERRIDE", 
      "OPEN", "PRIVATE", "PUBLIC", "INTERNAL", "PROTECTED", "CONSTRUCTOR", 
      "ENUM", "IF", "ELSE", "SWITCH", "DEFAULT", "FOR", "VAL", "VAR", "WHILE", 
      "TRY", "CATCH", "TRUE", "FALSE", "NULL_", "NEW", "OPERATOR", "IDENTIFIER", 
      "DOT", "ARROW", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "LBRAK", "RBRAK", 
      "COLON", "COMMA", "SEMICOLON", "EQ", "PLUS", "MINUS", "DIVIDE", "TIMES", 
      "MOD", "FLEFT", "FRIGHT", "AND", "OR", "LT", "GT", "EQEQ", "LEQ", 
      "GEQ", "NEQ", "NOT", "BAND", "BOR", "BXOR", "INT", "FLOAT", "STRING", 
      "FSTRING", "CHAR", "COMMENT", "COMMENT_BLOCK", "SEPARATOR", "MODULE", 
      "IMPORT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,70,599,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,7,
  	56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,1,0,1,
  	0,5,0,129,8,0,10,0,12,0,132,9,0,1,0,3,0,135,8,0,1,0,5,0,138,8,0,10,0,
  	12,0,141,9,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,168,8,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,184,8,1,10,1,12,1,187,9,
  	1,1,2,1,2,1,2,1,2,1,2,3,2,194,8,2,1,2,1,2,1,3,1,3,1,3,3,3,201,8,3,1,4,
  	1,4,3,4,205,8,4,1,4,1,4,1,5,1,5,1,5,5,5,212,8,5,10,5,12,5,215,9,5,1,6,
  	1,6,1,6,1,6,1,7,1,7,1,7,3,7,224,8,7,1,8,1,8,1,8,1,8,1,8,3,8,231,8,8,1,
  	9,1,9,1,9,1,9,3,9,237,8,9,1,10,1,10,1,10,3,10,242,8,10,1,10,3,10,245,
  	8,10,1,11,1,11,5,11,249,8,11,10,11,12,11,252,9,11,1,11,1,11,1,12,3,12,
  	257,8,12,1,12,1,12,1,12,3,12,262,8,12,1,12,3,12,265,8,12,1,12,3,12,268,
  	8,12,1,13,1,13,1,14,1,14,3,14,274,8,14,1,14,3,14,277,8,14,1,15,1,15,1,
  	15,1,15,5,15,283,8,15,10,15,12,15,286,9,15,1,15,1,15,1,16,1,16,3,16,292,
  	8,16,1,16,1,16,1,17,1,17,1,17,5,17,299,8,17,10,17,12,17,302,9,17,1,18,
  	1,18,1,18,1,18,1,18,1,18,3,18,310,8,18,3,18,312,8,18,1,19,1,19,1,19,1,
  	20,1,20,1,20,5,20,320,8,20,10,20,12,20,323,9,20,1,21,1,21,3,21,327,8,
  	21,1,22,1,22,3,22,331,8,22,1,22,1,22,5,22,335,8,22,10,22,12,22,338,9,
  	22,1,22,1,22,1,23,3,23,343,8,23,1,23,3,23,346,8,23,1,23,1,23,3,23,350,
  	8,23,1,24,1,24,1,24,1,25,1,25,1,26,1,26,1,26,1,27,1,27,1,27,3,27,363,
  	8,27,1,28,1,28,1,28,1,28,5,28,369,8,28,10,28,12,28,372,9,28,3,28,374,
  	8,28,1,28,1,28,1,29,1,29,3,29,380,8,29,1,30,1,30,1,30,1,30,5,30,386,8,
  	30,10,30,12,30,389,9,30,1,30,3,30,392,8,30,1,31,1,31,1,32,1,32,1,32,3,
  	32,399,8,32,1,33,1,33,1,33,1,33,1,33,1,34,1,34,1,34,1,35,1,35,1,35,1,
  	35,1,36,1,36,1,37,1,37,5,37,417,8,37,10,37,12,37,420,9,37,1,37,1,37,1,
  	38,1,38,3,38,426,8,38,1,38,1,38,1,38,1,38,3,38,432,8,38,1,39,1,39,1,39,
  	3,39,437,8,39,1,40,1,40,1,40,1,40,3,40,443,8,40,1,41,1,41,3,41,447,8,
  	41,1,41,1,41,3,41,451,8,41,1,41,1,41,3,41,455,8,41,1,41,1,41,1,42,1,42,
  	1,42,1,42,3,42,463,8,42,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,44,1,44,
  	1,44,1,44,1,45,1,45,1,45,1,45,3,45,480,8,45,1,45,4,45,483,8,45,11,45,
  	12,45,484,1,46,1,46,1,46,1,46,1,46,1,46,1,46,3,46,494,8,46,1,47,1,47,
  	1,48,1,48,1,48,1,48,1,48,1,48,3,48,504,8,48,1,49,1,49,1,49,1,49,1,49,
  	1,49,1,49,1,49,3,49,514,8,49,1,50,1,50,1,51,1,51,1,51,1,52,3,52,522,8,
  	52,1,52,1,52,1,53,1,53,1,53,1,53,1,53,1,54,1,54,1,54,1,55,1,55,3,55,536,
  	8,55,1,55,1,55,1,56,1,56,1,56,5,56,543,8,56,10,56,12,56,546,9,56,1,57,
  	1,57,1,57,1,57,3,57,552,8,57,1,57,1,57,1,57,3,57,557,8,57,1,58,1,58,1,
  	58,1,58,5,58,563,8,58,10,58,12,58,566,9,58,1,58,1,58,1,59,1,59,1,59,1,
  	59,3,59,574,8,59,1,59,3,59,577,8,59,1,60,1,60,1,61,1,61,5,61,583,8,61,
  	10,61,12,61,586,9,61,1,61,1,61,1,62,1,62,5,62,592,8,62,10,62,12,62,595,
  	9,62,1,62,1,62,1,62,0,1,2,63,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,
  	30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,
  	76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,
  	118,120,122,124,0,7,2,0,5,5,7,7,1,0,5,6,1,0,8,11,1,0,19,20,2,0,42,56,
  	58,60,2,0,42,46,57,60,2,0,24,26,61,65,631,0,126,1,0,0,0,2,167,1,0,0,0,
  	4,188,1,0,0,0,6,200,1,0,0,0,8,202,1,0,0,0,10,208,1,0,0,0,12,216,1,0,0,
  	0,14,223,1,0,0,0,16,225,1,0,0,0,18,232,1,0,0,0,20,238,1,0,0,0,22,246,
  	1,0,0,0,24,256,1,0,0,0,26,269,1,0,0,0,28,271,1,0,0,0,30,278,1,0,0,0,32,
  	289,1,0,0,0,34,295,1,0,0,0,36,311,1,0,0,0,38,313,1,0,0,0,40,316,1,0,0,
  	0,42,324,1,0,0,0,44,328,1,0,0,0,46,342,1,0,0,0,48,351,1,0,0,0,50,354,
  	1,0,0,0,52,356,1,0,0,0,54,359,1,0,0,0,56,364,1,0,0,0,58,379,1,0,0,0,60,
  	381,1,0,0,0,62,393,1,0,0,0,64,398,1,0,0,0,66,400,1,0,0,0,68,405,1,0,0,
  	0,70,408,1,0,0,0,72,412,1,0,0,0,74,414,1,0,0,0,76,425,1,0,0,0,78,436,
  	1,0,0,0,80,438,1,0,0,0,82,444,1,0,0,0,84,458,1,0,0,0,86,464,1,0,0,0,88,
  	471,1,0,0,0,90,475,1,0,0,0,92,486,1,0,0,0,94,495,1,0,0,0,96,503,1,0,0,
  	0,98,513,1,0,0,0,100,515,1,0,0,0,102,517,1,0,0,0,104,521,1,0,0,0,106,
  	525,1,0,0,0,108,530,1,0,0,0,110,533,1,0,0,0,112,539,1,0,0,0,114,547,1,
  	0,0,0,116,558,1,0,0,0,118,569,1,0,0,0,120,578,1,0,0,0,122,580,1,0,0,0,
  	124,589,1,0,0,0,126,130,5,69,0,0,127,129,5,70,0,0,128,127,1,0,0,0,129,
  	132,1,0,0,0,130,128,1,0,0,0,130,131,1,0,0,0,131,139,1,0,0,0,132,130,1,
  	0,0,0,133,135,5,1,0,0,134,133,1,0,0,0,134,135,1,0,0,0,135,136,1,0,0,0,
  	136,138,3,2,1,0,137,134,1,0,0,0,138,141,1,0,0,0,139,137,1,0,0,0,139,140,
  	1,0,0,0,140,1,1,0,0,0,141,139,1,0,0,0,142,143,6,1,-1,0,143,168,3,4,2,
  	0,144,168,3,18,9,0,145,168,3,20,10,0,146,168,3,24,12,0,147,168,3,54,27,
  	0,148,168,3,114,57,0,149,168,3,58,29,0,150,168,3,78,39,0,151,168,3,108,
  	54,0,152,168,3,90,45,0,153,154,3,96,48,0,154,155,3,2,1,12,155,168,1,0,
  	0,0,156,168,3,106,53,0,157,168,5,29,0,0,158,168,3,28,14,0,159,168,3,120,
  	60,0,160,161,5,27,0,0,161,162,3,28,14,0,162,163,3,110,55,0,163,168,1,
  	0,0,0,164,168,3,122,61,0,165,168,3,124,62,0,166,168,3,116,58,0,167,142,
  	1,0,0,0,167,144,1,0,0,0,167,145,1,0,0,0,167,146,1,0,0,0,167,147,1,0,0,
  	0,167,148,1,0,0,0,167,149,1,0,0,0,167,150,1,0,0,0,167,151,1,0,0,0,167,
  	152,1,0,0,0,167,153,1,0,0,0,167,156,1,0,0,0,167,157,1,0,0,0,167,158,1,
  	0,0,0,167,159,1,0,0,0,167,160,1,0,0,0,167,164,1,0,0,0,167,165,1,0,0,0,
  	167,166,1,0,0,0,168,185,1,0,0,0,169,170,10,14,0,0,170,171,5,30,0,0,171,
  	184,3,2,1,15,172,173,10,13,0,0,173,174,5,31,0,0,174,184,3,2,1,14,175,
  	176,10,10,0,0,176,177,3,94,47,0,177,178,3,2,1,11,178,184,1,0,0,0,179,
  	180,10,11,0,0,180,184,3,98,49,0,181,182,10,9,0,0,182,184,3,102,51,0,183,
  	169,1,0,0,0,183,172,1,0,0,0,183,175,1,0,0,0,183,179,1,0,0,0,183,181,1,
  	0,0,0,184,187,1,0,0,0,185,183,1,0,0,0,185,186,1,0,0,0,186,3,1,0,0,0,187,
  	185,1,0,0,0,188,189,5,2,0,0,189,190,3,6,3,0,190,193,3,8,4,0,191,192,5,
  	38,0,0,192,194,3,118,59,0,193,191,1,0,0,0,193,194,1,0,0,0,194,195,1,0,
  	0,0,195,196,3,14,7,0,196,5,1,0,0,0,197,201,5,29,0,0,198,199,5,28,0,0,
  	199,201,3,94,47,0,200,197,1,0,0,0,200,198,1,0,0,0,201,7,1,0,0,0,202,204,
  	5,34,0,0,203,205,3,10,5,0,204,203,1,0,0,0,204,205,1,0,0,0,205,206,1,0,
  	0,0,206,207,5,35,0,0,207,9,1,0,0,0,208,213,3,12,6,0,209,210,5,39,0,0,
  	210,212,3,12,6,0,211,209,1,0,0,0,212,215,1,0,0,0,213,211,1,0,0,0,213,
  	214,1,0,0,0,214,11,1,0,0,0,215,213,1,0,0,0,216,217,5,29,0,0,217,218,5,
  	38,0,0,218,219,3,118,59,0,219,13,1,0,0,0,220,224,3,102,51,0,221,224,3,
  	122,61,0,222,224,3,124,62,0,223,220,1,0,0,0,223,221,1,0,0,0,223,222,1,
  	0,0,0,224,15,1,0,0,0,225,226,5,2,0,0,226,227,3,6,3,0,227,230,3,8,4,0,
  	228,229,5,38,0,0,229,231,3,118,59,0,230,228,1,0,0,0,230,231,1,0,0,0,231,
  	17,1,0,0,0,232,233,3,8,4,0,233,236,5,31,0,0,234,237,3,124,62,0,235,237,
  	3,122,61,0,236,234,1,0,0,0,236,235,1,0,0,0,237,19,1,0,0,0,238,239,5,3,
  	0,0,239,241,5,29,0,0,240,242,3,32,16,0,241,240,1,0,0,0,241,242,1,0,0,
  	0,242,244,1,0,0,0,243,245,3,22,11,0,244,243,1,0,0,0,244,245,1,0,0,0,245,
  	21,1,0,0,0,246,250,5,32,0,0,247,249,3,16,8,0,248,247,1,0,0,0,249,252,
  	1,0,0,0,250,248,1,0,0,0,250,251,1,0,0,0,251,253,1,0,0,0,252,250,1,0,0,
  	0,253,254,5,33,0,0,254,23,1,0,0,0,255,257,3,26,13,0,256,255,1,0,0,0,256,
  	257,1,0,0,0,257,258,1,0,0,0,258,259,5,4,0,0,259,261,3,28,14,0,260,262,
  	3,32,16,0,261,260,1,0,0,0,261,262,1,0,0,0,262,264,1,0,0,0,263,265,3,38,
  	19,0,264,263,1,0,0,0,264,265,1,0,0,0,265,267,1,0,0,0,266,268,3,44,22,
  	0,267,266,1,0,0,0,267,268,1,0,0,0,268,25,1,0,0,0,269,270,7,0,0,0,270,
  	27,1,0,0,0,271,273,5,29,0,0,272,274,5,45,0,0,273,272,1,0,0,0,273,274,
  	1,0,0,0,274,276,1,0,0,0,275,277,3,30,15,0,276,275,1,0,0,0,276,277,1,0,
  	0,0,277,29,1,0,0,0,278,279,5,51,0,0,279,284,5,29,0,0,280,281,5,39,0,0,
  	281,283,5,29,0,0,282,280,1,0,0,0,283,286,1,0,0,0,284,282,1,0,0,0,284,
  	285,1,0,0,0,285,287,1,0,0,0,286,284,1,0,0,0,287,288,5,52,0,0,288,31,1,
  	0,0,0,289,291,5,34,0,0,290,292,3,34,17,0,291,290,1,0,0,0,291,292,1,0,
  	0,0,292,293,1,0,0,0,293,294,5,35,0,0,294,33,1,0,0,0,295,300,3,36,18,0,
  	296,297,5,39,0,0,297,299,3,36,18,0,298,296,1,0,0,0,299,302,1,0,0,0,300,
  	298,1,0,0,0,300,301,1,0,0,0,301,35,1,0,0,0,302,300,1,0,0,0,303,312,3,
  	114,57,0,304,305,5,29,0,0,305,306,5,38,0,0,306,309,3,118,59,0,307,308,
  	5,41,0,0,308,310,3,120,60,0,309,307,1,0,0,0,309,310,1,0,0,0,310,312,1,
  	0,0,0,311,303,1,0,0,0,311,304,1,0,0,0,312,37,1,0,0,0,313,314,5,38,0,0,
  	314,315,3,40,20,0,315,39,1,0,0,0,316,321,3,42,21,0,317,318,5,39,0,0,318,
  	320,3,42,21,0,319,317,1,0,0,0,320,323,1,0,0,0,321,319,1,0,0,0,321,322,
  	1,0,0,0,322,41,1,0,0,0,323,321,1,0,0,0,324,326,3,28,14,0,325,327,3,110,
  	55,0,326,325,1,0,0,0,326,327,1,0,0,0,327,43,1,0,0,0,328,330,5,32,0,0,
  	329,331,3,52,26,0,330,329,1,0,0,0,330,331,1,0,0,0,331,336,1,0,0,0,332,
  	335,3,48,24,0,333,335,3,46,23,0,334,332,1,0,0,0,334,333,1,0,0,0,335,338,
  	1,0,0,0,336,334,1,0,0,0,336,337,1,0,0,0,337,339,1,0,0,0,338,336,1,0,0,
  	0,339,340,5,33,0,0,340,45,1,0,0,0,341,343,7,1,0,0,342,341,1,0,0,0,342,
  	343,1,0,0,0,343,345,1,0,0,0,344,346,3,50,25,0,345,344,1,0,0,0,345,346,
  	1,0,0,0,346,349,1,0,0,0,347,350,3,4,2,0,348,350,3,16,8,0,349,347,1,0,
  	0,0,349,348,1,0,0,0,350,47,1,0,0,0,351,352,3,50,25,0,352,353,3,114,57,
  	0,353,49,1,0,0,0,354,355,7,2,0,0,355,51,1,0,0,0,356,357,5,12,0,0,357,
  	358,3,124,62,0,358,53,1,0,0,0,359,360,5,13,0,0,360,362,5,29,0,0,361,363,
  	3,56,28,0,362,361,1,0,0,0,362,363,1,0,0,0,363,55,1,0,0,0,364,373,5,32,
  	0,0,365,370,5,29,0,0,366,367,5,39,0,0,367,369,5,29,0,0,368,366,1,0,0,
  	0,369,372,1,0,0,0,370,368,1,0,0,0,370,371,1,0,0,0,371,374,1,0,0,0,372,
  	370,1,0,0,0,373,365,1,0,0,0,373,374,1,0,0,0,374,375,1,0,0,0,375,376,5,
  	33,0,0,376,57,1,0,0,0,377,380,3,60,30,0,378,380,3,70,35,0,379,377,1,0,
  	0,0,379,378,1,0,0,0,380,59,1,0,0,0,381,382,5,14,0,0,382,383,3,62,31,0,
  	383,387,3,64,32,0,384,386,3,66,33,0,385,384,1,0,0,0,386,389,1,0,0,0,387,
  	385,1,0,0,0,387,388,1,0,0,0,388,391,1,0,0,0,389,387,1,0,0,0,390,392,3,
  	68,34,0,391,390,1,0,0,0,391,392,1,0,0,0,392,61,1,0,0,0,393,394,3,122,
  	61,0,394,63,1,0,0,0,395,399,3,124,62,0,396,399,3,122,61,0,397,399,3,2,
  	1,0,398,395,1,0,0,0,398,396,1,0,0,0,398,397,1,0,0,0,399,65,1,0,0,0,400,
  	401,5,15,0,0,401,402,5,14,0,0,402,403,3,62,31,0,403,404,3,64,32,0,404,
  	67,1,0,0,0,405,406,5,15,0,0,406,407,3,64,32,0,407,69,1,0,0,0,408,409,
  	5,16,0,0,409,410,3,72,36,0,410,411,3,74,37,0,411,71,1,0,0,0,412,413,3,
  	122,61,0,413,73,1,0,0,0,414,418,5,32,0,0,415,417,3,76,38,0,416,415,1,
  	0,0,0,417,420,1,0,0,0,418,416,1,0,0,0,418,419,1,0,0,0,419,421,1,0,0,0,
  	420,418,1,0,0,0,421,422,5,33,0,0,422,75,1,0,0,0,423,426,3,120,60,0,424,
  	426,5,17,0,0,425,423,1,0,0,0,425,424,1,0,0,0,426,427,1,0,0,0,427,431,
  	5,31,0,0,428,432,3,2,1,0,429,432,3,124,62,0,430,432,3,122,61,0,431,428,
  	1,0,0,0,431,429,1,0,0,0,431,430,1,0,0,0,432,77,1,0,0,0,433,437,3,80,40,
  	0,434,437,3,84,42,0,435,437,3,88,44,0,436,433,1,0,0,0,436,434,1,0,0,0,
  	436,435,1,0,0,0,437,79,1,0,0,0,438,439,5,18,0,0,439,442,3,82,41,0,440,
  	443,3,2,1,0,441,443,3,124,62,0,442,440,1,0,0,0,442,441,1,0,0,0,443,81,
  	1,0,0,0,444,446,5,34,0,0,445,447,3,114,57,0,446,445,1,0,0,0,446,447,1,
  	0,0,0,447,448,1,0,0,0,448,450,5,40,0,0,449,451,3,2,1,0,450,449,1,0,0,
  	0,450,451,1,0,0,0,451,452,1,0,0,0,452,454,5,40,0,0,453,455,3,2,1,0,454,
  	453,1,0,0,0,454,455,1,0,0,0,455,456,1,0,0,0,456,457,5,35,0,0,457,83,1,
  	0,0,0,458,459,5,18,0,0,459,462,3,86,43,0,460,463,3,2,1,0,461,463,3,124,
  	62,0,462,460,1,0,0,0,462,461,1,0,0,0,463,85,1,0,0,0,464,465,5,34,0,0,
  	465,466,7,3,0,0,466,467,5,29,0,0,467,468,5,38,0,0,468,469,5,29,0,0,469,
  	470,5,35,0,0,470,87,1,0,0,0,471,472,5,21,0,0,472,473,3,62,31,0,473,474,
  	3,64,32,0,474,89,1,0,0,0,475,479,5,22,0,0,476,480,3,2,1,0,477,480,3,124,
  	62,0,478,480,3,122,61,0,479,476,1,0,0,0,479,477,1,0,0,0,479,478,1,0,0,
  	0,480,482,1,0,0,0,481,483,3,92,46,0,482,481,1,0,0,0,483,484,1,0,0,0,484,
  	482,1,0,0,0,484,485,1,0,0,0,485,91,1,0,0,0,486,487,5,23,0,0,487,488,5,
  	34,0,0,488,489,3,12,6,0,489,493,5,35,0,0,490,494,3,2,1,0,491,494,3,124,
  	62,0,492,494,3,122,61,0,493,490,1,0,0,0,493,491,1,0,0,0,493,492,1,0,0,
  	0,494,93,1,0,0,0,495,496,7,4,0,0,496,95,1,0,0,0,497,498,5,42,0,0,498,
  	504,5,42,0,0,499,500,5,43,0,0,500,504,5,43,0,0,501,504,5,45,0,0,502,504,
  	5,58,0,0,503,497,1,0,0,0,503,499,1,0,0,0,503,501,1,0,0,0,503,502,1,0,
  	0,0,504,97,1,0,0,0,505,506,5,42,0,0,506,514,5,42,0,0,507,508,5,43,0,0,
  	508,514,5,43,0,0,509,510,5,36,0,0,510,511,3,2,1,0,511,512,5,37,0,0,512,
  	514,1,0,0,0,513,505,1,0,0,0,513,507,1,0,0,0,513,509,1,0,0,0,514,99,1,
  	0,0,0,515,516,7,5,0,0,516,101,1,0,0,0,517,518,3,104,52,0,518,519,3,2,
  	1,0,519,103,1,0,0,0,520,522,3,100,50,0,521,520,1,0,0,0,521,522,1,0,0,
  	0,522,523,1,0,0,0,523,524,5,41,0,0,524,105,1,0,0,0,525,526,5,34,0,0,526,
  	527,3,118,59,0,527,528,5,35,0,0,528,529,3,2,1,0,529,107,1,0,0,0,530,531,
  	3,6,3,0,531,532,3,110,55,0,532,109,1,0,0,0,533,535,5,34,0,0,534,536,3,
  	112,56,0,535,534,1,0,0,0,535,536,1,0,0,0,536,537,1,0,0,0,537,538,5,35,
  	0,0,538,111,1,0,0,0,539,544,3,2,1,0,540,541,5,39,0,0,541,543,3,2,1,0,
  	542,540,1,0,0,0,543,546,1,0,0,0,544,542,1,0,0,0,544,545,1,0,0,0,545,113,
  	1,0,0,0,546,544,1,0,0,0,547,548,7,3,0,0,548,556,5,29,0,0,549,550,5,38,
  	0,0,550,552,3,118,59,0,551,549,1,0,0,0,551,552,1,0,0,0,552,553,1,0,0,
  	0,553,557,3,102,51,0,554,555,5,38,0,0,555,557,3,118,59,0,556,551,1,0,
  	0,0,556,554,1,0,0,0,557,115,1,0,0,0,558,559,5,32,0,0,559,564,3,2,1,0,
  	560,561,5,39,0,0,561,563,3,2,1,0,562,560,1,0,0,0,563,566,1,0,0,0,564,
  	562,1,0,0,0,564,565,1,0,0,0,565,567,1,0,0,0,566,564,1,0,0,0,567,568,5,
  	33,0,0,568,117,1,0,0,0,569,576,5,29,0,0,570,577,5,45,0,0,571,573,5,36,
  	0,0,572,574,5,61,0,0,573,572,1,0,0,0,573,574,1,0,0,0,574,575,1,0,0,0,
  	575,577,5,37,0,0,576,570,1,0,0,0,576,571,1,0,0,0,576,577,1,0,0,0,577,
  	119,1,0,0,0,578,579,7,6,0,0,579,121,1,0,0,0,580,584,5,34,0,0,581,583,
  	3,2,1,0,582,581,1,0,0,0,583,586,1,0,0,0,584,582,1,0,0,0,584,585,1,0,0,
  	0,585,587,1,0,0,0,586,584,1,0,0,0,587,588,5,35,0,0,588,123,1,0,0,0,589,
  	593,5,32,0,0,590,592,3,2,1,0,591,590,1,0,0,0,592,595,1,0,0,0,593,591,
  	1,0,0,0,593,594,1,0,0,0,594,596,1,0,0,0,595,593,1,0,0,0,596,597,5,33,
  	0,0,597,125,1,0,0,0,66,130,134,139,167,183,185,193,200,204,213,223,230,
  	236,241,244,250,256,261,264,267,273,276,284,291,300,309,311,321,326,330,
  	334,336,342,345,349,362,370,373,379,387,391,398,418,425,431,436,442,446,
  	450,454,462,479,484,493,503,513,521,535,544,551,556,564,573,576,584,593
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

tree::TerminalNode* FilParser::ProgramContext::MODULE() {
  return getToken(FilParser::MODULE, 0);
}

std::vector<tree::TerminalNode *> FilParser::ProgramContext::IMPORT() {
  return getTokens(FilParser::IMPORT);
}

tree::TerminalNode* FilParser::ProgramContext::IMPORT(size_t i) {
  return getToken(FilParser::IMPORT, i);
}

std::vector<FilParser::ExprContext *> FilParser::ProgramContext::expr() {
  return getRuleContexts<FilParser::ExprContext>();
}

FilParser::ExprContext* FilParser::ProgramContext::expr(size_t i) {
  return getRuleContext<FilParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> FilParser::ProgramContext::EXPORT() {
  return getTokens(FilParser::EXPORT);
}

tree::TerminalNode* FilParser::ProgramContext::EXPORT(size_t i) {
  return getToken(FilParser::EXPORT, i);
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
    setState(126);
    match(FilParser::MODULE);
    setState(130);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FilParser::IMPORT) {
      setState(127);
      match(FilParser::IMPORT);
      setState(132);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(139);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -2017564232010342210) != 0 || _la == FilParser::FSTRING

    || _la == FilParser::CHAR) {
      setState(134);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FilParser::EXPORT) {
        setState(133);
        match(FilParser::EXPORT);
      }
      setState(136);
      expr(0);
      setState(141);
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

FilParser::Variable_declContext* FilParser::ExprContext::variable_decl() {
  return getRuleContext<FilParser::Variable_declContext>(0);
}

FilParser::ConditionContext* FilParser::ExprContext::condition() {
  return getRuleContext<FilParser::ConditionContext>(0);
}

FilParser::LoopContext* FilParser::ExprContext::loop() {
  return getRuleContext<FilParser::LoopContext>(0);
}

FilParser::Function_callContext* FilParser::ExprContext::function_call() {
  return getRuleContext<FilParser::Function_callContext>(0);
}

FilParser::ExceptionContext* FilParser::ExprContext::exception() {
  return getRuleContext<FilParser::ExceptionContext>(0);
}

FilParser::Unary_op_preContext* FilParser::ExprContext::unary_op_pre() {
  return getRuleContext<FilParser::Unary_op_preContext>(0);
}

std::vector<FilParser::ExprContext *> FilParser::ExprContext::expr() {
  return getRuleContexts<FilParser::ExprContext>();
}

FilParser::ExprContext* FilParser::ExprContext::expr(size_t i) {
  return getRuleContext<FilParser::ExprContext>(i);
}

FilParser::CastContext* FilParser::ExprContext::cast() {
  return getRuleContext<FilParser::CastContext>(0);
}

tree::TerminalNode* FilParser::ExprContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

FilParser::Class_identifierContext* FilParser::ExprContext::class_identifier() {
  return getRuleContext<FilParser::Class_identifierContext>(0);
}

FilParser::LitteralContext* FilParser::ExprContext::litteral() {
  return getRuleContext<FilParser::LitteralContext>(0);
}

tree::TerminalNode* FilParser::ExprContext::NEW() {
  return getToken(FilParser::NEW, 0);
}

FilParser::Function_call_paramsContext* FilParser::ExprContext::function_call_params() {
  return getRuleContext<FilParser::Function_call_paramsContext>(0);
}

FilParser::Expr_parenthesisContext* FilParser::ExprContext::expr_parenthesis() {
  return getRuleContext<FilParser::Expr_parenthesisContext>(0);
}

FilParser::Expr_blockContext* FilParser::ExprContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}

FilParser::Array_assignContext* FilParser::ExprContext::array_assign() {
  return getRuleContext<FilParser::Array_assignContext>(0);
}

tree::TerminalNode* FilParser::ExprContext::DOT() {
  return getToken(FilParser::DOT, 0);
}

tree::TerminalNode* FilParser::ExprContext::ARROW() {
  return getToken(FilParser::ARROW, 0);
}

FilParser::Binary_operatorContext* FilParser::ExprContext::binary_operator() {
  return getRuleContext<FilParser::Binary_operatorContext>(0);
}

FilParser::Unary_op_postContext* FilParser::ExprContext::unary_op_post() {
  return getRuleContext<FilParser::Unary_op_postContext>(0);
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
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, FilParser::RuleExpr, precedence);

    

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
    setState(167);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(143);
      function();
      break;
    }

    case 2: {
      setState(144);
      lambda();
      break;
    }

    case 3: {
      setState(145);
      interface();
      break;
    }

    case 4: {
      setState(146);
      class_();
      break;
    }

    case 5: {
      setState(147);
      enum_();
      break;
    }

    case 6: {
      setState(148);
      variable_decl();
      break;
    }

    case 7: {
      setState(149);
      condition();
      break;
    }

    case 8: {
      setState(150);
      loop();
      break;
    }

    case 9: {
      setState(151);
      function_call();
      break;
    }

    case 10: {
      setState(152);
      exception();
      break;
    }

    case 11: {
      setState(153);
      unary_op_pre();
      setState(154);
      expr(12);
      break;
    }

    case 12: {
      setState(156);
      cast();
      break;
    }

    case 13: {
      setState(157);
      match(FilParser::IDENTIFIER);
      break;
    }

    case 14: {
      setState(158);
      class_identifier();
      break;
    }

    case 15: {
      setState(159);
      litteral();
      break;
    }

    case 16: {
      setState(160);
      match(FilParser::NEW);
      setState(161);
      class_identifier();
      setState(162);
      function_call_params();
      break;
    }

    case 17: {
      setState(164);
      expr_parenthesis();
      break;
    }

    case 18: {
      setState(165);
      expr_block();
      break;
    }

    case 19: {
      setState(166);
      array_assign();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(185);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(183);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(169);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(170);
          match(FilParser::DOT);
          setState(171);
          expr(15);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(172);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(173);
          match(FilParser::ARROW);
          setState(174);
          expr(14);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(175);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(176);
          binary_operator();
          setState(177);
          expr(11);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(179);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(180);
          unary_op_post();
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(181);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(182);
          assignation();
          break;
        }

        default:
          break;
        } 
      }
      setState(187);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
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

FilParser::Function_nameContext* FilParser::FunctionContext::function_name() {
  return getRuleContext<FilParser::Function_nameContext>(0);
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
  enterRule(_localctx, 4, FilParser::RuleFunction);
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
    setState(188);
    match(FilParser::FUN);
    setState(189);
    function_name();
    setState(190);
    fun_params();
    setState(193);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FilParser::COLON) {
      setState(191);
      match(FilParser::COLON);
      setState(192);
      type();
    }
    setState(195);
    fun_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_nameContext ------------------------------------------------------------------

FilParser::Function_nameContext::Function_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Function_nameContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

tree::TerminalNode* FilParser::Function_nameContext::OPERATOR() {
  return getToken(FilParser::OPERATOR, 0);
}

FilParser::Binary_operatorContext* FilParser::Function_nameContext::binary_operator() {
  return getRuleContext<FilParser::Binary_operatorContext>(0);
}


size_t FilParser::Function_nameContext::getRuleIndex() const {
  return FilParser::RuleFunction_name;
}


std::any FilParser::Function_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitFunction_name(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Function_nameContext* FilParser::function_name() {
  Function_nameContext *_localctx = _tracker.createInstance<Function_nameContext>(_ctx, getState());
  enterRule(_localctx, 6, FilParser::RuleFunction_name);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(200);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FilParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(197);
        match(FilParser::IDENTIFIER);
        break;
      }

      case FilParser::OPERATOR: {
        enterOuterAlt(_localctx, 2);
        setState(198);
        match(FilParser::OPERATOR);
        setState(199);
        binary_operator();
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
  enterRule(_localctx, 8, FilParser::RuleFun_params);
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
    setState(202);
    match(FilParser::LPAREN);
    setState(204);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FilParser::IDENTIFIER) {
      setState(203);
      fun_param_list();
    }
    setState(206);
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
  enterRule(_localctx, 10, FilParser::RuleFun_param_list);
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
    setState(208);
    fun_param();
    setState(213);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FilParser::COMMA) {
      setState(209);
      match(FilParser::COMMA);
      setState(210);
      fun_param();
      setState(215);
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
  enterRule(_localctx, 12, FilParser::RuleFun_param);

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
    match(FilParser::IDENTIFIER);
    setState(217);
    match(FilParser::COLON);
    setState(218);
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
  enterRule(_localctx, 14, FilParser::RuleFun_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(223);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FilParser::EQ:
      case FilParser::PLUS:
      case FilParser::MINUS:
      case FilParser::DIVIDE:
      case FilParser::TIMES:
      case FilParser::MOD:
      case FilParser::NOT:
      case FilParser::BAND:
      case FilParser::BOR:
      case FilParser::BXOR: {
        enterOuterAlt(_localctx, 1);
        setState(220);
        assignation();
        break;
      }

      case FilParser::LPAREN: {
        enterOuterAlt(_localctx, 2);
        setState(221);
        expr_parenthesis();
        break;
      }

      case FilParser::LBRACE: {
        enterOuterAlt(_localctx, 3);
        setState(222);
        expr_block();
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

//----------------- Function_declContext ------------------------------------------------------------------

FilParser::Function_declContext::Function_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Function_declContext::FUN() {
  return getToken(FilParser::FUN, 0);
}

FilParser::Function_nameContext* FilParser::Function_declContext::function_name() {
  return getRuleContext<FilParser::Function_nameContext>(0);
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
  enterRule(_localctx, 16, FilParser::RuleFunction_decl);
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
    setState(225);
    match(FilParser::FUN);
    setState(226);
    function_name();
    setState(227);
    fun_params();
    setState(230);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FilParser::COLON) {
      setState(228);
      match(FilParser::COLON);
      setState(229);
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
  enterRule(_localctx, 18, FilParser::RuleLambda);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    fun_params();
    setState(233);
    match(FilParser::ARROW);
    setState(236);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FilParser::LBRACE: {
        setState(234);
        expr_block();
        break;
      }

      case FilParser::LPAREN: {
        setState(235);
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
  enterRule(_localctx, 20, FilParser::RuleInterface);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    match(FilParser::INTERFACE);
    setState(239);
    match(FilParser::IDENTIFIER);
    setState(241);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(240);
      class_params();
      break;
    }

    default:
      break;
    }
    setState(244);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(243);
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
  enterRule(_localctx, 22, FilParser::RuleInterface_body);
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
    setState(246);
    match(FilParser::LBRACE);
    setState(250);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FilParser::FUN) {
      setState(247);
      function_decl();
      setState(252);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(253);
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

tree::TerminalNode* FilParser::Class_Context::CLASS() {
  return getToken(FilParser::CLASS, 0);
}

FilParser::Class_identifierContext* FilParser::Class_Context::class_identifier() {
  return getRuleContext<FilParser::Class_identifierContext>(0);
}

FilParser::Class_modifierContext* FilParser::Class_Context::class_modifier() {
  return getRuleContext<FilParser::Class_modifierContext>(0);
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
  enterRule(_localctx, 24, FilParser::RuleClass_);
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
    setState(256);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FilParser::ABSTRACT

    || _la == FilParser::OPEN) {
      setState(255);
      class_modifier();
    }
    setState(258);
    match(FilParser::CLASS);
    setState(259);
    class_identifier();
    setState(261);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(260);
      class_params();
      break;
    }

    default:
      break;
    }
    setState(264);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      setState(263);
      class_extends();
      break;
    }

    default:
      break;
    }
    setState(267);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      setState(266);
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
  enterRule(_localctx, 26, FilParser::RuleClass_modifier);
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
    setState(269);
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

//----------------- Class_identifierContext ------------------------------------------------------------------

FilParser::Class_identifierContext::Class_identifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Class_identifierContext::IDENTIFIER() {
  return getToken(FilParser::IDENTIFIER, 0);
}

tree::TerminalNode* FilParser::Class_identifierContext::TIMES() {
  return getToken(FilParser::TIMES, 0);
}

FilParser::Class_genericContext* FilParser::Class_identifierContext::class_generic() {
  return getRuleContext<FilParser::Class_genericContext>(0);
}


size_t FilParser::Class_identifierContext::getRuleIndex() const {
  return FilParser::RuleClass_identifier;
}


std::any FilParser::Class_identifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_identifier(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_identifierContext* FilParser::class_identifier() {
  Class_identifierContext *_localctx = _tracker.createInstance<Class_identifierContext>(_ctx, getState());
  enterRule(_localctx, 28, FilParser::RuleClass_identifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(271);
    match(FilParser::IDENTIFIER);
    setState(273);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      setState(272);
      match(FilParser::TIMES);
      break;
    }

    default:
      break;
    }
    setState(276);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      setState(275);
      class_generic();
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

//----------------- Class_genericContext ------------------------------------------------------------------

FilParser::Class_genericContext::Class_genericContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Class_genericContext::LT() {
  return getToken(FilParser::LT, 0);
}

std::vector<tree::TerminalNode *> FilParser::Class_genericContext::IDENTIFIER() {
  return getTokens(FilParser::IDENTIFIER);
}

tree::TerminalNode* FilParser::Class_genericContext::IDENTIFIER(size_t i) {
  return getToken(FilParser::IDENTIFIER, i);
}

tree::TerminalNode* FilParser::Class_genericContext::GT() {
  return getToken(FilParser::GT, 0);
}

std::vector<tree::TerminalNode *> FilParser::Class_genericContext::COMMA() {
  return getTokens(FilParser::COMMA);
}

tree::TerminalNode* FilParser::Class_genericContext::COMMA(size_t i) {
  return getToken(FilParser::COMMA, i);
}


size_t FilParser::Class_genericContext::getRuleIndex() const {
  return FilParser::RuleClass_generic;
}


std::any FilParser::Class_genericContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitClass_generic(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Class_genericContext* FilParser::class_generic() {
  Class_genericContext *_localctx = _tracker.createInstance<Class_genericContext>(_ctx, getState());
  enterRule(_localctx, 30, FilParser::RuleClass_generic);
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
    setState(278);
    match(FilParser::LT);
    setState(279);
    match(FilParser::IDENTIFIER);
    setState(284);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FilParser::COMMA) {
      setState(280);
      match(FilParser::COMMA);
      setState(281);
      match(FilParser::IDENTIFIER);
      setState(286);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(287);
    match(FilParser::GT);
   
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
  enterRule(_localctx, 32, FilParser::RuleClass_params);
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
    setState(289);
    match(FilParser::LPAREN);
    setState(291);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 538443776) != 0) {
      setState(290);
      class_param_list();
    }
    setState(293);
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
  enterRule(_localctx, 34, FilParser::RuleClass_param_list);
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
    setState(295);
    class_param();
    setState(300);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FilParser::COMMA) {
      setState(296);
      match(FilParser::COMMA);
      setState(297);
      class_param();
      setState(302);
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
  enterRule(_localctx, 36, FilParser::RuleClass_param);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(311);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FilParser::VAL:
      case FilParser::VAR: {
        enterOuterAlt(_localctx, 1);
        setState(303);
        variable_decl();
        break;
      }

      case FilParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(304);
        match(FilParser::IDENTIFIER);
        setState(305);
        match(FilParser::COLON);
        setState(306);
        type();
        setState(309);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == FilParser::EQ) {
          setState(307);
          match(FilParser::EQ);
          setState(308);
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
  enterRule(_localctx, 38, FilParser::RuleClass_extends);

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
    match(FilParser::COLON);
    setState(314);
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
  enterRule(_localctx, 40, FilParser::RuleClass_extend_list);

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
    setState(316);
    class_extend();
    setState(321);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(317);
        match(FilParser::COMMA);
        setState(318);
        class_extend(); 
      }
      setState(323);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
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

FilParser::Class_identifierContext* FilParser::Class_extendContext::class_identifier() {
  return getRuleContext<FilParser::Class_identifierContext>(0);
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
  enterRule(_localctx, 42, FilParser::RuleClass_extend);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(324);
    class_identifier();
    setState(326);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      setState(325);
      function_call_params();
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

//----------------- Class_bodyContext ------------------------------------------------------------------

FilParser::Class_bodyContext::Class_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Class_bodyContext::LBRACE() {
  return getToken(FilParser::LBRACE, 0);
}

tree::TerminalNode* FilParser::Class_bodyContext::RBRACE() {
  return getToken(FilParser::RBRACE, 0);
}

FilParser::Class_constructorContext* FilParser::Class_bodyContext::class_constructor() {
  return getRuleContext<FilParser::Class_constructorContext>(0);
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
  enterRule(_localctx, 44, FilParser::RuleClass_body);
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
    setState(328);
    match(FilParser::LBRACE);
    setState(330);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FilParser::CONSTRUCTOR) {
      setState(329);
      class_constructor();
    }
    setState(336);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3940) != 0) {
      setState(334);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
      case 1: {
        setState(332);
        class_variable();
        break;
      }

      case 2: {
        setState(333);
        class_function();
        break;
      }

      default:
        break;
      }
      setState(338);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(339);
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

FilParser::FunctionContext* FilParser::Class_functionContext::function() {
  return getRuleContext<FilParser::FunctionContext>(0);
}

FilParser::Function_declContext* FilParser::Class_functionContext::function_decl() {
  return getRuleContext<FilParser::Function_declContext>(0);
}

FilParser::Class_atr_modifierContext* FilParser::Class_functionContext::class_atr_modifier() {
  return getRuleContext<FilParser::Class_atr_modifierContext>(0);
}

tree::TerminalNode* FilParser::Class_functionContext::ABSTRACT() {
  return getToken(FilParser::ABSTRACT, 0);
}

tree::TerminalNode* FilParser::Class_functionContext::OVERRIDE() {
  return getToken(FilParser::OVERRIDE, 0);
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
  enterRule(_localctx, 46, FilParser::RuleClass_function);
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
    setState(342);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FilParser::ABSTRACT

    || _la == FilParser::OVERRIDE) {
      setState(341);
      _la = _input->LA(1);
      if (!(_la == FilParser::ABSTRACT

      || _la == FilParser::OVERRIDE)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(345);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3840) != 0) {
      setState(344);
      class_atr_modifier();
    }
    setState(349);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      setState(347);
      function();
      break;
    }

    case 2: {
      setState(348);
      function_decl();
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
  enterRule(_localctx, 48, FilParser::RuleClass_variable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(351);
    class_atr_modifier();
    setState(352);
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
  enterRule(_localctx, 50, FilParser::RuleClass_atr_modifier);
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
    setState(354);
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
  enterRule(_localctx, 52, FilParser::RuleClass_constructor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(356);
    match(FilParser::CONSTRUCTOR);
    setState(357);
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
  enterRule(_localctx, 54, FilParser::RuleEnum_);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(359);
    match(FilParser::ENUM);
    setState(360);
    match(FilParser::IDENTIFIER);
    setState(362);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      setState(361);
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
  enterRule(_localctx, 56, FilParser::RuleEnum_body);
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
    setState(364);
    match(FilParser::LBRACE);
    setState(373);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FilParser::IDENTIFIER) {
      setState(365);
      match(FilParser::IDENTIFIER);
      setState(370);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == FilParser::COMMA) {
        setState(366);
        match(FilParser::COMMA);
        setState(367);
        match(FilParser::IDENTIFIER);
        setState(372);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(375);
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
  enterRule(_localctx, 58, FilParser::RuleCondition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(379);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FilParser::IF: {
        enterOuterAlt(_localctx, 1);
        setState(377);
        if_();
        break;
      }

      case FilParser::SWITCH: {
        enterOuterAlt(_localctx, 2);
        setState(378);
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
  enterRule(_localctx, 60, FilParser::RuleIf_);

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
    setState(381);
    match(FilParser::IF);
    setState(382);
    if_condition();
    setState(383);
    if_body();
    setState(387);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(384);
        else_if(); 
      }
      setState(389);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    }
    setState(391);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      setState(390);
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
  enterRule(_localctx, 62, FilParser::RuleIf_condition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(393);
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

FilParser::Expr_blockContext* FilParser::If_bodyContext::expr_block() {
  return getRuleContext<FilParser::Expr_blockContext>(0);
}

FilParser::Expr_parenthesisContext* FilParser::If_bodyContext::expr_parenthesis() {
  return getRuleContext<FilParser::Expr_parenthesisContext>(0);
}

FilParser::ExprContext* FilParser::If_bodyContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
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
  enterRule(_localctx, 64, FilParser::RuleIf_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(398);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(395);
      expr_block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(396);
      expr_parenthesis();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(397);
      expr(0);
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
  enterRule(_localctx, 66, FilParser::RuleElse_if);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(400);
    match(FilParser::ELSE);
    setState(401);
    match(FilParser::IF);
    setState(402);
    if_condition();
    setState(403);
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
  enterRule(_localctx, 68, FilParser::RuleElse_);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(405);
    match(FilParser::ELSE);
    setState(406);
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
  enterRule(_localctx, 70, FilParser::RuleSwitch_);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(408);
    match(FilParser::SWITCH);
    setState(409);
    switch_condition();
    setState(410);
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
  enterRule(_localctx, 72, FilParser::RuleSwitch_condition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(412);
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
  enterRule(_localctx, 74, FilParser::RuleSwitch_body);
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
    setState(414);
    match(FilParser::LBRACE);
    setState(418);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la - 17) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 17)) & 545357767377793) != 0) {
      setState(415);
      switch_case();
      setState(420);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(421);
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
  enterRule(_localctx, 76, FilParser::RuleSwitch_case);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(425);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FilParser::TRUE:
      case FilParser::FALSE:
      case FilParser::NULL_:
      case FilParser::INT:
      case FilParser::FLOAT:
      case FilParser::STRING:
      case FilParser::FSTRING:
      case FilParser::CHAR: {
        setState(423);
        litteral();
        break;
      }

      case FilParser::DEFAULT: {
        setState(424);
        match(FilParser::DEFAULT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(427);
    match(FilParser::ARROW);
    setState(431);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      setState(428);
      expr(0);
      break;
    }

    case 2: {
      setState(429);
      expr_block();
      break;
    }

    case 3: {
      setState(430);
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
  enterRule(_localctx, 78, FilParser::RuleLoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(436);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(433);
      fori();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(434);
      foriter();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(435);
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
  enterRule(_localctx, 80, FilParser::RuleFori);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(438);
    match(FilParser::FOR);
    setState(439);
    fori_condition();
    setState(442);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      setState(440);
      expr(0);
      break;
    }

    case 2: {
      setState(441);
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
  enterRule(_localctx, 82, FilParser::RuleFori_condition);
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
    setState(444);
    match(FilParser::LPAREN);
    setState(446);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FilParser::VAL

    || _la == FilParser::VAR) {
      setState(445);
      variable_decl();
    }
    setState(448);
    match(FilParser::SEMICOLON);
    setState(450);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la - 2) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 2)) & -504391058002585553) != 0) {
      setState(449);
      expr(0);
    }
    setState(452);
    match(FilParser::SEMICOLON);
    setState(454);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la - 2) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 2)) & -504391058002585553) != 0) {
      setState(453);
      expr(0);
    }
    setState(456);
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
  enterRule(_localctx, 84, FilParser::RuleForiter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(458);
    match(FilParser::FOR);
    setState(459);
    foriter_condition();
    setState(462);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
    case 1: {
      setState(460);
      expr(0);
      break;
    }

    case 2: {
      setState(461);
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
  enterRule(_localctx, 86, FilParser::RuleForiter_condition);
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
    setState(464);
    match(FilParser::LPAREN);
    setState(465);
    _la = _input->LA(1);
    if (!(_la == FilParser::VAL

    || _la == FilParser::VAR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(466);
    match(FilParser::IDENTIFIER);
    setState(467);
    match(FilParser::COLON);
    setState(468);
    match(FilParser::IDENTIFIER);
    setState(469);
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
  enterRule(_localctx, 88, FilParser::RuleWhile_);

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
    match(FilParser::WHILE);
    setState(472);
    if_condition();
    setState(473);
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
  enterRule(_localctx, 90, FilParser::RuleException);

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
    setState(475);
    match(FilParser::TRY);
    setState(479);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      setState(476);
      expr(0);
      break;
    }

    case 2: {
      setState(477);
      expr_block();
      break;
    }

    case 3: {
      setState(478);
      expr_parenthesis();
      break;
    }

    default:
      break;
    }
    setState(482); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(481);
              catch_body();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(484); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
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
  enterRule(_localctx, 92, FilParser::RuleCatch_body);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(486);
    match(FilParser::CATCH);
    setState(487);
    match(FilParser::LPAREN);
    setState(488);
    fun_param();
    setState(489);
    match(FilParser::RPAREN);
    setState(493);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      setState(490);
      expr(0);
      break;
    }

    case 2: {
      setState(491);
      expr_block();
      break;
    }

    case 3: {
      setState(492);
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

tree::TerminalNode* FilParser::Binary_operatorContext::LT() {
  return getToken(FilParser::LT, 0);
}

tree::TerminalNode* FilParser::Binary_operatorContext::GT() {
  return getToken(FilParser::GT, 0);
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
  enterRule(_localctx, 94, FilParser::RuleBinary_operator);
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
    setState(495);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2161723423091326976) != 0)) {
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

//----------------- Unary_op_preContext ------------------------------------------------------------------

FilParser::Unary_op_preContext::Unary_op_preContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FilParser::Unary_op_preContext::PLUS() {
  return getTokens(FilParser::PLUS);
}

tree::TerminalNode* FilParser::Unary_op_preContext::PLUS(size_t i) {
  return getToken(FilParser::PLUS, i);
}

std::vector<tree::TerminalNode *> FilParser::Unary_op_preContext::MINUS() {
  return getTokens(FilParser::MINUS);
}

tree::TerminalNode* FilParser::Unary_op_preContext::MINUS(size_t i) {
  return getToken(FilParser::MINUS, i);
}

tree::TerminalNode* FilParser::Unary_op_preContext::TIMES() {
  return getToken(FilParser::TIMES, 0);
}

tree::TerminalNode* FilParser::Unary_op_preContext::BAND() {
  return getToken(FilParser::BAND, 0);
}


size_t FilParser::Unary_op_preContext::getRuleIndex() const {
  return FilParser::RuleUnary_op_pre;
}


std::any FilParser::Unary_op_preContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitUnary_op_pre(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Unary_op_preContext* FilParser::unary_op_pre() {
  Unary_op_preContext *_localctx = _tracker.createInstance<Unary_op_preContext>(_ctx, getState());
  enterRule(_localctx, 96, FilParser::RuleUnary_op_pre);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(503);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FilParser::PLUS: {
        enterOuterAlt(_localctx, 1);
        setState(497);
        match(FilParser::PLUS);
        setState(498);
        match(FilParser::PLUS);
        break;
      }

      case FilParser::MINUS: {
        enterOuterAlt(_localctx, 2);
        setState(499);
        match(FilParser::MINUS);
        setState(500);
        match(FilParser::MINUS);
        break;
      }

      case FilParser::TIMES: {
        enterOuterAlt(_localctx, 3);
        setState(501);
        match(FilParser::TIMES);
        break;
      }

      case FilParser::BAND: {
        enterOuterAlt(_localctx, 4);
        setState(502);
        match(FilParser::BAND);
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

//----------------- Unary_op_postContext ------------------------------------------------------------------

FilParser::Unary_op_postContext::Unary_op_postContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FilParser::Unary_op_postContext::PLUS() {
  return getTokens(FilParser::PLUS);
}

tree::TerminalNode* FilParser::Unary_op_postContext::PLUS(size_t i) {
  return getToken(FilParser::PLUS, i);
}

std::vector<tree::TerminalNode *> FilParser::Unary_op_postContext::MINUS() {
  return getTokens(FilParser::MINUS);
}

tree::TerminalNode* FilParser::Unary_op_postContext::MINUS(size_t i) {
  return getToken(FilParser::MINUS, i);
}

tree::TerminalNode* FilParser::Unary_op_postContext::LBRAK() {
  return getToken(FilParser::LBRAK, 0);
}

FilParser::ExprContext* FilParser::Unary_op_postContext::expr() {
  return getRuleContext<FilParser::ExprContext>(0);
}

tree::TerminalNode* FilParser::Unary_op_postContext::RBRAK() {
  return getToken(FilParser::RBRAK, 0);
}


size_t FilParser::Unary_op_postContext::getRuleIndex() const {
  return FilParser::RuleUnary_op_post;
}


std::any FilParser::Unary_op_postContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitUnary_op_post(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Unary_op_postContext* FilParser::unary_op_post() {
  Unary_op_postContext *_localctx = _tracker.createInstance<Unary_op_postContext>(_ctx, getState());
  enterRule(_localctx, 98, FilParser::RuleUnary_op_post);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(513);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FilParser::PLUS: {
        enterOuterAlt(_localctx, 1);
        setState(505);
        match(FilParser::PLUS);
        setState(506);
        match(FilParser::PLUS);
        break;
      }

      case FilParser::MINUS: {
        enterOuterAlt(_localctx, 2);
        setState(507);
        match(FilParser::MINUS);
        setState(508);
        match(FilParser::MINUS);
        break;
      }

      case FilParser::LBRAK: {
        enterOuterAlt(_localctx, 3);
        setState(509);
        match(FilParser::LBRAK);
        setState(510);
        expr(0);
        setState(511);
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
  enterRule(_localctx, 100, FilParser::RuleUnary_operator);
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
    setState(515);
    _la = _input->LA(1);
    if (!(((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2161864160579682304) != 0)) {
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
  enterRule(_localctx, 102, FilParser::RuleAssignation);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(517);
    assignation_operator();
    setState(518);
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
  enterRule(_localctx, 104, FilParser::RuleAssignation_operator);
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
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2161864160579682304) != 0) {
      setState(520);
      unary_operator();
    }
    setState(523);
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
  enterRule(_localctx, 106, FilParser::RuleCast);

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
    type();
    setState(527);
    match(FilParser::RPAREN);
    setState(528);
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

FilParser::Function_nameContext* FilParser::Function_callContext::function_name() {
  return getRuleContext<FilParser::Function_nameContext>(0);
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
  enterRule(_localctx, 108, FilParser::RuleFunction_call);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(530);
    function_name();
    setState(531);
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
  enterRule(_localctx, 110, FilParser::RuleFunction_call_params);
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
    setState(533);
    match(FilParser::LPAREN);
    setState(535);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la - 2) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 2)) & -504391058002585553) != 0) {
      setState(534);
      function_call_param_list();
    }
    setState(537);
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
  enterRule(_localctx, 112, FilParser::RuleFunction_call_param_list);
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
    setState(539);
    expr(0);
    setState(544);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FilParser::COMMA) {
      setState(540);
      match(FilParser::COMMA);
      setState(541);
      expr(0);
      setState(546);
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

FilParser::AssignationContext* FilParser::Variable_declContext::assignation() {
  return getRuleContext<FilParser::AssignationContext>(0);
}

tree::TerminalNode* FilParser::Variable_declContext::COLON() {
  return getToken(FilParser::COLON, 0);
}

FilParser::TypeContext* FilParser::Variable_declContext::type() {
  return getRuleContext<FilParser::TypeContext>(0);
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
  enterRule(_localctx, 114, FilParser::RuleVariable_decl);
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
    setState(547);
    _la = _input->LA(1);
    if (!(_la == FilParser::VAL

    || _la == FilParser::VAR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(548);
    match(FilParser::IDENTIFIER);
    setState(556);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx)) {
    case 1: {
      setState(551);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FilParser::COLON) {
        setState(549);
        match(FilParser::COLON);
        setState(550);
        type();
      }
      setState(553);
      assignation();
      break;
    }

    case 2: {
      setState(554);
      match(FilParser::COLON);
      setState(555);
      type();
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

//----------------- Array_assignContext ------------------------------------------------------------------

FilParser::Array_assignContext::Array_assignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Array_assignContext::LBRACE() {
  return getToken(FilParser::LBRACE, 0);
}

std::vector<FilParser::ExprContext *> FilParser::Array_assignContext::expr() {
  return getRuleContexts<FilParser::ExprContext>();
}

FilParser::ExprContext* FilParser::Array_assignContext::expr(size_t i) {
  return getRuleContext<FilParser::ExprContext>(i);
}

tree::TerminalNode* FilParser::Array_assignContext::RBRACE() {
  return getToken(FilParser::RBRACE, 0);
}

std::vector<tree::TerminalNode *> FilParser::Array_assignContext::COMMA() {
  return getTokens(FilParser::COMMA);
}

tree::TerminalNode* FilParser::Array_assignContext::COMMA(size_t i) {
  return getToken(FilParser::COMMA, i);
}


size_t FilParser::Array_assignContext::getRuleIndex() const {
  return FilParser::RuleArray_assign;
}


std::any FilParser::Array_assignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<FilParserVisitor*>(visitor))
    return parserVisitor->visitArray_assign(this);
  else
    return visitor->visitChildren(this);
}

FilParser::Array_assignContext* FilParser::array_assign() {
  Array_assignContext *_localctx = _tracker.createInstance<Array_assignContext>(_ctx, getState());
  enterRule(_localctx, 116, FilParser::RuleArray_assign);
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
    setState(558);
    match(FilParser::LBRACE);
    setState(559);
    expr(0);
    setState(564);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == FilParser::COMMA) {
      setState(560);
      match(FilParser::COMMA);
      setState(561);
      expr(0);
      setState(566);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(567);
    match(FilParser::RBRACE);
   
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
  enterRule(_localctx, 118, FilParser::RuleType);
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
    setState(569);
    match(FilParser::IDENTIFIER);
    setState(576);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
    case 1: {
      setState(570);
      match(FilParser::TIMES);
      break;
    }

    case 2: {
      setState(571);
      match(FilParser::LBRAK);
      setState(573);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == FilParser::INT) {
        setState(572);
        match(FilParser::INT);
      }
      setState(575);
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

tree::TerminalNode* FilParser::LitteralContext::FSTRING() {
  return getToken(FilParser::FSTRING, 0);
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
  enterRule(_localctx, 120, FilParser::RuleLitteral);
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
    setState(578);
    _la = _input->LA(1);
    if (!((((_la - 24) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 24)) & 4260607557639) != 0)) {
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

//----------------- Expr_parenthesisContext ------------------------------------------------------------------

FilParser::Expr_parenthesisContext::Expr_parenthesisContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FilParser::Expr_parenthesisContext::LPAREN() {
  return getToken(FilParser::LPAREN, 0);
}

tree::TerminalNode* FilParser::Expr_parenthesisContext::RPAREN() {
  return getToken(FilParser::RPAREN, 0);
}

std::vector<FilParser::ExprContext *> FilParser::Expr_parenthesisContext::expr() {
  return getRuleContexts<FilParser::ExprContext>();
}

FilParser::ExprContext* FilParser::Expr_parenthesisContext::expr(size_t i) {
  return getRuleContext<FilParser::ExprContext>(i);
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
  enterRule(_localctx, 122, FilParser::RuleExpr_parenthesis);
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
    setState(580);
    match(FilParser::LPAREN);
    setState(584);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la - 2) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 2)) & -504391058002585553) != 0) {
      setState(581);
      expr(0);
      setState(586);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(587);
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

tree::TerminalNode* FilParser::Expr_blockContext::LBRACE() {
  return getToken(FilParser::LBRACE, 0);
}

tree::TerminalNode* FilParser::Expr_blockContext::RBRACE() {
  return getToken(FilParser::RBRACE, 0);
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
  enterRule(_localctx, 124, FilParser::RuleExpr_block);
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
    setState(589);
    match(FilParser::LBRACE);
    setState(593);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la - 2) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 2)) & -504391058002585553) != 0) {
      setState(590);
      expr(0);
      setState(595);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(596);
    match(FilParser::RBRACE);
   
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
    case 1: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool FilParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 14);
    case 1: return precpred(_ctx, 13);
    case 2: return precpred(_ctx, 10);
    case 3: return precpred(_ctx, 11);
    case 4: return precpred(_ctx, 9);

  default:
    break;
  }
  return true;
}

void FilParser::initialize() {
  ::antlr4::internal::call_once(filparserParserOnceFlag, filparserParserInitialize);
}
