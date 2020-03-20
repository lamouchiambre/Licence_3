#ifndef CompteBancaire_h
#define CompteBancaire_h

class CompteBancaire {
	protected:
		float solde;
	public:
		CompteBancaire();
		virtual ~CompteBancaire();
		virtual void depot(float d);
		virtual void getSolde();

};
#endif

