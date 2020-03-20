#ifndef CompteRemunere_h
#define CompteRemunere_h

class CompteRemunere : virtual CompteBancaire
{
	protected:
		int bonus;
	public:
		CompteRemunere();
		virtual ~CompteRemunere();
		virtual void depot(float d);
};

#endif
