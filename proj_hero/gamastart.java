import java.util.Random;
import java.util.Scanner;
import java.util.Random;
import java.lang.Thread;

public class gamastart {
    static Scanner scanner;
    static hero h;
    static hero opphero;
    static boolean gamecontrol;

    public static void main(String[] args) throws InterruptedException {
        boolean matchcontrol = true;
        boolean roundcontrol = true;
        scanner = new Scanner(System.in);
        gamecontrol = true;
        while (gamecontrol == true) {
        
          
            choosehero();
            if (gamecontrol == false)
                break;
           
            Thread.sleep(1000);
            chooseopphero();
           
            opphero.setsc(scanner);
            opphero.setlvl(1);
            Thread.sleep(1000);
           
            opphero.showAll();

           
            opphero.setopp(h);
            System.out.println("characters choosed game starting...");
            System.out.println("---------------------------------------------------------------");
            Thread.sleep(1000);

            roundcontrol = true;

            while (roundcontrol == true) {
                System.out.println("Press 0 for auto-battle ");
                System.out.println("Press 1 for normal-battle ");
                
                int randombattlechoose=scanner.nextInt();
                scanner.nextLine();
                boolean randombattle=(randombattlechoose==1)?false:true;
                if (matchcontrol == false) {
                    h.updatelvl(h.getlvl() + 1);

                    chooseopphero();
                    opphero.setopplvl(h.getlvl());
                    opphero.setsc(scanner);
                    opphero.showAll();
                    opphero.setopp(h);
                    matchcontrol = true;
                }
                System.out.println("İf you want to change hero press 0 else press 1");
                int changehero=scanner.nextInt();
                if(changehero==0){
                    changehero();
                }
                roundcontrol = true;
                Thread.sleep(1000);
                h.setopp(opphero);
                opphero.setopp(h);
                h.chooseturn();
                opphero.chooseturn();

                while (matchcontrol == true) {
                    Thread.sleep(200);

                    h.herostate();
                    opphero.herostate();
                    if (h.getturn() == true) {
                        System.out.println("Your turn you may choose");
                        System.out.println();
                        h.randomstart(randombattle);
                        System.out.println("---------------------------------------------------------------");

                    } else {
                        System.out.println("Opponent's turn you may choose");
                        System.out.println();

                        opphero.randomstart(true);
                        System.out.println("---------------------------------------------------------------");

                    }
                    Thread.sleep(2000);
                    if (opphero.isAllive() == false) {
                        matchcontrol = false;
                        System.out.println(opphero.heroname + " defeated --- Battle ended");
                        h.herostate();
                        opphero.herostate();
                        System.out.println("-------------------------------------------------------------");
                    }

                    else if (h.isAllive() == false) {
                        roundcontrol = false;
                        matchcontrol = false;
                        System.out.println(h.heroname + " defeated --- Battle ended");
                        h.herostate();
                        opphero.herostate();
                        System.out.println("-------------------------------------------------------------");
                    }

                }

            }

        }

    }

    private static void chooseopphero() throws InterruptedException {
        Random random = new Random();
        int r = random.nextInt(3);

        if (r == 1)
            opphero = new human(h, "Oppenent", "Your character");
        else if (r == 2)
            opphero = new elves(h, "Oppenent", "Your character");
        else if (r == 3)
            opphero = new dwarfs(h, "Oppenent", "Your character");
        else if (r == 0)
            opphero = new dwarfs(h, "Oppenent", "Your character");
        else {
            System.out.println("choice: " + r);
        }

        System.out.println("Your character is " + h.getherotpye());
        Thread.sleep(1000);

        System.out.println("Opponent's character is " + opphero.getherotpye());

    }
    

    private static void choosehero() {
        System.out.println("Hi ");
        System.out.println("You may choice your character below:");
        System.out.println("press 1 for Human");
        System.out.println("press 2 for Elf");
        System.out.println("press 3 for Dwarf");
        System.out.println("press 4 for Halfling");
        System.out.println("press 5 for Ending the game");

        try {
            int choice = scanner.nextInt();
            scanner.nextLine();
            if (choice == 1)
                h = new human(opphero, "Your character", "Oppenent");
            else if (choice == 2)
                h = new elves(opphero, "Your character", "Oppenent");
            else if (choice == 3)
                h = new dwarfs(opphero, "Your character", "Oppenent");
            else if (choice == 4)
                h = new halflings(opphero, "Your character", "Oppenent");
            else if (choice == 5)
                gamecontrol = false;
            else {
                System.out.println("choice: " + choice);
            }
            h.setlvl(1);
            h.setsc(scanner);
            h.showAll();
            h.setopp(opphero);

        } catch (Exception e) {
            System.out.println("Enter a number please");
            choosehero();
        }
         

    }

    
    

    private static void changehero() {
        int bchp=h.getchp(); int bcmp=h.getcmp();
        System.out.println("You may change your character below:");
        System.out.println("press 1 for Human");
        System.out.println("press 2 for Elf");
        System.out.println("press 3 for Dwarf");
        System.out.println("press 4 for Halfling");
        System.out.println("press 5 for Ending the game");

        try {
            int choice = scanner.nextInt();
            scanner.nextLine();
            if (choice == 1)
                h = new human(opphero, "Your character", "Oppenent");
            else if (choice == 2)
                h = new elves(opphero, "Your character", "Oppenent");
            else if (choice == 3)
                h = new dwarfs(opphero, "Your character", "Oppenent");
            else if (choice == 4)
                h = new halflings(opphero, "Your character", "Oppenent");
            else if (choice == 5)
                gamecontrol = false;
            else {
                System.out.println("choice: " + choice);
            }
            h.setlvl(1);
            h.setsc(scanner);
            h.showAll();
            h.setopp(opphero);
            h.characterchange(bcmp, bchp);
            System.out.println(h.getheroname()+" was changed...");

        } catch (Exception e) {
            System.out.println("Enter a number please");
            choosehero();
        }

    }
}
