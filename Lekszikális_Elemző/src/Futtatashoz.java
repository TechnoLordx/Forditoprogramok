import java.util.Scanner;

public class Futtatashoz {
    public static void main(String[] args) {
        // input bekerese
        Scanner bemenet = new Scanner(System.in);
        System.out.println("Adja meg az Input-ot!");
        String input = bemenet.nextLine();

        // ha nem szeretne begepelni az input-ot, abban az esetben tegye kerem a
        // 8. sort megjegyzesbe es a tovabbiakban a 13. sorban levo inputot hasznalja

        //String input = "l(dsp{5}*:=<>p$";

        for (int i = 0; i < input.length(); i++)
        {
            System.out.println(input.charAt(i)); // egymas ala kiiratjuk az input karaktereit
        }

        allapotatmenetek elemzo = new allapotatmenetek(input); // letrehozunk egy peldanyt az allapotatmenetek osztalybol
        elemzo.feltetel1(); // elkezdi elemezni az input-ot

    }
}
