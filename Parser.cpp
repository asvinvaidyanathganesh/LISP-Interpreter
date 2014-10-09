///////////////////////////////////////////////////////////////////////////////
///
/// @file Parser.cpp
/// LISP Interpreter - Parser
///
/// This program handles the parsing of the input tokens
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
#include "Parser.h"
#include "ErrorManager.h"

Tree* Parser::parse(char* args,int len)
{

	char str1[1000];
	char alter[1000];
	int i=0,count=0,str1_count=0;
	int parenthesis_num=0;
	char s[1000];

	memset(str1,0,1000);
	memset(alter,0,1000);
	memset(s,0,1000);
	for(i=0;i<len;i++)
	{
		if (args[i] == '.'){
			if (args[i-1] == '(' || args[i-1] == ')' || args[i-1] == '\n' ||
				args[i-1] == '\t' || args[i-1] == ' '){
			}
			else{
				ErrorManager E;
				E.buildErrors(ErrorManager::SYNTAX_ERROR);
			}
			if (args[i+1] == '(' || args[i+1] == ')' || args[i+1] == '\n' ||
					args[i+1] == '\t' || args[i+1] == ' '){

			}
			else{
				ErrorManager E;
				E.buildErrors(ErrorManager::SYNTAX_ERROR);
			}
		}
	}

	for(i=0;i<len;i++)
	{
		if(args[i]=='(')
		{
			s[count++]=' ';
			s[count++]=args[i];
		}
		else if(args[i]==')')
		{
			s[count++]=args[i];
			s[count++]=' ';
		}
		else
			s[count++]=args[i];
	}

	len=count;
	count=0;

	i=0;
	while(i<len && s[i]==' ')
		i++;

	count=i;

	for(;i<len;i++)
	{
		alter[i-count]=s[i];

		if(alter[i-count]=='\n')
			alter[i-count]=' ';
		else if(alter[i-count]=='\r')
			alter[i-count]=' ';
		else if(alter[i-count]=='\t')
			alter[i-count]=' ';
		else if(alter[i-count]=='(')
			parenthesis_num++;
		else if(alter[i-count]==')')
		{
			parenthesis_num--;
			if(parenthesis_num<0)
			{
				ErrorManager E;
				E.buildErrors(ErrorManager::MISMATCH_PAREN);
				return NULL;
			}
		}
	}


	if(parenthesis_num==0)
	{
		// This is fine!
	}
	else
	{
		ErrorManager E;
		E.buildErrors(ErrorManager::MISMATCH_PAREN);
		return NULL;
	}


	count=len-count;
	i=str1_count=0;

	while(count>i)
	{
		if(alter[i]=='(' || alter[i]=='.')
		{
			str1[str1_count++]=alter[i];
			i++;

			while(alter[i]==' ')
				i++;

		}
		else if(alter[i]==' ')
		{
			while(alter[i]==' ')
				i++;

			if(alter[i]!='.' && alter[i]!=')' && alter[i]!='\0')
				str1[str1_count++]=' ';
		}

		if(i>=count){

		}else
			str1[str1_count++]=alter[i];

		i++;
	}


	return parseTree(str1);
}

int Parser::pairs(char* str, int pos)
{

	if(str[pos]!='(')
	{
		ErrorManager E;
		E.buildErrors(ErrorManager::STRING_POS_INVALID);
	}

	int len=strlen(str);
	int level = 0;
	int index = pos;

	while(index < len)
	{
	  if (str[index]=='(')
		 level++;
	  else if(str[index]==')')
		 level--;

	  if (level!=0){
		  index++;
	  }else
		 return index;

	}
	return -1;
}

char* Parser::getNeighbour(char* str, char* s, int index)
{

	int begin= index - 10;
	int end = index + 10;
	int count=0;
	int len=strlen(str);
	int i;

	if (0 > begin)
		begin = 0;
	if (end <= len){

	}
	else {
		end = len;
	}

	for(i=begin;i<index;i++)
		s[count++]=str[i];

	s[count++]='\'';
	s[count++]=str[index];
	s[count++]='\'';

	for(i=index+1;i<end;i++)
		s[count++]=str[i];

	return s;
}


Tree* Parser::parseTree(char* argstr)
{
	char error_str[1000];
	char temp_str[1000];
	char t_str[1000];

	Tree* T = new Tree();

	int next_index = 0;

	memset(t_str,0,1000);
	memcpy(t_str,argstr,strlen(argstr));

	char* str=removeS(t_str);

	if(strlen(str)==0)
		return T;

	memset(error_str,0,1000);

	if (str[0] != '(')
	{// This is fine. Skip through.
	}
	else
	{
	  next_index = pairs(str,0);
	   if (next_index == -1)
	  {
			ErrorManager E;
			E.buildRunTimeErrors(ErrorManager::MISMATCH_PAREN,getNeighbour(str,error_str,0));

	  }
	}

	int dot_index = indexOf(str,next_index,'.');
	int space_index = indexOf(str,next_index,' ');

	if (dot_index != -1 && dot_index < space_index)
	{
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::SYNTAX_ERROR,getNeighbour(str,error_str,dot_index));
	}


	memset(temp_str,0,1000);
	memcpy(temp_str,str,strlen(str));

	if (space_index != -1)
	{
	  temp_str[space_index]='\0';
	  T=parseTree(&(temp_str[space_index+1]));
	  if(T==NULL)
		  return NULL;

	}
	SExp* pls = parseOne(temp_str);

	if(pls==NULL)
		return NULL;

	T->appendHeader(pls);

	return T;
}


int Parser::getTop(char* str, int pos, char ch)
{
	int level = 0;
	int index = pos;
	int len=strlen(str);

	while (index<len)
	{
	  if (str[index]=='(')
		 level++;
	  else if (str[index]==')')
		 level--;
	  else if (level == 0 && str[index]==ch)
		return index;

	  index++;
	}

	return -1;
}



SExp*  Parser::parseOne(char* para_str)
{
	int i;
	char temp_str[1000];
	char error_str[1000];

	SExp* ps=new SExp();

	memset(error_str,0,1000);

	memset(temp_str,0,1000);
	memcpy(temp_str,para_str,strlen(para_str));

	char* str=removeS(temp_str);

	if(str[0]=='\0')
	{
		ErrorManager E;
		E.buildErrors(ErrorManager::EMPTY_STRING);
	}

	if(str[0]!='(')
	{

		ps->isAtom = 1;
		int len=strlen(str);

		if(isAlpha(str[0])==1)
		{

			ps->isInt=0;
			for(i=0;i<len;i++)
			{
				if(isAlphaOrDigit(str[i])==0)
				{
					ErrorManager E;
					E.buildRunTimeErrors(ErrorManager::SYNTAX_ERROR,getNeighbour(str,error_str,i));
				}
			}

			ps->setValue(str);
		}
		else if(isDigit(str[0])==1 || str[0]=='-' || str[0]=='+')
		{

			ps->isInt=1;

			if(str[0]!='+')
				ps->setValue(str);
			else
				ps->setValue(str+1);

			ps->iValue=atoi(str);
		}
		else
		{

			ErrorManager E;
			E.buildRunTimeErrors(ErrorManager::SYNTAX_ERROR,getNeighbour(str,error_str,0));
		}

		return ps;
	}

	char list_str[1000];
	memset(list_str,0,1000);

	ps->isAtom = 0;
	int end_index = pairs(str,0);

	int last_index=strlen(str)-1;
	if (end_index !=last_index)
	{
		ErrorManager E;
		E.buildRunTimeErrors(ErrorManager::SYNTAX_ERROR,getNeighbour(str,error_str,end_index));
	}

	memcpy(list_str,str,strlen(str));
	list_str[end_index]='\0';
	char* n_str=list_str+1;

	int dot_index = getTop(n_str, 0, '.');
	if (dot_index!=-1)
	{
		int ispace=getTop(n_str, 0, ' ');

		ispace=getTop(n_str, dot_index+1, '.');
		if (ispace!=-1)
		{
			ErrorManager E;
			E.buildRunTimeErrors(ErrorManager::SYNTAX_ERROR,getNeighbour(n_str,error_str,ispace));

		}

		n_str[dot_index]='\0';

		ps->car = parseOne(n_str);
		if(ps->car==NULL)
			return NULL;

		ps->cdr = parseOne(&(n_str[dot_index+1]));
		if(ps->cdr==NULL)
			return NULL;

		return ps;
	}

	Tree* li = parseTree(n_str);
	if(li==NULL)
		return NULL;

	return getSExp(li);
}

SExp* Parser::getSExp(Tree* li)
{
	if (li->getSize()==0)
	  return new SExp(0);

	SExp* s = new SExp();
	s->isAtom = 0;
	s->car = li->removeHeader();
	s->cdr = getSExp(li);
	return s;
}

char* Parser::removeS(char* str)
{
	int len=strlen(str);

	while(str[len-1]==' ')
		--len;
	str[len]='\0';

	len=0;
	while(str[len]==' ')
		++len;

	return str+len;
}
// To check if the input character is an alphabet
int Parser::isAlpha(char c)
{

	if(c>='A' && c<='Z')
		return 1;
	return 0;
}


// To check if the input character is a number
int Parser::isDigit(char c)
{
	if(c>='0' && c<='9')
		return 1;

	return 0;
}

int Parser::isAlphaOrDigit(char c)
{
	if(isAlpha(c) || isDigit(c))
		return 1;

	return 0;
}


int Parser::indexOf(char* str,int pos,char c)
{
	for(int i=pos;str[i]!='\0';i++)
		if(str[i]==c)
			return i;

	return -1;
}
