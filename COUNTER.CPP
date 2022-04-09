#include "prefix.h"
/////////////////Definicion de las funciones para Counter /////////
Counter::Counter(int newTerm ,unsigned int set)
{
	term=newTerm;
	count=set;
}

Counter::~Counter()
{
  cout<<"Destruido un counter: "<<term<<endl;
}


void Counter::ReStart(unsigned int set)
{
	count=set;
}

int Counter::DetectFinalCount(int parameter)
{
	parameter=0;   //modificado para que no marque warning
	if (!(--count))
		{
		cout<<"fin de contador";    //Aqui va Signal
		return 1;
		}
	return parameter;
}

int Counter::GetTerminal()
{
 	return term;
}

int Counter::operator ==(const Counter& t) const // Operador de igual
{
  return ( term ==t.term );
}