#if !defined( __KERNEL_H )
#include <c:\bc4\pbx\include\kernel.h>
#endif


extern void SearchLevel( Processor& T, void* nivel);
extern void SearchPriority ( Processor& T, void* prioridad);

Kernel::Kernel():TIListImp<Processor>(),numberOfProcessors(0)
{
}

int Kernel::Run()
{
 //	for(;;) {
			for ( int nivel = FULL; nivel >= NEAREMPTY; nivel--){
				for ( int prioridad = VERYHIGH; prioridad >= VERYLOW; prioridad-- ){
					this->ForEach (SearchLevel, &nivel);
					this->ForEach (SearchPriority, &prioridad);
				}
			}
 //	}  		//Si ponemos return aqui, sale del lazo,
				//cuando este vacio

	return 0; //No sale nunca del lazo
}

int Kernel::Run(unsigned int cnt)
{
	int count = cnt;
	do {
		for ( int nivel = FULL; nivel >= NEAREMPTY; nivel--){
			for ( int prioridad = VERYHIGH; prioridad >= VERYLOW; prioridad-- ){
				this->ForEach (SearchLevel, &nivel);
				this->ForEach (SearchPriority, &prioridad);
				//delay(100);
				count--;
			}
		}
	}while ( count>0);
return 0;
}

Kernel::~Kernel()
{
}

