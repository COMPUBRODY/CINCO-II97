#include "prefix.h"
//<<<<<<<<<<<< Definicion de Funciones de la clase Estadistica >>>>>>>>>>>>

Statistic::Statistic()		//Constructor de la clase
{
	 bhca=0;
	 fails=0;
	 failsToFirstDigit=0;
	 timeout=0;
	 onHookInDial=0;
	 noAnswer=0;
	 unSuccess=0;
	 success=0;
	 incoming=0;
	 outgoing=0;
	 transfered=0;
	 local=0;

}

unsigned long Statistic::GetBHCA()
{
	return(bhca);
}

void Statistic::IncBHCA()
{
	bhca++;
}

unsigned long Statistic::GetFails()
{
	return(fails);
}

void Statistic::IncFails()
{
	fails++;
}

unsigned long Statistic::GetFailsToFirstDigit()
{
	return(failsToFirstDigit);
}

void Statistic::IncFailsToFirstDigit()
{
	failsToFirstDigit++;
}

unsigned long Statistic::GetTimeout()
{
	return(timeout);
}

void Statistic::IncTimeout()
{
	timeout++;
}

unsigned long Statistic::GetOnHookInDial()
{
	return(onHookInDial);
}

void Statistic::IncOnHookInDial()
{
	onHookInDial++;
}

unsigned long Statistic::GetNoAnswer()
{
	return(noAnswer);
}

void Statistic::IncNoAnswer()
{
	noAnswer++;
}

unsigned long Statistic::GetUnSuccess()
{
	return(unSuccess);
}

void Statistic::IncUnSuccess()
{
	unSuccess++;
}

unsigned long Statistic::GetSuccess()
{
	return(success);
}

void Statistic::IncSuccess()
{
	success++;
}

unsigned long Statistic::GetIncoming()
{
	return(incoming);
}

void Statistic::IncIncoming()
{
	incoming++;
}

unsigned long Statistic::GetOutgoing()
{
	return(outgoing);
}

void Statistic::IncOutgoing()
{
	outgoing++;
}

unsigned long Statistic::GetTransfered()
{
	return(transfered);
}

void Statistic::IncTransfered()
{
	transfered++;
}

unsigned long Statistic::GetLocal()
{
	return(local);
}

void Statistic::IncLocal()
{
	local++;
}

/*Stadistic::~Stadistic()
{
	 cout<<"\nDestruida la clase estadistica";
} */

