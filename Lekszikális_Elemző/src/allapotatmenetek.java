import static java.lang.Character.isDigit;
import static java.lang.Character.isLetter;

public class allapotatmenetek {
    //  konstruktor
    allapotatmenetek(String obj)  // 'obj' jeloli az input string-et
    {
        input = obj;
        index = -1;

        // -1 -rol inditjuk az indexet, mivel
        // az 1.feltetelunkben leptetes tortenik
    }
    int index;
    String input;

    void leptetes()
    {
        index ++; // novelkuj az index-et 1 -el
    }

    void backup()
    {
        index --; // csokkentjuk az index-et 1 -el
    }

    void feltetel1()
    {
        System.out.println("Kezdőállapot");
        if(index == input.length()-1)
        {
            return; // ha az index egyenlo az input hosszaval kilep
        }
        leptetes();

        if (isLetter(input.charAt(index))) // ha szoveg akkor feltetel2 -re lep at
        {
            feltetel2();

        }else if(isDigit(input.charAt(index))) // ha szam akkor  feltetel4 -re lep at
        {
            feltetel4();

        }else if(input.charAt(index) == '{') // innentol kezdve a 67. sorig kezdo karakterek
        {
            feltetel6();

        }else if(input.charAt(index) == '(')
        {
            feltetel8();

        }else if(input.charAt(index) == ':')
        {
            feltetel12();

        }else if(input.charAt(index) == '<')
        {
            feltetel14();

        }else if(input.charAt(index) == '>')
        {
            feltetel17();

        }else if(input.charAt(index) == ' ')
        {
            feltetel1();

        }else if(input.charAt(index) == '$') // input véget talalt lép a feltetel21 -re
        {
            feltetel21();

        }else{
            feltetel19();
        }
    }

    void feltetel2()
    {
        System.out.println("azonoítóban");
        leptetes();

        if(isLetter(input.charAt(index)))
        {
            feltetel2();

        }else if(isDigit(input.charAt(index)))
        {
            feltetel2();

        }else{
            feltetel3();
        }
    }

    void feltetel3()
    {
        System.out.println("azonisító vége");
        backup();
        feltetel1();
    }

    void feltetel4()
    {
        System.out.println("számban");
        leptetes();
        if(isLetter(input.charAt(index)))
        {
            feltetel4();

        }else{
            feltetel5();
        }
    }

    void feltetel5()
    {
        System.out.println("szam vége");
        backup();
        feltetel1();
    }

    void feltetel6()
    {
        System.out.println("{} komm.-ban");
        leptetes();
        if(input.charAt(index) == '}')
        {
            feltetel7();

        }else if(input.charAt(index) == '$')
        {
            feltetel19();

        }else{
            feltetel6();
        }
    }

    void feltetel7()
    {
        System.out.println("{} komm. vég");
        feltetel1();
    }

    void feltetel8()
    {
        System.out.println("(-talált");
        leptetes();
        if(input.charAt(index) == '*')
        {
            feltetel9();

        }else if(input.charAt(index) == '$')
        {
            feltetel19();

        }else{
            feltetel20();
        }
    }

    void feltetel9()
    {
        System.out.println("(**) kom.ban");
        leptetes();
        if(input.charAt(index) == '*')
        {
            feltetel10();

        }else if(input.charAt(index) == '$')
        {
            feltetel19();

        }else{
            feltetel9();
        }
    }

    void feltetel10()
    {
        System.out.println("* (**)-ban");
        leptetes();
        if(input.charAt(index) == '*')
        {
            feltetel10();

        }else if(input.charAt(index) == ')')
        {
            feltetel11();

        }else if(input.charAt(index) == '$')
        {
            feltetel19();

        }else{
            feltetel9();
        }
    }

    void feltetel11()
    {
        System.out.println("(**) komm.vég");
        feltetel1();
    }

    void feltetel12()
    {
        System.out.println(":-t talált");
        leptetes();
        if(input.charAt(index) == '=')
        {
            feltetel13();

        }else if(input.charAt(index) == '$')
        {
            feltetel19();

        }else{
            feltetel20();
        }
    }

    void feltetel13()
    {
        System.out.println(":= token");
        feltetel1();
    }

    void feltetel14()
    {
        System.out.println("<-t talált");
        leptetes();
        if(input.charAt(index) == '=')
        {
            feltetel15();

        }else if(input.charAt(index) == '>')
        {
            feltetel16();

        }else if(input.charAt(index) == '$')
        {
            feltetel20();

        }else{
            feltetel20();
        }
    }

    void feltetel15()
    {
        System.out.println("<= token");
        feltetel1();
    }

    void feltetel16()
    {
        System.out.println("<> token");
        feltetel1();
    }

    void feltetel17()
    {
        System.out.println(">-t talált");
        leptetes();
        if(input.charAt(index) == '=')
        {
            feltetel18();

        }else if(input.charAt(index) == '$')
        {
            feltetel19();

        }else{
            feltetel20();
        }
    }

    void feltetel18()
    {
        System.out.println(">= token");
        feltetel1();
    }

    void feltetel19()
    {
        System.out.println("hibakezelo: " + input.charAt(index));
        feltetel1();
    }

    void feltetel20()
    {
        System.out.println("továbbfejl.");
        backup();
        feltetel1();
    }

    void feltetel21()
    {
        System.out.println("stop");
    }

}


