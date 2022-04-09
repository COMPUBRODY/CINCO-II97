

//<<<<<<<<<<<< Definicion de Funciones de la clase Estadistica >>>>>>>>>>>>

Stadistic::Stadistic()		//Constructor de la clase
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

unsigned long Stadistic::GetBHCA()
{
	return(bhca);
}

void Stadistic::IncBHCA()
{
	bhca++;
}

unsigned long Stadistic::GetFails()
{
	return(fails);
}

void Stadistic::IncFails()
{
	fails++;
}

unsigned long Stadistic::GetFailsToFirstDigit()
{
	return(failsToFirstDigit);
}

void Stadistic::IncFailsToFirstDigit()
{
	failsToFirstDigit++;
}

unsigned long Stadistic::GetTimeout()
{
	return(timeout);
}

void Stadistic::IncTimeout()
{
	timeout++;
}

unsigned long Stadistic::GetOnHookInDial()
{
	return(onHookInDial);
}

void Stadistic::IncOnHookInDial()
{
	onHookInDial++;
}

unsigned long Stadistic::GetNoAnswer()
{
	return(noAnswer);
}

void Stadistic::IncNoAnswer()
{
	noAnswer++;
}

unsigned long Stadistic::GetUnSuccess()
{
	return(unSuccess);
}

void Stadistic::IncUnSuccess()
{
	unSuccess++;
}

unsigned long Stadistic::GetSuccess()
{
	return(success);
}

void Stadistic::IncSuccess()
{
	success++;
}

unsigned long Stadistic::GetIncoming()
{
	return(incoming);
}

void Stadistic::IncIncoming()
{
	incoming++;
}

unsigned long Stadistic::GetOutgoing()
{
	return(outgoing);
}

void Stadistic::IncOutgoing()
{
	outgoing++;
}

unsigned long Stadistic::GetTransfered()
{
	return(transfered);
}

void Stadistic::IncTransfered()
{
	transfered++;
}

unsigned long Stadistic::GetLocal()
{
	return(local);
}

void Stadistic::IncLocal()
{
	local++;
}

~Stadistic::Stadistic()
{
	 cout<<"\nDestruida la clase estadistica";
}
