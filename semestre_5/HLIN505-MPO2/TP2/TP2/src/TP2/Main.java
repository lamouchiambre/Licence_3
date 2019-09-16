package TP2;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Livre l1 = new Livre( " l1 " , 3);
		Document l2 = new Livre( " l2 ", 4 ) ;
		Document d = new Document(" d " );
		Biblio b =new Biblio() ;
		BiblioSansDoublons bsd=new BiblioSansDoublons() ;
		Biblio bsd2=new BiblioSansDoublons();
		// a j o u t d a n s b : B i b l i o
		b.ajoutDocument( l1 );
		b.ajoutDocument( l1 );
		b.ajoutDocument( l2 ) ;
		b.ajoutDocument( d ) ;
		System.out.println(b.toString());
		//ajout dans bsd : BiblioSansDoublons
		bsd.ajoutDocument(l1);
		bsd.ajoutDocument(l1);
		bsd.ajoutDocument(l2);
		bsd.ajoutDocument(d);
		System.out.println(bsd.toString());
		//a j o u t dans bsd2 : B i b l i o S a n s D o u b l o n s
		bsd2.ajoutDocument(l1);
		bsd2.ajoutDocument(l1);
		bsd2.ajoutDocument(l2);
		bsd2.ajoutDocument(d);
		System.out.println(bsd2.toString());
	}

}
