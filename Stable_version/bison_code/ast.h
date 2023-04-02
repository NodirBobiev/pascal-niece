#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ---------------- classes ---------------- //
class Visitor;
class Visitable;
class Program;
class Declaration;
class SimpleDeclaration;
class RoutineDeclaration;
class VariableDeclaration;
class TypeDeclaration;
class Type;
class UserType;
class Expression;
class Parameters;
class ParameterDeclaration;
class Body;
class Statement;
class Assignment;
class Integer;
class Real;
class Boolean;
class ModifiablePrimary;
class RoutineCall;
class Range;
// ---------------- classes ---------------- //

// ---------------- typedefs ---------------- //
typedef string Identifier;
typedef vector<Expression> ExpressionList;
// ---------------- typedefs ---------------- //

class Visitor
{
public:
    virtual ~Visitor() {}
};

class Visitable
{
public:
    virtual ~Visitable() {}
    virtual void accept(Visitor*v) = 0;
};

class Declaration : public Visitable {};

class Program: public Visitable
{
public:
    vector<Declaration*> declarations;    
};

class SimpleDeclaration : public Declaration, public BodyInteface {};

class VariableDeclaration : public SimpleDeclaration
{
public:
    Identifier identifier;
    Type* type;
    Expression* expression;
};

class TypeDeclaration : public SimpleDeclaration
{
public:
    Identifier identifier;
    Type* type;
};

class RoutineDeclaration : public Declaration
{
public:
    Identifier identifier;
    Parameters* parameters;
    Type* type;
    Body* body;
};

class Parameters : public Visitable
{
public:
    vector<ParameterDeclaration*> parameterDeclarations;
};

class ParameterDeclaration : public Visitable
{
public:
    Identifier identifier;
    Type* type;
};

class Type: public Visitable {};

class PrimitiveType : public Type {};

class Integer : public PrimitiveType {};

class Real : public PrimitiveType {};

class Boolean : public PrimitiveType {};

class UserType : public Type {};

class ArrayType : public UserType
{
public:
    Expression* expression;
    Type* type;
};

class RecordType : public UserType
{
public:
    VariableDeclaration* variableDeclaration;
};

class Statement : public BodyInteface {};

class Assignment : public Statement 
{
public:
    ModifiablePrimary* modifiablePrimary;
    Expression* expression;
};

class RoutineCall : public Statement 
{
public:
    Identifier identifier;
    ExpressionList expressionList;
};

class WhileLoop : public Statement 
{
public:
    Expression* expression;
    Body* body;
};

class ForLoop : public Statement 
{
public:
    Identifier identifier;
    bool reverse;
    Range* range;
    Body* body;
};

class Range : Visitable
{
public:
    Expression* beginExpression;
    Expression* endExpression;
};

class IfStatement : public Statement 
{
public:
    Expression* expression;
    Body* body;
    Body* elseBody;
};

class BodyInteface : public Visitable {};

class Body : public Visitable 
{
public:
    vector<BodyInteface*> bodyElements;
};

class Expression : public Visitable {};
