class Counter{
	unsigned int count;
	public:
	Counter(unsigned int);
	void ReStart ( unsigned int );
	int DetectFinalCount(int);
	};



Counter::Counter(unsigned int set){
	count=set;
	}

void Counter::ReStart(unsigned int set){
	count=set;
	}

int Counter::DetectFinalCount(int parameter){
	if (!(--count))
		{
		//cout<<"fin";    //Aqui va Signal
		return 1;
		}
	return 0;
	}


