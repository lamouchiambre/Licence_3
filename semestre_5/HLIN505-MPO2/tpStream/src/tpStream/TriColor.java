package tpStream;

import java.awt.Color;
import java.util.Iterator;

public class TriColor implements Iterable<Color> {
	private Color[] couleurs = {Color.red, Color.orange, Color.green};
	
	public TriColor(){}
	
	public Iterator<Color> iterator() {
        return new FeuTricoloreIterateur(couleurs);
    }

    public static void main(String[] arg)
    {
        TriColor f = new TriColor();
        Iterator<Color> ite = f.iterator();

        for (int step = 0; step < 12; step++)
            {
                System.out.println(ite.next());
            }
    }

}