%{
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//#define true 1
//#define false 0
extern int yylex();
extern FILE* yyin;
extern char* yytext;
void yyerror(const char *s);

char* STATES_NAME[] = {"camera", "primitive", "texture", "material", "light"};
char* current_shader = NULL;
int index_of_shader = 0;

/* design for test7: if the interface doesn't belongs to the current shader, then ignore the errors inside the implementation of the interface */
bool ignore_the_error_inside_interface = false; 

/* states and interfaces of camera. I don't list constructor, because every shader has this interface*/
char* Camera_states[] = {"rt_RayOrigin", "rt_RayDirection", "rt_InverseRayDirection" , "rt_Epsilon"  , "rt_HitDistance" , "rt_ScreenCoord" , "rt_LensCoord", "rt_du", "rt_dv", "rt_TimeSeed", "generateRay" };

/* states and interfaces of primitive. I don't list constructor, because every shader has this interface*/
char* Primitive_states[] = {"rt_RayOrigin", "rt_RayDirection" , "rt_InverseRayDirection " , "rt_Epsilon", "rt_HitDistance" ,"rt_HitPoint", "rt_BoundMin" , "rt_BoundMax" , "rt_GeometricNormal " , "rt_dPdu" , "rt_dPdv" , "rt_ShadingNormal " , "rt_TextureUV" , "rt_TextureUVW", "rt_dsdu", "rt_dsdv", "rt_PDF", "rt_TimeSeed", "intersect" ,"computeBounds" ,"computeNormal" ,"computeTextureCoordinates" ,"computeDerivatives" ,"generateSample" ,"samplePDF" };

/* states and interfaces of texture. I don't list constructor, because every shader has this interface*/
char* Texture_states[] = {"rt_TextureUV"  , "rt_TextureUVW " , "rt_TextureColor " , "rt_FloatTextureValue " , "rt_du" , "rt_dv" , "rt_dsdu"  , "rt_dtdu" , "rt_dsdv" , "rt_dtdv" , "rt_dPdu " , "rt_dPdv " , "rt_TimeSeed", "lookup" };

/* states and interfaces of material. I don't list constructor, because every shader has this interface*/
char* Material_states[] = {"rt_RayOrigin" , "rt_RayDirection" , "rt_InverseRayDirection " , "rt_HitPoint" ,"rt_ShadingNormal", "rt_HitDistance", "rt_dPdu" , "rt_dPdv" , "rt_LightDirection" , "rt_LightDistance" , "rt_LightColor" , "rt_EmissionColor " , "rt_BSDFSeed" , "rt_TimeSeed" , "rt_PDF" , "rt_SampleColor" , "rt_BSDFValue" , "rt_du" , "rt_dv", "shade" ,"BSDF" ,"sampleBSDF" ,"evaluatePDF" ,"emission" };

/* states and interfaces of light. I don't list constructor, because every shader has this interface*/
char* Light_states[] = {"rt_HitPoint" , "rt_GeometricNormal " , "rt_ShadingNormal " , "rt_LightDirection " , "rt_TimeSeed", "illumination" };

char** All[] = {Camera_states, Primitive_states, Texture_states, Material_states, Light_states};

/* State_size[] is used to store the size of every shader states(and interface) array */
int State_size[] = {sizeof(Camera_states)/sizeof(Camera_states[0]),
	sizeof(Primitive_states)/sizeof(Primitive_states[0]), 
	sizeof(Texture_states)/sizeof(Texture_states[0]), 
	sizeof(Material_states)/sizeof(Material_states[0]), 
	sizeof(Light_states)/sizeof(Light_states[0])};


/* Description: find current text belongs to which shader
 * Parameter: yytext from Lexer. When calling this function, the text is always a state. 
 * Return Value: Normally(actually always), the function will return an index which can be used in State_names[] or State_size[] to indicate the parameter(state) belongs to which shader; otherwise, return -1. This branch would never be reached, just to avoid warning by compiler 
*/
int get_index(char* text){
	for(int i = 0; i < sizeof(All)/sizeof(All[0]); i++){
		for(int j = 0; j < State_size[i]; j++){
			//printf("%d, %d, %s\n", i, j, All[i][j]);
			if(!strcmp(text, All[i][j])){
				return i;
			}
		}
	}
	return -1;
}

/* Description: judge whether the state belongs to current shader
 * Parameter: text(state)
 * Return Value: return true if the state is in current shader; otherwise false
*/
bool is_state_in_current_shader(char* text){
	for(int i = 0; i < State_size[index_of_shader]; i++){
		//printf("TEST: %d, %s, %s, %s\n",index_of_shader, All[index_of_shader][i], current_shader, text);
		if(!strcmp(All[index_of_shader][i], text))
			return true;
	}
	return false;
}

/* Description: check whether current state got from Lexer is legal in current context
 * Parameter: text(state)
 * Return Value: None; if illegal, call yyerror(char* );
*/
void check_state(char* text){
	char ret[100] = "0";
	/* First condition: judge whether the state belongs to current shader
	 * Second condition: judge wheter the state holder is current shader
	 * The reason why setting the first condition:
	 * Normally, if a state only belongs to one shader, such as rt_LensCoord only belongs to Camera, ignoring the first condition wont have any problem.
         * However, if a state is shared by one more shader, then we need the first condition to avoid error. For example, both shader Camera and Primitive have a state called rt_RayOrigin, if the current shader is Primitive and the parameter is rt_RayOrigin, then the second condition will be true. Without the first condition, there would be a wrong error message in this case.
        */
	if(!is_state_in_current_shader(text) &&  strcmp(STATES_NAME[get_index(text)],current_shader) ){
		sprintf(ret, "%s cannot access a state of %s", current_shader, STATES_NAME[get_index(text)]);
		yyerror(ret);
	}
}

/* Description: check whether current interface got from Lexer is legal in current context
 * Parameter: text(state)
 * Return Value: None; if illegal, call yyerror(char* );
*/
void check_interface(char* text){
	char ret[100] = "0";
	if(strcmp(STATES_NAME[get_index(text)],current_shader)){
		sprintf(ret, "%s cannot have an interface method of %s", current_shader, STATES_NAME[get_index(text)]);
		/* if the interface is illegal, ignore the errors inside the definition of the interface. Test7 follows this rule*/
		ignore_the_error_inside_interface = true;
		yyerror(ret);
	}
}

%}

%token	IDENTIFIER I_CONSTANT F_CONSTANT STRING_LITERAL FUNC_NAME SIZEOF

%token LBRACE RBRACE LPARENTHESIS RPARENTHESIS LBRACKET RBRACKET
%token COMMA SEMICOLON COLON

%token ASSIGN LT LE GT GE EQUAL NOT_EQUAL PLUS MINUS MUL DIV
%token	PTR_OP INC DEC LEFT_OP RIGHT_OP

%token	AND OR MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN PLUS_ASSIGN MINUS_ASSIGN
%token	SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN

%token	CONST RESTRICT VOLATILE PUBLIC PRIVATE

%token	BOOL CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID VEC2 VEC3 VEC4 BVEC2 BVEC3 BVEC4 CLASS COLOR

%token	IF ELSE RETURN WHILE FOR

%token PRIMITIVE CAMERA MATERIAL TEXTURE LIGHT

%token RAYORIGIN RAYDIRECTION INVERSERAYDIRECTION EPSILON HITDISTANCE SCREENCOORD LENSCOORD DU DV TIMESEED

%token BOUNDMIN BOUNDMAX DPDU DPDV SHADINGNORMAL TEXTUREUV TEXTUREUVW DSDU DSDV PDF

%token TEXTURECOLOR FLOATTEXTUREVALUE DTDU DTDV

%token LIGHTDISTANCE LIGHTCOLOR EMISSIONCOLOR BSDFSEED SAMPLECOLOR BSDFVALUE

%token HITPOINT GEOMETRICNORMAL LIGHTDIRECTION

%token INTERFACE_GENERATERAY

%token INTERFACE_INTERSECT INTERFACE_COMPUTEBOUNDS INTERFACE_COMPUTENORMAL INTERFACE_COMPUTETEXTURECOORDINATES INTERFACE_COMPUTEDERIVATIVES INTERFACE_GENERATESAMPLE INTERFACE_SAMPLEPDF

%token INTERFACE_LOOKUP

%token INTERFACE_SHADE INTERFACE_BSDF INTERFACE_SAMPLEBSDF INTERFACE_EVALUATEPDF INTERFACE_EMISSION

%token INTERFACE_ILLUMINATION


%%

primary_statement
	: primary_statement statement
	| primary_statement shader_def
	| primary_statement function_definition
	| primary_statement declaration
	| shader_def
	| statement
	| function_definition
	| declaration
	;

rt
	: CAMERA  { printf("SHADER_DEF camera\n"); index_of_shader = 0; current_shader = "camera";}
	| PRIMITIVE { printf("SHADER_DEF primitive\n"); index_of_shader = 1; current_shader = "primitive";}
	| TEXTURE { printf("SHADER_DEF texture\n"); index_of_shader = 2; current_shader = "texture";}
	| MATERIAL { printf("SHADER_DEF material\n"); index_of_shader = 3; current_shader = "material";}
	| LIGHT { printf("SHADER_DEF light\n"); index_of_shader = 4; current_shader = "light";}
	;

shader_states
	: RAYORIGIN
	| RAYDIRECTION
	| INVERSERAYDIRECTION
	| EPSILON
	| HITDISTANCE 
	| SCREENCOORD 
	| LENSCOORD 
	| DU 
	| DV 
	| TIMESEED
	| BOUNDMIN 
	| BOUNDMAX 
	| DPDU 
	| DPDV 
	| SHADINGNORMAL 
	| TEXTUREUV 
	| TEXTUREUVW 
	| DSDU 
	| DSDV 
	| PDF
	| TEXTURECOLOR 
	| FLOATTEXTUREVALUE 
	| DTDU 
	| DTDV
	| LIGHTDISTANCE 
	| LIGHTCOLOR 
	| EMISSIONCOLOR 
	| BSDFSEED 
	| SAMPLECOLOR 
	| BSDFVALUE
	| HITPOINT 
	| GEOMETRICNORMAL 
	| LIGHTDIRECTION
	;

shader_def
	: CLASS IDENTIFIER COLON rt SEMICOLON
	;


type_specifier
	: VOID
	|  CHAR
	| SHORT
	| INT 
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| BOOL
	| VEC2
	| VEC3
	| VEC4
	| BVEC2
	| BVEC3
	| BVEC4
	| COLOR
	| CLASS
	;

operator
	: PLUS
	| MINUS
	| MUL
	| DIV
	| DEC
	| INC
	| ASSIGN
	| PLUS_ASSIGN
	| MINUS_ASSIGN
	| DIV_ASSIGN
	| MUL_ASSIGN
	| MOD_ASSIGN
	| EQUAL
	| NOT_EQUAL
	| LE
	| LT
	| GT
	| GE
	; 


type_qualifier
	: CONST
	| PUBLIC
	| PRIVATE
	;

interface
	: INTERFACE_GENERATERAY  		{ check_interface(yytext);}
	| INTERFACE_INTERSECT   		{ check_interface(yytext);}
	| INTERFACE_COMPUTEBOUNDS		{ check_interface(yytext);}    
	| INTERFACE_COMPUTENORMAL 		{ check_interface(yytext);}   
	| INTERFACE_COMPUTETEXTURECOORDINATES   { check_interface(yytext);}
	| INTERFACE_COMPUTEDERIVATIVES   	{ check_interface(yytext);}
	| INTERFACE_GENERATESAMPLE   		{ check_interface(yytext);}
	| INTERFACE_SAMPLEPDF   		{ check_interface(yytext);}
	| INTERFACE_LOOKUP   			{ check_interface(yytext);}
	| INTERFACE_SHADE   			{ check_interface(yytext);}
	| INTERFACE_BSDF   			{ check_interface(yytext);}
	| INTERFACE_SAMPLEBSDF   		{ check_interface(yytext);}
	| INTERFACE_EVALUATEPDF   		{ check_interface(yytext);}
	| INTERFACE_EMISSION   			{ check_interface(yytext);}
	| INTERFACE_ILLUMINATION                { check_interface(yytext);}    
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

declaration
	: specifier_qualifier_list IDENTIFIER 
	| specifier_qualifier_list IDENTIFIER COMMA
	| specifier_qualifier_list IDENTIFIER SEMICOLON { printf("DECLARATION\n");}
	| specifier_qualifier_list IDENTIFIER ASSIGN expression SEMICOLON { printf("DECLARATION\n");}
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

/*confused, run correctly in normal cases, but cannot recursion, to be optimized later*/
declarator
	: IDENTIFIER LPARENTHESIS RPARENTHESIS
	| IDENTIFIER LPARENTHESIS declaration_list RPARENTHESIS
	| interface LPARENTHESIS RPARENTHESIS { ignore_the_error_inside_interface = false;}
	| interface LPARENTHESIS declaration_list RPARENTHESIS  { ignore_the_error_inside_interface = false;}
	| LPARENTHESIS declarator RPARENTHESIS
	| declarator LPARENTHESIS RPARENTHESIS
	| declarator LPARENTHESIS declaration_list RPARENTHESIS
	;


expression
	: expression operator expression
	| IDENTIFIER
	| I_CONSTANT
	| F_CONSTANT
	| function_call
	| shader_states {check_state(yytext);}
	| LPARENTHESIS expression RPARENTHESIS
	|
	;


statement
	: expression_statement
	| assign_statement
	| if_statement
	| loop_statement
	| return_statement
	| compound_statement
	| function_call_statement
	;

expression_statement
	: SEMICOLON { printf("STATEMENT\n"); }
	| expression SEMICOLON  { printf("STATEMENT\n");}
	;

assign_statement
	: IDENTIFIER ASSIGN expression SEMICOLON { printf("STATEMENT\n");}
	;

if_statement
	: IF LPARENTHESIS expression RPARENTHESIS statement ELSE statement { printf("IF - ELSE\nSTATEMENT\n");}
	| IF LPARENTHESIS expression RPARENTHESIS statement {printf("IF\nSTATEMENT\n");}
	;

loop_statement
	: WHILE LPARENTHESIS expression RPARENTHESIS statement { printf("STATEMENT\n");}
	| FOR LPARENTHESIS expression SEMICOLON expression SEMICOLON expression RPARENTHESIS statement { printf("STATEMENT\n");}
	;

return_statement
	: RETURN expression SEMICOLON { printf("STATEMENT\n");}
	;

compound_statement
	: LBRACE RBRACE { printf("STATEMENT\n");}
	| LBRACE block_statement RBRACE { printf("STATEMENT\n");}
	;

block_statement
	: block_item
	| block_statement block_item
	;

block_item
	: declaration
	| statement
	;

function_definition
	: specifier_qualifier_list declarator function_body_statement {printf("FUNCTION_DEF\n");}
	;

function_body_statement
	: LBRACE RBRACE 
	| LBRACE block_statement RBRACE 
	;

function_call_statement
	: function_call SEMICOLON { printf("STATEMENT\n");}
	;

function_call
	: type_specifier LPARENTHESIS parameter_list RPARENTHESIS
	| IDENTIFIER LPARENTHESIS parameter_list RPARENTHESIS
	;

parameter_list
	: expression
	| expression COMMA expression
	| function_call COMMA expression
	;

%%

int main(int argc, char** argv){
	if(argc > 1){
		yyin = fopen(argv[1], "r");
	}
	else{
		yyin = stdin;
	}
	yyparse();
}

void yyerror(const char *s){
	fflush(stdout);
	fprintf(stderr, "Error: %s\n", s);
}
