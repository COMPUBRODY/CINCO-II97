
#if !defined( __KERNEL_H )
#define __KERNEL_H

class Kernel: public TIListImp<Processor>
{
	unsigned int numberOfProcessors;
	public:
	Kernel();
	int Run(unsigned int);
	int Run();
	~Kernel();
};

#endif

