#ifndef CompteDepot_h
#define CompteDepot_h

class CompteDepot : public CompteBancaire {
public:
	CompteDepot();
	virtual ~CompteDepot();
	virtual void depot(float d);
	
};

#endif