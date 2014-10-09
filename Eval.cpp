///////////////////////////////////////////////////////////////////////////////
///
/// @file Eval.cpp
/// LISP Interpreter - Eval
/// This program handles all the evaluations of the LISP interpreter
///
/// @author Asvin Vaidyanath Ganesh
///
/// @version 001 - 19Oct2013 - Asvin Vaidyanath Ganesh					  //001
///
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Header Files
///////////////////////////////////////////////////////////////////////////////

#include "stdlib.h"
#include "stdio.h"
#include "Eval.h"
#include "ErrorManager.h"

///////////////////////////////////////////////////////////////////////////////
/// Eval::isKeyword(SExp* s) - Check the function for keywords
///////////////////////////////////////////////////////////////////////////////
int Eval::isKeyword(SExp* s)
{
	if(s==NULL)
		return 0;

	if (strcmp("ATOM", s->value)==0 || strcmp("CAR", s->value)==0
	|| strcmp("CDR", s->value)==0 || strcmp("CONS", s->value)==0
	|| strcmp("EQ", s->value)==0 || strcmp("GREATER", s->value)==0
	|| strcmp("INT", s->value)==0 || strcmp("LESS", s->value)==0
	|| strcmp("MINUS", s->value)==0 || strcmp("NULL", s->value)==0
	|| strcmp("PLUS", s->value)==0 || strcmp("QUOTIENT", s->value)==0
	|| strcmp("REMAINDER", s->value)==0 || strcmp("TIMES", s->value)==0)
		return 1;

	return 0;
}


///////////////////////////////////////////////////////////////////////////////
/// SExp* Eval::isNULL(SExp* s)
///////////////////////////////////////////////////////////////////////////////
SExp* Eval::isNull(SExp* s)
{
	if (s->isAtom==1 && strcmp(s->value,"NIL")==0)
	  return new SExp(1);

	return new SExp(0);
}

///////////////////////////////////////////////////////////////////////////////
/// SExp* Eval::ATOM(SExp* s)
///////////////////////////////////////////////////////////////////////////////
SExp* Eval::atom(SExp* s)
{
	if (s->isAtom==1)
		return new SExp(1);

	return new SExp(0);
}

///////////////////////////////////////////////////////////////////////////////
/// SExp* Eval::INT(SExp* s)
///////////////////////////////////////////////////////////////////////////////
SExp* Eval::Int(SExp* s)
{
	if (s->isInt==1)
	  return new SExp(1);

	return new SExp(0);
}

///////////////////////////////////////////////////////////////////////////////
/// SExp* Eval::EQ(SExp* p1, SExp* p2)
///////////////////////////////////////////////////////////////////////////////
SExp* Eval::eq(SExp* p1, SExp* p2)
{
	char sStr[1000];
	memset(sStr,0,1000);

	if (p1->isAtom==0)
	{
		p1->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::EQ_NON_ATOMIC,sStr);
	}

	if (p2->isAtom==0)
	{
		p2->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::EQ_NON_ATOMIC,sStr);
	}

	if (p1->value[0]=='\0')
	{
		p1->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::P1_VALUE_NULL,sStr);
	}

	if (p2->value[0]=='\0')
	{
		p2->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::P2_VALUE_NULL,sStr);
	}

	if(strcmp(p1->value,p2->value)==0)
		return new SExp(1);

	return new SExp(0);
}
///////////////////////////////////////////////////////////////////////////////
/// SExp* Eval::cons(SExp* p1, SExp* p2)
///////////////////////////////////////////////////////////////////////////////
SExp* Eval::cons(SExp* p1, SExp* p2)
{
	SExp* s = new SExp();
	s->car = p1;
	s->cdr = p2;
	return s;
}

///////////////////////////////////////////////////////////////////////////////
/// SExp* Eval::CAR(SExp* s)
///////////////////////////////////////////////////////////////////////////////
SExp* Eval::car(SExp* s)
{
	char sStr[1000];
	memset(sStr,0,1000);

	if (s->isAtom==1)
	{
		s->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::CAR_ATOMIC,sStr);
	}
	if (s->car == NULL)
	{
		s->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::CAR_NULL,sStr);
	}

	return s->car;
}

///////////////////////////////////////////////////////////////////////////////
/// SExp* Eval::CDR(SExp* s)
///////////////////////////////////////////////////////////////////////////////
SExp* Eval::cdr(SExp* s)
{
	char sStr[1000];
	memset(sStr,0,1000);

	if (s->isAtom==1)
	{
		s->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::CDR_ATOMIC,sStr);
	}
	if (s->car == NULL)
	{
		s->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::CDR_NULL,sStr);
	}

	return s->cdr;
}

SExp* Eval::plus(SExp* p1, SExp* p2)
{
	char sStr[1000];
	memset(sStr,0,1000);

	if (p1->isInt==0)
	{
		p1->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::MATH_NON_INT,sStr);
	}

	if (p2->isInt==0)
	{
		p2->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::MATH_NON_INT,sStr);
	}

	SExp* r=new SExp();
	r->isAtom=1;
	r->isInt=1;
	r->iValue=p1->iValue+p2->iValue;
	sprintf(r->value,"%d",r->iValue);

	return r;
}

SExp* Eval::minus(SExp* p1, SExp* p2)
{
	char sStr[1000];
	memset(sStr,0,1000);

	if (p1->isInt==0)
	{
		p1->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::MATH_NON_INT,sStr);
	}

	if (p2->isInt==0)
	{
		p2->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::MATH_NON_INT,sStr);
	}

	SExp* r=new SExp();
	r->isAtom=1;
	r->isInt=1;
	r->iValue=p1->iValue-p2->iValue;
	sprintf(r->value,"%d",r->iValue);

	return r;
}

SExp* Eval::times(SExp* p1, SExp* p2)
{
	char sStr[1000];
	memset(sStr,0,1000);

	if (p1->isInt==0)
	{
		p1->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::MATH_NON_INT,sStr);
	}

	if (p2->isInt==0)
	{
		p2->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::MATH_NON_INT,sStr);
	}

	SExp* r=new SExp();
	r->isAtom=1;
	r->isInt=1;
	r->iValue=(p1->iValue) * (p2->iValue);
	sprintf(r->value,"%d",r->iValue);
	return r;
}


SExp* Eval::quotient(SExp* p1, SExp* p2)
{
	char sStr[1000];
	memset(sStr,0,1000);

	if (p1->isInt==0)
	{
		p1->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::MATH_NON_INT,sStr);
	}

	if (p2->isInt==0)
	{
		p2->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::MATH_NON_INT,sStr);
	}

	if (p2->iValue==0)
	{
		p2->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::DIVISION_BY_ZERO,sStr);
	}

	SExp* r=new SExp();
	r->isAtom=1;
	r->isInt=1;
	r->iValue=(p1->iValue) / (p2->iValue);
	sprintf(r->value,"%d",r->iValue);
	return r;
}

SExp* Eval::remainder(SExp* p1, SExp* p2)
{
	char sStr[1000];
	memset(sStr,0,1000);

	if (p1->isInt==0)
	{
		p1->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::MATH_NON_INT,sStr);
	}

	if (p2->isInt==0)
	{
		p2->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::MATH_NON_INT,sStr);
	}

	SExp* r=new SExp();
	r->isAtom=1;
	r->isInt=1;
	r->iValue=(p1->iValue) % (p2->iValue);
	sprintf(r->value,"%d",r->iValue);
	return r;
}

SExp* Eval::greater(SExp* p1, SExp* p2)
{
	char sStr[1000];
	memset(sStr,0,1000);

	if (p1->isInt==0)
	{
		p1->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::MATH_NON_INT,sStr);
	}

	if (p2->isInt==0)
	{
		p2->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::MATH_NON_INT,sStr);
	}

	if ((p1->iValue) > (p2->iValue))
		return new SExp(1);

	return new SExp(0);
}


SExp* Eval::less(SExp* p1, SExp* p2)
{
	char sStr[1000];
	memset(sStr,0,1000);

	if (p1->isInt==0)
	{
		p1->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::MATH_NON_INT,sStr);
	}

	if (p2->isInt==0)
	{
		p2->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::MATH_NON_INT,sStr);
	}

	if ((p1->iValue) < (p2->iValue))
		return new SExp(1);

	return new SExp(0);
}


SExp* Eval::bound(SExp* p1, SExp* p2)
{
	char sStr[1000];
	memset(sStr,0,1000);

	if (p1->isAtom==0)
	{
		p1->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::V1_NOT_ATOMIC,sStr);
	}

	if(p2->isNIL()==1)
		return new SExp(0);

	while(p2->isNIL()==0)
	{
		SExp* p=eq(p1,p2->car->car);
		if(p==NULL)
			return NULL;

		if(p->isT()==1)
			return new SExp(1);

		p2=p2->cdr;
	}

	return new SExp(0);
}

SExp* Eval::getVal(SExp* p1, SExp* p2)
{
	char sStr[1000];
	memset(sStr,0,1000);

	if (p1->isAtom==0)
	{
		p1->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::V1_NOT_ATOMIC,sStr);
	}

	while(p2->isNIL()==0)
	{
		SExp* p=eq(p1,p2->car->car);
		if(p==NULL)
			return NULL;

		if(p->isT()==1)
			return p2->car->cdr;

		p2=p2->cdr;
	}

	p1->convertString(sStr);
	ErrorManager E;
	E.buildRunTimeErrors(ErrorManager::CANT_FIND_MATCH,sStr);

	return NULL;

}

SExp* Eval::getFunc(SExp* p1, Tree* p2)
{
	char sStr[1000];
	memset(sStr,0,1000);


	for (int i=0;i<p2->getSize();i++)
	{
	  SExp* s = p2->get(i);
	  SExp* sp=eq(p1,s->car);

	  if(sp==NULL || s==NULL)
		  return NULL;

	  if (sp->isT()==1)
		return s->cdr;
	}

	return new SExp(0);
}

SExp* Eval::addPairs(SExp* p, SExp* x,SExp* a)
{
	char sStr[1000];
	memset(sStr,0,1000);

	if (x->isNIL()==1 && p->isNIL()==1)
	  return a;
	if (x->isNIL()==1)
	{
		x->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::USER_ARG_NO_MATCH,sStr);
	}

	if (p->isNIL()==1)
	{
		p->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::USER_ARG_NO_MATCH,sStr);
	}

	SExp* s=new SExp();
	s->car=p->car;
	s->cdr=x->car;

	return 	addPairs(p->cdr,x->cdr,cons(s,a));
}

SExp* Eval::eval_list(SExp* l, SExp* a,Tree* d)
{
	char sStr[1000];
	memset(sStr,0,1000);

	if(l->isNIL()!=1)
	{

	}
	else
		return new SExp(0);

	if(l->isAtom==1)
	{
		l->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::NOT_LIST,sStr);
	}

	SExp* q1=eval(l->car,a,d);
	if(q1!=NULL){

	}else
		return NULL;
	SExp* q2=eval_list(l->cdr,a,d);
	if(q2!=NULL){

	}else
		return NULL;

	return cons(q1,q2);
}

SExp* Eval::eval_con(SExp* be, SExp* a,Tree* d)
{
	char sStr[1000];

	memset(sStr,0,1000);

	if(be->isNIL()==1)
		return new SExp(0);

	if(be->isAtom==1 || be->car->isAtom==1 || be->car->cdr->isAtom==1)
	{
		be->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::ERROR_COND,sStr);
	}

	SExp* pp=eval(be->car->car,a,d);
	if(pp==NULL)
		return NULL;

	if(pp->isNIL()==0)
		return eval(be->car->cdr->car,a,d);

	return eval_con(be->cdr,a,d);
}

SExp* Eval::eval(SExp* exp, SExp* a,Tree* d)
{
	char sStr[1000];

	memset(sStr,0,1000);

	if(exp->isAtom==1)
	{
		if (exp->isT())
			return new SExp(1);
		if (exp->isNIL())
			return new SExp(0);
		if (exp->isInt==1)
			return exp;
		if (exp->isEOF())
			return NULL;

		SExp* b=bound(exp, a);
		if(b!=NULL){}
		else
			return NULL;
		if (b->isT()!=1){}
		else
			return getVal(exp, a);

		exp->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::UNBOUNDED_VARIABLE,sStr);

	}

	if(strcmp(exp->car->value,"QUOTE")==0)
		return exp->cdr->car;

	if(strcmp(exp->car->value,"COND")==0)
		return eval_con(exp->cdr,a,d);

	if(strcmp(exp->car->value,"DEFUN")==0)
	{
		if(a->isNIL()==0)
		{
			exp->convertString(sStr);
			ErrorManager E;
			E.buildRunTimeErrors(ErrorManager::DEFUN_NOT_TOP,sStr);

		}

		if(getFunc(exp->cdr->car,d)->isNIL()!=0)
		{ }
		else
		{
			exp->cdr->car->convertString(sStr);
			ErrorManager E;
			E.buildRunTimeErrors(ErrorManager::REDEFINED_FUNC,sStr);
		}

		SExp* f_name = exp->cdr->car;
		SExp* f_para = exp->cdr->cdr->car;
		SExp* f_body = exp->cdr->cdr->cdr->car;

		if(f_name==NULL || f_para==NULL || f_body==NULL)
			return NULL;

		d->append(cons(f_name,cons(f_para,f_body)));

		printf("%s\n",f_name->value);
		def=1;

		return new SExp(1);
	}

	if(isKeyword(exp->car)==0 && getFunc(exp->car, d)->isNIL()==1)
	{
		exp->car->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::UNDEFINED_FUNC,sStr);
	}

	SExp* rv=eval_list(exp->cdr,a,d);
	if(rv==NULL)
		return NULL;

	return apply(exp->car, rv,a,d);
}

SExp* Eval::apply(SExp* f, SExp* x, SExp* a,Tree* d)
{
	char sStr[1000];

	memset(sStr,0,1000);

	if(f->isAtom==0)
	{
		f->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::NON_ATOMIC_FUNC,sStr);
	}

	if(f->value[0]=='\0')
	{
		f->convertString(sStr);
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::F_VALUE_NULL,sStr);
	}

	if(strcmp(f->value,"NULL")==0)
	{
		if(x->car==NULL)
		{
			x->convertString(sStr);
			ErrorManager E;
			E.buildRunTimeErrors(ErrorManager::ARGUMENT_NO_MATCH,sStr);
		}
		else
			return isNull(x->car);
	}

	if(strcmp(f->value,"ATOM")==0)
	{
		if(x->car==NULL)
		{
			x->convertString(sStr);
			ErrorManager E;
			E.buildRunTimeErrors(ErrorManager::ARGUMENT_NO_MATCH,sStr);
		}
		else
			return atom(x->car);
	}

	if(strcmp(f->value,"INT")==0)
	{
		if(x->car==NULL)
		{
			x->convertString(sStr);
			ErrorManager E;
			E.buildRunTimeErrors(ErrorManager::ARGUMENT_NO_MATCH,sStr);
		}
		else
			return Int(x->car);
	}

	if(strcmp(f->value,"CAR")==0)
	{
		if(x->car==NULL)
		{
			x->convertString(sStr);
			ErrorManager E;
			E.buildRunTimeErrors(ErrorManager::ARGUMENT_NO_MATCH,sStr);
		}
		else
			return car(x->car);
	}

	if(strcmp(f->value,"CDR")==0)
	{
		if(x->car==NULL)
		{
			x->convertString(sStr);
			ErrorManager E;
			E.buildRunTimeErrors(ErrorManager::ARGUMENT_NO_MATCH,sStr);
		}
		else
			return cdr(x->car);
	}

	if(strcmp(f->value,"EQ")==0)
	{
		if(x->car==NULL || x->cdr->car==NULL)
		{
			x->convertString(sStr);
			ErrorManager E;
			E.buildRunTimeErrors(ErrorManager::ARGUMENT_NO_MATCH,sStr);

		}
		else
			return eq(x->car,x->cdr->car);
	}

	if(strcmp(f->value,"CONS")==0)
	{
		if(x->car==NULL || x->cdr->car==NULL)
		{
			x->convertString(sStr);
			ErrorManager E;
			E.buildRunTimeErrors(ErrorManager::ARGUMENT_NO_MATCH,sStr);
		}
		else
			return cons(x->car,x->cdr->car);
	}

	if(strcmp(f->value,"PLUS")==0)
	{
		if(x->car==NULL || x->cdr->car==NULL)
		{
			x->convertString(sStr);
			ErrorManager E;
			E.buildRunTimeErrors(ErrorManager::ARGUMENT_NO_MATCH,sStr);
		}
		else
			return plus(x->car,x->cdr->car);
	}

	if(strcmp(f->value,"MINUS")==0)
	{
		if(x->car==NULL || x->cdr->car==NULL)
		{
			x->convertString(sStr);
			ErrorManager E;
			E.buildRunTimeErrors(ErrorManager::ARGUMENT_NO_MATCH,sStr);
		}
		else
			return minus(x->car,x->cdr->car);
	}

	if(strcmp(f->value,"TIMES")==0)
	{
		if(x->car==NULL || x->cdr->car==NULL)
		{
			x->convertString(sStr);
			ErrorManager E;
			E.buildRunTimeErrors(ErrorManager::ARGUMENT_NO_MATCH,sStr);
		}
		else
			return times(x->car,x->cdr->car);
	}


	if(strcmp(f->value,"QUOTIENT")==0)
	{
		if(x->car==NULL || x->cdr->car==NULL)
		{
			x->convertString(sStr);
			ErrorManager E;
			E.buildRunTimeErrors(ErrorManager::ARGUMENT_NO_MATCH,sStr);
		}
		else
			return quotient(x->car,x->cdr->car);
	}

	if(strcmp(f->value,"REMAINDER")==0)
	{
		if(x->car==NULL || x->cdr->car==NULL)
		{
			x->convertString(sStr);
			ErrorManager E;
			E.buildRunTimeErrors(ErrorManager::ARGUMENT_NO_MATCH,sStr);

		}
		else
			return remainder(x->car,x->cdr->car);
	}

	if(strcmp(f->value,"GREATER")==0)
	{
		if(x->car==NULL || x->cdr->car==NULL)
		{
			x->convertString(sStr);
			ErrorManager E;
			E.buildRunTimeErrors(ErrorManager::ARGUMENT_NO_MATCH,sStr);
		}
		else
			return greater(x->car,x->cdr->car);
	}

	if(strcmp(f->value,"LESS")==0)
	{
		if(x->car==NULL || x->cdr->car==NULL)
		{
			x->convertString(sStr);
			ErrorManager E;
			E.buildRunTimeErrors(ErrorManager::ARGUMENT_NO_MATCH,sStr);
		}
		else
			return less(x->car,x->cdr->car);
	}

	SExp* body = getFunc(f, d)->cdr;
	if(body!=NULL){}
	else
		return NULL;

	SExp* SE = addPairs(getFunc(f, d)->car, x, a);
	if(SE!=NULL){

	}else
		return NULL;

	return eval(body,SE,d);
}


